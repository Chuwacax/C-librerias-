#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>

///Defino a ESC como una constante para poder salir de un bucle de carga.
const char ESC=27;
///Declaro la dimension constante lo que permite hacer solo una modificacion del sistema.
const int dimension=20;
const int dimensionCaract=20;
const int dimensionNuevoCaract=30;

///Encabezados
int cargarArreglo (int A[], int dimension);
void mostrarArreglo (int A[], int validos);
int sumaArreglo (int A[], int validos);
void copiarArreglo (int A[], int validos, Pila *dada);
float cargarArregloReales (float arreglo[], int dimension);
void mostrarArregloReales (float arreglo[], int validos);
float sumaArregloReales (float arreglo[], int validos);
int cargarArregloCaracteres (char arreglo[], int dimension);
void mostrarArregloCaracteres (char arreglo[], int validos);
int buscarDato (char arreglo[], int validos, char dato);
void ordenarDatoChar (char arreglo[], int pos, char datoChar);
void ordenarArregloChar(char arreglo[], int validos);
char caracterMasGrande (char arreglo[], int validos);
int arregloCapicua (int arreglo[], int validos);
void invertirArreglo (int arreglo [], int validos);
int posicionMenor (int arreglo[], int pos, int validos);
void ordenarArregloPorSeleccion (int arreglo[], int validos);
void insertarDato (int arreglo[], int pos, int dato);
void ordenarArregloPorInsercion(int arreglo[], int validos);
int crearNuevoArreglo(char primerArreglo[], int primerValidos, char segundoArreglo[], int segundoValidos, char nuevoArreglo[], int dim);

