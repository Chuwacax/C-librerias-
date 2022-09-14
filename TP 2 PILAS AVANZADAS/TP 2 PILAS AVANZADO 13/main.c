#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Suponer un juego de cartas en el que en cada mano se reparten dos cartas por jugador. Un jugador
gana la mano cuando la suma de sus cartas es mayor que las del contrario y al hacerlo coloca todas
las cartas (las de él y las de su rival) en su pila de puntos. En caso de empate (y para simplificar)
siempre gana el jugador1. Simular la ejecución del juego de tal manera que dada una pila MAZO
(con un número de elementos múltiplo de cuatro) distribuya las cartas en las pilas PUNTOSJUG1 y
PUNTOSJUG2 como si estos hubieran jugado. Utilizar las pilas auxiliares que crea conveniente.*/

const char ESC=27;

int main()
{   Pila jug1;
    Pila jug2;
    Pila mazo;
    Pila aux;
    Pila basura;

    inicpila(&jug1);
    inicpila(&jug2);
    inicpila(&mazo);
    inicpila(&aux);
    inicpila(&basura);

    int sumaJug1;
    int sumaJug2;
    int i=0;
    int j=0;
    int carta=0;
    int rondas=0;
    int rondasJug1=0;
    int rondasJug2=0;
    int flag=0;


    char opcion;

    srand(time(NULL));


    carta= (rand()% 12)+1;
    apilar(&mazo, carta);

    printf("\tMezclando cartas.\n");
    system("pause");

    while(i<11){
        carta= (rand() %12) + 1;
        while(!pilavacia(&mazo)){
            if(tope(&mazo)==carta){
                carta=(rand() %12) + 1;
                while(!pilavacia(&aux)){
                    apilar(&mazo, desapilar(&aux));
                }
            }
            else{
                apilar(&aux, desapilar(&mazo));
            }
        }
        while(!pilavacia(&aux)){
            apilar(&mazo, desapilar(&aux));
        }
        apilar(&mazo, carta);
        i++;
    }

    do{
        flag=0;
        j=0;
        sumaJug1=0;
        sumaJug2=0;
        rondas++;
        printf("\n\tRonda numero %d:\n", rondas);
        while(flag==0){
            while(j<2){
                apilar(&jug1, desapilar(&mazo));
                apilar(&jug2, desapilar(&mazo));
                sumaJug1= sumaJug1 + tope(&jug1);
                sumaJug2= sumaJug2 + tope(&jug2);
                j++;
            }

            printf("\n\nCartas del jugador 1:\n");
            mostrar(&jug1);
            printf("\n\nCartas del jugador 2:\n");
            mostrar(&jug2);

            if(sumaJug1>=sumaJug2){
                printf("\n\nEl jugador 1 sumo %d puntos y el jugador 2 sumo %d. El jugador 1 es el ganador de la ronda %d.", sumaJug1, sumaJug2, rondas);
                rondasJug1++;

            }
            else{
                printf("\n\nEl jugador 2 sumo %d puntos y el jugador 1 sumo %d. El jugador 2 es el ganador de la ronda %d.", sumaJug2, sumaJug1, rondas);
                rondasJug2++;
            }
            flag=1;
        }

        printf("\n\nEl jugador 1 lleva ganadas %d rondas y el jugador 2 lleva ganadas %d rondas.", rondasJug1, rondasJug2);

        printf("\n\nPresione ESC para salir del juego.\n\n");
        fflush(stdin);
        opcion=getch();
        system("pause");
        system("cls");
        }
    while(opcion!=ESC && !pilavacia(&mazo));

    printf("NO QUEDAN MAS CARTAS EN EL MAZO.\n");
    return 0;
}
