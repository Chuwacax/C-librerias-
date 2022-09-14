#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la búsqueda.*/

const char ESC=27;

int main()
{   Pila dada;
    Pila aux;

    inicpila(&dada);
    inicpila(&aux);

    char opcion;
    int i=0;
    int flag=0;

    printf("Cargar pila dada:\n");
    do{
        leer(&dada);
        printf("Presione ESC para salir.\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");

    printf("Ingrese el valor a encontrar:\n");
    scanf("%d", &i);

    while(!pilavacia(&dada)&&flag==0){
        if(tope(&dada)==i){
            flag=1;
        }
        else{
            apilar(&aux, desapilar(&dada));
        }
    }
    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }

    system("pause");
    system("cls");

    if(flag==1){
        printf("El valor %d se encuentra en la pila dada.\n", i);
    }
    else{
        printf("El valor %d no se encuentra en la pila dada.\n", i);
    }

    printf("\n\nPila dada:\n");
    mostrar(&dada);
    return 0;
}
