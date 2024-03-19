#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

void cargarPilaRandom(Pila *p);

int main()
{
    char control;
    int opcion;

    Pila dada;
    inicpila(&dada);

    do {
        printf("TP 2 - FUNCIONES CON PILAS\n\n");
        printf("1  -  Ejercicio 1\n");
        printf("2  -  Ejercicio 2\n");
        printf("3  -  Ejercicio 3\n");
        printf("4  -  Ejercicio 4\n");
        printf("5  -  Ejercicio 5\n");
        printf("6  -  Ejercicio 6\n");
        printf("7  -  Ejercicio 7\n");
        printf("8  -  Ejercicio 8\n");
        printf("9  -  Ejercicio 9\n");
        printf("10  -  Ejercicio 10\n");
        printf("11  -  Ejercicio 11\n");
        printf("12  -  Ejercicio 12\n\n");
        printf("Ingrese opcion numerica\n");
        fflush(stdin);
        scanf("%d", &opcion);
        printf("Desea salir: s/n");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");

        switch(opcion){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            default:
                printf("La opcion ingresada no es valida.");
        }

    } while(control=='s');

    cargarPilaRandom(&dada);

    mostrar(&dada);

    return 0;
}

void cargarPilaRandom(Pila *p){
    char control;

    do
    {
        leer(p);

        printf("\nDesea continuar? s/n");
        fflush (stdin);
        scanf("%c", &control);

    }
    while (control=='s');
}
