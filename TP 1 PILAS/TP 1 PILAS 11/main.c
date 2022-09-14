#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*11. Suponiendo la existencia de una pila MODELO que no esté vacía, eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO.*/

const char ESC=27;

int main()
{   Pila modelo;
    Pila dada;
    Pila aux;
    Pila basura;

    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&basura);

    char opcion;

    apilar(&modelo,1);
    apilar(&modelo,5);
    apilar(&modelo,3);
    apilar(&modelo,8);
    apilar(&modelo,4);
    apilar(&modelo,6);

    printf("Cargar la pila dada:\n\n");
    do{
        leer(&dada);
        printf("ESC para salir:\n");
        fflush(stdin);
        opcion= getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");

    printf("Pila dada:\n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        if(tope(&dada)==tope(&modelo)){
            apilar(&basura, desapilar(&dada));
        }
        else{
            apilar(&aux, desapilar(&dada));
        }
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }
    printf("\n\nPila modelo:");
    mostrar(&modelo);
    printf("\n\nPila dada sin los elementos iguales al tope de la pila modelo:\n");
    mostrar(&dada);

    return 0;
}
