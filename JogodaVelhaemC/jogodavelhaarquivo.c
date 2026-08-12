#include <stdio.h>
#include <stdlib.h>

#include "velha.h"

int main() {
    int num_jogadas = 0;
    char tabuleiro[TAM];
    gerar_tab(tabuleiro);

    while(num_jogadas < 9) {

        jogada(&num_jogadas, tabuleiro);
        mostrar_tab(tabuleiro, num_jogadas);

        int resultado = ver_jogada(tabuleiro, num_jogadas);
        
    }
    return 0;
}


void gerar_tab(char tabuleiro[TAM]) {
    for(int i = 0; i < TAM; i++) {
        tabuleiro[i] = ' '; 
    }
}

void mostrar_tab(char tabuleiro[9], int num_jogadas) {
    FILE *fs = fopen("jogo.txt", "w");
    if(fs == NULL) {
            perror("Erro ao abrir o arquivo");
            return;
    }
    for(int i = 0; i < 9; i += 3) {
        fprintf(fs, "%c | %c | %c", tabuleiro[i], tabuleiro[i + 1], tabuleiro[i + 2]);
        fprintf(fs, "\n");
    }
    int resultado = ver_jogada(tabuleiro, num_jogadas);
    if(resultado == 1) {
            fprintf(fs, "Vitoria do jogador");
            if((num_jogadas - 1) % 2 == 0) {
                fprintf(fs, " 0\n");
            }
            else {
                fprintf(fs, " X\n");
            }
            fprintf(fs, "Total de jogadas foi %d\n", num_jogadas);
            fclose(fs);
        }
        fflush(fs);

}

void jogada(int *num_jogadas, char tabuleiro[9]) {
    int jogada, ver = 0;
    printf("Fale o indice em que deseja jogar (comecando do 1)\n");
    do{
        scanf("%d", &jogada);
        jogada--;
        if((jogada < 9 || jogada > 0) && tabuleiro[jogada] == ' ') {
            ver = 1;
            if(*num_jogadas % 2 == 0) {
                tabuleiro[jogada] = 'O';
            }
            else {
                tabuleiro[jogada] = 'X';
            }
            (*num_jogadas)++;
        }
        else {
            printf("Jogada invalida\n");
        }
    }while(ver == 0);
}

int ver_jogada(char tabuleiro[9], int num_jogadas) {
    int teste[3];
    int combinacoes[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for(int x = 0; x < 8; x++) {
        for(int y = 0; y < 3; y++) {
            teste[y] = tabuleiro[combinacoes[x][y]];
        }
        if(teste[0] != ' ' && teste[1] != ' ' && teste[2] != ' ') {
            if(teste[0] == teste[1] && teste[1] == teste[2]) {
                return 1;
            }
        }
    }
    return 0;
}