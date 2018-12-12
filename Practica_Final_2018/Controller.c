#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reglasNegocio.h"
#include "utn.h"
#include "LinkedList.h"
#include "Parser.h"
#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2

///CARGAR EN MODO TEXTO
int controller_loadFromText(char* path, LinkedList* this) //Le pasamos el archivo a leer y la lista
{
    int retorno = 0;
    FILE* fp = fopen( path, "r");

    if( fp != NULL && this != NULL)
    {
        parser_clienteFromText( fp, this);
        retorno = 1;
    }
    else
    {
        printf("El archivo no se pudo cargar.\n");
        fclose(fp);
    }
    fclose(fp);
    return retorno;
}


///LISTAR los abonos de manera descendente por importe, mostrando tmb los datos del/os cliente/s (nombre, sexo, numero telefonico, importe)
int controller_List(LinkedList* this)
{
    eCliente* auxiliarCliente;
    /// eAbono* auxiliarAbonos;
    //eAbono* pAuxAbono;
    int retorno = 0;
    int largoLista = ll_len(this);
    int idAux;
    char nombreAux[50];
    char sexoAux[2];
    char numeroTelefonicoAux[21];
    int importeAux;
    // int idAuxAbono;
    // int tipoAux;
    // int idClienteAux;
    // int importeFinalAux;
    int i;

    if(this!=NULL)
    {
        if(largoLista>0)
        {
            ///tengo todos los empleados cargados ya en una lista
            ///desde 0 hasta el largo de la lista
            ///ir recorriendo la lista, obteniendo cada empleado y mostrarlo
            printf(" Id\t\tNombre\t\tSexo\tNumero telefonico   importe\n");
            for(i = 0; i < largoLista; i++)
            {
                auxiliarCliente = (eCliente*)ll_get(this, i);
                //  auxiliarAbonos = (eAbono*)ll_get(this, i);
                cliente_getId( auxiliarCliente, &idAux);
                cliente_getNombre( auxiliarCliente, nombreAux);
                cliente_getSexo( auxiliarCliente, sexoAux);
                cliente_getNumeroTelefonico( auxiliarCliente, numeroTelefonicoAux);
                cliente_getImporte( auxiliarCliente, &importeAux);
                ///abono_getId( auxiliarAbonos, &idAuxAbono);
                /// abono_getTipo( auxiliarAbonos, &tipoAux);
                /// abono_getIdCliente( auxiliarAbonos, &idClienteAux);
                /// abono_getImporteFinal( auxiliarAbonos, &importeFinalAux);
                //abono_getTipo( auxiliarAbonos, &tipoAux);
                //abono_getIdCliente( auxiliarAbonos, &idClienteAux);
                printf("%3d  %22s    %3s    %10s    %10d   \n", idAux, nombreAux, sexoAux, numeroTelefonicoAux, importeAux);
                /// algoritmo de guardado de pEmpleadoAux en archivo de texto
            }
            retorno = 1;
        }
        else
        {
            printf("No se cargaron los datos.\n");
        }

    }
    return retorno;
}


