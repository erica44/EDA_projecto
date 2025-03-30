#include <stdio.h>
#include <stdlib.h>
#include "antenas.h"

int main(int argc, char *argv[]) {
    // Verifica se foi fornecido um arquivo como argumento
    if (argc < 2) {
        printf("Erro: O caminho do arquivo de entrada é necessário.\n");
        return 1;
    }

    // Carregar as antenas do arquivo
    Antena *listaAntenas = carregarAntenas(argv[1]);
    if (!listaAntenas) {
        printf("Erro ao carregar as antenas do arquivo.\n");
        return 1;
    }

    // Listar as antenas carregadas
    printf("Lista de antenas carregadas do arquivo:\n");
    Antena *temp = listaAntenas;
    while (temp) {
        printf("Antena - Frequência: %c, Coordenada: (%d, %d)\n", temp->frequencia, temp->x, temp->y);
        temp = temp->prox;
    }

    // Inserir uma nova antena
    printf("\nInserindo uma nova antena...\n");
    inserirAntena(&listaAntenas, 'A', 10, 10);

    // Listar as antenas após a inserção
    printf("\nLista de antenas após inserção:\n");
    temp = listaAntenas;
    while (temp) {
        printf("Antena - Frequência: %c, Coordenada: (%d, %d)\n", temp->frequencia, temp->x, temp->y);
        temp = temp->prox;
    }

    // Remover uma antena (exemplo: coordenada (10, 10))
    printf("\nRemovendo a antena na coordenada (10, 10)...\n");
    removerAntena(&listaAntenas, 10, 10);

    // Listar as antenas após remoção
    printf("\nLista de antenas após remoção:\n");
    temp = listaAntenas;
    while (temp) {
        printf("Antena - Frequência: %c, Coordenada: (%d, %d)\n", temp->frequencia, temp->x, temp->y);
        temp = temp->prox;
    }

    // Calcular pontos nefastos (exemplo entre duas antenas)
    printf("\nCalculando pontos nefastos entre antena (10, 10) e antena (5, 5)...\n");
    Antena *pontosNefastos = NULL;
    Antena *a1 = listaAntenas; // Primeiro exemplo de antena
    
