/**
 * @file antenas.h
 * @brief Cabeçalho para a implementação de uma lista ligada para representar antenas.
 *
 * @author Erica Mamade Segredo
 * @date 28-03-2025
 * Este arquivo contém a definição das funções e estruturas para trabalhar com antenas a usar listas ligadas.
 */

#ifndef ANTENAS_H
#define ANTENAS_H

/**
 * @struct Antena
 * @brief Representa uma antena com frequência e coordenadas.
 */
typedef struct Antena {
    char frequencia;     ///< Frequência da antena (ex: 'A', 'B')
    int x;                ///< Coordenada X na matriz
    int y;                ///< Coordenada Y na matriz
    struct Antena *prox; ///< Ponteiro para a próxima antena na lista
} Antena;

/**
 * @brief Carrega antenas de um arquivo para uma lista ligada.
 * @param filename Nome do arquivo.
 * @return Ponteiro para a primeira antena da lista.
 */
Antena* carregarAntenas(const char *filename);

/**
 * @brief Insere uma nova antena na lista.
 * @param cabeca Ponteiro para a cabeça da lista.
 * @param freq Frequência da antena.
 * @param x Coordenada X da antena.
 * @param y Coordenada Y da antena.
 */
void inserirAntena(Antena **cabeca, char freq, int x, int y);

/**
 * @brief Remove uma antena da lista.
 * @param cabeca Ponteiro para a cabeça da lista.
 * @param x Coordenada X da antena a remover.
 * @param y Coordenada Y da antena a remover.
 */
void removerAntena(Antena **cabeca, int x, int y);

/**
 * @brief Calcula pontos nefastos entre duas antenas.
 * @param a1 Primeira antena.
 * @param a2 Segunda antena.
 * @param pontos Lista para armazenar os pontos.
 */
void calcularPontosNefastos(Antena *a1, Antena *a2, Antena **pontos);

#endif // ANTENAS_H