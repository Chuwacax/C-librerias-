#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Verificar si una pila DADA es capicúa.*/

const char ESC=27;

int main()
{   Pila dada;
    Pila aux;
    Pila basura;
    Pila dada2;
    Pila basura2;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&basura);
    inicpila(&dada2);
    inicpila(&basura2);

    char opcion;
    int i=0;
    int mitad=0;
    int flag=0;

    printf("Cargar la pila dada:\n");
    do{
        leer(&dada);
        printf("Presione ESC para salir.\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");

    while(!pilavacia(&dada)){
        apilar(&aux, desapilar(&dada));
        i++;
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }

    if(i%2==0){
        printf("La pila contiene valores pares.\n");
        i= i/2;
        while(!pilavacia(&dada)&& (float)mitad < i){
            apilar(&dada2, desapilar(&dada));
            mitad++;
        }
    }
    else{
        printf("La pila contiene valores impares.\n");
        i= i/2;
        while(!pilavacia(&dada)&& (float)mitad < i){
            apilar(&dada2, desapilar(&dada));
            mitad++;
        }
        apilar(&aux, desapilar(&dada));
    }

    while(!pilavacia(&dada)&&!pilavacia(&dada2)&& flag==0){
        if(tope(&dada)==tope(&dada2)){
            apilar(&basura, desapilar(&dada));
            apilar(&basura2, desapilar(&dada2));
        }
        else{
            flag=1;
        }
    }

    if(flag==0){
        printf("\n\nLa pila dada es capicua.\n");
    }
    else{
        printf("\n\nLa pila dada no es capicua.\n");
    }

    while(!pilavacia(&basura)){
        apilar(&dada, desapilar(&basura));
    }
    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }
    while(!pilavacia(&basura2)){
        apilar(&dada2, desapilar(&basura2));
    }
    while(!pilavacia(&dada2)){
        apilar(&dada, desapilar(&dada2));
    }

    printf("\n\nPila dada:\n");
    mostrar(&dada);
    return 0;
}
