#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.*/

int main()
{   Pila origen;
    Pila destino;

    char opcion='s';

    inicpila(&origen);
    inicpila(&destino);

    do{
        leer(&origen);
        printf("\nDesea seguir cargando la pila? s/n:\t");
        fflush(stdin);
        scanf("%c", &opcion);
        system("pause");
        system("cls");
    }
    while(opcion=='s');

    printf("\nPila origen cargada:\n");
    mostrar(&origen);

    while(!pilavacia(&origen)){
        apilar(&destino, desapilar(&origen));
    }

    printf("\nPila origen:\n");
    mostrar(&origen);
    printf("\nPila destino:\n");
    mostrar(&destino);

    return 0;
}