int main()
{   int opcion=0;
    char salir;

    int arregloEnteros [dimension];
    int validos=0;

    int suma=0;

    Pila dada;
    inicpila(&dada);


    float arregloReales [10];
    int validosReales=0;
    srand(time(NULL)); ///Permite que la funcion rand() arroje numeros randoms en funcion del reloj.
    float sumaReales=0;

    char arregloCaracteres[dimensionCaract]; ///Se creo una dimension para los arreglos de caracteres para poder modificar su valor sin modificar la de numeros enteros o reales.
    char caracter;
    int flag=0;

    int i=0;

    int orden=0;

    char arregloCaracteresDos[dimensionCaract];
    int validosDos=0;
    char arregloCaracteresNuevo[dimensionNuevoCaract]; ///Dimension creada para arreglos compuestos de otros arreglos, tambien se puede modificarse ya que esta creada como una constante.
    int validosNuevo=0;

    do{
        system("cls");
        printf("\tMenu de opciones.\n");
        printf("1. Hacer una funcion que reciba como parametro un arreglo de numeros enteros y permita que el usuario ingrese valores al mismo por teclado. La funcion debe retornar la cantidad de elementos cargados en el arreglo.\n");
        printf("2. Hacer una funcion que reciba como parametro un arreglo y la cantidad de elementos (validos) cargados en el y los muestre por pantalla.\n");
        printf("3. Hacer una funcion que reciba como parametro un arreglo y la cantidad de elementos (validos) cargados en el y calcule la suma de sus elementos.\n");
        printf("4. Hacer una funcion que reciba como parametro un arreglo, la cantidad de elementos (validos) cargados en el y una Pila. La funcion debe copiar los elementos del arreglo en la pila.\n");
        printf("5. Realizar una funcion que sume los elementos de un arreglo numeros reales de dimension 100.\n");
        printf("6. Realizar una funcion que indique si un elemento dado se encuentra en un arreglo de caracteres.\n");
        printf("7. Realizar una funcion que inserte un caracter en un arreglo ordenado alfabeticamente, conservando el orden.\n");
        printf("8. Realizar una funcion que obtenga el maximo carácter de un arreglo dado.\n");
        printf("9. Realizar una funcion que determine si un arreglo es capicua.\n");
        printf("10. Realizar una funcion que invierta los elementos de un arreglo.\n");
        printf("11. Ordenar un arreglo segun los siguientes metodos:\n\t1) Seleccion.\n\t2) Insercion.\n");
        printf("12. Dados dos arreglos ordenados alfabeticamente, crear un tercer arreglo con los elementos de los dos primeros intercalados, de manera que quede un arreglo también ordenado alfabeticamente.\n");
        printf("\nEjercicio:\t");
        fflush(stdin);
        scanf("%d", &opcion);

        ///Menu que en base a la variable "opcion" realiza un comando.
        switch(opcion){
            case 1:
                system("cls");
                printf("Ejercicio 1 y 2:\n");
                validos= cargarArreglo(arregloEnteros, dimension);
                system("pause");
                system("cls");

                printf("El arreglo quedo cargado de la siguiente manera:\n\n");
                mostrarArreglo(arregloEnteros, validos);

                break;

            case 2:
                system("cls");
                printf("Ejercicio 1 y 2:\n");
                validos= cargarArreglo(arregloEnteros, dimension);
                system("pause");
                system("cls");

                printf("El arreglo quedo cargado de la siguiente manera:\n\n");
                mostrarArreglo(arregloEnteros, validos);

                break;

            case 3:
                system("cls");
                printf("Ejercicio 3:\n");
                validos= cargarArreglo(arregloEnteros, dimension);
                system("pause");
                system("cls");

                printf("El arreglo quedo cargado de la siguiente manera:\n\n");
                mostrarArreglo(arregloEnteros, validos);

                suma= sumaArreglo(arregloEnteros, validos); ///Variable de valores enteros.
                printf("\n\nLa suma de los elementos del arreglo es: %d.", suma);

                break;

            case 4:
                system("cls");
                printf("Ejercicio 4:\n");
                validos= cargarArreglo(arregloEnteros, dimension);
                system("pause");
                system("cls");

                printf("El arreglo quedo cargado de la siguiente manera:\n\n");
                mostrarArreglo(arregloEnteros, validos);

                copiarArreglo(arregloEnteros, validos, &dada); ///Se utiliza el "&" ya que la pila sufre modificaciones (se la esta cargando).
                printf("\n\nPila que contiene los valores del arreglo:\n");
                mostrar(&dada);

                break;

            case 5:
                system("cls");
                printf("Ejercicio 5:\n");
                validosReales= cargarArregloReales(arregloReales, 10); ///Se llama a la variable float para poder recibir valores decimales.

                printf("\nEl arreglo de reales queda cargado de la siguiente manera:\n\n");
                mostrarArregloReales(arregloReales, validosReales);

                sumaReales= sumaArregloReales(arregloReales, validosReales); ///Variable float que recibe el valor que envia la funcion, ese valor es un numero real.
                printf("\n\nLa suma de los valores reales del arreglo es: %.2f", sumaReales);

                break;

            case 6:
                system("cls");
                printf("Ejercicio 6:\n");
                validos=cargarArregloCaracteres(arregloCaracteres, dimensionCaract); ///Se utiliza la misma variable que antes ya que por mas que es un arreglo char, la cantidad de elementos cargados es un valor entero.
                system("pause");
                system("cls");

                printf("Ingrese el caracter a buscar:\n");
                scanf("%c", &caracter); ///Caracter que se debe buscar en el arreglo.

                flag=buscarDato(arregloCaracteres, validos, caracter); ///Flag toma el valor que arroja la funcion.
                if(flag==1){ ///Si el valor de flag es 1 entonces el caracter se encuentra en el arreglo.
                    printf("\n\nEl caracter a buscar se encuentra en el arreglo.\n\n");
                }
                else{ ///Si flag es 0 entonces el caracter no se encuentra en el arreglo.
                    printf("\n\nEl caracter a buscar NO se encuentra en el arreglo.\n\n");
                }

                printf("\nEl arreglo de caracteres esta cargado de la siguente manera:\n\n");
                mostrarArregloCaracteres(arregloCaracteres, validos);

                break;

            case 7:
                system("cls");
                printf("Ejercicio 7:\n");
                validos=cargarArregloCaracteres(arregloCaracteres, dimensionCaract); ///Cargo el arreglo.
                system("pause");
                system("cls");

                printf("El arreglo de caracteres esta cargado de la siguente manera:\n\n");
                mostrarArregloCaracteres(arregloCaracteres, validos);

                ordenarArregloChar(arregloCaracteres, validos); ///Ordeno el arreglo, para luego solicitar que se cargue un caracter nuevo.
                printf("\n\nEl arreglo de caracteres ordenado alfabeticamente:\n\n");
                mostrarArregloCaracteres(arregloCaracteres, validos);

                printf("\n\nIngrese el caracter que desea cargar en el arreglo:\n");
                scanf("%c", &caracter);

                if(dimension>validos){ ///Entra si el arreglo no esta cargado por completo.
                    i= validos; ///Toma la posicion de validos que es el primer lugar sin datos cargados.
                    arregloCaracteres[i]=caracter; ///El caracter cargado por teclado se le asigna al primer lugar vacio del arreglo.
                    validos++; ///Actualizo la cantidad de elementos del arreglo.
                    ordenarArregloChar(arregloCaracteres, validos); ///Ordeno el arreglo con el nuevo caracter cargado.
                    printf("\n\nEl arreglo de caracteres con el nuevo dato queda cargador de la siguiente manera:\n\n");
                    mostrarArregloCaracteres(arregloCaracteres, validos);
                }
                else{ ///Si validos es igual a dimension el arreglo no podra recibir mas elementos.
                    printf("\n\nEl arreglo ya se encuentra cargado por completo.\n\n");
                }

                break;

            case 8:
                system("cls");
                printf("Ejercicio 8:\n");
                validos= cargarArregloCaracteres(arregloCaracteres, dimension);
                system("pause");
                system("cls");

                caracter= caracterMasGrande(arregloCaracteres, validos); ///Asigno varible char para que tome el caracter que arroja la funcion.
                printf("El maximo caracter del arreglo es: %c", caracter);

                printf("\n\nEl arreglo es el siguiente:\n\n");
                mostrarArregloCaracteres(arregloCaracteres, validos);

                break;

            case 9:
                system("cls");
                printf("Ejercicio 9:\n");
                validos= cargarArreglo(arregloEnteros, dimension);
                system("pause");
                system("cls");

                flag=arregloCapicua(arregloEnteros, validos); ///Flag toma el valor que arroja la funcion, que puede ser 1 o 0.

                if(flag==1){ ///Si flag es igual a 1 entonces el arreglo es capicua.
                    printf("El arreglo es capicua.\n");
                }
                else{ ///Si flag es igual a 0 el arreglo no es capicua.
                    printf("El arreglo NO es capicua.\n");
                }

                printf("\nEl arreglo es el siguiente:\n\n");
                mostrarArreglo(arregloEnteros, validos);

                break;

            case 10:
                system("cls");
                printf("Ejercicio 10:\n");
                validos= cargarArreglo(arregloEnteros,dimension);
                printf("\n\nEl arreglo es el siguiente:\n\n");
                mostrarArreglo(arregloEnteros, validos);

                invertirArreglo(arregloEnteros, validos);
                printf("\n\nArreglo invertido:\n\n");
                mostrarArreglo(arregloEnteros, validos);

                break;

            case 11:
                system("cls");
                printf("Ejercicio 11:\n");
                validos= cargarArreglo(arregloEnteros, dimension);
                printf("\n\nEl arreglo es el siguiente:\n\n");
                mostrarArreglo(arregloEnteros, validos);
                printf("\n\n");
                system("pause");
                system("cls");

                do{
                    printf("Seleccione un metodo de ordenacion:\t 1) Seleccion\t 2) Insercion: ");
                    fflush(stdin);
                    scanf("%d", &orden);

                    ///Creo un nuevo menu de opciones para poder seleccionar el metodo de ordenacion del arreglo.
                    switch(orden){
                        case 1:
                            ordenarArregloPorSeleccion(arregloEnteros, validos);
                            printf("\n\nA traves del metodo de SELECCION el arreglo queda ordenado de la siguiente manera:\n\n");
                            mostrarArreglo(arregloEnteros, validos);
                            break;

                        case 2:
                            ordenarArregloPorInsercion(arregloEnteros, validos);
                            printf("\n\nA traves del metodo de INSERCION el arreglo queda ordenado de la siguiente manera:\n\n");
                            mostrarArreglo(arregloEnteros, validos);
                            break;

                        ///Si no se ingresa una opcion correcta saldra el siguiente mensaje por pantalla.
                        default:
                            printf("\n\nLa opcion ingresada es incorrecta. Por favor ingrese una opcion valida.\n\n");
                            system("pause");
                            system("cls");
                            break;
                    }
                }
                while(orden!=1 && orden!=2); ///Permite que se vuelva a ejecutar el menu hasta que se ingrese una opcion correcta.

                break;

            case 12:
                system("cls");
                printf("Ejercicio 12:\n");

                printf("\nPrimer arreglo:\n\n");
                validos= cargarArregloCaracteres(arregloCaracteres, dimensionCaract); ///Cargo el primer arreglo por teclado y lo ordeno.
                ordenarArregloChar(arregloCaracteres,validos);
                system("pause");
                system("cls");

                printf("Segundo arreglo:\n\n");
                validosDos= cargarArregloCaracteres(arregloCaracteresDos, dimensionCaract); ///Cargo el segundo arreglo por teclado y lo ordeno. Se crearon nuevas variables y arreglos para este ejercicio.
                ordenarArregloChar(arregloCaracteresDos, validosDos);
                system("pause");
                system("cls");

                printf("El primer arreglo ordenado alfabeticamente:\n\n");
                mostrarArregloCaracteres(arregloCaracteres, validos);
                printf("\n\nEl segundo arreglo ordenado alfabeticamente:\n\n");
                mostrarArregloCaracteres(arregloCaracteresDos, validosDos); ///Muestro ambos arreglos ordenados.

                validosNuevo=crearNuevoArreglo(arregloCaracteres, validos, arregloCaracteresDos, validosDos, arregloCaracteresNuevo, dimensionNuevoCaract); ///Creo un nuevo arreglo en base a los dos anteriores.
                printf("\n\nEl nuevo arreglo formado por los dos anteriores queda de la siguiente manera:\n\n");
                mostrarArregloCaracteres(arregloCaracteresNuevo, validosNuevo);

                break;

            default:
                printf("\n\nLa opcion ingresada es incorrecta. Por favor ingrese una opcion valida.\n\n");
                break;

        }
        printf("\n\nESC para salir (presione cualquier otra tecla para volver al menu inicial).\n");
        fflush(stdin);
        salir= getch();
    }
    while(salir!=ESC); ///Mientras se presione cualquier otro comando que no sea ESC, el programa volvera a ejecutarse.
    return 0;
}

