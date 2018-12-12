#ifndef reglasNegocio_H_INCLUDED
#define reglasNegocio_H_INCLUDED
#include "LinkedList.h"

//Creamos las estructuras para los abonos y los clientes

typedef struct
{
    //Validar todos los campos
    int id; //id>0
    char nombre[51];
    char sexo[2]; ///Fijarse si se puede usar char y no un string, y validar F/M
    char numeroTelefonico[21];
    int importe;


}eCliente;

typedef struct
{
    int id; //Autonumerico
    int tipo;
    int idCliente;
    float importeFinal;

}eAbono;

eCliente* new_cliente();
eAbono* new_abono();

eCliente* cliente_newParametros(char* idStr, char* nombreStr, char* sexoStr, char* numeroTelefonicoStr, char* importeStr);

int cliente_setId(eCliente* this,int id);
int cliente_getId(eCliente* this,int* id);

int cliente_setNombre(eCliente* this,char* nombre);
int cliente_getNombre(eCliente* this,char* nombre);

int cliente_setSexo(eCliente* this,char* sexo);
int cliente_getSexo(eCliente* this,char* sexo);

int cliente_setNumeroTelefonico(eCliente* this,char* numeroTelefonico);
int cliente_getNumeroTelefonico(eCliente* this,char* numeroTelefonico);

int cliente_setImporte(eCliente* this,int importe);
int cliente_getImporte(eCliente* this,int* importe);

int abono_setId(eAbono* this,int id);
int abono_getId(eAbono* this,int* id);

int abono_setTipo(eAbono* this,int tipo);
int abono_getTipo(eAbono* this,int* tipo);

int abono_setIdCliente(eAbono* this,int idCliente);
int abono_getIdCliente(eAbono* this,int* idCliente);

int abono_setImporteFinal(eAbono* this,float importeFinal);
int abono_getImporteFinal(eAbono* this,float* importeFinal);

int employeeSortById(void* empleadoA, void* empleadoB);

int lista_abonos(void* pElement);

int abonoSortByImporte(void* empleadoA, void* empleadoB);

LinkedList* crearListaAbono(LinkedList* this);


//Sort


#endif
