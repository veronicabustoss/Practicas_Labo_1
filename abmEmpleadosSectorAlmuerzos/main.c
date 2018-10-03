#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

typedef struct
{
    int id;
    char descripcion[20];
} eComida;

typedef struct
{
    int id;
    int idEmpleado;
    int IdComida;

} eAlmuerzo;

void inicializarEmpleados( eEmpleado x[], int tam);
int buscarLibre( eEmpleado x[], int tam);
int buscarEmpleado(eEmpleado x[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector);
void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector);
void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void eliminarEmpleado(eEmpleado *empleados, int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);;
int elegirSector(eSector sectores[], int tam);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);
void listarEmpleadosXSector(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void ordenarXSectorYNombre(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void mostrarEmpleadosMasGanadores(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void harcodearEmpleados(eEmpleado x[]);
void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[]);
void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleados, eComida comidas[], int tamComidas);
void cargarNombreEmpleado(eEmpleado empleados[], int tam, int legajo, char cadena[]);
void mostrarAlmuerzosEmpleado(eAlmuerzo almuerzos[], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleados, eComida comidas[], int tamComidas, eSector sectores[], int tamSector);
int menu();

int main()
{

    char seguir = 's';
    eEmpleado lista[10];
    eSector sectores[] =
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    eComida comidas[] =
    {
        {1, "Milanesa"},
        {2, "Fideos"},
        {3, "Pizza"},
        {4, "Sopa"},
        {5, "Pescado"}
    };

    eAlmuerzo almuerzos[] =
    {
        {100, 1111, 2},
        {101, 5555, 1},
        {102, 4545, 3},
        {103, 3232, 4},
        {104, 1111, 1},
        {105, 5555, 5},
        {106, 4545, 2},
        {107, 3232, 5},
        {108, 1111, 2},
        {109, 4545, 1},
        {110, 3232, 1},
        {111, 1111, 4},
        {112, 5555, 3},
        {113, 4545, 5},
        {114, 3232, 2},
        {115, 5555, 5},
        {116, 4545, 2},
        {117, 3232, 3},
        {118, 1111, 2},
        {119, 5555, 1},
        {120, 4545, 3},

    };



    inicializarEmpleados(lista, 10);
    harcodearEmpleados(lista);

    do
    {
        switch(menu())
        {

        case 1:
            agregarEmpleado(lista, 10, sectores, 5);
            system("pause");
            break;
        case 2:
            eliminarEmpleado(lista, 10, sectores, 5);
            break;
        case 3:
            modificarEmpleado(lista, 10, sectores, 5);
            break;
        case 4:
            mostrarEmpleados(lista, 10, sectores, 5);
            system("pause");
            break;
        case 5:
            listarEmpleadosXSector(lista, 10, sectores, 5);
            system("pause");
            break;
        case 6:
            ordenarXSectorYNombre(lista, 10, sectores, 5);
            system("pause");
            break;
        case 7:
            mostrarEmpleadosMasGanadores(lista, 10, sectores, 5);
            system("pause");
            break;
        case 8:
            mostrarAlmuerzos(almuerzos, 21, lista, 10, comidas, 5);
            system("pause");
            break;
        case 9:
            mostrarAlmuerzosEmpleado(almuerzos, 21, lista, 10, comidas, 5, sectores, 5);
            system("pause");
            break;
        case 10:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');



    return 0;
}

void inicializarEmpleados( eEmpleado x[], int tam)
{
    int i;

    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}

int buscarLibre( eEmpleado x[], int tam)
{
    int indice = -1;
    int i;

    for(i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado x[], int tam, int legajo)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {


        if( x[i].legajo == legajo && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Listar todos los empleados de un sector\n");
    printf("6- Ordenar empleados por sector y dentro del sector por nombre\n");
    printf("7- Mostrar los datos de o los empleados que mas ganan por sector\n");
    printf("8- Mostrar almuerzos\n");
    printf("9- Mostrar almuerzos empleado\n");
    printf("10- Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{
    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;

    system("cls");
    printf("  *** Alta Empleado ***\n\n");

    indice = buscarLibre(empleados, tam);


    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(empleados, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado con el legajo %d\n", legajo);
            mostrarEmpleado( empleados[esta], sectores, tamSector);
        }
        else
        {
            nuevoEmpleado.legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            nuevoEmpleado.idSector = elegirSector(sectores, 5);

            nuevoEmpleado.isEmpty = 1;

            empleados[indice] = nuevoEmpleado;

        }
    }

}

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector)
{
    char descripcion[20];

    cargarDescripcion(sectores, tamSector, emp.idSector, descripcion);

    printf("%4d %10s %2c    %5.2f   %10s \n\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, descripcion);

}


void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector)
{
    int i;

    system("cls");
    printf(("Legajo  Nombre  Sexo    Sueldo     Sector\n\n"));
    for(i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarEmpleado(nomina[i], sectores, tamSector);
        }
    }
}

void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{

    int legajo;
    int indice;
    char borrar;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado( empleados[indice], sectores, tamSector);

        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else
        {
            empleados[indice].isEmpty = 0;
            printf("Se ha eliminado el empleado\n\n");
        }
        system("pause");
    }

}

void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{

    int legajo;
    int indice;
    char modificar;
    float nuevoSueldo;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado( empleados[indice], sectores, tamSector);

        printf("\nModifica sueldo?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

            empleados[indice].sueldo = nuevoSueldo;
            printf("Se ha modificado el sueldo con exito\n\n");
        }

        system("pause");
    }

}


int elegirSector(eSector sectores[], int tam)
{
    int idSector;
    int i;
    printf("\nSectores\n\n");
    for(i=0; i < tam; i++)
    {
        printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);

    return idSector;
}

void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[])
{
    int i;

    for(i=0; i < tamSector; i++)
    {
        if( sectores[i].id == idSector)
        {
            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }
}
void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[])
{
    int i;

    for(i=0; i < tamComida; i++)
    {
        if( comidas[i].id == idComida)
        {
            strcpy(cadena, comidas[i].descripcion);
            break;
        }
    }
}

