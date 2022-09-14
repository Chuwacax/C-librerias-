#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

const char ESC=27;

void cargarPila (Pila *a);
void pasarPila (Pila *a, Pila *b);
void copiarPila (Pila a, Pila *copia);
int encontrarMenor (Pila *a);
void pilaOrdenada (Pila *a, Pila *ordenada);
void insertarElemento (Pila *a, Pila *nuevoElemento);
void cargarPilaOrdenada (Pila *a, Pila *b);
int sumarLosPrimerosDos (Pila a);
int sumarPila (Pila a);
int cantidadDeElementos (Pila a);
float promedio (int a, int b);
int numDecimal (Pila *a);

int main()
{   int opcion=0;
    char salir;

    Pila dada;
    inicpila(&dada);

    Pila dada2;
    Pila aux2;
    inicpila(&dada2);
    inicpila(&aux2);

    Pila dada3;
    Pila copia3;
    inicpila(&dada3);
    inicpila(&copia3);

    Pila dada4;
    inicpila(&dada4);
    int menor=0;

    Pila dada5;
    Pila ordenada5;
    inicpila(&dada5);
    inicpila(&ordenada5);

    Pila dada6;
    Pila ordenada6;
    Pila elemento6;
    inicpila(&dada6);
    inicpila(&ordenada6);
    inicpila(&elemento6);

    Pila dada7;
    Pila nuevaOrdenada7;
    inicpila(&dada7);
    inicpila(&nuevaOrdenada7);

    Pila dada8;
    inicpila(&dada8);
    int sumaDosPrimeros=0;

    Pila dada9;
    inicpila(&dada9);
    int sumaPila=0;
    int i=0;
    float prom=0;

    Pila crearDecimal;
    inicpila(&crearDecimal);
    int valorDecimal=0;

    do{
        system("cls");
        printf("Menu de opciones.\n");
        printf("1. Hacer una funcion que permita ingresar varios elementos a una Pila, tantos como quiera el usuario.\n");
        printf("2. Hacer una funcion que pase todos los elementos de una pila a otra.\n");
        printf("3. Hacer una funcion que pase todos los elementos de una pila a otra, pero conservando el orden.\n");
        printf("4. Hacer una funcion que encuentre el menor elemento de una pila y lo retorne. La misma debe eliminar ese dato de la pila.\n");
        printf("5. Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funcion del ejercicio 4. (Ordenamiento por seleccion).\n");
        printf("6. Hacer una funcion que inserte en una pila ordenada un nuevo elemento, conservando el orden de esta.\n");
        printf("7. Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funcion del ejercicio 6.  (Ordenamiento por insercion).\n");
        printf("8. Hacer una funcion que sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar su contenido.\n");
        printf("9. Hacer una funcion que calcule el promedio de los elementos de una pila.\n");
        printf("10. Hacer una funcion que reciba una pila con numeros de un solo digito, y que transforme esos digitos en un numero decimal.\n");
        printf("\nEjercicio:\t");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                cargarPila(&dada);
                printf("\nPila dada:\n");
                mostrar(&dada);
                break;

            case 2:
                cargarPila(&dada2);
                printf("La pila dada2:\n");
                mostrar(&dada2);
                pasarPila(&dada2, &aux2);
                printf("\n\nSe paso la pila dada2 a aux2:\n");
                mostrar(&aux2);
                break;

            case 3:
                cargarPila(&dada3);
                printf("Pila dada3:\n");
                mostrar(&dada3);
                copiarPila(dada3, &copia3);
                printf("\n\nCopia de la pila dada3:\n");
                mostrar(&copia3);
                break;

            case 4:
                cargarPila(&dada4);
                printf("Pila dada4:\n");
                mostrar(&dada4);
                menor=encontrarMenor(&dada4);
                printf("\n\nEL menor valor de la pila es: %d", menor);
                printf("\n\nLa pila queda de la siguiente manera sin su menor dato.\n");
                mostrar(&dada4);
                break;

            case 5:
                cargarPila(&dada5);
                printf("Pila dada5:\n");
                mostrar(&dada5);
                pilaOrdenada(&dada5, &ordenada5);
                printf("\n\nLa pila ordenada queda de la siguiente manera:\n");
                mostrar(&ordenada5);
                break;

            case 6:
                cargarPila(&dada6);
                printf("Pila dada6:\n");
                mostrar(&dada6);
                pilaOrdenada(&dada6, &ordenada6);
                printf("\n\nElemento a insertar en la pila ordenada:\n");
                leer(&elemento6);
                insertarElemento(&ordenada6, &elemento6);
                printf("\n\n Pila ordenada6 con el nuevo elemento:\n");
                mostrar(&ordenada6);
                break;

            case 7:
                cargarPilaOrdenada(&dada7, &nuevaOrdenada7);
                printf("La nueva pila ordenada7 es:\n");
                mostrar(&nuevaOrdenada7);
                break;

            case 8:
                cargarPila(&dada8);
                printf("Pila dada8:\n");
                mostrar(&dada8);
                sumaDosPrimeros= sumarLosPrimerosDos(dada8);
                printf("\n\nLa suma de los dos primeros valores de la pila dada8 es: %d.", sumaDosPrimeros);
                printf("\n\nLa pila dada8 no sufre modificaciones.\n");
                mostrar(&dada8);
                break;

            case 9:
                cargarPila(&dada9);
                printf("Pila dada9:");
                mostrar(&dada9);

                sumaPila= sumarPila(dada9);
                printf("\n\nLa suma de los elementos de la pila dada9 es: %d.", sumaPila);

                i= cantidadDeElementos(dada9);
                printf("\n\nLa pila dada9 cuenta con %d elementos.", i);

                prom= promedio(sumaPila, i);
                printf("\n\nEl promedio de los elementos de la pila dada9 es: %.2f.", prom);

                printf("\n\nLa pila dada9 no sufre modificaciones.\n");
                mostrar(&dada9);
                break;

            case 10:
                printf("Por favor, solo ingrese valores enteros de un digito.\n");

                valorDecimal= numDecimal(&crearDecimal);

                printf("El valor decimal creado con la pila es: %d.", valorDecimal);

                printf("\n\nLa pila crearDecimal queda de la siguiente manera:\n");
                mostrar(&crearDecimal);
                break;

            default:
                printf("La opcion que ingreso es incorrecta.\n");
                break;
        }
        printf("\nESC para salir (presione cualquier tecla para continuar).\n");
        fflush(stdin);
        salir=getch();
    }
    while (salir!=ESC);


    return 0;
}

