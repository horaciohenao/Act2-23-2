#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// Crea una funcion para imprimir un array int
void printArr( int values[], int size ) {

    printf("[ ");
    
    // Recorre el array
    for ( int i = 0; i < size; i++ ) {

        printf("%i ", values[i]);

    }

    printf("]\n");
    
}

// funcion para generar numero aletatorio
int randomInt( int min, int max ) {

    // retorna un numero aleatorio
    return rand() % max + 2 - min ;

}

// funcion para aplicar un selectionsort
void selectionSort( int values[], int size) {

    // recorre el array
    for ( int i = 0; i < size; i++ ) {

        // toma index como pivote
        int minI = i; 

        // recorre el array para buscar un nuevo valor más bajo desde del ultimo más bajo, i
        for ( int j = i; j < size; j++ ) {

            // si valor actual en j es menor a minI actual y actualiza minI
            if ( values[j] < values[minI] ) {

                minI = j;

            }

        }

        // los intercambia
        int temp = values[minI];

        values[minI] = values[i];

        values[i] = temp;

        // imprime el estado actual del array luego de modificarlo
        printArr(values, size);

    }

}

int main() {

    // semilla de generacion de numeros
    srand(time(NULL));

    // crea un array de 10 espacios
    int arrInt[10];

    // guarda su tamaño en una variable
    int size = sizeof(arrInt) / sizeof(arrInt[0]);

    // asigna valores aleatorios
    for (int i = 0; i < size; i++) {

        arrInt[i] = randomInt(1, 8);
        
    }
    
    // imprime el array original
    printf("= Array original =\n");
    printArr(arrInt, size);

    // aplica el selectionsort
    printf("= Ordenando Array =\n");
    selectionSort(arrInt, size);

    // imprime el array ordenado
    printf("= Array ordenado =\n");
    printArr(arrInt, size);

}