void cargarNombreEmpleado(eEmpleado empleados[], int tam, int legajo, char cadena[])
{
    int i;

    for(i=0; i < tam; i++)
    {
        if( empleados[i].legajo == legajo)
        {
            strcpy(cadena, empleados[i].nombre);
            break;
        }
    }
}

void listarEmpleadosXSector(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{
    int idSector;
    char descripcion[20];
    int flag = 0;
    int i;

    idSector = elegirSector(sectores, tamSector);

    cargarDescripcion(sectores, tam, idSector, descripcion);

    system("cls");
    printf("Empleados del sector %s\n\n", descripcion);
    for(i=0; i< tam; i++)
    {
        if(x[i].isEmpty == 1 && x[i].idSector == idSector)
        {
            mostrarEmpleado(x[i], sectores, tamSector);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }

}

void ordenarXSectorYNombre(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{
    int i, j;
    char descripcionI[20];
    char descripcionJ[20];
    eEmpleado auxEmpleado;

    for(i=0; i<tam -1; i++)
    {
        for(j = i +1; j < tam; j++)
        {
            cargarDescripcion(sectores, tamSector, x[i].idSector, descripcionI);
            cargarDescripcion(sectores, tamSector, x[j].idSector, descripcionJ);
            if( strcmp(descripcionI, descripcionJ) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
            else if( strcmp(descripcionI, descripcionJ) == 0 && strcmp(x[i].nombre, x[j].nombre) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
        }
    }

}
void harcodearEmpleados(eEmpleado x[])
{
    int i;

    eEmpleado y[]=
    {
        {1111, "ana", 'f', 15000, 5, 1},
        {3333, "luis", 'm', 25000, 4, 1},
        {4444, "alberto", 'm', 10000, 5, 1},
        {5555, "julia", 'f', 30000, 1, 1},
        {1313, "julieta", 'f', 23000, 2, 1},
        {4545, "andrea", 'f', 31000, 5, 1},
        {3232, "mauro", 'm', 27000, 5, 1},
    };

    for(i=0; i<7; i++)
    {
        x[i] = y[i];
    }

}

void mostrarEmpleadosMasGanadores(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{
    float maxSueldo;
    char descripcion[20];
    int flag;
    int flag2;
    int i, j;

    system("cls");
    printf("\n*** Empleados que mas ganan por sector ***\n\n");

    for(i=0; i < tamSector; i++)
    {

        cargarDescripcion(sectores, tamSector, sectores[i].id, descripcion);
        printf("Sector %s\n\n", descripcion);
        flag = 0;
        flag2 = 0;
        for(j=0; j < tam; j++)
        {
            if( (x[j].sueldo > maxSueldo && x[j].isEmpty == 1 && x[j].idSector == sectores[i].id) || flag == 0)
            {
                maxSueldo = x[j].sueldo;
                flag = 1;
            }

            if( x[j].isEmpty == 1 && x[j].idSector == sectores[i].id)
            {
                flag2 = 1;
            }

        }

        if(flag2 == 0)
        {
            printf("Sector Vacio\n");
        }
        else
        {

            for(j=0; j < tam; j++)
            {
                if( x[j].sueldo == maxSueldo)
                {
                    mostrarEmpleado(x[j], sectores, tamSector);
                }
            }

        }

        printf("\n\n");
    }
}

void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleados, eComida comidas[], int tamComidas)
{
    char descComida[20];
    char nombreEmpleado[20];
    int i, j, k;

    system("cls");
    printf("  *** Listado de Almuerzos ***\n\n");
    printf("Id  Legajo     Nombre     Comida\n\n");

    for(i=0; i< tamAlmuerzo; i++)
    {
        for(j = 0; j < tamEmpleados; j++)
        {
            if(almuerzos[i].idEmpleado == empleados[j].legajo)
            {
                strcpy(nombreEmpleado, empleados[j].nombre);
                break;
            }
        }
        for(k = 0; k < tamComidas; k++)
        {
            if(almuerzos[i].IdComida == comidas[k].id)
            {
                strcpy(descComida, comidas[k].descripcion);
                break;
            }
        }

        printf("%d  %d %10s   %10s\n", almuerzos[i].id, almuerzos[i].idEmpleado, nombreEmpleado, descComida);

    }

    printf("\n\n");

}

void mostrarAlmuerzosEmpleado(eAlmuerzo almuerzos[], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleados, eComida comidas[], int tamComidas, eSector sectores[], int tamSector)
{
    int legajo;
    int flag = 0;
    int i, j;

    system("cls");

    mostrarEmpleados(empleados,tamEmpleados, sectores, tamSector);
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    system("cls");
    printf("  *** Listado de almuerzos legajo %d ***\n\n", legajo);

    for(i=0; i < tamAlmuerzo; i++)
    {
        if( almuerzos[i].idEmpleado == legajo)
        {
            for(j=0; j < tamComidas; j++)
            {
                if( comidas[j].id == almuerzos[i].IdComida)
                {
                    printf("%d  %10s\n", almuerzos[i].id, comidas[j].descripcion);
                }
            }
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("El empleado no presenta almuerzos");
    }
    printf("\n\n");
}
