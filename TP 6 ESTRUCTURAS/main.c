#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char ESC=27;

///Estructura
typedef struct {
    int matricula;
    char nombre[ 30 ];
    char genero; ///m, f, o
} stAlumno ;

///Encabezados
int cargarAlumnos (stAlumno alumnos[], int dim);
void mostrarGenero (stAlumno alumnos[], int pos);
void mostrarAlumnos (stAlumno alumnos[], int dimension);
void mostrarUnAlumno (stAlumno alumno[], int pos);
int posAlumnoPorMatricula (stAlumno alumno[], int validos, int matri);
void mostrarAlumnoPorMatricula (stAlumno alumno[], int validos, int matri);
int posAlumnoPorNombre (stAlumno alumno[], int validos, char nombre[]);
void mostrarAlumnoPorNombre (stAlumno alumno[], int validos, char nombre[]);
void mostrarAlumnoPorGenero (stAlumno alumno[], int validos, char genero);
int posMenorMatricula (stAlumno alumno[], int validos, int pos);
void intercambioAlumnos (stAlumno alumno[], int i, int pos);
void ordenarAlumnosPorMatricula (stAlumno alumno[], int validos);
stAlumno cargarUnAlumno ();
int insertarAlumno (stAlumno alumno[],int validos, stAlumno nuevoAl);
void insertarPorNombre (stAlumno alumnos[], int pos, stAlumno dato);
void ordenarPorInsercion (stAlumno alumnos[], int validos);
int contarTipoGenero (stAlumno alumnos[], int validos, char gen);

int main()
{   int dim=15;
    int validos=0;
    stAlumno alumnos[dim];

    validos=cargarAlumnos(alumnos, dim);
    mostrarAlumnos(alumnos, validos);

    system("pause");

    char opcion;

    int menu=0;
    int matricula=0;
    int pos=0;
    char nombre[30];
    char genero;

    do{

        system("cls");
        printf("Buscar alumno por:\n");
        printf("1) Matricula.\n");
        printf("2) Nombre.\n");
        printf("3) Genero.\n");
        printf("0) Salir.\n");
        scanf("%d", &menu);

        switch(menu){
            case 0:
                printf("\nSaliendo del menu de busqueda...\n");
                opcion=ESC;
                break;

            case 1:
                printf("\nIngrese la matricula que desea buscar: ");
                scanf("%d", &matricula);
                pos= posAlumnoPorMatricula(alumnos, validos, matricula);
                if(pos==-1){
                    printf("\nLa matricula ingresada no existe.\n");
                }
                else{
                    mostrarAlumnoPorMatricula(alumnos, validos, matricula);
                }
                break;

            case 2:
                printf("\nIngrese el nombre que desea buscar: ");
                fflush(stdin);
                gets(nombre);
                pos= posAlumnoPorNombre(alumnos, validos, nombre);
                if(pos==-1){
                    printf("\nEl nombre ingresado no existe.\n");
                }
                else{
                    mostrarAlumnoPorNombre(alumnos, validos, nombre);
                }
                break;

            case 3:
                printf("\nIngrese el genero que desea buscar: ");
                fflush(stdin);
                scanf("%c", &genero);
                mostrarAlumnoPorGenero(alumnos, validos, genero);
                break;

            default:
                printf("\nOpcion invalida.\n");
                break;

        }
        if(menu!=0){
            printf("\nSi desea realizar una nueva busqueda presione cualquier tecla (ESC para salir).\n");
            fflush(stdin);
            opcion= getch();
        }
    }
    while(opcion!=ESC);

    printf("\n");
    system("pause");

    int matriOrdenadas=0;

    do{
        system("cls");
        printf("Ordenar alumnos:\n");
        printf("1) Por matricula.\n");
        printf("2) Por nombre.\n");
        printf("0) Salir.\n");
        scanf("%d", &menu);

        switch(menu){
            case 0:
                printf("\nSaliendo del menu de ordenamiento...\n");
                opcion=ESC;
                break;

            case 1:
                printf("\nAlumnos ordenados por matricula:\n");
                ordenarAlumnosPorMatricula(alumnos, validos);
                mostrarAlumnos(alumnos, validos);
                matriOrdenadas=1;
                break;

            case 2:
                printf("\nAlumnose ordenados por nombre:\n");
                ordenarPorInsercion(alumnos, validos);
                mostrarAlumnos(alumnos, validos);
                matriOrdenadas=0;
                break;

            default:
                printf("\nOpcion invalida.\n");
                break;
        }
        if(menu!=0){
            printf("\nSi desea realizar un nuevo ordenamiento presione cualquier tecla (ESC para salir).\n");
            fflush(stdin);
            opcion= getch();
        }
    }
    while(opcion!=ESC);

    if(matriOrdenadas==1){
        system("pause");
        system("cls");
        stAlumno nuevoAlumno;

        printf("Cargar un nuevo alumno:\n");
        nuevoAlumno= cargarUnAlumno();

        validos= insertarAlumno(alumnos, validos, nuevoAlumno);
        mostrarAlumnos(alumnos, validos);
    }

    system("pause");
    system("cls");

    char gen;
    int cantidad=0;

    do{
        do{
            printf("Ingrese el tipo de genero a buscar ('m'/ 'f'/ 'o'): ");
            fflush(stdin);
            scanf("%c", &gen);
            if(gen!='o' && gen!='m' && gen!='f'){
                printf("Caracter invalido.\n\n");
            }
        }
        while(gen!='o' && gen!='m' && gen!='f');

        cantidad= contarTipoGenero(alumnos, validos, gen);
        printf("\n\nCantidad de alumnos con tipo de genero '%c' son: %d.", gen, cantidad);
        printf("\n\nESC para salir (presione cualquier otra tecla para contar otro genero).\n\n");
        fflush(stdin);
        opcion= getch();
    }
    while(opcion!=ESC);
    return 0;
}

