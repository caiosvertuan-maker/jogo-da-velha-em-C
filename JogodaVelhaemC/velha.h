#ifndef VELHA_H
#define VELHA_H

#define TAM 9
void gerar_tab(char tabuleiro[TAM]);
void mostrar_tab(char tabuleiro[9], int num_jogadas);
void jogada(int *num_jogadas, char tabuleiro[9]);
int ver_jogada(char tabuleiro[9], int num_jogadas);

#endif