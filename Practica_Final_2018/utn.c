#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}
/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') )
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}
/**
 * \brief Valida el array para no tomar el ultimo barra n
 * \param lista Array con la cadena a ser analizada
 * \param tamanio es el tamaño del  Array
 *
 */
void arreglarCadena(char lista[], int tamanio) //cambiar nombre
{
    for(int i=0; i<tamanio; i++)
    {
        if(lista[i]=='\n')
        {
            lista[i]='\0';
            break;
        }
        else if(lista[i]=='\0')
        {
            break;
        }
    }
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%s", input);

}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux)&&aux[0]!='\0')
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
       // cleanStdin();
        break;
    }

}

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */

float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(requestMessage, auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxFloat = atof(auxStr);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxFloat;

    }


}

/**
 * \brief Solicita un char al usuario y lo valida si es f o m
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param input Array donde se cargará el texto ingresado
 * \return El caracter ingresado por el usuario
 *
 */

char getValidSexo( char requestMessage[], char*input)
{
    int retorno=-1;
    char auxInput;
    while(1)
    {
        if(!getStringLetras(requestMessage, &auxInput))
        {
            printf("Debe contener solo letras\n");
            continue;
        }
        if(auxInput!='f' && auxInput!='F' && auxInput!='m' &&auxInput!='M' )
        {
            printf("Debe introducir f o m \n");
            continue;
        }
        retorno=0;
        strcpy(input, &auxInput);
        break;
    }
    return retorno;
}

/**
 * \brief Solicita un texto al usuario con espacios y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */

void getStringConEspacio(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin); // se lo dejo, sin el mismo, no funcionaria
    gets(input);
    arreglarCadena(input, 51);
}

/**
 * \brief Solicita un texto al usuario, valiando espacios y numeros y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras y numeros
 */
int getStringLetrasYNumeros(char mensaje[],char input[])
{
    char aux[256];
    getStringConEspacio(mensaje,aux);
    if(esAlfaNumerico(aux) && aux[0]!='\0')
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto al usuario, valiando espacios y numeros mas extricto
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
  * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getSuperAlfaNumerico(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetrasYNumeros(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        break;
    }

}


/**
 * \brief Solicita un texto al usuario, devolviendo  espacios y letras
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
  * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */

///FUNCION CREADA PARA INGRESAR NOMBRES CON ESPACIOS
int getStringValidNombre(char mensaje[],char input[])
{
    char aux[256];
    getStringConEspacio(mensaje,aux);
    if(esSoloLetras(aux) && aux[0]!='\0')
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto al usuario, valiando espacios y letras unicamente mas extricto
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
  * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
///FUNCION CREADA PARA VALIDAR NOMBRE CON ESPACIOS
void getValidStringEspaciosYLetras(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringValidNombre(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        break;
    }
}

/**
 * \brief Solicita un texto al usuario, valiando numeros y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras y numeros
 */
///FUNCION CREADA PARA VALIDAR STRING DE NUMEROS
int getNumeros(char mensaje[],char input[])
{
    char aux[256];
    getStringConEspacio(mensaje,aux);
    if(esNumerico(aux) && aux[0]!='\0')
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}




 /**
 * \brief Solicita un string al usuario, valiando unicamente numeros mas extricto
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
  * \param input Array donde se cargará el string ingresado
 * \return -
 */
void getValidStringNumeros(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getNumeros(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        break;
    }
}


/**
 * \brief Solicita un texto al usuario, valiando puntos y numeros, y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras y numeros
 */

int getNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getStringConEspacio(mensaje,aux);
    if(esNumericoFlotante(aux) && aux[0]!='\0')
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un string al usuario, valiando unicamente numeros y puntos para hacer numeros decimales
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
  * \param input Array donde se cargará el string ingresado
 * \return -
 */
void getValidStringNumerosFlotantes(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getNumerosFlotantes(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        break;
    }
}


