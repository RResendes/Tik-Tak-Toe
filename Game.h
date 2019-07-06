#include <iostream>
#include <bits/stdc++.h>
#include "AiBot.h"
 
using namespace std;

class Game 
{
public:
    int moves[9];    
    void drawBoard(char **board);
    void showInstructions();
    int promptMove();
    void declareWinner (int whoseTurn);
    void toggleWhoseTurn (int whoseTurn );
    bool rowCrossed (char **board);
    bool columnCrossed(char **board);
    bool diagonalCrossed(char **board);
    bool gameOver(char **board);
    void initialise (char **board, int moves[3]);
    void playTicTacToe(int whoseTurn, char charOption); 

    friend class AiBot;
};