///*1. Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el usuario.

void cargarPila (Pila *a){
    char opcion;

    do{
        leer(a);
        printf("\nPresione s si desea seguir cargando la pila: s/n\n\n");
        fflush(stdin);
        opcion= getch();
    }
    while(opcion=='s');
}

///*2. Hacer una función que pase todos los elementos de una pila a otra.

void pasarPila (Pila *a, Pila *b){
    while(!pilavacia(a)){
        apilar(b, desapilar(a));
    }
}

///*3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.

void copiarPila (Pila a, Pila *copia){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&a)){
        apilar(&aux, desapilar(&a));
    }
    while(!pilavacia(&aux)){
        apilar(copia, desapilar(&aux));
    }
}

///*4. Hacer una función que encuentre el menor elemento de una pila y lo retorne. La misma debe eliminar ese dato de la pila.

int encontrarMenor (Pila *a){
    Pila pilaMenor;
    Pila aux;
    inicpila(&pilaMenor);
    inicpila(&aux);

    int menor;

    apilar(&pilaMenor, desapilar(a));

    while(!pilavacia(a)){
        if(tope(a)< tope(&pilaMenor)){
            apilar(&aux, desapilar(&pilaMenor));
            apilar(&pilaMenor, desapilar(a));
        }
        else{
            apilar(&aux, desapilar(a));
        }
    }
    while(!pilavacia(&aux)){
        apilar(a, desapilar(&aux));
    }
    menor= tope(&pilaMenor);

    return menor;
}

///*5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)

void pilaOrdenada (Pila *a, Pila *ordenada){
    int menor=0;

    while(!pilavacia(a)){
        menor=encontrarMenor(a);
        apilar(ordenada, menor);
    }
}

///*6. Hacer una función que inserte en una pila ordenada un nuevo elemento, conservando el orden de ésta.

void insertarElemento (Pila *a, Pila *nuevoElemento){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(nuevoElemento)){
        if(pilavacia(a) || tope(a)< tope(nuevoElemento)){
            apilar(a, desapilar(nuevoElemento));
        }
        else{
            apilar(&aux, desapilar(a));
        }
    }
    while(!pilavacia(&aux)){
        apilar(a, desapilar(&aux));
    }
}

///*7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción)

void cargarPilaOrdenada (Pila *a, Pila *b){
    char opcion;

    printf("Cargar una nueva pila:\n");
    do{
        leer(a);
        insertarElemento(b,a);
        printf("\n\nDesea continuar cargando? s/n\n");
        fflush(stdin);
        opcion= getch();
    }
    while(opcion=='s');
}

///*8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar su contenido.

int sumarLosPrimerosDos (Pila a){
    int suma=0;
    int i=0;

    while(!pilavacia(&a)&& i<2){
        suma= suma + desapilar(&a);
        i++;
    }

    return suma;
}

///*9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también
/// una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones,
/// y la función que calcula el promedio invoca a las otras 3.

int sumarPila (Pila a){
    Pila aux;
    inicpila(&aux);

    int suma=0;

    while(!pilavacia(&a)){
        suma= suma + tope(&a);
        apilar(&aux, desapilar(&a));
    }
    return suma;
}

int cantidadDeElementos (Pila a){
    Pila aux;
    inicpila(&aux);

    int i=0;

    while(!pilavacia(&a)){
        apilar(&aux, desapilar(&a));
        i++;
    }
    return i;
}

float promedio (int a, int b){
    float prom=0;

    prom= (float)a / (float)b;

    return prom;
}

///*10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de quien usa el programa)
/// y que transforme esos dígitos en un número decimal. Por ejemplo, la pila:

int numDecimal (Pila *a){
    Pila aux;
    inicpila(&aux);

    int i=0;
    int multiplicador=1;
    int valorDecimal=0;

    cargarPila(a);

    while(!pilavacia(a)){
        apilar(&aux, desapilar(a));
    }

    while(!pilavacia(&aux)){
        valorDecimal= valorDecimal + (tope(&aux) * multiplicador);
        apilar(a, desapilar(&aux));
        multiplicador= multiplicador * 10;
    }
   return valorDecimal;
}
