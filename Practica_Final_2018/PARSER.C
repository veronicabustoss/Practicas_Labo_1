#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reglasNegocio.h"
#include "utn.h"
#include "LinkedList.h"
#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2

//Cargamos los clientes en forma de texto
int parser_clienteFromText(FILE* pFile , LinkedList* cliente)
{
    eCliente* auxCliente = new_cliente();
    int r;
    int i = 0;
    char idAux[50],nombreAux[50],sexoAux[50],numeroTelefonicoAux[50],importeAux[50];

    if( pFile != NULL )
    {
        r = fscanf( pFile ,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, sexoAux, numeroTelefonicoAux, importeAux); //El titulo

        while(!feof(pFile)) //Si llego al final del archivo sale
        {
            r = fscanf( pFile ,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, sexoAux, numeroTelefonicoAux, importeAux);

            if( r == 5 )
            {
                auxCliente = cliente_newParametros(idAux, nombreAux, sexoAux, numeroTelefonicoAux, importeAux);
                ll_add( cliente , auxCliente);
                i++; //Me va contando todos los archivos que se cargaron
            }
            else
                break;
        }
        printf("Se cargaron %d clientes a la lista!\n", i);
    }



    return i;
}
