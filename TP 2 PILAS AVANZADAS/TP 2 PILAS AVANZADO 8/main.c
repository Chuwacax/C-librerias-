#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en el mismo orden.*/

const char ESC=27;

int main()
{   Pila dada;
    Pila aux;
    Pila eliminado;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&eliminado);

    char opcion;
    int i=0;
    int flag=0;

    printf("Cargar la pila dada.\n");
    do{
        leer(&dada);
        printf("Presione ESC para salir.\n");
        fflush(stdin);
        opcion= getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");

    printf("Ingrese el valor a eliminar:\n");
    scanf("%d", &i);

    printf("\n\nLa pila dada contiene los siguentes datos.\n");
    mostrar(&dada);

    while(!pilavacia(&dada) && flag==0){
        if(tope(&dada)==i){
            apilar(&eliminado, desapilar(&dada));
            flag=1;
        }
        else{
            apilar(&aux, desapilar(&dada));
        }
        while(pilavacia(&dada)&& flag==0){
            printf("El dato ingresado no se encuentra en la pila, vuelva a ingresar un valor.\n");
            scanf("%d", &i);
            while(!pilavacia(&aux)){
                apilar(&dada, desapilar(&aux));
            }
        }
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }
    printf("\n\nPila dada sin el valor %d.\n", i);
    mostrar(&dada);

    return 0;
}