///PARA LISTAR LOS ABONOS Y CLIENTES
///Podria pedir el id del abono para que le muestre los clientes correspondientes
int controller_listAbonos(LinkedList* this, LinkedList* this2)
{
    eAbono* auxiliarAbono;
    eCliente* auxiliarCliente;
    /// eAbono* auxiliarAbonos;
    //eAbono* pAuxAbono;
    int retorno = 0;
    int largoLista = ll_len(this);
    int largoListaDos = ll_len(this2);
    int idAuxAbono;
    int tipoAuxAbono;
    int idClienteAuxAbono;
    float importeFinalAuxAbono;
    char nombreAuxCliente[50];
    char sexoAuxCliente[2];
    char numeroTelefonicoAuxCliente[21];
    int importeAuxCliente;
    int i;
    int j;

    if(this!=NULL)
    {
        if(largoLista>0)
        {
            ///tengo todos los empleados cargados ya en una lista
            ///desde 0 hasta el largo de la lista
            ///ir recorriendo la lista, obteniendo cada empleado y mostrarlo
            printf(" Id\t\tTipo\t\tId Cliente\t Importe Total   \n");
            for(i = 0; i < largoLista; i++)
            {
                auxiliarAbono = (eAbono*)ll_get(this, i);
                abono_getId( auxiliarAbono, &idAuxAbono);
                abono_getTipo( auxiliarAbono, &tipoAuxAbono);
                abono_getIdCliente( auxiliarAbono, &idClienteAuxAbono);
                abono_getImporteFinal( auxiliarAbono, &importeFinalAuxAbono);
                printf("%3d\t\t  %d\t\t    %d\t\t    %f\t\t  \n", idAuxAbono, tipoAuxAbono, idClienteAuxAbono, importeFinalAuxAbono );

                for( j = 0; j<largoListaDos ; j++)
                {
                    auxiliarCliente = (eCliente*)ll_get(this2, j);
                    if(auxiliarAbono->id == auxiliarCliente->id)
                    {
                        cliente_getNombre(auxiliarCliente, nombreAuxCliente);
                        cliente_getSexo(auxiliarCliente, sexoAuxCliente);
                        cliente_getNumeroTelefonico(auxiliarCliente,numeroTelefonicoAuxCliente);
                        cliente_getImporte(auxiliarCliente, &importeAuxCliente);
                        printf("Cliente --- %-3s\t    %s\t     %-s\t      %d\t \n", nombreAuxCliente, sexoAuxCliente, numeroTelefonicoAuxCliente, importeAuxCliente );
                    }
                }
                /// algoritmo de guardado de pEmpleadoAux en archivo de texto
            }

            retorno = 1;
        }
        else
        {
            printf("No se cargaron los datos.\n");
        }

    }
    return retorno;
}









int controller_saveAsText(char* path, LinkedList* pArrayAbono)
{
    int retorno = 0;
    int largoLista = ll_len(pArrayAbono);
    eAbono* pArrayAbonoAux;
    FILE* fp = fopen(path, "w");
    int i;
    if(fp==NULL)
    {
        printf("Error al abrir archivo para guardar\n");
        return retorno;
    }
    fprintf(fp, "Id,Tipo,Id Cliente,Importe final\n");
    if(pArrayAbono!=NULL)
    {
        for(i = 0; i < largoLista; i++)
        {
            pArrayAbonoAux = (eAbono*)ll_get(pArrayAbono, i);
            fprintf(fp, "%d,%d,%d,%f\n", pArrayAbonoAux->id, pArrayAbonoAux->tipo, pArrayAbonoAux->idCliente, pArrayAbonoAux->importeFinal);
        }
        printf("Se ha realizado el guardado del archivo con exito !\n");
        retorno = 1;
    }
    fclose(fp);
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayAbono)
{
    int retorno = 0;
    int largoLista = ll_len(pArrayAbono);
    eAbono* pAbonoAux;
    FILE* fp = fopen(path, "wb");
    int i;
    if(fp==NULL)
    {
        printf("Error al guardar\n");
        return retorno;
    }
    if(pArrayAbono!=NULL)
    {
        for(i = 0; i < largoLista; i++)
        {
            pAbonoAux = (eAbono*)ll_get(pArrayAbono, i);
            fwrite(pAbonoAux, sizeof(eAbono), 1, fp);
        }
        printf("Se ha realizado el guardado del archivo con exito !\n");
        retorno = 1;
    }
    fclose(fp);
    return retorno;
}




int menu()
{
    int eleccion;

    system("cls");
    printf(" - - - - - - - - - - -Menu- - - - - - - - - -\n\n");
    printf("1) Cargar los datos de los clientes desde el archivo clientes.csv (modo texto).\n");
    printf("2) Listar los clientes cargados.\n");
    printf("3) Crear nueva lista con abonos\n");
    printf("4) Listar abono y cliente ordenado por importe\n");
    printf("5) Guardar los datos de los abonos en el archivo abonos.csv (modo texto).\n");
    printf("6) Guardar los datos de los abonos en el archivo abonos.bin (modo binario).\n");
    printf("7) Salir del menu\n\n");
    printf("Elija una opcion: ");
    scanf("%d",&eleccion);

    return eleccion;

}

