#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

void cargarPila(Pila *p);
void pasarElementos(Pila p, Pila *q);
void pasarElementosConservandoOrden(Pila p, Pila *q);
int encuentraEliminaRetornaMenorValor(Pila *p);
void pasarElementosANuevaPilaOrdenada(Pila p, Pila *q);

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
                printf("1. Hacer una funcion que permita ingresar varios elementos a una pila, tanto como quiera el usuario.\n\n");

                cargarPila(&dada);

                mostrar(&dada);

                break;
            case 2:
                printf("2. Hacer una funcion que pase todos los elementos de una pila a otra.\n\n");

                Pila aux;
                inicpila(&aux);

                pasarElementos(dada, &aux);

                printf("DADA");
                mostrar(&dada);
                printf("AUX");
                mostrar(&aux);

                break;
            case 3:
                printf("3. Hacer una funcion que pase todos los elementos de una pila a otra, pero conservando el orden.\n\n");

                Pila aux2;
                inicpila(&aux2);

                pasarElementosConservandoOrden(dada, &aux2);

                printf("DADA");
                mostrar(&dada);
                printf("AUX2");
                mostrar(&aux2);

                break;
            case 4:
                printf("4. Hacer una funcion que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.\n\n");

                int menor;

                printf("DADA");
                mostrar(&dada);

                menor = encuentraEliminaRetornaMenorValor(&dada);

                printf("DADA");
                mostrar(&dada);

                printf("El menor de los valores: %i", menor);

                break;
            case 5:
                printf("5. Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funcion del ejercicio 4. (Ordenamiento por selección)\n\n");

                Pila aux3;
                inicpila(&aux3);

                printf("DADA");
                mostrar(&dada);

                pasarElementosANuevaPilaOrdenada(dada, &aux3);

                printf("DADA");
                mostrar(&dada);
                printf("AUX3");
                mostrar(&aux3);

                break;
            case 6:
                printf("6. Hacer una funcion que inserta en una pila ordenada un nuevo elemento, conservando el orden de esta.\n\n");
                break;
            case 7:
                printf("7. Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funcion del ejercicio 6.  (Ordenamiento por inserción)\n\n");
                break;
            case 8:
                printf("8. Hacer una funcion que sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar su contenido.\n\n");
                break;
            case 9:
                printf("9. Hacer una funcion que calcule el promedio de los elementos de una pila, para ello hacer tambien una funcion que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la funcion que calcula el promedio invoca a las otras 3.\n\n");
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

    aux = p;

    printf("Pila aux");
    mostrar(&aux);

    while(!pilavacia(&p)){
        int menor = encuentraEliminaRetornaMenorValor(&p);
        apilar(q, menor);
    }

    pasarElementos(aux, &p);
}
