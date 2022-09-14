#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*6. Pasar el primer elemento (tope) de la pila DADA a su última posición (base), dejando los restantes elementos en el mismo orden.*/

int main()
{   Pila dada;
    Pila aux1;
    Pila basura;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&basura);

    char opcion='s';

    do{
        leer(&dada);
        printf("\nDesea continuar cargando? s/n\n");
        fflush(stdin);
        opcion= getch();
    }
    while(opcion=='s');

    system("pause");
    system("cls");
    printf("Pila dada:\n");
    mostrar(&dada);

    apilar(&basura,desapilar(&dada));

    while(!pilavacia(&dada)){
        apilar(&aux1, desapilar(&dada));
    }

    while(!pilavacia(&basura)){
        apilar(&dada, desapilar(&basura));
    }

    while(!pilavacia(&aux1)){
        apilar(&dada, desapilar(&aux1));
    }

    printf("\nPila dada nueva:\n");
    mostrar(&dada);
    return 0;
}
