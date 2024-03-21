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

void cargarPila(Pila *p);
void pasarElementos(Pila p, Pila *q);
void pasarElementosConservandoOrden(Pila p, Pila *q);
int encuentraEliminaRetornaMenorValor(Pila *p);
void pasarElementosANuevaPilaOrdenada(Pila p, Pila *q);
void insertarDatoEnOrden(Pila *p, int dato);
///void insertarDatoEnOrden(Pila *p, Pila *q);
void insertarPilaDesordenadaEnOrdenada(Pila *p, Pila *q);
int retornaSumaTopeYAnterior(Pila p);
int sumaElementosPila(Pila p);
int cantidadElementosPila(Pila p);
float divisionSumaCantidad(int p, int q);
float promedioElementosPila(Pila p);

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
        system("cls");

        switch(opcion){
            case 1:
                printf("1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.\n\n");

                cargarPila(&dada);

                mostrar(&dada);

                break;
            case 2:
                printf("2. Hacer una función que pase todos los elementos de una pila a otra.\n\n");

                Pila aux;
                inicpila(&aux);

                pasarElementos(dada, &aux);

                printf("DADA");
                mostrar(&dada);
                printf("AUX");
                mostrar(&aux);

                break;
            case 3:
                printf("3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.\n\n");

                Pila aux2;
                inicpila(&aux2);

                pasarElementosConservandoOrden(dada, &aux2);

                printf("DADA");
                mostrar(&dada);
                printf("AUX2");
                mostrar(&aux2);

                break;
            case 4:
                printf("4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.\n\n");

                int menor;

                printf("DADA");
                mostrar(&dada);

                menor = encuentraEliminaRetornaMenorValor(&dada);

                printf("DADA");
                mostrar(&dada);

                printf("El menor de los valores: %i", menor);

                break;
            case 5:
                printf("5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)\n\n");

                Pila aux3;
                inicpila(&aux3);

                /*printf("DADA");
                mostrar(&dada);*/

                pasarElementosANuevaPilaOrdenada(dada, &aux3);

                printf("DADA");
                mostrar(&dada);
                printf("AUX3");
                mostrar(&aux3);

                break;
            case 6:
                printf("6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.\n\n");

                int elemento = 0;

                printf("Ingrese el elemento que desee introducir a la pila: ");
                scanf("%d", &elemento);

                insertarDatoEnOrden(&dada, elemento);

                printf("DADA con elemento ingresado: ");
                mostrar(&dada);

                /**Pila elemento;
                inicpila(&elemento);

                printf("Ingresar el elemento que desee introducir a la pila: \n");
                leer(&elemento);

                insertarDatoEnOrden(&dada, &elemento);

                printf("DADA con elemento ingresado: ");
                mostrar(&dada);*/

                break;
            case 7:
                printf("7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción)\n\n");

                Pila desordenada;
                Pila ordenada;
                inicpila(&desordenada);
                inicpila(&ordenada);

                cargarPila(&desordenada);

                printf("DESORDENADA");
                mostrar(&desordenada);
                printf("ORDENADA vacia");
                mostrar(&ordenada);

                insertarPilaDesordenadaEnOrdenada(&ordenada, &desordenada);

                printf("ORDENADA");
                mostrar(&ordenada);

                break;
            case 8:
                printf("8. Hacer una función que sume los dos primeros elementos de una pila (tope y anterior), y retorne la suma,  sin alterar el contenido de la pila.\n\n");

                int sumaTopeYAnterior = 0;

                sumaTopeYAnterior = retornaSumaTopeYAnterior(dada);

                printf("El resultado de la suma del tope de la pila y su anterior es: %i", sumaTopeYAnterior);

                break;
            case 9:
                printf("9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3.\n\n");

                /**int sumaElementos = 0;
                int cantidadElementos = 0;
                float division = 0;

                sumaElementos = sumaElementosPila(dada);
                cantidadElementos = cantidadElementosPila(dada);
                division = divisionSumaCantidad(sumaElementos, cantidadElementos);

                printf("Suma de elementos de la pila: %i", sumaElementos);
                printf("\nCantidad de elementos de la pila: %i", cantidadElementos);
                printf("\nResultado de la division de la suma de elementos y la cantidad: %.2f", division);*/

                float promedio = 0;

                promedio = promedioElementosPila(dada);

                printf("El promedio de los elementos de una pila es: %.2f", promedio);

                break;
            case 10:
                printf("10. Hacer una funcion que reciba una pila con numeros de un solo digito (es responsabilidad de quien usa el programa) y que transforme esos digitos en un numero decimal.\n\n");



                break;
            case 11:
                printf("Realizar una funcion que cargue la pila sin utilizar la funcion leer.\n\n");
                break;
            case 12:
                printf("Realizar una funcion que muestre la pila sin utilizar la funcion mostrar.\n\n");
                break;
            default:
                printf("La opcion ingresada no es valida.");
        }
        printf("\nDesea salir: s/n\n");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");
    } while(control == 'n' || control == 'N');

    return 0;
}

