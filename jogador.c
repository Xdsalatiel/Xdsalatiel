// jogadores.c

#include <stdlib.h>
#include <string.h>
#include "declaracoes.h"

JOGADOR *Cria_Jogadores(int n_jogadores) {
    return (JOGADOR *)malloc(n_jogadores * sizeof(JOGADOR));
}

void Destroi_Jogadores(JOGADOR **jogadores) {
    free(*jogadores);
    *jogadores = NULL;
}

void Inicializa_Jogador(JOGADOR *jogadores, int i_jogador, char *nome) {
    strncpy(jogadores[i_jogador].nome, nome, sizeof(jogadores[i_jogador].nome) - 1);
    jogadores[i_jogador].soma_cartas = 0;
    jogadores[i_jogador].nro_vitorias = 0;
    for (int i = 0; i < 3; i++) {
        jogadores[i_jogador].mao[i] = NULL;
    }
}

void Atualiza_Vitorias(JOGADOR *jogador, int i_jogador) {
    jogador[i_jogador].nro_vitorias++;
}

void Atualiza_Mao(JOGADOR *jogador, int i_jogador, CARTA *carta, int i_cartas) {
    jogador[i_jogador].mao[i_cartas] = carta;
}

void Soma_Mao(JOGADOR *jogador, int i_jogador) {
    jogador[i_jogador].soma_cartas = 0;
    for (int i = 0; i < 3; i++) {
        if (jogador[i_jogador].mao[i] != NULL) {
            jogador[i_jogador].soma_cartas += jogador[i_jogador].mao[i]->valor;
        }
    }
}

void Recupera_Dados_Jogador(JOGADOR *jogador, int i_jogador, char *nome, CARTA **carta, int *soma, int *vitorias) {
    strncpy(nome, jogador[i_jogador].nome, 30);
    *carta = jogador[i_jogador].mao[0]; // Pega a primeira carta (ou pode adaptar)
    *soma = jogador[i_jogador].soma_cartas;
    *vitorias = jogador[i_jogador].nro_vitorias;
}

void Ordena_Jogadores(JOGADOR *jogadores, int n_jogadores) {
    for (int i = 0; i < n_jogadores - 1; i++) {
        for (int j = i + 1; j < n_jogadores; j++) {
            if (jogadores[i].nro_vitorias < jogadores[j].nro_vitorias) {
                JOGADOR temp = jogadores[i];
                jogadores[i] = jogadores[j];
                jogadores[j] = temp;
            }
        }
    }
}