///Ejercicio 1
int cargarAlumnos (stAlumno alumnos[], int dim){
    int i=0;
    char opcion;

    printf("MENU DE CARGA DE ALUMNOS.\n");
    printf("Desea cargar un alumno (s/n)? ");
    fflush(stdin);
    do{
        scanf("%c", &opcion);
        if(opcion!='s' && opcion!='n'){
            printf("\nError. Intentelo nuevamente (debe ingresar s si desea cargar o n si no desea cargar): ");
            scanf("%c", &opcion);
        }
    }
    while(opcion!='s' && opcion!='n');

    if(opcion=='s'){
        while(opcion!=ESC && i<dim){
            printf("\nCarga de alumno:\n");
            printf("Matricula: ");
            scanf("%d", &alumnos[i].matricula);
            printf("Nombre: ");
            fflush(stdin);
            gets(alumnos[i].nombre);
            do{
                printf("Genero (m/ f/ o): ");
                fflush(stdin);
                scanf("%c", &alumnos[i].genero);
                if(alumnos[i].genero!='m' && alumnos[i].genero!='f' && alumnos[i].genero!='o'){
                    printf("\nError al ingresar el genero. Intentelo nuevamente.\n");
                }
            }
            while(alumnos[i].genero!='m' && alumnos[i].genero!='f' && alumnos[i].genero!='o');
            printf("\nPresione cualquier tecla para cargar un nuevo alumno (ESC para salir de la carga).\n");
            fflush(stdin);
            opcion=getch();
            i++;
        }
    }
    return i;
}

///Ejercicio 2
void mostrarGenero (stAlumno alumnos[], int pos){

    if(alumnos[pos].genero=='m'){
        printf("\nGenero..........: Masculino.");
    }
    else if(alumnos[pos].genero=='f'){
        printf("\nGenero..........: Femenino.");
    }
    else{
        printf("\nGenero..........: Otro.");
    }
}

void mostrarAlumnos (stAlumno alumnos[], int validos){
    int i=0;

    while(i<validos){
        mostrarUnAlumno(alumnos, i);
        i++;
    }
}

void mostrarUnAlumno (stAlumno alumno[], int pos){

    printf("\nMatricula......: %d.", alumno[pos].matricula);
    printf("\nNombre.........: %s.", alumno[pos].nombre);
    mostrarGenero(alumno, pos);
    printf("\n");
}

