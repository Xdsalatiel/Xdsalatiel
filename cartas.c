// cartas.c

#include <stdlib.h>
#include "declaracoes.h"

CARTA* Cria_Carta(NAIPE naipe, int valor) {
    CARTA *nova_carta = (CARTA *)malloc(sizeof(CARTA));
    if (nova_carta != NULL) {
        nova_carta->naipe = naipe;
        nova_carta->valor = valor;
    }
    return nova_carta;
}

void Consulta_carta(CARTA* carta, NAIPE* naipe, int* valor) {
    if (carta != NULL) {
        *naipe = carta->naipe;
        *valor = carta->valor;
    }
}

CARTA* Destroi_carta(CARTA* carta) {
    free(carta);
    return NULL;
}
```

### Funções para Baralho

No arquivo `baralho.c`, implementamos as funções para gerenciar o baralho.

```c
// baralho.c

#include <stdlib.h>
#include <time.h>
#include "declaracoes.h"

int Cria_Baralho(BARALHO **baralho) {
    *baralho = (BARALHO *)malloc(sizeof(BARALHO));
    if (*baralho == NULL) {
        return 0; // Fracasso na criação do baralho
    }

    int index = 0;
    for (NAIPE n = ouro; n <= paus; n++) {
        for (int v = 1; v <= 13; v++) {
            (*baralho)->cartas[index++] = Cria_Carta(n, v);
        }
    }
    (*baralho)->atual = 0;
    return 1; // Sucesso
}

void Destrói_Baralho(BARALHO **baralho) {
    if (*baralho) {
        for (int i = 0; i < 52; i++) {
            Destroi_carta((*baralho)->cartas[i]);
        }
        free(*baralho);
        *baralho = NULL;
    }
}

void Inicializa_Baralho(BARALHO *baralho) {
    baralho->atual = 0;
}

void Embaralha_Baralho(BARALHO *baralho) {
    srand(time(NULL));
    for (int i = 0; i < 50; i++) {
        int a = rand() % 52;
        int b = rand() % 52;
        CARTA *temp = baralho->cartas[a];
        baralho->cartas[a] = baralho->cartas[b];
        baralho->cartas[b] = temp;
    }
}

void Corta_Baralho(BARALHO *baralho) {
    // Implementa um corte simples no baralho
    int cut_point = rand() % 52;
    for (int i = 0; i < cut_point; i++) {
        CARTA *temp = baralho->cartas[i];
        baralho->cartas[i] = baralho->cartas[cut_point + i];
        baralho->cartas[cut_point + i] = temp;
    }
}

CARTA* Recupera_Carta(BARALHO *baralho) {
    if (baralho->atual < 52) {
        return baralho->cartas[baralho->atual++];
    }
    return NULL; // Baralho vazio
}
