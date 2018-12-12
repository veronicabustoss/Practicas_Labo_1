#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reglasNegocio.h"
#include "utn.h"
#include "LinkedList.h"
#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2

static int generarNextId() //Genero un unico id por cada empleado que se ingresa
{
    static int id = 0;

    id ++;

    return id;
}

eCliente* new_cliente()
{
    return (eCliente*) calloc(1, sizeof(eCliente)); //Me inicializa todo en cero
}

eAbono* new_abono()
{
    return (eAbono*) calloc(1, sizeof(eAbono));
}


eCliente* cliente_newParametros(char* idStr, char* nombreStr, char* sexoStr, char* numeroTelefonicoStr, char* importeStr)
{
    eCliente* auxCliente = new_cliente();

    if( auxCliente != NULL )
    {
        int id = atoi(idStr);
        cliente_setId(auxCliente, id);

        cliente_setNombre(auxCliente, nombreStr);

        cliente_setSexo(auxCliente, sexoStr);

        cliente_setNumeroTelefonico(auxCliente, numeroTelefonicoStr);

        int importe = atoi(importeStr);
        cliente_setImporte(auxCliente, importe);
    }

    return auxCliente;

}

int cliente_setId(eCliente* this,int id)
{
    int retorno = 0;
    if( this !=NULL )
    {
        if( id > 0 )
        {
            this->id = id;
            retorno = 1;
        }
    }
    return retorno;
}



int cliente_setNombre(eCliente* this,char* nombre)
{
    int retorno = 0;
    if( this != NULL && strlen(nombre))
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}



///VALIDAR F/M
int cliente_setSexo(eCliente* this,char* sexo)
{
    int retorno = 0;
    if( this != NULL && strlen(sexo))
    {
            strcpy(this->sexo, sexo);
            retorno = 1;
    }

    return retorno;
}



int cliente_setNumeroTelefonico(eCliente* this, char* numeroTelefonico)
{
    int retorno = 0;
    if( this != NULL && strlen(numeroTelefonico))
    {
        strcpy(this->numeroTelefonico, numeroTelefonico);
        retorno = 1;
    }
    return retorno;
}




int cliente_setImporte(eCliente* this, int importe)
{
    int retorno = 0;
    if( this != NULL )
    {
        if( importe > 0)
        {
            this->importe = importe;
            retorno = 1;
        }
    }
    return retorno;
}




int cliente_getId(eCliente* this, int* id)
{
    int retorno = 0;
    if( this != NULL )
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}