///Ejercicio 3
int posAlumnoPorMatricula (stAlumno alumno[], int validos, int matri){
    int i=0;
    int pos=-1;

    while(pos==-1 && i<validos){
        if(alumno[i].matricula==matri){
            pos=i;
        }
        i++;
    }
    return pos;
}

void mostrarAlumnoPorMatricula (stAlumno alumno[], int validos, int matri){
    int pos=0;

    pos=posAlumnoPorMatricula(alumno, validos, matri);

    mostrarUnAlumno(alumno, pos);
}

int posAlumnoPorNombre (stAlumno alumno[], int validos, char nombre[]){
    int i=0;
    int pos=-1;

    while(pos==-1 && i<validos){
        if(strcmp(alumno[i].nombre, nombre)==0){
            pos=i;
        }
        i++;
    }
    return pos;
}

void mostrarAlumnoPorNombre (stAlumno alumno[], int validos, char nombre[]){
    int pos=0;

    pos=posAlumnoPorNombre(alumno, validos, nombre);

    mostrarUnAlumno(alumno, pos);
}

///Ejercicio 5
void mostrarAlumnoPorGenero (stAlumno alumno[], int validos, char genero){
    int i=0;
    int contador=0;

    while(i<validos){
        if(genero==alumno[i].genero){
            mostrarUnAlumno(alumno, i);
            contador++;
        }
        i++;
    }
    if(contador==0){
        printf("\nNo existen alumnos que cumplan con esas condiciones.\n");
    }
}

///Ejercicio 4
int posMenorMatricula (stAlumno alumno[], int validos, int pos){
    int posMenor= pos;
    int i=pos+1;
    int menor= alumno[pos].matricula;

    while(i<validos){
        if(menor>alumno[i].matricula){
            menor= alumno[i].matricula;
            posMenor= i;
        }
        i++;
    }
    return posMenor;
}

void intercambioAlumnos (stAlumno alumno[], int i, int pos){
    stAlumno aux;

    aux= alumno[pos];
    alumno[pos]=alumno[i];
    alumno[i]= aux;
}

void ordenarAlumnosPorMatricula (stAlumno alumno[], int validos){
    int i=0;
    int pos=0;
    stAlumno aux;

    while(i<validos){
        pos= posMenorMatricula(alumno, validos, i);
        intercambioAlumnos(alumno, i, pos);
        i++;
    }
}

///Ejercicio 6
stAlumno cargarUnAlumno (){
    stAlumno alumno;

    printf("\nCarga de alumno:\n");
    printf("Matricula: ");
    scanf("%d", &alumno.matricula);
    printf("Nombre: ");
    fflush(stdin);
    gets(alumno.nombre);
    do{
        printf("Genero (m/ f/ o): ");
        fflush(stdin);
        scanf("%c", &alumno.genero);
        if(alumno.genero!='m' && alumno.genero!='f' && alumno.genero!='o'){
            printf("\nError al ingresar el genero. Intentelo nuevamente.\n");
        }
    }
    while(alumno.genero!='m' && alumno.genero!='f' && alumno.genero!='o');

    return alumno;
}

int insertarAlumno (stAlumno alumno[],int validos, stAlumno nuevoAl){
    int i=validos-1;

    while(i>=0 && alumno[i].matricula>nuevoAl.matricula){
        alumno[i+1]= alumno[i];
        i--;
    }
    alumno[i+1]= nuevoAl;
    return validos+1;
}

///Ejercicio 7
void insertarPorNombre (stAlumno alumnos[], int pos, stAlumno dato){
    int i=pos;

    while(i>=0 && strcmpi(alumnos[i].nombre, dato.nombre)>0){
        alumnos[i+1]= alumnos[i];
        i--;
    }
    alumnos[i+1]= dato;
}

void ordenarPorInsercion (stAlumno alumnos[], int validos){
    int i=0;

    while(i<validos-1){
        insertarPorNombre(alumnos, i, alumnos[i+1]);
        i++;
    }
}

///Ejercicio 8
int contarTipoGenero (stAlumno alumnos[], int validos, char gen){
    int i=0;
    int contador=0;

    while(i<validos){
        if(alumnos[i].genero==gen){
            contador++;
        }
        i++;
    }
    return contador;
}

