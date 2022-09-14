#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal que se conserve el orden. (sin variables, solo pilas)*/

int main()
{   Pila dada;
    Pila aux;
    Pila valor;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&valor);

    apilar(&dada, 10);
    apilar(&dada, 9);
    apilar(&dada, 6);
    apilar(&dada, 6);
    apilar(&dada, 4);
    apilar(&dada, 3);
    apilar(&dada, 1);

    printf("Valor a insertar:\n");
    leer(&valor);

    printf("\n\nPila dada:\n");
    mostrar(&dada);

    while(!pilavacia(&valor)){
        if(tope(&dada)<tope(&valor)&&!pilavacia(&dada)){
            apilar(&aux, desapilar(&dada));
        }
        else{
            apilar(&dada, desapilar(&valor));
        }
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }

    printf("\n\nPila dada con el elemento insertado:\n");
    mostrar(&dada);

    return 0;
}
