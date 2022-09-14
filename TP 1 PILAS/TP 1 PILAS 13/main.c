#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*13. Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores
o iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES.*/

const   char ESC=27;

int main()
{   Pila limite;
    Pila dada;
    Pila mayores;
    Pila menores;

    inicpila(&limite);
    inicpila(&dada);
    inicpila(&menores);
    inicpila(&mayores);

    char opcion;

    apilar(&limite,1);
    apilar(&limite,4);
    apilar(&limite,3);
    apilar(&limite,5);
    apilar(&limite,6);
    apilar(&limite,8);
    apilar(&limite,3);

    printf("Cargar pila dada.\n");
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
        if(tope(&dada)>=tope(&limite)){
            apilar(&mayores, desapilar(&dada));
        }
        else{
            apilar(&menores, desapilar(&dada));
        }
    }

    printf("\n\nPila limite:\n");
    mostrar(&limite);
    printf("\n\nPila menores:\n");
    mostrar(&menores);
    printf("\n\nPila mayores o iguales:\n");
    mostrar(&mayores);

    return 0;
}
