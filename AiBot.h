#include <iostream>
#include <bits/stdc++.h>
//Criaçao duma struct para facilitar visualiçao da jogada

using namespace std;

class AiBot 
{
public:
    AiBot(char charOption, char **board);
    char humanMove = 'X', computerMove = 'O';
    int moveIndex;
    struct Move;
    void charChoosing (char charOption);
    int move2dToIndex (int x, int y);
    int movesLeft (char *b[3]);
    int evaluate (char *b[3], char charOption);
    int miniMax (char *board[3], int depth, bool isMax, char charOption);
    int findBestMove(char charOption);
};