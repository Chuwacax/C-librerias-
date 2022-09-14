#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8.*/


int main()
{   Pila dada;
    Pila distintos;
    Pila basura;
    inicpila(&dada);
    inicpila(&distintos);
    inicpila(&basura);

    char opcion='s';

    do{
        leer(&dada);
        printf("\nDesea seguir cargando la pila dada? s/n\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion=='s');

    system("pause");
    system("cls");
    printf("Pila dada cargada:\n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        if(tope(&dada)==8){
            apilar(&basura, desapilar(&dada));
        }
        else{
            apilar(&distintos, desapilar(&dada));
        }
    }
    while(!pilavacia(&basura)){
        apilar(&dada, desapilar(&basura));
    }

    printf("\Pila dada:\n");
    mostrar(&dada);
    printf("\nPila distintos:\n");
    mostrar(&distintos);

    return 0;
}
