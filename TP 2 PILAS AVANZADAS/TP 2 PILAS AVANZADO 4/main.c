#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables, solo pilas)*/

const char ESC=27;

int main()
{   Pila dada;
    Pila aux;
    Pila menor;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&menor);

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
    printf("Pila dada con todos sus valores cargados:\n");
    mostrar(&dada);

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

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }

    printf("Pila dada sin su menor valor:\n");
    mostrar(&dada);
    printf("\n\nPila menor:\n");
    mostrar(&menor);
    return 0;
}
