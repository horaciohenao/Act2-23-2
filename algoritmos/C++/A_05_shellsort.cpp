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

    for ( int pass = 0; pass != 3; pass++ ) {
    
        // un bucle for que recorre el array pero mientras que gap sea mayor que 0 y en cada intreacion su tamaño se reduce a la mitad
        for ( int gap = size / 2; gap > 0; gap /= 2 ) {

            // recorre el array hasta la longitud - el gap actual para evitar un outOfBounds
            for ( int i = 0; i < size - gap; i++ ) {
                    
                // si i actual es mayor a gap, osea no hay posibilidad de outOfBounds
                if ( i > gap ) {

                    // si el valor en i-gap es mayor que i los intercambia
                    if ( values[i-gap] > values[i] ) {
    
                        int temp2 = values[i];
    
                        values[i] = values[i-gap];
    
                        values[i-gap] = temp2;
                        
                    }
                    
                }
                
                // si el valor en i es mayor que i + gap los intercambia
                if ( values[i] > values[i+gap] ) {

                    int temp = values[i];

                    values[i] = values[i+gap];

                    values[i+gap] = temp;
                    
                }
        
                // imprime el estado actual del array luego de modificarlo
                printArr(values, size);
                
            }

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

    // aplica el selectionsort
    printf("= Ordenando Array =\n");
    selectionSort(arrInt, size);

    // imprime el array ordenado
    printf("= Array ordenado =\n");
    printArr(arrInt, size);

}