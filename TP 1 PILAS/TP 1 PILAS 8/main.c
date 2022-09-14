#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

const char ESC=27;
/*8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.*/

int main()
{   Pila mazo;
    Pila jugador1;
    Pila jugador2;

    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);

    char opcion;
    int i=0;
    do{
        leer(&mazo);
        printf("Presione ESC para salir.\n");
        fflush(stdin);
        opcion= getch();
        i++;
    }
    while(opcion!=ESC);

    printf("El mazo contiene:\n");
    mostrar(&mazo);

    while(!pilavacia(&mazo)){
        if(i%2==0){
        apilar(&jugador1, desapilar(&mazo));
        }
        else{
        apilar(&jugador2, desapilar(&mazo));
        }
        i--;
    }

    printf("Jugador nuermo 1:\n");
    mostrar(&jugador1);
    printf("Jugador nuermo 2:\n");
    mostrar(&jugador2);
    return 0;
}
