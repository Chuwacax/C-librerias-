#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).*/

int main()
{   Pila ordenada1;
    Pila ordenada2;
    Pila ordenadaFinal;
    Pila aux;


    inicpila(&ordenada1);
    inicpila(&ordenada2);
    inicpila(&ordenadaFinal);
    inicpila(&aux);


    apilar(&ordenada1, 1);
    apilar(&ordenada1, 2);
    apilar(&ordenada1, 5);
    apilar(&ordenada1, 8);
    apilar(&ordenada1, 8);
    apilar(&ordenada1, 10);

    apilar(&ordenada2, 2);
    apilar(&ordenada2, 3);
    apilar(&ordenada2, 6);
    apilar(&ordenada2, 7);
    apilar(&ordenada2, 9);

    printf("Pila ordenada1:\n");
    mostrar(&ordenada1);
    printf("\n\nPila ordenada2:\n");
    mostrar(&ordenada2);

    while(!pilavacia(&ordenada1)){
        while(!pilavacia(&ordenada2)){
            if(tope(&ordenada1)<tope(&ordenada2)){
                apilar(&aux, desapilar(&ordenada2));
            }
            else{
                apilar(&aux, desapilar(&ordenada1));
            }
        }
        while(!pilavacia(&ordenada1)){
            apilar(&aux, desapilar(&ordenada1));
        }
    }
    while(!pilavacia(&aux)){
        apilar(&ordenadaFinal, desapilar(&aux));
    }

    system("pause");

    printf("\n\nPila ORDENADA:\n");
    mostrar(&ordenadaFinal);
    return 0;
}
