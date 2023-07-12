#include <iostream>
#define TAM_TABULEIRO 9
#define INFINITO 999999999

using namespace std;

typedef struct{
    int origem;
    int destino;
    int peso;
} Aresta;

Aresta arestas[350];

int BellmanFord(int num_arestas, int num_nodos, int origem, int destino) {
    int i, j, trocou = 1;
    int distancia[65];

    for (i = 0; i <= num_nodos; i++) {
        distancia[i] = INFINITO;
    }

    distancia[origem] = 0;

    for (i = 0; i <= num_nodos && trocou; i++) {
        trocou = 0;
        for (j = 0; j < num_arestas; j++) {
            if (distancia[arestas[j].destino] > distancia[arestas[j].origem] + arestas[j].peso) {
                distancia[arestas[j].destino] = distancia[arestas[j].origem] + arestas[j].peso;
                trocou = 1;
            }
        }
    }

    return distancia[destino];
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    int cont = 1, i, j;
    for (i = 1; i < TAM_TABULEIRO; i++) {
        for (j = 1; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = cont++;
        }
    }

    int num_arestas = 0;
    for (i = 1; i < TAM_TABULEIRO; i++) {
        for (j = 1; j < TAM_TABULEIRO; j++) {
            if ((i + 1) < TAM_TABULEIRO && (j + 2) < TAM_TABULEIRO) {
                arestas[num_arestas].origem = tabuleiro[i][j];
                arestas[num_arestas].destino = tabuleiro[i + 1][j + 2];
                arestas[num_arestas].peso = 1;
                num_arestas++;
            }
            if( (i + 1) < TAM_TABULEIRO && (j - 2) >= 1 ) {
                arestas[num_arestas].origem = tabuleiro[i][j];
                arestas[num_arestas].destino = tabuleiro[i + 1][j - 2];
                arestas[num_arestas].peso = 1;
                num_arestas++;
            }
            if( (i + 2) < TAM_TABULEIRO && (j + 1) < TAM_TABULEIRO ) {
                arestas[num_arestas].origem = tabuleiro[i][j];
                arestas[num_arestas].destino = tabuleiro[i + 2][j + 1];
                arestas[num_arestas].peso = 1;
                num_arestas++;
            }
            if( (i + 2) < TAM_TABULEIRO && (j - 1) >= 1 ) {
                arestas[num_arestas].origem = tabuleiro[i][j];
                arestas[num_arestas].destino = tabuleiro[i + 2][j - 1];
                arestas[num_arestas].peso = 1;
                num_arestas++;
            }
            if( (i - 1) > 0 && (j + 2) < TAM_TABULEIRO ) {
                arestas[num_arestas].origem = tabuleiro[i][j];
                arestas[num_arestas].destino = tabuleiro[i - 1][j + 2];
                arestas[num_arestas].peso = 1;
                num_arestas++;
            }
            if( (i - 1) > 0 && (j - 2) >= 1 ) {
                arestas[num_arestas].origem = tabuleiro[i][j];
                arestas[num_arestas].destino = tabuleiro[i - 1][j - 2];
                arestas[num_arestas].peso = 1;
                num_arestas++;
            }
            if( (i - 2) > 0 && (j + 1) <TAM_TABULEIRO  ) {
                arestas[num_arestas].origem = tabuleiro[i][j];
                arestas[num_arestas].destino = tabuleiro[i - 2][j + 1];
                arestas[num_arestas].peso = 1;
                num_arestas++;
            }
            if( (i - 2) > 0 && (j - 1) >= 1 ) {
                arestas[num_arestas].origem = tabuleiro[i][j];
                arestas[num_arestas].destino = tabuleiro[i - 2][j - 1];
                arestas[num_arestas].peso = 1;
                num_arestas++;
            }
        }
    }

    int origem, destino;
    string inicio, fim;

    while (cin >> inicio >> fim) {
        origem = (inicio[0] - 'a') * 8 + inicio[1] - '0';
        destino = (fim[0] - 'a') * 8 + fim[1] - '0';

        cout << "To get from " << inicio << " to " << fim << " takes " << BellmanFord(num_arestas, 64, origem, destino) << " knight moves." << endl;

        if (inicio == fim) {
            break;
        }
    }
    return 0;
}