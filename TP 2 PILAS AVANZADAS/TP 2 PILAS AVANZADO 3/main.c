#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Calcular el promedio de los valores de una pila (usar variables)*/

const char ESC=27;

int main()
{   Pila dada;
    Pila aux;

    inicpila(&dada);
    inicpila(&aux);

    int i=0;
    int suma=0;
    float promedio=0;

    char opcion;

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
        suma= suma + tope(&dada);
        apilar(&aux, desapilar(&dada));
    }
    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
        i++;
    }

    promedio= (float)suma / (float)i;

    printf("El promedio de los elementos cargados en la pila dada es de: %.2f", promedio);
    printf("\n\nPila dada:\n");
    mostrar(&dada);

    return 0;
}
