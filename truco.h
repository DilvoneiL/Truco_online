#ifndef __TRUCO_H
#define __TRUCO_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define TAM 10
#define MAX 40
#define tamanho 6
#define N_MAO
#define NUM_JOGADORES 4
typedef struct CARTAS{
    char nome_nipe[TAM];
    int valor;
}CARTAS;

typedef struct jogador{
    int id_dupla;
    CARTAS carta[3];
}JOGADOR;

typedef struct baralho{
    CARTAS carta[MAX];
}BARALHO;

typedef struct mesa{
    CARTAS carta[4];
    int placar_dupla[2];
    int id_dupla[2];
    int num_rodadas;
}MESA;


void atribui_valor(BARALHO *baralho);
void atribui_nome(BARALHO *baralho);
void cria_baralho(BARALHO *baralho);
void imprimir_carta(CARTAS carta);
void imprimir_baralho(BARALHO baralho, int tam);
void embaralhar(BARALHO *baralho);
void distribuir_cartas(JOGADOR *jogador, BARALHO *baralho, int max_jogadores);
void cria_mesa(JOGADOR *jogador, MESA *mesa, int indice);
int maior_carta(MESA *mesa);
void placar(MESA *mesa,int *placar_dupla, int *id_dupla);
int buscar_valor(char *nome_nipe, BARALHO *baralho);
void menu();

#endif /* __TRUCO_H */