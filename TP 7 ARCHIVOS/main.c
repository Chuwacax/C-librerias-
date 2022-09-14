#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define archi "archivo.bin"
#define alum "alumnos.bin"

const char ESC=27;

typedef struct {
    int legajo;
    char nombreYapellido [ 30 ];
    int edad;
    int anio;///año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

///Encabezado
void cargarUnEntero();
void mostrarArchivo();
int cantidadRegistros();
void cargarAlumnos();
void mostrarAlumnos();
void mostrarUnAlumno();
void mostrarAlumnos();
void cargarUnAlumno();
void pasarAPila(Pila *a);
int mayoresDeEdad(int edad);
void nombreRangoEdad(int menor, int mayor);
void alumnoMayor();
int anioCursado(int anio);
int cargarArreglo(stAlumno arreglo[], int dim);
void mostrarArreglo(stAlumno arreglo[], int validos);
void copiarArregloEnArchivo(stAlumno alumno[], int validos);
int pasarArchivoAArreglo(stAlumno arreglo[], int dim);
int cantidadRegistrosCualquierArchivo(FILE *puntero, int bytes);
void mostrarContenidoRegistro(int dato);
stAlumno modificarAlumno(stAlumno aux);
void hacerEfectivaModificacionAlumno(int legajo);
void invertirArchivo();

int main()
{   int dato=0;

    int cantidad=0;

    Pila dada;
    inicpila(&dada);

    int edad=0;
    int mayores=0;
    int menores=0;
    int anio=0;

    stAlumno alumnos[15];

    char opcion;

    do{
        system("cls");
        dato=menu();

        switch(dato){
            case 1:
                system("cls");
                printf("1)Hacer una funcion que agregue un elemento al final de un archivo.\n");
                cargarUnEntero();
                break;

            case 2:
                system("cls");
                printf("2)Hacer una funcion que muestre por pantalla el contenido de un archivo.\n");
                mostrarArchivo();
                break;

            case 3:
                system("cls");
                printf("3)Hacer una funcion que retorne la cantidad de registros que contiene un archivo.\n");
                cantidad=cantidadRegistros();
                printf("\nCantidad de registros cargados en el archivo: %d.\n", cantidad);
                break;

            case 4:
                system("cls");
                printf("4)Crear una funcion que cargue un archivo de alumnos.\n");
                cargarAlumnos();
                break;

            case 5:
                system("cls");
                printf("5)Crear una funcion que muestre por pantalla los registros de un archivo de alumnos.\n");
                mostrarAlumnos();
                break;

            case 6:
                system("cls");
                printf("6)Crear una funcion que permita agregar de a un elemento al final del archivo.\n");
                printf("\nAgregar un nuevo alumno:\n");
                cargarUnAlumno();
                mostrarAlumnos();
                break;

            case 7:
                system("cls");
                printf("7)Crear una funcion que pase a una pila los numeros de legajo de los alumnos mayores de edad.\n");
                pasarAPila(&dada);
                printf("\nPila de legajos:\n");
                mostrar(&dada);
                break;

            case 8:
                system("cls");
                printf("8)Dado un archivo de alumnos, hacer una funcion que cuente la cantidad de alumnos mayores a edad especifica que se envia por parametro.\n");
                printf("Ingrese una edad: ");
                scanf("%d", &edad);
                mayores= mayoresDeEdad(edad);
                printf("\nLos mayores de %d son: %d.", edad, mayores);
                break;

            case 9:
                system("cls");
                printf("9)Mostrar por pantalla el nombre de todos los alumnos entre un rango de edades especifico.\n");
                printf("\nIngrese un rango:\n");
                printf("Mayores a: ");
                scanf("%d", &menores);
                printf("Menores a: ");
                scanf("%d", &mayores);
                nombreRangoEdad(menores, mayores);
                break;

            case 10:
                system("cls");
                printf("10)Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.\n");
                printf("\nAlumno de mayor edad cargado en el archivo:\n");
                alumnoMayor();
                break;

            case 11:
                system("cls");
                printf("11)Crear una funcion que retorne la cantidad de alumnos que cursan un determinado anio. El anio buscado se pasa por parametro.\n");
                printf("\nIngrese el anio de cursada: ");
                scanf("%d", &anio);
                cantidad= anioCursado(anio);
                printf("\nEl anio %d lo cursan: %d.\n", anio, cantidad);
                break;

            case 12:
                system("cls");
                printf("12)Crear una funcion que reciba como parametro un arreglo de tipo alumno y lo copie en el archivo. Realice otra funcion que pase los elementos del archivo a un arreglo de alumnos, filtrando los estudiantes de un año en particular.\n");
                cantidad= cargarArreglo(alumnos, 15);
                printf("\nArchivo con los arreglos cargados:\n");
                copiarArregloEnArchivo(alumnos, cantidad);
                mostrarAlumnos();
                cantidad=pasarArchivoAArreglo(alumnos, 15);
                printf("\nArreglo de alumnos con los datos del archivo:\n");
                mostrarArreglo(alumnos, cantidad);
                break;

            case 13:
                system("cls");
                printf("13)Crear una funcion que retorne la cantidad de registros que tiene el archivo.\n");
                do{
                    printf("\nIngrese de que tipo de archivo desea contar sus registros:\n1)archi.\n2)alum.\n");
                    scanf("%d", &dato);

                    if(dato==1 || dato==2){
                        if(dato==1){
                            FILE *puntero;
                            puntero= fopen(archi, "rb");
                            if(puntero!=NULL){
                                cantidad=cantidadRegistrosCualquierArchivo(puntero, sizeof(int));
                                printf("El archivo de enteros contiene %d registros.\n", cantidad);
                            }
                            else{
                            printf("\nNo se pudo abrir el archivo.\n");
                            }
                            fclose(puntero);
                        }
                        else{
                            FILE *puntero;
                            puntero= fopen(alum, "rb");
                            if(puntero!=NULL){
                                cantidad=cantidadRegistrosCualquierArchivo(puntero, sizeof(stAlumno));
                                printf("\nEl archivo de alumnos contiene %d registros.\n", cantidad);
                            }
                            else{
                            printf("\nNo se pudo abrir el archivo.\n");
                            }
                            fclose(puntero);
                        }
                    }
                    else{
                        printf("\nLa opcion ingresada es invalida.\n");
                    }
                }
                while(dato!=1 && dato!=2);
                break;

            case 14:
                system("cls");
                printf("14)Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una funcion que muestre el contenido de un registro, cuyo numero (entre 0 y 9) se pase por parámetro.\n");
                do{
                    printf("\nIngrese el registro del archivo de alumnos que desea mostrar (entre 0 y 9): ");
                    scanf("%d", &dato);
                    if(dato>=0 && dato<10){
                        printf("\nAlumno en el registro %d del archivo.\n", dato);
                        mostrarContenidoRegistro(dato);
                    }
                    else{
                        printf("\nLa opcion ingresada no es valida.\n");
                    }
                }
                while(dato<0 || dato>9);
                break;

            case 15:
                system("cls");
                printf("15)Realice una (o varias) funciones que permitan modificar un registro existente en el archivo de alumnos.\n");
                printf("\nIngrese el numero de legajo del usuario a modificar: ");
                scanf("%d", &dato);
                hacerEfectivaModificacionAlumno(dato);
                break;

            case 16:
                system("cls");
                printf("16)Dado un archivo de alumnos, hacer una funcion que invierta los elementos del mismo. No se puede usar otro archivo auxiliar ni un arreglo auxiliar.\n");
                invertirArchivo();
                mostrarAlumnos();
                break;

            default:
                printf("\nLa opcion ingresada es invalida.\n");
                break;

        }
        printf("\nSi desea volver al menu principal presione cualquier letra (ESC para salir).\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=ESC);
    return 0;
}

///MENU
int menu(){
    int opcion=0;

    printf("MENU:\n");
    printf("\n1)Hacer una funcion que agregue un elemento al final de un archivo.\n");
    printf("2)Hacer una funcion que muestre por pantalla el contenido de un archivo.\n");
    printf("3)Hacer una funcion que retorne la cantidad de registros que contiene un archivo.\n");
    printf("4)Crear una funcion que cargue un archivo de alumnos.\n");
    printf("5)Crear una funcion que muestre por pantalla los registros de un archivo de alumnos.\n");
    printf("6)Crear una funcion que permita agregar de a un elemento al final del archivo.\n");
    printf("7)Crear una funcion que pase a una pila los numeros de legajo de los alumnos mayores de edad.\n");
    printf("8)Dado un archivo de alumnos, hacer una funcion que cuente la cantidad de alumnos mayores a edad especifica que se envia por parametro.\n");
    printf("9)Mostrar por pantalla el nombre de todos los alumnos entre un rango de edades especifico.\n");
    printf("10)Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.\n");
    printf("11)Crear una funcion que retorne la cantidad de alumnos que cursan un determinado anio. El anio buscado se pasa por parametro.\n");
    printf("12)Crear una funcion que reciba como parametro un arreglo de tipo alumno y lo copie en el archivo. Realice otra funcion que pase los elementos del archivo a un arreglo de alumnos, filtrando los estudiantes de un anio en particular.\n");
    printf("13)Crear una funcion que retorne la cantidad de registros que tiene el archivo.\n");
    printf("14)Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una funcion que muestre el contenido de un registro, cuyo numero (entre 0 y 9) se pase por parámetro.\n");
    printf("15)Realice una (o varias) funciones que permitan modificar un registro existente en el archivo de alumnos.\n");
    printf("16)Dado un archivo de alumnos, hacer una funcion que invierta los elementos del mismo. No se puede usar otro archivo auxiliar ni un arreglo auxiliar.\n");
    printf("\n0)Salir.\n");
    printf("\nOpcion: ");
    scanf("%d", &opcion);

    return opcion;
}

///Ejercicio 1
void cargarUnEntero(){
    int nota=0;

    FILE *puntero;
    puntero= fopen(archi, "ab");

    if(puntero){
        printf("Cargue una nota: ");
        scanf("%d", &nota);
        fwrite(&nota, sizeof(int), 1, puntero);
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
}

///Ejercicio 2
void mostrarArchivo(){
    int nota=0;

    FILE *puntero;
    puntero= fopen(archi, "rb");

    if(puntero!=NULL){
        while(fread(&nota, sizeof(int), 1, puntero)>0){
            printf("\nNota: %d\n", nota);
        }
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
}

///Ejercicio 3
int cantidadRegistros(){
    int cantidad=0;

    FILE *puntero;
    puntero= fopen(archi, "rb");

    if(puntero!=NULL){
        fseek(puntero, 0, SEEK_END);
        cantidad= ftell(puntero);
        cantidad= cantidad/sizeof(int);
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
    return cantidad;
}

///Ejercicio 4
void cargarAlumnos(){
    char opcion;
    stAlumno alumno;

    FILE *puntero;
    puntero= fopen(alum, "ab");

    if(puntero!=NULL){
        do{
            printf("\nCarga de alumnos:\n");
            printf("\nLegajo: ");
            scanf("%d", &alumno.legajo);
            printf("Nombre y apellido: ");
            fflush(stdin);
            gets(alumno.nombreYapellido);
            printf("Edad: ");
            scanf("%d", &alumno.edad);
            printf("Anio: ");
            scanf("%d", &alumno.anio);
            fwrite(&alumno, sizeof(stAlumno), 1, puntero);

            printf("\nPresione cualquier tecla para cargar otro alumno (ESC para salir).\n\n");
            fflush(stdin);
            opcion= getch();
        }
        while(opcion!=ESC);
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
}


void mostrarUnAlumno(stAlumno alumno){
    printf("\nLegajo...............: %d\n", alumno.legajo);
    printf("Nombre y apellido....: %s\n", alumno.nombreYapellido);
    printf("Edad.................: %d\n", alumno.edad);
    printf("Anio.................: %d\n", alumno.anio);
}


///Ejercicio 5
void mostrarAlumnos(){
    stAlumno alumno;

    FILE *puntero;
    puntero= fopen(alum, "rb");

    if(puntero!=NULL){
        while(fread(&alumno, sizeof(stAlumno), 1, puntero)>0){
            mostrarUnAlumno(alumno);
        }
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
}

///Ejercicio 6
void cargarUnAlumno(){
    stAlumno alumno;

    FILE *puntero;
    puntero= fopen(alum,"ab");

    if(puntero!=NULL){
        printf("Cargar un alumno:\n");
        printf("\nLegajo: ");
        scanf("%d", &alumno.legajo);
        printf("Nombre y apellido: ");
        fflush(stdin);
        gets(alumno.nombreYapellido);
        printf("Edad: ");
        scanf("%d", &alumno.edad);
        printf("Anio: ");
        scanf("%d", &alumno.anio);
        fwrite(&alumno, sizeof(stAlumno), 1, puntero);
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
}

///Ejercicio 7
void pasarAPila(Pila *a){
    stAlumno alumno;

    FILE *puntero;
    puntero= fopen(alum, "rb");

    if(puntero!=NULL){
        while(fread(&alumno, sizeof(stAlumno), 1, puntero)>0){
            apilar(a, alumno.legajo);
        }
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
}

///Ejercicio 8
int mayoresDeEdad(int edad){
    stAlumno alumno;
    int contador=0;

    FILE *puntero;
    puntero= fopen(alum, "rb");

    if(puntero!=NULL){
        while(fread(&alumno, sizeof(stAlumno), 1, puntero)>0){
            if(alumno.edad>edad){
                contador++;
            }
        }
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
    return contador;
}

///Ejercicio 9
void nombreRangoEdad(int menor, int mayor){
    stAlumno alumno;

    FILE *puntero;
    puntero= fopen(alum, "rb");

    if(puntero!=NULL){
        while(fread(&alumno, sizeof(stAlumno), 1, puntero)>0){
            if(menor<alumno.edad && alumno.edad< mayor){
                mostrarUnAlumno(alumno);
            }
        }
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
}

///Ejercicio 10
void alumnoMayor(){
    stAlumno alumno;
    stAlumno aux;

    FILE *puntero;
    puntero= fopen(alum, "rb");

    if(puntero!=NULL){
        if((fread(&alumno, sizeof(stAlumno), 1, puntero)>0)){
            aux= alumno;
        }
        while(fread(&alumno, sizeof(stAlumno), 1, puntero)>0){
            if(alumno.edad>aux.edad){
                aux=alumno;
            }
        }
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
    mostrarUnAlumno(aux);
}

///Ejercicio 11
int anioCursado(int anio){
    stAlumno alumno;
    int contador=0;

    FILE *puntero;
    puntero= fopen(alum, "rb");

    if(puntero!=NULL){
        while(fread(&alumno, sizeof(stAlumno), 1, puntero)>0){
            if(alumno.anio==anio){
                contador++;
            }
        }
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
    return contador;
}

///Ejercicio 12
int cargarArreglo(stAlumno arreglo[], int dim){
    int i=0;
    char opcion;

    while(i<dim && opcion!=ESC){
        printf("\nCargar alumno en la posicion %d:\n", i);
        printf("\nLegajo: ");
        scanf("%d", &arreglo[i].legajo);
        printf("Nombre y apellido: ");
        fflush(stdin);
        gets(arreglo[i].nombreYapellido);
        printf("Edad: ");
        scanf("%d", &arreglo[i].edad);
        printf("Anio: ");
        scanf("%d", &arreglo[i].anio);
        printf("\nPresione cualquier tecla para continuar la carga (ESC para salir).\n");
        fflush(stdin);
        opcion=getch();
        i++;
    }
    return i;
}

void mostrarArreglo(stAlumno arreglo[], int validos){
    int i=0;

    while(i<validos){
        printf("\nLegajo..............: %d.\n", arreglo[i].legajo);
        printf("Nombre y apellido...: %s.\n", arreglo[i].nombreYapellido);
        printf("Edad................: %d.\n", arreglo[i].edad);
        printf("Anio................: %d.\n", arreglo[i].anio);
        i++;
    }
}

void copiarArregloEnArchivo(stAlumno alumno[], int validos){
    FILE *puntero;
    puntero= fopen(alum, "ab");

    if(puntero!=NULL){
        fwrite(alumno, sizeof(stAlumno), validos, puntero);
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
}

int pasarArchivoAArreglo(stAlumno arreglo[], int dim){
    stAlumno alumno;
    int i=0;

    FILE *puntero;
    puntero= fopen(alum, "rb");

    if(puntero!=NULL){
        while(fread(&alumno, sizeof(stAlumno), 1, puntero)>0 && i<dim){
            arreglo[i]= alumno;
            i++;
        }
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
    return i;
}

///Ejercicio 13
int cantidadRegistrosCualquierArchivo(FILE *puntero, int bytes){
    int cantidad=0;

    fseek(puntero, 0, SEEK_END);
    cantidad= ftell(puntero);
    cantidad= cantidad/bytes;

    return cantidad;
}

///Otra forma de hacer el ejercicio 13, pero hay que crear como un arreglo de char el nombre del archivo (char arreglo[]="archi.bin";)
/*int RegistrosDelArchivoGenerico(char nomArchi[],int bytes)
{
    int cantidad=0;
    FILE *puntero;
    puntero= fopen(nomArchi,"rb");
    if(puntero!=NULL)
    {
        fseek(puntero,0,SEEK_END);
        cantidad=ftell(puntero)/bytes;
    }
    else
    {
        printf("Error de datos - El archivo no pude ser abierto\n");
    }
    fclose(puntero);
    return cantidad;
}*/

///Ejercicio 14
void mostrarContenidoRegistro(int dato){
    stAlumno alumno;
    int contador=0;

    FILE *puntero;
    puntero= fopen(alum, "rb");

    if(puntero!=NULL){
        while(fread(&alumno, sizeof(stAlumno), 1, puntero)>0 && contador!=dato){
            contador++;
        }
         if(contador!=dato){
            printf("\nLa posicion elejida no se encuentra cargada en el archivo.\n");
        }
        else{
            mostrarUnAlumno(alumno);
        }
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
}

///Ejercicio 15
stAlumno modificarAlumno(stAlumno aux){
    int opcion=0;
    char hacer;
    stAlumno nuevoAlumno=aux;

    printf("\nQue desea modificar?\n");
    printf("1)Legajo.\n");
    printf("2)Nombre y apellido.\n");
    printf("3)Edad.\n");
    printf("4)Anio.\n");

    do{
        printf("\nOpcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("Ingrese nuevo legajo: ");
                scanf("%d", &nuevoAlumno.legajo);
                break;

            case 2:
                printf("Ingrese nuevo nombre y apellido: ");
                fflush(stdin);
                gets(nuevoAlumno.nombreYapellido);
                break;

            case 3:
                printf("Ingrese nueva edad: ");
                scanf("%d", &nuevoAlumno.edad);
                break;

            case 4:
                printf("Ingrese nuevo anio: ");
                scanf("%d", &nuevoAlumno.anio);
                break;
        }
        printf("\nDesea modificar un nuevo dato? s/n\n");
        fflush(stdin);
        hacer=getch();
    }
    while(hacer=='s');
    return nuevoAlumno;
}

void hacerEfectivaModificacionAlumno(int legajo){
    stAlumno alumno;
    stAlumno aux;
    int flag=0;

    FILE *puntero;
    puntero= fopen(alum, "r+b");

    if(puntero!=NULL){
        while(flag==0 && fread(&alumno, sizeof(stAlumno), 1, puntero)>0){
            if(alumno.legajo==legajo){
                flag=1;
            }
        }
        if(flag==1){
        fseek(puntero, (-1)*sizeof(stAlumno),SEEK_CUR);
        aux=alumno;
        aux=modificarAlumno(aux);
        fwrite(&aux, sizeof(stAlumno), 1, puntero);
        }
        else{
            printf("\nEl legajo no se encuentra en el archivo.\n");
        }
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
}

///Ejercicio 16
void invertirArchivo(){
    stAlumno inicio;
    stAlumno fin;

    FILE *puntero;
    puntero= fopen(alum, "r+b");

    int i=0;
    int u=cantidadRegistrosCualquierArchivo(puntero, sizeof(stAlumno))-1;
    int mov=-1;

    if(puntero!=NULL){
        while(i<u){
            fseek(puntero, i*sizeof(stAlumno), SEEK_SET);
            fread(&inicio, sizeof(stAlumno), 1, puntero);

            fseek(puntero,(u)*sizeof(stAlumno), SEEK_SET);
            fread(&fin, sizeof(stAlumno), 1, puntero);

            fseek(puntero, i*sizeof(stAlumno), SEEK_SET);
            fwrite(&fin, sizeof(stAlumno), 1, puntero);

            fseek(puntero, u*sizeof(stAlumno), SEEK_SET);
            fwrite(&inicio, sizeof(stAlumno), 1, puntero);

            i++;
            u--;
        }
    }
    else{
        printf("\nNo se pudo abrir el archivo.\n");
    }
    fclose(puntero);
}
