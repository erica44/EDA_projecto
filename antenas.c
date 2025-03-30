/**
 * @file antenas.c
 * @brief Implementação de uma lista ligada para representar antenas.
 * @author Erica Mamade Segredo
 * @date 29-03-2025
 *
 * Este código foi desenvolvido como parte do projeto de EDA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "antenas.h"

/**
 * @brief Carrega antenas de um arquivo para uma lista ligada.
 * @param filename Nome do arquivo.
 * @return Ponteiro para a primeira antena da lista.
 */

//Funcao de carregamento

Antena* carregarAntenas(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL; // Verifica se o arquivo foi aberto corretamente

    int linhas;
    fscanf(file, "%d", &linhas);
    fgetc(file); // Pular '\n' para evitar erros ao ler as linhas seguintes

    Antena *cabeca = NULL, *atual = NULL;

    for (int y = 0; y < linhas; y++) {
        char linha[100];
        fgets(linha, sizeof(linha), file);
        for (int x = 0; x < strlen(linha); x++) {
            if (linha[x] != '.' && linha[x] != '\n') { // Identifica uma antena na matriz
                Antena *nova = malloc(sizeof(Antena)); // Aloca memória para nova antena
                nova->frequencia = linha[x];
                nova->x = x;
                nova->y = y;
                nova->prox = NULL;

                if (!cabeca) cabeca = atual = nova; // Primeira antena da lista
                else {
                    atual->prox = nova;
                    atual = nova;
                }
            }
        }
    }
    fclose(file);
    return cabeca;
}

/**
 * @brief Insere uma nova antena na lista.
 * @param cabeca Ponteiro para a cabeça da lista.
 * @param freq Frequência da antena.
 * @param x Coordenada X da antena.
 * @param y Coordenada Y da antena.
 */

 //Insercao de Antena

void inserirAntena(Antena **cabeca, char freq, int x, int y) {
    Antena *nova = malloc(sizeof(Antena)); // Primeira antena da lista
    nova->frequencia = freq;
    nova->x = x;
    nova->y = y;
    nova->prox = *cabeca; // Adiciona no início da lista
    *cabeca = nova;
}

/**
 * @brief Remove uma antena da lista.
 * @param cabeca Ponteiro para a cabeça da lista.
 * @param x Coordenada X da antena a remover.
 * @param y Coordenada Y da antena a remover.
 */

 //Remocao de antena 

void removerAntena(Antena **cabeca, int x, int y) {
    Antena *temp = *cabeca, *anterior = NULL;
    while (temp) {
        if (temp->x == x && temp->y == y) { // Encontra a antena a ser removida
            if (anterior) anterior->prox = temp->prox; // Remove a antena do meio/fim
            else *cabeca = temp->prox; // Remove a antena do início
            free(temp); // Libera a memória alocada
            return;
        }
        anterior = temp;
        temp = temp->prox;
    }
}

/**
 * @brief Calcula pontos nefastos entre duas antenas.
 * @param a1 Primeira antena.
 * @param a2 Segunda antena.
 * @param pontos Lista para armazenar os pontos.
 */

 // Calculo de Localizacoes Nefastas

void calcularPontosNefastos(Antena *a1, Antena *a2, Antena **pontos) {
    if (a1->frequencia != a2->frequencia) return; // Apenas calcula se as frequências forem iguais

    // Calcula um ponto nefasto: L1 está a duas vezes a distância de a1 em relação a a2
    int l1x = a2->x + (a2->x - a1->x);
    int l1y = a2->y + (a2->y - a1->y);

    inserirAntena(pontos, a1->frequencia, l1x, l1y); // Adiciona o ponto nefasto à lista
}