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

// funcion para aplicar un bubblesort
void bubbleSort( int values[], int size) {

    // recorre el array
    for ( int index = 0; index < size; index++ ) {
        
        // recorre el arrya menos el ultimo elemento
        for ( int index2 = 0; index2 < size - 1; index2++ ) {

            // si el valor en index2 es mayor al de index2 + 1 los intercambia
            if ( values[index2] > values[index2+1] ) {

                int temp = values[index2];

                values[index2] = values[index2+1];

                values[index2+1] = temp;
                
            }

            // imprime el estado actual del array en esa interacion
            printArr(values, size);
            
        }

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

    // aplica el bubblesort
    printf("= Ordenando Array =\n");
    bubbleSort(arrInt, size);

    // imprime el array ordenado
    printf("= Array ordenado =\n");
    printArr(arrInt, size);

}