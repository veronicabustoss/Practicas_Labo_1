#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "reglasNegocio.h"
#include "Controller.h"
#include "PARSER.H"
#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2



static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList)); //Liberamos memoria para esa nueva lista
    if(this != NULL) //Comprobamos que sea distinta de null
    {
        this->size=0; //Le asignamos tamaño cero a la lista
        this->pFirstNode = NULL; //Y que el primer nodo apunte a nada, ya que es el primero y ultimo
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = this->size; //Me devuelve el tamaño de la lista
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    if(this != NULL )// && nodeIndex>=0 && nodeIndex<=ll_len(this) )
    {
        int auxIndex = 0; //Creamos un auxiliar de index para ir comparando mas adelante
        LinkedList listaAux = *this; //Crearemos una lista nuevo que apunta a lo mismo que tiene this, para no modificar el original
        if(nodeIndex>=0 && nodeIndex< ll_len(this)) //Comprobamos que el index que nos pasaron es mayor a cero y menor a la lista
        {
            while(auxIndex != nodeIndex) //Si el index auxiliar no coincide con el nodeIndex, el auxiliar se incrementa a uno, hasta que coincida
            {
                listaAux.pFirstNode = listaAux.pFirstNode->pNextNode;  //Lo que declaro es que el nodo donde se encuentra en este lugar, es que avance (que sea en todo caso) al siguiente nodo ya que no coinciden los index
                auxIndex++; //Se incrementa el contador para luego coincidir con el Index pedido
            }
            pNode = listaAux.pFirstNode; //Declaramos que el nodo es igual a el nodo que coincidio con la busqueda
        }

    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    ///Podria utilizar un get_Node?
    int returnAux = -1;
    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this)) //Comprobamos que el this tenga memoria y que el index pasado sea mayor o igual a cero y que no sobrepase a la lista
    {
        LinkedList listaAux = *this; //Creo una nueva lista para poder recorrerla y no perder nada de la original
        Node* pNodo = (Node*)calloc(1, sizeof(Node)); //Creo memoria para el nuevo nodo
        if(pNodo != NULL) // Tuve memoria para crear el nodo con el calloc //Comprobamos si se pudo agregar el nodo
        {
            pNodo->pElement = pElement; //Al nodo creado, le asignamos los valores que le pasamos a pElement
            if(this->size!=0) //Comprobamos que el tamaño de la lista sea mayor a cero o distinto en este caso
            {
                int indexAux = 0; //Creamos un indice auxiliar que va a incrementar para ir comparando
                if(nodeIndex==0) //Si la ubicacion del nodo que nos pasaron es igual a cero
                {
                    pNodo->pNextNode = this->pFirstNode; //Para no perder la referencia del unico nodo que tenia la lista, lo conecto al nuevo nodo creado
                    this->pFirstNode = pNodo; //Luego el primer nodo de la lista sera ese nodo creado
                }
                else //Si la lista es distinta de cero, osea, tendra mas nodos
                {
                    while(indexAux+1 != nodeIndex) //Se empieza a comparar  a ver si coinciden los indices, y el primer indice
                    {
                        listaAux.pFirstNode = listaAux.pFirstNode->pNextNode;
                        indexAux++;
                    }
                    pNodo->pNextNode = listaAux.pFirstNode->pNextNode; //Mmmmm lo paso al auxiliar?
                    listaAux.pFirstNode->pNextNode = pNodo;
                }
            }
            else //we
            {
                this->pFirstNode = pNodo;
                pNodo->pNextNode = NULL;
            }
            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(addNode(this, ll_len(this), pElement) != -1)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = -1;
        }
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodo; //Necesito crear un nodo para poder empezar a comparlo
    if( this!= NULL && index>=0 && index<=ll_len(this))
    {
        nodo = getNode(this, index);
        if(nodo != NULL)
        {
            returnAux = nodo->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL; ///Siempre hay que inicializarlos
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        pNode = getNode(this, index); ///Pido el nodo que deseo modificar
        pNode->pElement = pElement;
        returnAux = 0;
    }

    return returnAux;
}




/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode = NULL;
    Node* nodoAux= NULL ;
    if(this != NULL && index >= 0 && index < ll_len(this) )
    {
        if( index == ll_len(this) /*&& index != 0*/) ///Si el indice es igual al tamaño de la lista, quiere decir que es el ultimo elemento de la lista
        {
            free(pNode);
        }

        else if(index !=0 && index != (ll_len(this))) ///Si el indice es distinto de cero y de la lista, se encuentra en medio de la lista
        {
            // pNode = getNode(this, index);
            nodoAux = getNode(this, index-1); ///Cambie el orden en que pedi las cosas
            pNode = getNode(this, index);
            nodoAux->pNextNode = pNode->pNextNode;
            free(pNode);
        }

        else if(index == 0) ///Si el indice es el primer elemento de la lista
        {
            pNode = getNode(this, index);
            this->pFirstNode = pNode->pNextNode;
            free(pNode);
        }
        this->size--;
        returnAux=0;
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    if(this != NULL)
    {
        for ( i = 0; i <=(ll_len(this)); i ++)
        {
            //free(ll_get(this, i));
            ll_remove(this, i);
            // this->size-- ;

            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
        returnAux = this->size =0 ; //El tamaño de la lista sera de cero, por lo tanto no tendra nada
        free(this);
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this != NULL)
    {
        Node* nodo;
        for( i=0 ; i<ll_len(this); i++) ///Recorro la lista
        {
            nodo = getNode(this, i); ///Obtengo los nodos de la lista
            if(nodo!=NULL)
            {
                if(nodo->pElement == pElement) ///Si el elemento del nodo coincide con el elemento pedido
                {
                    returnAux = i; ///Me devuelve ese indice
                    break;
                }
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(this->size == 0)
        {
            returnAux = 1;
        }
        if(this->size >= 1)
        {
            returnAux =  0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    ///Utiliza el add_Node
    int returnAux = -1;
    if( this != NULL )
    {
        if(addNode(this, index, pElement) != -1)
        {
            returnAux = 0 ;
        }
        else
        {
            returnAux = -1;
        }

    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    //Node* nodo;
    if(this != NULL && index>=0 && index<=ll_len(this))
    {
        returnAux = ll_get(this, index);
        if(returnAux != NULL)
        {
            ll_remove(this, index);
        }

    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(ll_indexOf(this, pElement) != -1)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
/*{
    int returnAux = -1;

    if(this!=NULL && this2!=NULL)
    {
        if(ll_indexOf(this2, this) != -1 )
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}*/
{
    int returnAux = -1;
    int i;
    Node* nodo;

    if( this != NULL && this2 != NULL)
    {
        returnAux = 1;

        for(i = 0; i < ll_len(this2); i++)
        {
            nodo = getNode(this2, i);

            if( ll_contains(this, nodo->pElement) == 0)
            {
                returnAux = 0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* auxiliar ;  //Obtener nodos
    int i;

    if(this!= NULL && from>=0 && from<ll_len(this) && to>0 && to<=ll_len(this)) //Compruebo que la lista no apunte a null, que el from no sea mayor a len
    {
        cloneArray = ll_newLinkedList();
        //if(cloneArray!=NULL) //Comprueb
        //{
        for(i = from ; i<= to; i++ ) //Voy recorriendo lo que propuse yo
        {
            auxiliar = ll_get(this, i ); //Obtengo todos los nodos de donde le propuse yo
            if(auxiliar != NULL)
            {
                ll_add(cloneArray, auxiliar);

            }

            //  }

        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!= NULL ) //Compruebo que la lista no apunte a null, que el from no sea mayor a len
    {
        cloneArray = ll_subList(this, 0, ll_len(this));  //Copiaria desde el primer nodo hasta el ultimoo en este caso el tamaño de la lista
    }
    return cloneArray;
}



/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* elementOne = NULL;
    void* elementTwo = NULL;
    void* elementAux = NULL;
    int i;
    int j;
    if(this!=NULL && (order == 1 || order == 0)  && pFunc !=NULL)
    {
        for( i = 0; i<ll_len(this)-1; i++)
        {
            elementOne = ll_get(this, i);

            for ( j = i+1; j<ll_len(this); j++)
            {
                elementTwo = ll_get(this, j);
                if(order == 0)
                {
                    if(pFunc(elementOne,elementTwo)<0)
                    {
                        ///Se aplica un swap a los elementos para que cambien de lugar
                        elementAux = elementTwo;
                        elementTwo = elementOne;
                        elementOne = elementAux;
                    }
                }
                if( order == 1)
                {
                    if(pFunc(elementOne,elementTwo)>0)
                    {
                        ///Se aplica un swap a los elementos para que cambien de lugar
                        elementAux = elementTwo;
                        elementTwo = elementOne;
                        elementOne = elementAux;
                    }
                }
                ll_set(this, i, elementOne);
                ll_set(this, j, elementTwo);

            }
        }
        returnAux = 0;
    }
    return returnAux;
}


void ll_map(LinkedList*this, int(*pFunc(void*)))
{
    int i;

    eCliente *listaEmpleados;


    for(i=0; i<ll_len(this); i++)
    {
        listaEmpleados = (eCliente*)ll_get(this,i);
        pFunc(listaEmpleados);
    }


}




/** \brief Se crea una nueva lista con ciertas condiciones.
 *
 * \param lista LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return devuelve una lista con los mismos datos y los sueldos cargados.
 *
 */

LinkedList* ll_filter(LinkedList* this, int (*pFuncion)(void*)) ///Lista filtrada
{
    LinkedList* auxThis ;
    void* pElement = NULL; //Creo un elemento con void
    int i;

    if (this!=NULL && pFuncion!=NULL)//Verificamos que sean distinto de NULL
    {
        auxThis = ll_newLinkedList();  //Creamos una nueva lista

        if(auxThis!=NULL) //Comprobamos esa nueva lista
        {
            for( i=0 ; i<ll_len(this); i++) //Recorremos la lista original
            {
                pElement = ll_get(this, i); //Obtenemos el elemento de lo que vamos recorriendo
                if(pFuncion(pElement)) // Utilizo la funcion para cada elemento de la lista
                {
                    ll_add(auxThis, pElement); //Se agregan los elementos modificados por la funcion  a la lista nueva

                }
            }
        }
    }
    return auxThis;
}









