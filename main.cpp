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
char promptChar(char charOption)
{
    char c;
    do {
        cout << "Escolha o caracter inserindo \'x\' ou \'o\'" << endl;
        cin >> c ;
        charOption = c;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (charOption != 'x' && charOption != 'o');
}

int promptDif(int dif)
{
    int d;
    do {
        cout << "Escolha a dificuldade do computador, entre 1 e 4" << endl;
        cin >> d;
        dif = d;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (dif >=5 && dif <= 0);
}
void promptStarter(char starter)
{
    char s;
    do {
        cout << "Escolha quem começa primeiro entre o Computador, \"Eu\" ou aleatorio[c/e/a]" << endl;
        cin >> s;
        starter = s;            
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (s != 'c' && s != 'e' && s != 'a');
}

void menu(int dif, char charOpt, char starter)
{   
    promptStarter(starter);
    promptDif(dif);
    promptChar(charOpt);
}

int main()
{   
    char charOption = '\0', starter = '\0'; int dificulty = -1;
    Game jogo1;
    jogo1.showInstructions();
    menu(dificulty, starter, charOption);
    //dar prompt do simbolo pretendido
    jogo1.playTicTacToe(_COMPUTER, charOption);
    return(0);
    
}