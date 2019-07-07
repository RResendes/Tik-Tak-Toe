#include "Game.h"

#define _COMPUTER 1
#define _HUMAN 2
#define _LADO 3


void Game::drawBoard(char **board)
{
    system("clear");
    printf( "\n");
    printf("\t\t  %c | | %c | | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t --------------- \n");
    printf("\t\t --------------- \n");
    printf("\t\t  %c | | %c | | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t --------------- \n");
    printf("\t\t --------------- \n");
    printf("\t\t  %c | | %c | | %c \n", board[2][0], board[2][1], board[2][2]);
    cout << endl;
    return;
}

//Função para mostrar instruçoes copy paste da source GFG

void Game::showInstructions() 
{ 
    printf("\t\t\t  Tic-Tac-Toe\n\n"); 
    printf("Escolha uma das celulas numeradas de 1 a 9 para introduzir a jogada"
            " and play \" jogo da belha \" \n\n"); 
      
    printf("\t\t\t  1 ||  2  || 3\n"); 
    printf("\t\t\t-----------------\n");
    printf("\t\t\t-----------------\n");  
    printf("\t\t\t  4 ||  5  || 6  \n"); 
    printf("\t\t\t-----------------\n"); 
    printf("\t\t\t-----------------\n"); 
    printf("\t\t\t  7 ||  8  || 9  \n\n"); 
      
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n"); 
  
    return; 
} 
// funçao para dar prompt da jogada do humano
int Game::promptMove(){
    int a;
    do {
        cout << "Introduza o nr da casa que pretende jogar" << endl;
        cin >> a;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (a < 1 || a > 9);
    a --;
    return a;
}
// Uma função para declarar o vencedor tambem sugerido no source GFG

void Game::declareWinner (int whoseTurn)
{
    if (whoseTurn == _COMPUTER ){
        printf("Ganhaste a partida! Parabéns");
        cout << endl;
    }  else {
        printf("O computador ganhou, tenta outra vez");
        cout << endl;
    }
    return;
}

// Uma função para dar toggle da variavel whoseTurn entre o jogador e computador

void Game::toggleWhoseTurn (int whoseTurn )
{
    if (whoseTurn == _COMPUTER ) { whoseTurn = _HUMAN; }
     else {whoseTurn = _COMPUTER ;}
    return;
}

//Funçoes genericas que retornam verdadeiro se um certo determinado quadro esta em posiçao vitoriosa para algum dos jogadores 
//linha igual
bool Game::rowCrossed (char **board){
    for (int i=0; i<_LADO; i++) 
    { 
        if (board[i][0] == board[i][1] && 
            board[i][1] == board[i][2] &&  
            board[i][0] != '\0') 
            return (true); 
    } 
    return(false); 
}
//coluna igual
bool Game::columnCrossed(char **board) 
{ 
    for (int i=0; i<_LADO; i++) 
    { 
        if (board[0][i] == board[1][i] && 
            board[1][i] == board[2][i] &&  
            board[0][i] != '\0') 
            return (true); 
    }  
    return(false); 
} 
//diagonal igual
bool Game::diagonalCrossed(char **board) 
{ 
    if (board[0][0] == board[1][1] && 
        board[1][1] == board[2][2] &&  
        board[0][0] != '\0') 
        return(true); 
          
    if (board[0][2] == board[1][1] && 
        board[1][1] == board[2][0] && 
         board[0][2] != '\0') 
        return(true); 
  
    return(false); 
} 

// funçao que retorna true quando o jogo acaba e false quando nao esta numa posição vitoriosa
bool Game::gameOver(char **board)
{
    if (columnCrossed(board) || rowCrossed(board) || diagonalCrossed(board))
    {
        return true;
    }
    else {
        return false;
    }
}
//funçao para inicializar o campo de jogo
void Game::initialise (char **board, int moves[])
{
    //recomendado pela source:ainda por determinar funcionalidade
    srand(time(NULL));

    //Limpar o quadro
    for (int i=0; i<_LADO; i++) 
    { 
        for (int j=0; j<_LADO; j++) 
            {
                board[i][j] = '\0';};
    }
    //encher uma variavel array com a ordem dos movimentos
    for (int h=0; h<(_LADO*_LADO); h++)
    {
        moves[h]=h;
    }
    // sugerido pela source mas nao implementado
    // randomise the moves 
    //random_shuffle(moves, moves + _LADO*_LADO); 
    return;
}
//funçao de jogo
void Game::playTicTacToe(int whoseTurn, char charOption)
{
    //inicializar as variaveis
    char **board = new char*[_LADO];    
    for (int i = 0; i < _LADO; i++)
    {
        board[i] = new char[_LADO];
    }
    int chosenMoveIndex = -1 ;
       
    int moves[_LADO*_LADO];
    //inicializar as coordenadas da jogada e o nr da jogada
    int x,y, moveIndex = 0;
    // simbolo da entidade
    char humanMove , computerMove;

    initialise(board, moves); 
    drawBoard(board);

    // estabelecer o simbolo de cada jogador dos movimentos
    if (charOption == 'x'){
        humanMove = 'X';
        computerMove = 'O';
    }   else if (charOption == 'o') {
        humanMove = 'O';
        computerMove = 'X';
    }
    //loop para continuar o jogo ate uma das condiçoes se verificar
    while (gameOver(board) == false && moveIndex < _LADO*_LADO)
    {   
        if (whoseTurn == _COMPUTER){
            //estabelecer as coordenadas da jogada atravez da projeçao 2d duma matriz
            AiBot Bot1(charOption , board); 
            if (moveIndex==0) {chosenMoveIndex = 4;}
            else {
                // difficulty adv = 4
                chosenMoveIndex = Bot1.findBestMove(charOption, 1);
            }
            x = chosenMoveIndex / _LADO;
            y = chosenMoveIndex % _LADO;
             board[x][y] = computerMove;
            drawBoard(board);
            printf("O Computador pos o %c na casa nr %d \n",
                     computerMove , chosenMoveIndex+1 );
            moveIndex ++;
            whoseTurn = _HUMAN;
        } else if (whoseTurn == _HUMAN) { 
            //escolher a jogada
            chosenMoveIndex = promptMove();
            //estabelecer as coordenadas da jogada atravez da projeçao 2d duma matriz
            x = chosenMoveIndex / _LADO; 
            y = chosenMoveIndex % _LADO; 
            board[x][y] = humanMove; 
            drawBoard(board); 
            printf ("O jogador pos o %c na casa nr %d \n", 
                    humanMove, chosenMoveIndex-1); 
            moveIndex ++; 
            whoseTurn = _COMPUTER;
        } 
    }
    if (gameOver(board) == false && moveIndex == _LADO*_LADO){
        printf("Jogo resultou num empate");
    } else {
        // dar toggle do turno para declar o vencedor
        declareWinner(whoseTurn);
    }
    // Caso de empate

    
    return;
}
