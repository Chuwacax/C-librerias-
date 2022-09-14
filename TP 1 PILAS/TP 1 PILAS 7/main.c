#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*7. Pasar el último elemento (base) de la pila DADA a su primera posición (tope), dejando los restantes elementos en el mismo orden.*/


int main()
{   Pila dada;
    Pila aux;
    Pila basura;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&basura);

    char opcion='s';
    int i=0;

    do{
        leer(&dada);
        printf("Desea continuar cargando datos en la pila? s/n\n");
        fflush(stdin);
        opcion= getch();
    }
    while(opcion=='s');

    system("pause");
    system("cls");
    printf("Pila dada:\n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        apilar(&aux, desapilar(&dada));
    }

    while(!pilavacia(&aux)&& i<1){
        apilar(&basura, desapilar(&aux));
        i++;
    }
    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }

    while(!pilavacia(&basura)){
        apilar(&dada, desapilar(&basura));
    }

    printf("\nPila dada nueva:\n");
    mostrar(&dada);
    return 0;
}
