#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*14. Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR.*/

const char ESC=27;

int main()
{   Pila dada;
    Pila aux;
    Pila par;
    Pila impar;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&par);
    inicpila(&impar);

    char opcion;

    printf("Cargar pila dada:\n");
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

    if(!pilavacia(&dada)){
        while(!pilavacia(&dada)){
            apilar(&aux, desapilar(&dada));
            if(!pilavacia(&dada)){
                apilar(&aux, desapilar(&dada));
                if(pilavacia(&dada)){
                    printf("\n\nLa pila contiene una cantidad par de elementos.\n\n");
                    apilar(&par, desapilar(&aux));
                }
            }
            else{
                printf("\n\nLa pila dada contiene una cantidad impar de elementos.\n\n");
                apilar(&impar, desapilar(&aux));
            }
        }
    }
    else{
        printf("\n\nLa pila no contiene datos.\n\n");
    }

    printf("\n\nPila par:\n");
    mostrar(&par);
    printf("\n\nPila impar:\n");
    mostrar(&impar);
    return 0;
}
