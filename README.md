# Trabajo Práctico N° : Funciones con pilas

NOTA: todas las funciones pedidas deben recibir por parámetro la/s pila/s cargadas con los datos. No se debe usar la función leer() dentro de la función, excepto en la función 1. 

Realizar todas las funciones en un mismo proyecto, para ir probando su correcto funcionamiento deberá desarrollar una función main, donde cree las variables y pilas que necesite, e invoque a las funciones como corresponda en cada caso.

Se sugiere crear un menú de opciones para que el usuario del sistema ejecute cada una de las funciones cuando lo desee. Asimismo, utilizar una estructura switch que ejecute cada opción elegida, contenido dentro de un do-while, que finalice cuando el usuario lo requiera.

1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario. 
2. Hacer una función que pase todos los elementos de una pila a otra. 
3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden. 
4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.
5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)
6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta. 
7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción)
8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar su contenido. 
9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3. 
10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de quien usa el programa) y que transforme esos dígitos en un número decimal. Por ejemplo, la pila:

1

4

6

7

5

Debe retornar el número: 14675

Ejercicios extra: Con el fin de generar una experiencia de usuario diferente a la que otorga la librería se requiere desarrollar las siguientes funciones:
- Realizar una función que cargue la pila sin utilizar la función leer.
- Realizar una función que muestre la pila sin utilizar la función mostrar.


# CODIGO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int cargarArreglo(int *arreglo);
void mostrarArreglo(int arreglo[], int validos);
int sumaElementosArreglo(int arreglo[], int validos);
void copiaArregloAPila(int arreglo[], int validos, Pila *p);
void cargarArrFloat(float *arreglo);
//void mostrarArrFloat(float arreglo[]);
float sumaArrFloat(float arreglo[]);
void encuentraElementoArrChar(char arreglo[], char elemento);
void insertarCharManteniendoOrden(char *arreglo, char elemento);
void mostrarArrChar(char arreglo[]);

int main()
{

    srand(time(NULL));

    int arreglo[100];
    int validos = 0;
    int sumaArreglo;
    Pila pila1;
    inicpila(&pila1);
    float arrfloat[100];
    float sumaFloat;
    char arrChar[] = {'a', 'c', 'd', 'e', 'g'};
    char elemento;


    validos = cargarArreglo(arreglo);

    printf("\nCantidad de elementos en el arreglo: %i", validos);

    mostrarArreglo(arreglo, validos);

    sumaArreglo = sumaElementosArreglo(arreglo, validos);
    printf("\nLa suma de los elementos del arreglo es: %i", sumaArreglo);

    copiaArregloAPila(arreglo, validos, &pila1);
    printf("\nPila1: ");
    mostrar(&pila1);

    cargarArrFloat(arrfloat);
//    mostrarArrFloat(arrfloat);
    sumaFloat = sumaArrFloat(arrfloat);
    printf("\nLa suma de los elementos de un arreglo de numeros reales es: %.2f", sumaFloat);

    printf("\nIngrese un elemento para verificar si se encuentra en los datos: ");
    fflush(stdin);
    scanf("%c", &elemento);
    encuentraElementoArrChar(arrChar, elemento);

    printf("Elemento ingresado.");
    insertarCharManteniendoOrden(arrChar, elemento);
    mostrarArrChar(arrChar);

    return 0;

}

int cargarArreglo(int *arreglo){

    int cantidad;

    printf("\nIngrese la cantidad de elementos a cargar: ");
    scanf("%i", &cantidad);

    printf("\nIngrese los elementos del arreglo: \n");

    for(int i = 0; i < cantidad; i++){
        printf("Elemento %i: ", i+1);
        scanf("%i", arreglo + i);
    }

    return cantidad;

}

void mostrarArreglo(int arreglo[], int validos){

    printf("\nEl arreglo: ");

    for(int i = 0; i < validos; i++){
        printf("%i | ", arreglo[i]);
    }

}

int sumaElementosArreglo(int arreglo[], int validos){

    int suma = 0;

    for(int i = 0; i < validos; i++){
        suma += arreglo[i];
    }

    return suma;

}

void copiaArregloAPila(int arreglo[], int validos, Pila *p){

    for(int i = 0; i < validos; i++){
        apilar(p, arreglo[i]);
    }

}

void cargarArrFloat(float *arreglo){

    int random;

    for(int i = 0; i < 100; i++){
        random = rand() % 101;
        arreglo[i] = random;
    }

}

//    void mostrarArrFloat(float arreglo[]){
//
//    printf("\nEl arreglo: ");
//
//    for(int i = 0; i < 100; i++){
//        printf("%.2f | ", arreglo[i]);
//    }
//
//}

float sumaArrFloat(float arreglo[]){
    float suma = 0;

    for(int i = 0; i < 100; i++){
        suma += arreglo[i];
    }

    return suma;
}

void encuentraElementoArrChar(char arreglo[], char elemento){

    int flag = 0;
    int i = 0;

    while(i < 6 && flag == 0){
        if(elemento == arreglo[i]){
            flag = 1;
        } else {
            flag = 0;
        }
        i++;
    }

    if(flag == 1){
        printf("\nEl elemento se encuentra dentro del arreglo.");
    } else {
        printf("\nEl elemento no se encuentra dentro del arreglo.");
    }

}

///7

void insertarCharManteniendoOrden(char *arreglo, char elemento){

}

void mostrarArrChar(char arreglo[]){

    printf("\nEl arreglo: ");

    for(int i = 0; i < 6; i++){
        printf("%c | ", arreglo[i]);
    }

}

///8

///9