///Funcion que permite cargar un arreglo de enteros con un tope que lo define la dimension.
int cargarArreglo (int A[], int dimension){
    int i=0;
    char salir;

    while(salir!=ESC && i<dimension){
        printf("\nIngrese el valor a cargar en la posicion %d del arreglo:\n", i);
        fflush(stdin);
        scanf("%d", &A[i]); ///Toma el valor ingresado por teclado y lo coloca en la posicion "i" del arreglo.
        i++;
        printf("\nSi desea salir presione ESC.\n");
        fflush(stdin);
        salir=getch(); ///Toma el comando ingreado por teclado y lo ejecuta directamente, sin mostrarlo por pantalla.
    }
    return i;
}

///Funcion que permite mostrar un arreglo de enteros.
void mostrarArreglo (int A[], int validos){
    int i=0;

    while(i<validos){
        printf(" |%d| ", A[i]);
        i++;
    }
}
/// OTRA MANERA DE MOSTRAR EL ARREGLO DE ENTEROS
void mostrarArreglo(int A[],int validos){
    int i;
    for(i=0;i<validos;i++){
        printf(" %d ",A[i]);
    }
}

///Sumar todos los valores de un arreglo de enteros.
int sumaArreglo (int A[], int validos){
    int i=0;
    int suma=0;

    while(i<validos){
        suma= suma + A[i];
        i++;
    }
    return suma;
}

