#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char ESC=27;

///Encabezados
int cargarUsuario (int legajos[], char nombres[][30], int anios[], int dim);
void mostrarUsuario (int legajos[], char nombres[][30], int anios[], int cantUsuarios);
int encontrarLegajo (int legajo[], int cantUsuarios, int numLegajo);
int posicionLegajo (int legajo[], int cantUsuarios, int numLegajo);
void nombreToLegajo (int legajos[], char nombres[][30], int cantUsuarios, int numLegajo);
int menorArregloChar (char nombres[][30], int cantUsuarios, int pos);
void intercambioPalabra (char nombres[][30], int pos, int i);
void intercambioEntero (int arreglo[], int pos, int i);
void ordenarUsuarios (int legajos[], char nombres[][30], int anios[], int cantUsuarios);

int main()
{   int legajos[ 20 ];
    char nombres[ 20 ][ 30 ];
    int anios[ 20 ];

    printf("USUARIOS.\n\n");

    int cantUsuarios=0;

    cantUsuarios= cargarUsuario(legajos, nombres, anios, 20);
    printf("Usuarios cargados:\n\n");
    mostrarUsuario(legajos, nombres, anios, cantUsuarios);

    int numLegajo=0;
    int pos=0;
    int flag=0;
    char opcion;

    do{
        printf("\nIngrese su numero de legajo: ");
        scanf("%d", &numLegajo);
        flag= encontrarLegajo(legajos, cantUsuarios, numLegajo);
        if(flag==0){
            printf("\nEl numero de legajo cargado no existe.\nESC para salir (cualquier otra tecla para volver a intentarlo).\n");
            fflush(stdin);
            opcion= getch();
        }
    }
    while(flag==0 && opcion!=ESC);

    pos= posicionLegajo(legajos, cantUsuarios, numLegajo);
    printf("\nEl legajo ingresado se encuentra en la posicion: %d.\n", pos);

    nombreToLegajo(legajos, nombres, cantUsuarios, numLegajo);

    system("pause");
    system("cls");

    printf("USUARIOS ORDENADOS POR NOMBRE:\n\n");
    ordenarUsuarios(legajos, nombres, anios, cantUsuarios);
    mostrarUsuario(legajos, nombres, anios, cantUsuarios);
    return 0;
}

///Ejercicio 1
int cargarUsuario (int legajos[], char nombres[][30], int anios[], int dim){
    int i=0;
    char opcion;

    do{
        printf("Cargando usuario...\n");
        printf("Ingrese numero de legajo: ");
        scanf("%d", &legajos[i]);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombres[i]);
        do{
            printf("Ingrese anios (mayor a 0 y menor a 100): ");
            scanf("%d", &anios[i]);
            if(anios[i]>100 || anios[i]<=0){
                printf("Valor no valido.\n");
            }
        }
        while(anios[i]>100 || anios[i]<0);
        printf("\n\nPresione ESC para salir (cualquier otra letra para cargar otro usuario).\n\n");
        fflush(stdin);
        opcion= getch();
        i++;
    }
    while(opcion!=ESC && i<dim);

    return i;
}

void mostrarUsuario (int legajos[], char nombres[][30], int anios[], int cantUsuarios){
    int i=0;

    while(i<cantUsuarios){
        printf("Numero de legajo......: %d\n", legajos[i]);
        printf("Nombre................: %s\n", nombres[i]);
        printf("Anios.................: %d\n\n", anios[i]);
        i++;
    }
}

///Ejercicio 2
int encontrarLegajo (int legajo[], int cantUsuarios, int numLegajo){
    int i=0;
    int flag=0;

    while(flag==0 && i<cantUsuarios){
        if(numLegajo==legajo[i]){
            flag=1;
        }
        else{
            i++;
        }
    }
    return flag;
}


int posicionLegajo (int legajo[], int cantUsuarios, int numLegajo){
    int i=0;
    int flag=0;

    while(flag==0 && i<cantUsuarios){
        if(numLegajo==legajo[i]){
            flag=1;
        }
        else{
            i++;
        }
    }
    return i;
}

///Ejercicio 3
void nombreToLegajo (int legajos[], char nombres[][30], int cantUsuarios, int numLegajo){
    int i=0;
    int pos=0;

    pos= posicionLegajo(legajos, cantUsuarios, numLegajo);

    printf("\nNombre del legajo %d: %s\n\n", numLegajo, nombres[pos]);
}

///Ejercicio 4
int menorArregloChar (char nombres[][30], int cantUsuarios, int pos){
    int i=pos+1;
    int posMenor= pos;
    char aux[30];
    strcpy(aux, nombres[posMenor]);
    int valor=0;

    while(i<cantUsuarios){
        valor= strcmp(aux, nombres[i]);
        if(valor>0){
            strcpy(aux, nombres[i]);
            posMenor=i;
        }
        i++;
    }
    return posMenor;
}

void intercambioPalabra (char nombres[][30], int pos, int i){
    char aux[30];
    strcpy(aux, nombres[pos]);
    strcpy(nombres[pos], nombres[i]);
    strcpy(nombres[i], aux);
}

void intercambioEntero (int arreglo[], int pos, int i){
    int aux=0;
    aux= arreglo[pos];
    arreglo[pos]= arreglo[i];
    arreglo[i]= aux;
}

void ordenarUsuarios (int legajos[], char nombres[][30], int anios[], int cantUsuarios){
    int i=0;
    int pos=0;

    while(i<cantUsuarios){
        pos= menorArregloChar(nombres, cantUsuarios, i);
        intercambioEntero(legajos, pos, i);
        intercambioPalabra(nombres, pos, i);
        intercambioEntero(anios, pos, i);
        i++;
    }
}
