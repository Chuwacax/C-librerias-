#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

const char ESC=27;

const int filas=3;
const int columnas=3;

const int filasChar=10;
const int columnasChar=10;

///Encabezados
void cargarMatriz (int matriz[][columnas], int filas, int columnas);
void mostrarMatriz (int matriz[][columnas], int filas, int columnas);
void cargarMatrizRandom (int matriz[][columnas], int filas, int columnas);
int sumarMatriz (int matriz[][columnas], int filas, int columnas);
int contarMatriz (int matriz[][columnas], int filas, int columnas);
float promedioMatriz (int matriz[][columnas], int filas, int columnas);
int buscarDato (int matriz[][columnas], int filas, int columnas, int dato);
int cargarMatrizChar (char matriz[][columnasChar], int filasChar, int columnasChar);
void mostrarMatrizChar (char matriz[][columnasChar], int cantFilas);
int buscarPalabra (int filasChar, char matriz[][columnasChar], char palabra[]);
int palabraMenor (int filasChar, int columnasChar, char matriz[][columnasChar], int pos);
void ordenarPalabras (int filasChar, int columnasChar, char matriz[][columnasChar]);

int main()
{   int matriz[filas][columnas];

    srand(time(NULL));

    int hacer=0;

    do{
        printf("\t\tMATRICES.\n");
        printf("Cargar matriz:\n1)Cargado manual.\n2)Cargado automatico.\n");
        printf("Ingresar: ");
        scanf("%d", &hacer);

        switch(hacer){
            case 1:
                cargarMatriz(matriz, filas, columnas);
                printf("\nMatriz cargada:\n");
                mostrarMatriz(matriz, filas, columnas);
                break;

            case 2:
                cargarMatrizRandom(matriz, filas, columnas);
                printf("\nMatriz cargada automaticamente:\n");
                mostrarMatriz(matriz, filas, columnas);
                break;

            default:
                printf("\nOpcion no valida.\n");
                system("pause");
                system("cls");
        }
    }
    while(hacer!=1 && hacer!=2);

    int suma=0;

    suma= sumarMatriz(matriz, filas, columnas);
    printf("\nLa suma de los elementos de la matriz es: %d.\n", suma);

    float promedio=0;

    promedio= promedioMatriz(matriz, filas, columnas);
    printf("\nEl promedio de los elementos de la matriz es: %.2f.\n", promedio);

    int flag=0;
    int dato=0;

    do{
        printf("\nBUSCAR DATO.\nIngrese el valor a buscar (entre 0 y 9): ");
        scanf("%d", &dato);
        if(dato>=10 || dato<0){
            printf("\nEl valor ingresado no es valido.\n");
        }
    }
    while(dato>=10 || dato<0);

    flag= buscarDato(matriz, filas, columnas, dato);

    if(flag==1){
        printf("\nEl dato buscado se encuentra en la matriz.\n");
    }
    else{
        printf("\nEl dato buscado NO se encuentra en la matriz.\n");
    }

    system("pause");
    system("cls");

    printf("\t\tMATRIZ DE PALABRAS.\n");

    char matrizChar[filasChar][columnasChar];
    int validos=0;

    validos= cargarMatrizChar(matrizChar, filasChar, columnasChar);
    printf("\nLa matriz de palabras:\n");
    mostrarMatrizChar(matrizChar, validos);

    char palabra[columnasChar];

    printf("\nIngrese una palabra a buscar en el arreglo (que contenga menos de %d caracteres): ", columnasChar);
    fflush(stdin);
    gets(palabra);

    flag=buscarPalabra(filasChar, matrizChar, palabra);

    if(flag==1){
        printf("\nLa palabra se encuentra en el arreglo.\n");
    }
    else{
        printf("\nLa palabra NO se encuentra en el arreglo.\n");
    }

    if(validos>1){
        printf("\nPalabras ordenadas por orden alfabetico:\n");
        ordenarPalabras(validos, columnasChar, matrizChar);
        mostrarMatrizChar(matrizChar, validos);
    }
    else{
        printf("\nHay menos de dos strings cargados por lo que no se puede ordenar.\n");
    }
    return 0;
}

///Ejercicio 1
void cargarMatriz (int matriz[][columnas], int filas, int columnas){
    int f=0;
    int c=0;
    int valor=0;

    for(f=0; f<filas; f++){
        for(c=0; c<columnas; c++){
            printf("\nIngrese el valor a cargar en la posicion %d.%d (deben ser valores entre el 0 y el 9):\n", f, c);
            scanf("%d", &matriz[f][c]);
            valor= matriz[f][c];
            if(valor>=10 || valor<0){
                printf("\nEl valor ingresado no es valido.\n");
                c--;
            }
            }
        }
}

