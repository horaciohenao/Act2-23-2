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

// funcion "esta ordenado?"
bool isSort ( int values[], int size ) {

    // recorre el array
    for ( int i = 1; i < size; i++ ) {
        
        // si el valor en i es menor al valor anterior entonces no esta ordenado
        if ( values[i] < values[i - 1] ) {

            return false;

        }

    }

    // si al recorrer el array no se cumple el if está ordenado
    return true;
    
}

// funcion para aplicar un bogosort
void bogoSort ( int values[], int size) {

    // semilla de generacion de numeros
    srand(time(NULL));

    // mientras isSort sea falso
    while ( isSort(values, size) == false ) {

        // recorre el array
        for ( int index = 0; index < size; index++ ) {

            int randInt = randomInt(0, size);

            // intercambia valores aleatorios
            int temp = values[ randInt ];

            values[ randInt ] = values[index];

            values[index] = temp;

            randInt = randomInt(0, size);

            // intercambia valores aleatorios
            temp = values[ randInt ];

            values[ randInt ] = values[index];

            values[index] = temp;

            // imprime el estado actual del array luego de modificarlo
            printArr(values, size);

        }
            
    }

}

int main() {

    // semilla de generacion de numeros
    srand(time(NULL));

    // crea un array de 3 espacios
    int arrInt[3];

    // guarda su tamaño en una variable
    int size = sizeof(arrInt) / sizeof(arrInt[0]);

    // asigna valores aleatorios
    for (int i = 0; i < size; i++) {

        arrInt[i] = randomInt(1, 8);
        
    }
    
    // imprime el array original
    printf("= Array original =\n");
    printArr(arrInt, size);

    // aplica el bogosort
    printf("= Ordenando Array =\n");
    bogoSort(arrInt, size);

    // imprime el array ordenado
    printf("= Array ordenado =\n");
    printArr(arrInt, size);

}