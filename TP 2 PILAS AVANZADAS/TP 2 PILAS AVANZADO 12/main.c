#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.*/

const char ESC=27;

int main()
{   Pila origen;
    Pila aux;
    Pila menor;

    inicpila(&origen);
    inicpila(&aux);
    inicpila(&menor);

    char opcion;

    printf("Cargar la pila origen.\n");
    do{
        leer(&origen);
        printf("Presionar ESC para salir.\n");
        fflush(stdin);
        opcion= getch();
    }
    while(opcion!=ESC);

    system("pause");
    system("cls");

    printf("Pila origen cargada:\n");
    mostrar(&origen);

    while(!pilavacia(&origen)){
        apilar(&menor, desapilar(&origen));
         while(!pilavacia(&origen)){
            if(tope(&origen)<tope(&menor)){
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&origen));
            }
            else{
                apilar(&aux, desapilar(&origen));
            }
         }
         while(!pilavacia(&aux)){
            apilar(&origen, desapilar(&aux));
         }
    }
    while(!pilavacia(&menor)){
        apilar(&origen, desapilar(&menor));
    }
    printf("\n\nPila origen ordenada de menor a mayor:\n");
    mostrar(&origen);
    return 0;
}
