//
// Created by duce on 05/11/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "mochila.h"

#ifndef TP2_AEDS_ENTRADA_H
#define TP2_AEDS_ENTRADA_H

#define true 1

void MenuTerminal(Item *itens);
int LehArquivo(Item **itens);
void Libera(Item **itens);

#endif //TP2_AEDS_ENTRADA_H
