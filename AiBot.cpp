#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include "AiBot.h"

using namespace std;
int bestMoveid = 0;

char **boardCpy;
//funçao para incializar a visao da Ai criando o ponteiro 


//defenir o simbolo de cada jogador
AiBot::AiBot(char charOption, char **board)
{   
    boardCpy = new char*[3];
    for (int i = 0; i < 3; i++)
    {
        boardCpy[i] = new char[3];
        boardCpy[i] = board[i];
    }
}
//transformar um x e um y num moveIndex
int AiBot::move2dToIndex(int x, int y)
{
    int moveIndex;
    moveIndex = y + 3 * x;
    return moveIndex;
}

// funçao para determinar quantos movimentos faltam no quadro
int AiBot::movesLeft(char **boardCpy)
{
    int movesLeft;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (boardCpy[i][j] == '\0')
            {
                movesLeft++;
            }
        }
    }
    return movesLeft;
}

// funçao que retorna uma pontuaçao vencedora ou perdedora avaliando uma matriz
int AiBot::evaluate(char **boardCpy, char charOption)
{
    //defenir os movimentos atravez da funçao
    // avaliar as linhas para ver se ha jogada vencedora
    for (int row = 0; row < 3; row++)
    {
        if (boardCpy[row][0] == boardCpy[row][1] &&
            boardCpy[row][1] == boardCpy[row][2])
        {
            if (boardCpy[row][0] == computerMove)
                return +10;
            else if (boardCpy[row][0] == humanMove)
                return -10;
        }
    }

    // avaliar as colunas para ver se ha jogada vencedora
    for (int col = 0; col < 3; col++)
    {
        if (boardCpy[0][col] == boardCpy[1][col] &&
            boardCpy[1][col] == boardCpy[2][col])
        {
            if (boardCpy[0][col] == computerMove)
                return +10;

            else if (boardCpy[0][col] == humanMove)
                return -10;
        }
    }

    // avaliar as diagonais para ver se ha jogada vencedora
    if (boardCpy[0][0] == boardCpy[1][1] && boardCpy[1][1] == boardCpy[2][2])
    {
        if (boardCpy[0][0] == computerMove)
            return +10;
        else if (boardCpy[0][0] == humanMove)
            return -10;
    }

    if (boardCpy[0][2] == boardCpy[1][1] && boardCpy[1][1] == boardCpy[2][0])
    {
        if (boardCpy[0][2] == computerMove)
            return +10;
        else if (boardCpy[0][2] == humanMove)
            return -10;
    }

    // se for empate retorna 0
    return 0;
}

int AiBot::miniMax(char **boardCpy, int depth, bool isMax, char charOption)
{

    int score = evaluate(boardCpy, charOption);

    // se o maximizer ganhou
    if (score == 10)
        return score-depth;

    // se o minimizer ganhar
    if (score == -10)
        return score+depth;

    //em caso de empate
    if (movesLeft(boardCpy) == 0)
        return 0;

    // se for o turno do maximizer
    if (isMax)
    {
        int best = -1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (boardCpy[i][j] == '\0')
                {
                    // desenhar o movimento
                    boardCpy[i][j] = computerMove;

                    // chamar o minimax recursivamente e escolher o maior valor
                    // com a funçao max()
                    best = max(best,
                               miniMax(boardCpy, depth + 1, !isMax, charOption));

                    // desfazer
                    boardCpy[i][j] = '\0';
                }
            }
        }
        printf("%d\n", best);
        return best;
    }

    // se for o turno do minimizer
    else
    {
        int best = 1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (boardCpy[i][j] == '\0')
                {
                    // desenhar o movimento
                    boardCpy[i][j] = humanMove;

                    // chamar o minimax recursivamente e escolher o menor valor
                    // com a funçao min()
                    best = min(best,
                               miniMax(boardCpy, depth + 1, !isMax, charOption));

                    // desfazer
                    boardCpy[i][j] = '\0';
                }
            }
        }
        //retorna o valor do quadro
        printf("%d\n", best);
        return best;
    }
}
//findBestMove(char** a = new char*[3])

int AiBot::dificultyAdv(char charOption){
    /*board[0] = new char[3]
    board[0] = 'ab'
    int bestVal = -1000;
    int bestMove[2];
    bestMove.row = -1;
    bestMove.col = -1; */
    int bestVal = -1000;
    int bestMoveIndex = -1;
    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Check if cell is empty
            if (boardCpy[i][j] == '\0')
            {
                // Make the move
                boardCpy[i][j] = computerMove;

                // compute evaluation function for this
                // move.
                printf("%d_______________!_________%d\n", i, j);
                int moveVal = miniMax(boardCpy, 0, false, charOption);
                printf("_________________%d_____________________\n", moveVal);

                // Undo the move
                boardCpy[i][j] = '\0';

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestMoveIndex = move2dToIndex(i, j);
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMoveIndex;

}

int AiBot::dificultyBasic(char charOption){
    vector<int> emptyIndex; 
    int randIndex, bestMoveIndex;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (boardCpy[i][j] == '\0'){
                emptyIndex.push_back(move2dToIndex(i,j));
            }
        }
    }
    randIndex = rand() % emptyIndex.size();
    bestMoveIndex = emptyIndex[randIndex];
    printf("rand int %d\n", bestMoveIndex);


    return bestMoveIndex;
}

// Thois will return the best possible move for the player
int AiBot::findBestMove(char charOption, int dificulty)
{
    switch(dificulty){
        case 1:
            return dificultyBasic(charOption);

        case 4:
            return dificultyAdv(charOption);
    }
}