void cargarPila(Pila *p){
    char control;

    do
    {
        leer(p);

        printf("\nDesea continuar? s/n\n");
        fflush (stdin);
        scanf("%c", &control);

    }
    while (control=='s');
}

void pasarElementos(Pila p, Pila *q){ //Pila p es una copia de la pila dada. Pila *q hace referencia a la direccion de memoria de la pila aux
    while(!pilavacia(&p)){
        apilar(q, desapilar(&p));
    }
}

void pasarElementosConservandoOrden(Pila p, Pila *q){
    Pila aux;
    inicpila(&aux);

    pasarElementos(p, &aux);
    pasarElementos(aux, q);
}

int encuentraEliminaRetornaMenorValor(Pila *p){
    Pila aux;
    inicpila(&aux);

    int menor;

    if(!pilavacia(p)){
        menor = desapilar(p);
    }

    while(!pilavacia(p)){
        if(menor > tope(p)){
            apilar(&aux, menor);
            menor = desapilar(p);
        } else {
            apilar(&aux, desapilar(p));
        }
    }

    pasarElementos(aux, p);

    return menor;
}

void pasarElementosANuevaPilaOrdenada(Pila p, Pila *q){
    Pila aux;
    inicpila(&aux);

    pasarElementos(p, &aux);

    while(!pilavacia(&aux)){
        int menor = encuentraEliminaRetornaMenorValor(&aux);
        apilar(q, menor);
    }
}

void insertarDatoEnOrden(Pila *p, int dato){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p) && dato < tope(p)){
        apilar(&aux, desapilar(p));
    }

    apilar(p, dato);

    pasarElementos(aux, p);
}

/// Si el dato fuera una pila

/**void insertarDatoEnOrden(Pila *p, Pila *q){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p) && tope(q) < tope(p)){
        apilar(&aux, desapilar(p));
    }

    apilar(p, desapilar(q));

    pasarElementos(aux, p);
}**/

void insertarPilaDesordenadaEnOrdenada(Pila *p, Pila *q){
    while(!pilavacia(q)){
        insertarDatoEnOrden(p, desapilar(q));
    }
}

int retornaSumaTopeYAnterior(Pila p){
    int suma = 0;

    if(!pilavacia(&p)){
        suma += desapilar(&p);
        if(!pilavacia(&p)){
            suma += desapilar(&p);
        }
    }

    return suma;
}

int sumaElementosPila(Pila p){
    int suma = 0;

    while(!pilavacia(&p)){
        suma += desapilar(&p);
    }

    return suma;
}

int cantidadElementosPila(Pila p){
    int contador = 0;

    while(!pilavacia(&p)){
        contador ++;
        desapilar(&p);
    }

    return contador;
}

float divisionSumaCantidad(int p, int q){
    int division = 0;

    division = (float) p / q;

    return division;
}

float promedioElementosPila(Pila p){
    float promedio = 0;
    int suma = 0, cantidad = 0;

    suma = sumaElementosPila(p);
    cantidad = cantidadElementosPila(p);
    promedio = divisionSumaCantidad(suma, cantidad);

    return promedio;
}



