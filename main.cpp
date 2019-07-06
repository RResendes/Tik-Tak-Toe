//Aplicação tik tak toe a proposito do projeto da Disciplina Estrutura de Dados e Algoritmos
//Muito deste codigo tem por base logica de implementação do tic tak toe do site futuramente referenciada como GFG:
//https://www.geeksforgeeks.org/implementation-of-tic-tac-toe-game/

#include <iostream>

// lib que a source usa:
#include <bits/stdc++.h>
#include "Game.h"


using namespace std;
//Defenir o humano, o computador e o lado da matriz de jogo segundo a sugestao do source usando uma variavel global
#define _COMPUTER 1
#define _HUMAN 2
#define _LADO 3

//Defenir o character default para caracterizar cada jogada     NAO IMPLEMENTADO
//#define _COMPUTERMOVE "O"
//#define _HUMANMOVE "X"

//Defenir uma função para desenhar o quadro


int main()
{   
    char charOption = ' ', a;
    Game jogo1;
    jogo1.showInstructions();
    //dar prompt do simbolo pretendido
    do {
        cout << "Escolha o caracter inserindo \'x\' ou \'o\'" << endl;
        cin >> a ;
        charOption = a;
    } while (charOption == ' ' );
    jogo1.playTicTacToe(_COMPUTER, charOption);
    return(0);
    
}