///Funcion que copia un arreglo en una pila. La pila necesita de un puntero ya que va a ser modificada.
void copiarArreglo (int A[], int validos, Pila *dada){
    validos--;

    while(validos>=0){
        apilar(dada, A[validos]);
        validos--;
    }
}

///Permite cargar un arreglo con numeros reales.
float cargarArregloReales (float arreglo[], int dimension){
    int i=0;
    char salir;

    while(i<dimension){
        arreglo[i]= (float)(rand()%100)/(float)((rand()%5)+1); ///Casteo para poder arrojar numeros random con decimales.
        i++;
    }
    return i;
}

///Funcion para mostrar los arreglos de numeros reales.
void mostrarArregloReales (float arreglo[], int validos){
    int i=0;

    while(i<validos){
        printf(" |%.2f| ", arreglo[i]);
        i++;
    }
}

///Sumar arreglos cargado con numeros reales.
float sumaArregloReales (float arreglo[], int validos){
    float suma=0;
    int i=0;

    while(i<validos){
        suma= suma + arreglo[i];
        i++;
    }
    return suma;
}

///Funcion que permite cargar un arreglo con caracteres, limitando la cantidad por la dimension.
int cargarArregloCaracteres (char arreglo[], int dimension){
    int i=0;
    char salir;

    while(i<dimension && salir!=ESC){ ///Si "i" se iguala a la dimension tambien corta el while.
        printf("Ingrese el caracter a cargar en la posicion %d:\n", i);
        fflush(stdin);
        scanf("%c", &arreglo[i]);
        i++;
        printf("\nESC para salir (presione cualquier tecla para continuar cargando caracteres).\n\n");
        fflush(stdin);
        salir=getch();
    }
    return i;
}

