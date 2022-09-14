#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*1) Sumar los elementos de una pila (usar variables)*/

const char ESC=27;

int main()
{   Pila dada;
    Pila aux;

    inicpila(&dada);
    inicpila(&aux);

    int suma=0;
    char opcion;

    printf("Cargar la pila dada:\n");
    do{
        leer(&dada);
        printf("Presione ESC para salir.\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");
    printf("Pila dada:\n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        suma= suma+ tope(&dada);
        apilar(&aux, desapilar(&dada));
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }

    printf("\n\nLa suma de los elementos de la pila dada es: %i", suma);
    return 0;
}
