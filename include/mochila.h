//
// Created by duce on 05/11/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TP2_AEDS_MOCHILA_H
#define TP2_AEDS_MOCHILA_H

typedef struct item{
    int peso;
    int valor;
} Item;

typedef struct item Mochila;
void ResolveMochila(Mochila *aux,Mochila *mochilaFinal, Item *items , Mochila *mochila, int start, int end, int index, int size);
void PrintaItens(Mochila *aux,Mochila *mochilaFinal, Item *itens, int n, int size);
void CriaMochila(Mochila *mochila);
Mochila Atributos(Mochila mochila[], int size);
void Armazena(int n, Item **itens);


#endif //TP2_AEDS_MOCHILA_H