///Permite mostrar arreglo cargado con caracteres.
void mostrarArregloCaracteres (char arreglo[], int validos){
    int i=0;

    while(i<validos){
        printf(" |%c|", arreglo[i]);
        i++;
    }
}

///Buscar un elemento char en un arreglo.
int buscarDato (char arreglo[], int validos, char dato){
    int i=0;
    int flag=0;

    while(i<validos && flag==0){
        if(arreglo[i]==dato){ ///Cuando el dato sea igual a un caracter del arreglo, el ciclo corta.
            flag=1;
        }
        else{
            i++;
        }
    }
    return flag; ///Si flag es igual a 1 el elemento se encuentra en el arreglo, de ser 0 el elemento no se encuentra.
}

///Funcion que ordena un dato char enviado como parametro.
void ordenarDatoChar (char arreglo[], int pos, char datoChar){
    int i= pos;

    while(i>=0 && datoChar<arreglo[i]){
        arreglo[i+1]= arreglo[i];
        i--;
    }
    arreglo[i+1]=datoChar; ///Cuando encuentra el hueco en donde el elemento del arreglo no es mas grande que el dato recibido, se coloca el dato en el lugar siguiente.
}

///Toma la funcion de ordenar un dato char y la llama tantas veces sea necesario para alcanzar los datos que contiene el arreglo.
void ordenarArregloChar(char arreglo[], int validos){
    int i=0;

    while(i<validos-1){
        ordenarDatoChar(arreglo, i, arreglo[i+1]);
        i++;
    }
}

///Encontrar el caracter mas grande y devolverlo.
char caracterMasGrande (char arreglo[], int validos){
    int i=0;
    char masGrande= arreglo[i];

    while(i<validos){
        if(masGrande<arreglo[i]){ ///Cuando el elemento del arreglo es mas grande que el caracter recibido, la variable creada toma ese valor.
            masGrande= arreglo[i];
        }
        i++;
    }
    return masGrande; ///Devuelve el caracter maximo.
}

///Funcion que determina si un arreglo es o no capicua.
int arregloCapicua (int arreglo[], int validos){
    int i=0;
    int j= validos-1;
    int flag=1;

    while(i<(validos/2) && flag==1){ ///Se hace el recorrido hasta la mitad de los validos o hasta que se demuestre que dos datos no son iguales.
        if(arreglo[i]==arreglo[j]){
            i++;
            j--;
        }
        else{
            flag=0;
        }
    }
    return flag; ///Si devuelve 1 es capicua, si devuelve 0 no lo es.
}

