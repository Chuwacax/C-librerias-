#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*12. Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los elementos que existan en MODELO.*/

const char ESC=27;

int main()
{   Pila modelo;
    Pila dada;
    Pila aux;
    Pila basura;
    Pila auxmodelo;

    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&basura);
    inicpila(&auxmodelo);

    char opcion;

    printf("Cargar pila modelo:\n\n");
    do{
        leer(&modelo);
        printf("Presione ESC para salir:\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");

    printf("Cargar pila dada:\n\n");
    do{
        leer(&dada);
        printf("Presione ESC para salir:\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");

    printf("Pila modelo:\n");
    mostrar(&modelo);
    printf("\n\nPila dada:\n");
    mostrar(&dada);

    while(!pilavacia(&modelo)){
        while (!pilavacia(&dada)){
            if(tope(&modelo)==tope(&dada)){
                apilar(&basura, desapilar(&dada));
            }
            else{
                apilar(&aux,desapilar(&dada));
            }
        }
        while(!pilavacia(&aux)){
            apilar(&dada, desapilar(&aux));
        }
        apilar(&auxmodelo, desapilar(&modelo));
    }

    while(!pilavacia(&auxmodelo)){
        apilar(&modelo, desapilar(&auxmodelo));
    }

    printf("\n\nPila dada sin los elementos contenidos en modelo:\n");
    mostrar(&dada);
    return 0;
}


