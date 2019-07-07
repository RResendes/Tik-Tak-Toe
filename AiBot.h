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
    int movesLeft (char **boardCpy);
    int evaluate (char **boardCpy, char charOption);
    int miniMax (char **boardCpy, int depth, bool isMax, char charOption);
    int findBestMove(char charOption, int dificulty);
    int randomIndex(int size);
    int dificultyAdv(char charOption);
    int dificultyElementary(char charOption);
    int dificultyBasic(char charOption);
    int dificultyMedium(char charOption);
};