///Devuelve la posicion del menor elemento del arreglo.
int posicionMenor (int arreglo[], int pos, int validos){
    int i= pos+1;
    int menor= arreglo[pos];
    int posMenor= pos;

    while(i<validos){
        if(menor>arreglo[i]){
            menor= arreglo[i];
            posMenor= i; ///Cuando la variable menor es mayor al elemento del arreglo se hace el reemplazo.
        }
        i++;
    }
    return posMenor;
}

///Ordena en base a la funcion que encuentra la posicion del menor dato.
void ordenarArregloPorSeleccion (int arreglo[], int validos){
    int i=0;
    int posMenor=0;
    int aux=0;

    while(i<validos-1){
        posMenor= posicionMenor(arreglo,i,validos);
        aux= arreglo[posMenor]; /// La variable auxiliar toma el valor del menor dato del arreglo.
        arreglo[posMenor]= arreglo[i]; ///Envio el valor del dato que se encuentra en la posicion "i", a la posicion donde se encuentra el menor dato y lo piso.
        arreglo[i]= aux; ///El menor dato a traves de auxiliar pasa a la primer posicion.
        i++;
    }
}

///Invertir un arreglo de enteros.
void invertirArreglo (int arreglo [], int validos){
    int i=0;
    int j= validos-1;
    int aux=0;
    while(i<(validos/2)){
        aux=arreglo[i]; /// La variable aux toma el valor del elemento en la posicion "i".
        arreglo[i]= arreglo[j]; /// El elemento en la posicion "i" es pisado por el de la posicion "j".
        arreglo[j]=aux; /// La posicion "j" es pisado por el aux que contiene el valor que tenia la posicion "i".
        i++;
        j--;
    }
}

///Insertar un dato menor en su posicion.
void insertarDato (int arreglo[], int pos, int dato){
    int i= pos;

    while(i>=0 && dato<arreglo[i]){
        arreglo[i+1]= arreglo[i];
        i--; ///Hago que salga del bucle.
    }
    arreglo[i+1]=dato; ///Al estar en i=-1 debo sumarle 1 para copiar el dato que recibi por parametro.
}

///Utiliza la funcion insertar el menor para llamarla las veces que sea necesario para ordenar el arreglo.
void ordenarArregloPorInsercion(int arreglo[], int validos){
    int i=0;

    while(i<validos-1){ ///Validos - 1 porque el ultimo dato ya queda ordenado.
        insertarDato(arreglo, i, arreglo[i+1]);
        i++;
    }
}

///Crear un nuevo arreglo en base a dos arreglos que se van a ordenar previamente.
int crearNuevoArreglo(char primerArreglo[], int primerValidos, char segundoArreglo[], int segundoValidos, char nuevoArreglo[], int dim){
    int i=0;
    int j=0;
    int nuevoValidos=0;

    while(nuevoValidos<dim && i<primerValidos && j<segundoValidos){ ///Se ejecuta mientras no se supere los validos del arreglo nuevo y no se queden sin valores alguno de los otros dos arreglos.
        if(primerArreglo[i]<segundoArreglo[j]){
            nuevoArreglo[nuevoValidos]= primerArreglo[i]; ///Toma el valor del primer arreglo de ser menor.
            i++;
        }
        else{
            nuevoArreglo[nuevoValidos]= segundoArreglo[j]; ///Tomar el valor del segundo arreglo de ser menor.
            j++;
        }
        nuevoValidos++;
    }

    while(i<primerValidos && nuevoValidos < dim){
        nuevoArreglo[nuevoValidos]= primerArreglo[i]; ///Si quedaron datos en el arreglo, se pasan al nuevo arreglo.
        i++;
        nuevoValidos++;
    }

    while(j<segundoValidos && nuevoValidos < dim){
        nuevoArreglo[nuevoValidos]= segundoArreglo[j];
        j++;
        nuevoValidos++;
    }
    return nuevoValidos; ///Se devuelve la cantidad de elementos cargados en el nuevo arreglo.
}
