#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*5. Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga los elementos cargados originalmente en ella, pero en orden inverso.*/

int main()
{   Pila dada;
    Pila aux1;
    Pila aux2;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    char opcion='s';

    do{
        leer(&dada);
        printf("\nDesea continuar cargando? s/n\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion=='s');

    system("pause");
    system("cls");

    printf("Pila dada:\n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        apilar(&aux1, desapilar(&dada));
    }

    while(!pilavacia(&aux1)){
        apilar(&aux2, desapilar(&aux1));
    }

    while(!pilavacia(&aux2)){
        apilar(&dada, desapilar(&aux2));
    }

    printf("Pila dada invertida:\n");
    mostrar(&dada);

    return 0;
}
