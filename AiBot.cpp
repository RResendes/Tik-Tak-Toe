#include <iostream>
#include <bits/stdc++.h>
#include "AiBot.h"

using namespace std;
int bestMoveid = 0;

char **boardCpy;
//funçao para incializar a visao da Ai criando o ponteiro 


//defenir o simbolo de cada jogador
AiBot::AiBot(char charOption, char **board)
{
    if (charOption == 'x')
    {
        this->humanMove = 'X';
        this->computerMove = 'O';
    }
    else if (charOption == 'o')
    {
        this->humanMove = 'O';
        this->computerMove = 'X';
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
int AiBot::movesLeft(char *board[3])
{
    int movesLeft;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                movesLeft++;
            }
        }
    }
    return movesLeft;
}

// funçao que retorna uma pontuaçao vencedora ou perdedora avaliando uma matriz
int AiBot::evaluate(char *b[3], char charOption)
{
    //defenir os movimentos atravez da funçao
    // avaliar as linhas para ver se ha jogada vencedora
    for (int row = 0; row < 3; row++)
    {
        if (b[row][0] == b[row][1] &&
            b[row][1] == b[row][2])
        {
            if (b[row][0] == computerMove)
                return +10;
            else if (b[row][0] == humanMove)
                return -10;
        }
    }

    // avaliar as colunas para ver se ha jogada vencedora
    for (int col = 0; col < 3; col++)
    {
        if (b[0][col] == b[1][col] &&
            b[1][col] == b[2][col])
        {
            if (b[0][col] == computerMove)
                return +10;

            else if (b[0][col] == humanMove)
                return -10;
        }
    }

    // avaliar as diagonais para ver se ha jogada vencedora
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        if (b[0][0] == computerMove)
            return +10;
        else if (b[0][0] == humanMove)
            return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
    {
        if (b[0][2] == computerMove)
            return +10;
        else if (b[0][2] == humanMove)
            return -10;
    }

    // se for empate retorna 0
    return 0;
}

int AiBot::miniMax(char *board[3], int depth, bool isMax, char charOption)
{

    int score = evaluate(board, charOption);

    // se o maximizer ganhou
    if (score == 10)
        return score;

    // se o minimizer ganhar
    if (score == -10)
        return score;

    //em caso de empate
    if (movesLeft(board) == 0)
        return 0;

    // se for o turno do maximizer
    if (isMax)
    {
        int best = -1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '_')
                {
                    // desenhar o movimento
                    board[i][j] = computerMove;

                    // chamar o minimax recursivamente e escolher o maior valor
                    // com a funçao max()
                    best = max(best,
                               miniMax(board, depth + 1, !isMax, charOption));

                    // desfazer
                    board[i][j] = '_';
                }
            }
        }
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
                if (board[i][j] == '_')
                {
                    // desenhar o movimento
                    board[i][j] = humanMove;

                    // chamar o minimax recursivamente e escolher o menor valor
                    // com a funçao min()
                    best = min(best,
                               miniMax(board, depth + 1, !isMax, charOption));

                    // desfazer
                    board[i][j] = '_';
                }
            }
        }
        //retorna o valor do quadro
        return best;
    }
}
//findBestMove(char** a = new char*[3])



// Thois will return the best possible move for the player
int AiBot::findBestMove(char charOption)
{
    /*board[0] = new char[3]
    board[0] = 'ab'
    int bestVal = -1000;
    int bestMove[2];
    bestMove.row = -1;
    bestMove.col = -1; */
    
    int bestVal = -1000;
    int bestMoveIndex = 0;
    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Check if cell is empty
            if (boardCpy[i][j] == '_')
            {
                // Make the move
                boardCpy[i][j] = computerMove;

                // compute evaluation function for this
                // move.
                int moveVal = miniMax(boardCpy, 0, false, charOption);

                // Undo the move
                boardCpy[i][j] = '_';

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
    
    printf("The value of the best Move is : %d\n\n",
           bestVal);

    return bestMoveIndex;
}


