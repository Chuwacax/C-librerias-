#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión.*/

const char ESC=27;

int main()
{   Pila pilaA;
    Pila pilaB;
    Pila pilaC;
    Pila auxA;
    Pila auxB;

    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&pilaC);
    inicpila(&auxA);
    inicpila(&auxB);

    int num=0;
    char opcion;

    printf("Cargar la pila a:\n");
    do{
        leer(&pilaA);
        printf("Presione ESC para salir.\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");

     printf("Cargar la pila b:\n");
    do{
        leer(&pilaB);
        printf("Presione ESC para salir.\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");

    while(!pilavacia(&pilaA)){
            while(!pilavacia(&pilaB)){
                if(tope(&pilaA)==tope(&pilaB)){
                    num= tope(&pilaB);
                    apilar(&pilaC, num);
                    apilar(&auxB, desapilar(&pilaB));
                }
                else{
                    apilar(&auxB, desapilar(&pilaB));
                }
            }
            while(!pilavacia(&auxB)){
                apilar(&pilaB, desapilar(&auxB));
            }
            apilar(&auxA, desapilar(&pilaA));
    }

    while(!pilavacia(&auxA)){
        apilar(&pilaA, desapilar(&auxA));
    }

    printf("Pila a:\n");
    mostrar(&pilaA);
    printf("\n\nPila b:\n");
    mostrar(&pilaB);
    printf("\n\nPila c:\n");
    mostrar(&pilaC);

    return 0;
}
