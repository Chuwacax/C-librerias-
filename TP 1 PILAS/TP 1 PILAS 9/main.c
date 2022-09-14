#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.*/

const char ESC=27;

int main()
{   Pila a;
    Pila b;
    Pila auxA;
    Pila auxB;

    inicpila(&a);
    inicpila(&b);
    inicpila(&auxA);
    inicpila(&auxB);

    char opcion;

    printf("Pila a:\n");

    do{
        leer(&a);
        printf("ESC para salir de la pila a:\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");

    printf("Pila b:\n");

    do{
        leer(&b);
        printf("ESC para salir de la pila b:\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");

    while(!pilavacia(&a)&&!pilavacia(&b)){
        apilar(&auxA, desapilar(&a));
        apilar(&auxB, desapilar(&b));
    }
    if(!pilavacia(&a)){
        while(!pilavacia(&a)){
            apilar(&auxA, desapilar(&a));
        }
        printf("La pila a tiene mas datos\n");
    }
    else if (!pilavacia(&b)) {
        while(!pilavacia(&b)){
            apilar(&auxB, desapilar(&b));
        }
        printf("La pila b tiene mas datos\n");
    }

    else{
        printf("Ambas tienen la misma cantidad de datos");
    }

    while(!pilavacia(&auxA)){
        apilar(&a, desapilar(&auxA));
    }

    while(!pilavacia(&auxB)){
        apilar(&b, desapilar(&auxB));
    }

    printf("\nPila a:\n");
    mostrar(&a);
    printf("\nPila b:\n");
    mostrar(&b);
    return 0;
}
