//
// Created by duce on 05/11/2019.
//

#include "include/mochila.h"
#include "include/entrada.h"

void MenuTerminal(Item *itens)
{

    int opcao, n, flag;
    Mochila aux;
    Mochila mochilaFinal[40];

    double total;

    while(true)
    {
        printf("|-------------------------------------------|\n");
        printf("|O que deseja fazer?                        |\n");
        printf("|1 - Receber arquivo.txt                    |\n");
        printf("|2 - Resolver o problema da mochila         |\n");
        printf("|3 - Desalocar memória utilizada            |\n");
        printf("|0 - Encerrar                               |\n");
        printf("|-------------------------------------------|\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        printf("\n|-------------------------------------------|\n");

        switch(opcao)
        {
            case 1:

                n = LehArquivo(&(itens));
                flag = 1;
                break;

            case 2:

                total = 0.0;
                clock_t ini = clock();

                CriaMochila(&aux);

                printf("|----------------- LOADING -----------------|\n");

                for(int i = 1; i <= n ; ++i)
                {

                    printf("\nCaso %d de %d",i,n);
                    printf("\n");
                    PrintaItens(&aux,&mochilaFinal, itens, n, i);

                }

                for(int i = 0; i < 40; ++i) {


                    if (total >= aux.peso)
                    {

                        break;

                    }

                    printf("Item adicionado! - Peso: %d | Valor: %d\n", mochilaFinal[i].peso, mochilaFinal[i].valor);
                    total += mochilaFinal[i].peso;

                }

                printf("\n\nValor total obtido na melhor mochila: %d\nPeso total obtido na melhor mochila: %d\n\n", aux.valor, aux.peso);
                sleep(2);

                clock_t fim = clock();
                total += (double) (fim - ini)/ CLOCKS_PER_SEC;
                printf("Tempo de execução: %lf\n", total);
                printf("\n___$####-- Execução bem sucedida --####$___\n\n");

                break;

            case 3:

                printf("\n");
                printf("|-------------------------------------------|\n");

                if(flag)
                {

                    Libera(&itens);
                    printf("Memoria utilizada desalocada com sucesso.\n");

                }

                flag = 0;
                printf("|-------------------------------------------|\n");

                break;

            case 0:

                printf("\n\nPROGRAMA ENCERRADO\n");

                if(flag)
                {

                    Libera(&itens);

                }

                return;

            default:

                break;

        }

    }

}

int LehArquivo(Item **itens)
{

    FILE *arq;
    char arquivo[30];
    int cont; cont = 0;
    int n;

    printf("\nInsira o nome do arquivo seguido de \".txt\"\n");
    scanf("%s", arquivo);
    printf("\n");

    arq = fopen(arquivo, "r+");

    if(arq == NULL)
    {

        printf("## Arquivo não encontrado ou inexistente ##\n\n" );
    }

    else
    {

        while(!feof(arq)){

            if(cont==0)
            {

                fscanf(arq, "%d", &n);
                Armazena(n, &(*itens));

                ++cont;
            }

            else
            {

                fscanf(arq,"%d%d", &(*itens)[cont-1].peso, &(*itens)[cont-1].valor);
                ++cont;

            }

        }

    }

    fclose(arq);
    return n;

}