#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reglasNegocio.h"
#include "utn.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"


int main()
{
    int opcion;
    LinkedList* listaCliente = ll_newLinkedList();
    LinkedList* listaAbono;
    do
    {

        ///Faltaria poner banderas para validar
        opcion = menu();
        switch(opcion)
        {
        case 1:
            controller_loadFromText("clientes.csv",listaCliente);
            ll_sort(listaCliente, employeeSortById,0);
            break;
        case 2:
            controller_List( listaCliente);
            break;
        case 3:

            listaAbono = crearListaAbono(listaCliente);
            printf("\nLista creada con exito!!  \n\n");
            ///MODO DE PRUEBA PARA COMPROBAR SI FUNCIONA
           /* eAbono* abono;
            for(int i =0; i<ll_len(listaAbono); i++)
            {
                abono = ll_get(listaAbono, i);
                printf("ID de abono: %d\nTipo: %d\nId Cliente: %d\nImporte final: %f\n\n\n",abono->id, abono->tipo, abono->idCliente, abono->importeFinal);
            }*/
            break;
        case 4:
            ll_sort(listaAbono,abonoSortByImporte,0);
            controller_listAbonos(listaAbono, listaCliente);
            break;
        case 5:
            controller_saveAsText("abono.txt", listaAbono);
            break;
        case 6:
            controller_saveAsBinary("abono.bin", listaAbono);
            break;
        case 7:
            printf("Usted esta saliendo del menu.\n");
            break;
        default:
            printf("No se ingreso bien el dato.\n\n");
        }
        system("pause");
    }
    while(opcion != 7);
    ll_deleteLinkedList(listaCliente);
    return 0;
}
