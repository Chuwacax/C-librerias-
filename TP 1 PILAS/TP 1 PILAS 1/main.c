#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*1. Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres primeros elementos a la pila AUX1 y los dos restantes a la pila AUX2, ambas pilas inicializadas en vacío.*/


int main()
{   Pila DADA;
    Pila aux1;
    Pila aux2;
    inicpila(&DADA);
    inicpila(&aux1);
    inicpila(&aux2);
    int m=0;
    int i=0;

    for(i=0; i<5; i++){
        leer(&DADA);
        system("pause");
        system("cls");
    }
    printf("Pila DADA:\n");
    mostrar(&DADA);

    while(!pilavacia(&DADA)&& m<3){
        apilar(&aux1,desapilar(&DADA));
        m++;
    }
    m=0;
    while(!pilavacia(&DADA)&& m<2){
        apilar(&aux2, desapilar(&DADA));
        m++;
    }
    printf("\nPila DADA:\n");
    mostrar(&DADA);
    printf("Pila aux1:\n");
    mostrar(&aux1);
    printf("Pila aux2:\n");
    mostrar(&aux2);

    return 0;
}
