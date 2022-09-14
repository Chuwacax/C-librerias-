#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*4. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden.*/

int main()
{   Pila origen;
    Pila destino;
    Pila aux;
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux);

    char opcion='s';

    do{
        leer(&origen);
        printf("Desea seguir cargando? s/n\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion=='s');

    system("pause");
    system("cls");
    printf("Pila origen:\n");
    mostrar(&origen);

    while(!pilavacia(&origen)){
        apilar(&aux, desapilar(&origen));
    }
    while(!pilavacia(&aux)){
        apilar(&destino, desapilar(&aux));
    }

    printf("Pila origen:\n");
    mostrar(&origen);
    printf("Pila destino\n");
    mostrar(&destino);

    return 0;
}
