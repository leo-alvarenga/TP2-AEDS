//
// Created by duce on 05/11/2019.
//

#include "include/mochila.h"


Mochila Atributos(Mochila mochila[], int size)
{

    Mochila aux;

    CriaMochila(&aux);

    for(int i = 0; i < size; ++i)
    {
        aux.valor += mochila[i].valor;
        aux.peso += mochila[i].peso;

    }

    return aux;

}

void ResolveMochila(Mochila *aux,Mochila *mochilaFinal, Item *itens , Mochila mochila[], int start, int end, int index, int size)
{

    Mochila compare;

    if(index == size)
    {

        CriaMochila(&compare);
        compare = Atributos(mochila, size);
        if(compare.valor >= aux->valor && compare.peso <=40)
        {
            *aux = compare;
            for (int i = 0;i<40;++i) {

                mochilaFinal[i] = mochila[i];
            }
        }
        return;
    }

    for(int i = start; i <= end && end - i + 1 >= size-index; ++i)
    {

        mochila[index].valor = itens[i].valor;
        mochila[index].peso = itens[i].peso;
        ResolveMochila(aux,mochilaFinal, itens, mochila, i+1, end, index+1, size);

    }

}

void Libera(Item **itens)
{

    free(*itens);

}

void PrintaItens(Mochila *aux,Mochila *mochilaFinal, Item *items, int n, int size)
{
    //int total; total = 0;

    Mochila mochila[size];
    ResolveMochila(aux,mochilaFinal, items, mochila, 0, n-1, 0, size);

/*
    *mochilaPrint = temp;
    for (int i=0;i<size;++i) {
        if (total >= 40) break;
        printf("Item adicionado! - Peso: %d | Valor: %d",mochilaPrint[i].peso,mochilaPrint[i].valor);
        total+=mochilaPrint[i].peso;
    }*/
}

void CriaMochila(Mochila *mochila)
{

    mochila -> valor = 0;
    mochila -> peso = 0;

}

void Armazena(int n, Item **items)
{

    (*items) = (Item*) malloc(n * sizeof(Item));

}