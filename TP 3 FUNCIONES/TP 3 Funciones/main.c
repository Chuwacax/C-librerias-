#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

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
{   Pila dada;
    Pila aux;
    Pila copia;
    Pila ordenada;
    Pila elemento;
    Pila nueva;
    Pila nuevaOrdenada;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&copia);
    inicpila(&ordenada);
    inicpila(&elemento);
    inicpila(&nueva);
    inicpila(&nuevaOrdenada);

    ///1)
    cargarPila(&dada);
    printf("\nPila dada:\n");
    mostrar(&dada);

    system("pause");
    system("cls");

    ///2)
    pasarPila(&dada, &aux);
    printf("Pila aux:\n");
    mostrar(&aux);

    ///3)
    copiarPila(aux, &copia);
    printf("\n\nCopia de la pila aux:\n");
    mostrar(&copia);

    ///4)
    int menor=0;

    menor=encontrarMenor(&aux);
    printf("\n\nEL menor valor de la pila es: %d", menor);
    printf("\n\nLa pila queda de la siguiente manera sin su menor dato.\n");
    mostrar(&aux);

    ///5)
    pilaOrdenada(&aux, &ordenada);
    printf("\n\nLa pila ordenada queda de la siguiente manera:\n");
    mostrar(&ordenada);

    ///6)
    printf("\n\nElemento a insertar en la pila ordenada:\n");
    leer(&elemento);
    insertarElemento(&ordenada, &elemento);
    printf("\n\n Pila ordenada con el nuevo elemento:\n");
    mostrar(&ordenada);

    system("pause");
    system("cls");

    ///7)
    cargarPilaOrdenada(&nueva, &nuevaOrdenada);
    printf("La nueva pila ordenada es:\n");
    mostrar(&nuevaOrdenada);

    ///8)
    int sumaDosPrimeros=0;

    sumaDosPrimeros= sumarLosPrimerosDos(nuevaOrdenada);
    printf("\n\nLa suma de los dos primeros valores de la pila nuevaOrdenada es: %d.", sumaDosPrimeros);
    printf("\n\nLa pila nuevaOrdenada no sufre modificaciones.\n");
    mostrar(&nuevaOrdenada);

    ///9)
    int sumaPila=0;

    sumaPila= sumarPila(nuevaOrdenada);
    printf("\n\nLa suma de los elementos de la pila nuevaOrdenada es: %d.", sumaPila);

    int i=0;

    i= cantidadDeElementos(nuevaOrdenada);
    printf("\n\nLa pila nuevaOrdenada cuenta con %d elementos.", i);

    float prom=0;

    prom= promedio(sumaPila, i);
    printf("\n\nEl promedio de los elementos de la pila nuevaOrdenada es: %.2f.", prom);

    printf("\n\nLa pila nuevaOrdenada no sufre modificaciones.\n");
    mostrar(&nuevaOrdenada);

    system("pause");
    system("cls");

    ///10)
    Pila crearDecimal;
    inicpila(&crearDecimal);

    int valorDecimal=0;

    printf("Por favor, solo ingrese valores enteros de un digito.\n");	

    valorDecimal= numDecimal(&crearDecimal);

    printf("El valor decimal creado con la pila es: %d.", valorDecimal);

    printf("\n\nLa pila crearDecimal queda de la siguiente manera:\n");
    mostrar(&crearDecimal);


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
