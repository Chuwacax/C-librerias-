#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*10. Comparar las pilas A y B, evaluando si son completamente iguales (en cantidad de elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado.*/

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
        printf("ESC si desea salir de la pila a:\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");

     do{
        leer(&b);
        printf("ESC si desea salir de la pila b:\n");
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
        printf("\n\nLa pila a tiene mas datos.\n\n");
    }
    else if(!pilavacia(&b)){
        while(!pilavacia(&b)){
            apilar(&auxB, desapilar(&b));
        }
        printf("\n\nLa pila b tiene mas datos.\n\n");
    }
    else{
        printf("\n\nTienen la misma cantidad de datos.\n\n");
    }

    while(!pilavacia(&auxA)&&!pilavacia(&auxB)&&tope(&auxA)==tope(&auxB)){
            apilar(&a, desapilar(&auxA));
            apilar(&b, desapilar(&auxB));
    }

    if(pilavacia(&auxA)&&pilavacia(&auxB)){
        printf("Sus datos son iguales en todas sus posiciones.\n\n");
    }
    else {
        printf("Sus valores no son iguales en todas sus posiciones.\n\n");
    }

    return 0;
}
