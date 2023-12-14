#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{

    char nome[50];
    int pontuacao;
    int rodadas;

    }jogadores;

void menu();
void menuJogo(jogadores jogador, int dificuldade);
int jog1 (int *ptr1, int *ptrPara, jogadores jogador);
int jog2(int *ptr2, int *ptrPara, jogadores jogador);
int cadastroJogador();
int jog1Dificil(int *ptr1,int *ptrPara, jogadores jogador);
int jog2Dificil(int *ptr2, int *ptrPara, jogadores jogador);
void mostraJogadores();