///Ejercicio 2
void mostrarMatriz (int matriz[][columnas], int filas, int columnas){
    int f=0;
    int c=0;

    for(f=0; f<filas; f++){
        for(c=0; c<columnas; c++){
            printf(" %d ", matriz[f][c]);
            }
        printf("\n");
    }
}

///Ejercicio 3
void cargarMatrizRandom (int matriz[][columnas], int filas, int columnas){
    int f=0;
    int c=0;

    for(f=0; f<filas; f++){
        for(c=0; c<columnas; c++){
            printf("\nValor generado automaticamente en la posicion %d.%d:\n", f, c);
            matriz[f][c]= rand()%10;
            printf("%d", matriz[f][c]);
            }
        }
}

///Ejercico 4
int sumarMatriz (int matriz[][columnas], int filas, int columnas){
    int suma=0;
    int f=0;
    int c=0;

    for(f=0; f<filas; f++){
        for(c=0; c<columnas; c++){
            suma= suma + matriz[f][c];
        }
    }
    return suma;
}

///Ejercicio 5

int contarMatriz (int matriz[][columnas], int filas, int columnas){
    int contador=0;
    int f=0;
    int c=0;

    for(f=0; f<filas; f++){
        for(c=0; c<columnas; c++){
            contador++;
        }
    }
    return contador;
}

float promedioMatriz (int matriz[][columnas], int filas, int columnas){
    float promedio=0;
    int suma=sumarMatriz(matriz, filas, columnas);
    int contador=contarMatriz(matriz, filas, columnas);

    promedio= (float)suma/(float)contador;

    return promedio;
}

///Ejercicio 6

int buscarDato (int matriz[][columnas], int filas, int columnas, int dato){
    int f=0;
    int c=0;
    int flag=0;

    while(flag==0 && f<filas && c<columnas){
        for(f=0; f<filas; f++){
            for(c=0; c<columnas; c++){
                if(matriz[f][c]==dato){
                    flag=1;
                }
            }
        }
    }
    return flag;
}

///Ejercicio 7

int cargarMatrizChar (char matriz[][columnasChar], int filasChar, int columnasChar){
    int f=0;
    char opcion;

    do{
        printf("\nIngrese una frase a cargar con una longitud menor a %d caracteres (inlcuidos los espacios): ", columnasChar);
        fflush(stdin);
        gets(matriz[f]);
        if(strlen(matriz)>= columnasChar){
            printf("\nLa palabra contiene mas caracteres de los permitidos.\nDebera reemplazar la palabra.");
            f--;
        }
        printf("\nPresione ESC para salir de la carga (cualquier otra tecla para continuar).\n");
        fflush(stdin);
        opcion=getch();
        f++;
    }
    while(opcion!=ESC && f<filasChar);

    return f;
}

///Ejercicio 8
void mostrarMatrizChar (char matriz[][columnasChar], int cantFilas){
    int f=0;

    for(f=0; f<cantFilas; f++){
        printf("%s\n", matriz[f]);
    }
}

///Ejercicio 9
int buscarPalabra (int filasChar, char matriz[][columnasChar], char palabra[]){
    int flag=0;
    int i=0;

    while(i<filasChar && flag==0){
        if(strcmpi(matriz[i], palabra)==0){
            flag=1;
        }
        i++;
    }
    return flag;
}

///Ejercicio 10
int palabraMenor (int cantFilas, int columnasChar, char matriz[][columnasChar], int pos){
    int i;
    int posMenor= pos;
    char menorPalabra[columnasChar];

    strcpy(menorPalabra, matriz[posMenor]);

    for(i=pos+1; i<cantFilas; i++){
        if(strcmpi(matriz[i], menorPalabra)<0){
            strcpy(menorPalabra, matriz[i]);
            posMenor= i;
        }
    }
    return posMenor;
}

void ordenarPalabras (int cantFilas, int columnasChar, char matriz[][columnasChar]){
    int i=0;
    int posMenor=0;
    char aux[columnasChar];

    while(i<cantFilas){
        posMenor=palabraMenor(cantFilas, columnasChar, matriz, i);
        strcpy(aux, matriz[posMenor]);
        strcpy(matriz[posMenor],matriz[i]);
        strcpy(matriz[i], aux);
        i++;
    }
}