int cliente_getNombre(eCliente* this, char* nombre)
{
    int retorno = 0;
    if( this != NULL )
    {
        strcpy ( nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}



int cliente_getSexo(eCliente* this,char* sexo)
{
    int retorno = 0;
    if( this != NULL )
    {
        strcpy ( sexo, this->sexo);
        retorno = 1;
    }
    return retorno;
}



int cliente_getNumeroTelefonico(eCliente* this,char* numeroTelefonico)
{
    int retorno = 0;
    if(this!=NULL)
    {
        strcpy ( numeroTelefonico, this->numeroTelefonico);
        retorno = 1;
    }
    return retorno;
}


int cliente_getImporte(eCliente* this,int* importe)
{
    int retorno = 0;
    if(this!=NULL)
    {
        *importe = this->importe;
        retorno = 1;
    }
    return retorno;
}


int abono_setId(eAbono* this,int id)
{
    int retorno = 0;
    if( this !=NULL )
    {
        if( id > 0 )
        {
            this->id = id;
            retorno = 1;
        }
    }
    return retorno;
}


int abono_setTipo(eAbono* this,int tipo)
{
    int retorno = 0;
    if( this !=NULL )
    {
        if( tipo > 0 )
        {
            this->tipo = tipo;
            retorno = 1;
        }
    }
    return retorno;
}

int abono_setIdCliente(eAbono* this,int idCliente)
{
    int retorno = 0;
    if( this !=NULL )
    {
        if( idCliente > 0 )
        {
            this->idCliente = idCliente;
            retorno = 1;
        }
    }
    return retorno;
}

int abono_setImporteFinal(eAbono* this,float importeFinal)
{
    int retorno = 0;
    if( this !=NULL )
    {
        if( importeFinal > 0 )
        {
            this->importeFinal = importeFinal;
            retorno = 1;
        }
    }
    return retorno;
}


int abono_getId(eAbono* this,int* id)
{
    int retorno = 0;
    if ( this != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int abono_getTipo(eAbono* this,int* tipo)
{
    int retorno = 0;
    if ( this != NULL)
    {
        *tipo = this->tipo;
        retorno = 1;
    }
    return retorno;
}


int abono_getIdCliente(eAbono* this,int* idCliente)
{
    int retorno = 0;
    if ( this != NULL)
    {
        *idCliente = this->idCliente;
        retorno = 1;
    }
    return retorno;
}



int abono_getImporteFinal(eAbono* this,float* importeFinal)
{
    int retorno = 0;
    if ( this != NULL)
    {
        *importeFinal = this->importeFinal;
        retorno = 1;
    }
    return retorno;
}

int employeeSortById(void* empleadoA, void* empleadoB)
{
    int retorno;

    eCliente* empA;
    eCliente*empB;

    if((empleadoA != NULL )&& (empleadoB != NULL))
    {
        empA = (eCliente*) empleadoA;
        empB = (eCliente*) empleadoB;
        if(empA->id == empB->id)
        {
             retorno = 1;
        }
        if(empA->id > empB->id)
        {
            retorno = -1;
        }
        if(empA->id < empB->id)
        {
            retorno = 0;
        }
    }

    return retorno;
}



int abonoSortByImporte(void* empleadoA, void* empleadoB)
{
    int retorno;

    eAbono* empA;
    eAbono*empB;

    if((empleadoA != NULL )&& (empleadoB != NULL))
    {
        empA = (eAbono*) empleadoA;
        empB = (eAbono*) empleadoB;
        if(empA->importeFinal == empB->importeFinal)
        {
             retorno = 1;
        }
        else if(empA->importeFinal > empB->importeFinal)
        {
            retorno = -1;
        }
        else if(empA->importeFinal < empB->importeFinal)
        {
            retorno = 0;
        }
    }

    return retorno;
}

///Ver si se puede incluir en la linkedlist
LinkedList* crearListaAbono(LinkedList* this)
{
    eAbono* abono; ///Creamos un puntero a la estructura abonos
    eCliente* clienteActual; ///Creamos un puntero a la posicion actual del cliente
    eCliente* clienteSiguiente;  ///Creamos un puntero a la posicion proxima del cliente
    LinkedList* listaAbono = ll_newLinkedList();  ///Se declara la nueva linkedlist
    int contador=0; ///Creamos un contador igualandolo a cero
    int importeTotal=0;  ///Definimos el importe total
    int i;
    if(this != NULL)
    {
        for( i=0; i<ll_len(this); i++) ///Recorremos la lista this
        {
            clienteActual = (eCliente*)ll_get(this, i); ///Obtenemos cada elemento de la posicion actual de la lista
            if(i+1 < ll_len(this)) ///Si la posicion sumandelo uno, es menor a la lista (esto se hace una vez que se llega al final de la lista)
            ///Lo que se quiere lograr es analizar si el cliente actual y proximo coinciden, se empizan a contar, y antes de llegar a la lista y que el cliente proximo no exista, se declara la condicion del if
            clienteSiguiente = (eCliente*)ll_get(this, i+1); ///Se obtiene el cliente de la posicion proxima del actual
            contador++; /// Y se empieza  a contar cada cliente
            importeTotal=importeTotal+clienteActual->importe; ///Se va calculando el importe

            if((clienteActual->id != clienteSiguiente->id) || i+1 == ll_len(this)) ///Se verifica que los id no coincidan para ir creando la nueva lista y que (ademas) no se termine de recorrer la lista por completo
            {
                //contador++;
                //importeTotal=importeTotal+clienteActual->importe;
                abono = new_abono(); ///Se reserva memoria para el abono
                if(contador==1) ///Vemos que si se conto un solo id, es de tipo personal
                {
                    abono_setTipo(abono, PERSONAL);
                    abono_setImporteFinal(abono, importeTotal);
                    abono_setIdCliente(abono, clienteActual->id);
                    abono->id = generarNextId();
                }
                else if(contador>=2 && contador <=4) ///Si se conto 2 a 4 ids que coinciden, es de tipo familiar
                {
                    abono_setTipo(abono, FAMILIAR);
                    abono_setImporteFinal(abono, importeTotal*1.1); // CASTEAR A FLOAT AMEWO
                    abono_setIdCliente(abono, clienteActual->id);
                    abono->id = generarNextId();
                }
                else ///Si se conto mas de 4 ud que coinciden, es de tipo Corporativo
                {
                    abono_setTipo(abono, CORPORATIVO);
                    abono_setImporteFinal(abono, importeTotal*1.2); // CASTEAR A FLOAT AMEWO
                    abono_setIdCliente(abono, clienteActual->id);
                    abono->id = generarNextId();
                }
                ll_add(listaAbono, abono); ///Una vez, generado cada campo, se agrega la lista
                //Resetear los acumuladores ya que tiene que volver a analizar todo
                contador = 0;
                importeTotal = 0;
            }
        }
    }

    return listaAbono; //Me retorna la linkedlist
}






