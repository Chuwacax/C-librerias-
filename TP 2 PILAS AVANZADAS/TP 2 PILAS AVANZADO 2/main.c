#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Contar los elementos de una pila (usar variables)*/

const char ESC=27;
int main()
{   Pila dada;
    Pila aux;

    inicpila(&dada);
    inicpila(&aux);

    int i=0;
    char opcion;

    printf("Cargar la pila dada:\n");

    do{
        leer(&dada);
        printf("\nPresione ESC para salir.\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");

    while(!pilavacia(&dada)){
        apilar(&aux, desapilar(&dada));
        i++;
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }

    printf("La pila dada contiene %d elementos.", i);
    printf("\n\nPila dada:\n");
    mostrar(&dada);

    return 0;
}
