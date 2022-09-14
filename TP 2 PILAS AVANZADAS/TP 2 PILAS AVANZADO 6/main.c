#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que la segunda pila quede ordenada
de mayor (tope) a menor (base). Esto se llama método de ordenación por selección.*/

const char ESC=27;

int main()
{   Pila dada;
    Pila aux;
    Pila menor;
    Pila ordenada;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&menor);
    inicpila(&ordenada);

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
    printf("Pila original:\n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        if(!pilavacia(&dada)){
            apilar(&menor, desapilar(&dada));
        }
        while(!pilavacia(&dada)){
            if(tope(&dada)<tope(&menor)){
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&dada));
            }
            else{
                apilar(&aux, desapilar(&dada));
            }
        }
        apilar(&ordenada, desapilar(&menor));
        while(!pilavacia(&aux)){
            apilar(&dada, desapilar(&aux));
        }
    }

    printf("\n\nPila original ordenada de menor a mayor:\n");
    mostrar(&ordenada);

    return 0;
}
