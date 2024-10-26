// declaracoes.h

#ifndef DECLARACOES_H
#define DECLARACOES_H

typedef struct {
    int valor;  // O valor da carta (2 a 14, onde 11-14 são J, Q, K, A)
    char naipe; // O naipe da carta (C, E, O, P)
} Carta;

typedef struct {
    Carta cartas[3]; // Três cartas por jogador
    int vitorias;     // Número de vitórias do jogador
    char nome[20];    // Nome do jogador
} Jogador;

typedef struct {
    Carta baralho[52]; // 52 cartas no baralho
    int topo;          // Indica o topo do baralho
} Baralho;

#endif // DECLARACOES_H
