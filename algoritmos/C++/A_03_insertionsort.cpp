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

// funcion para aplicar un insertionsort
void insertionSort( int values[], int size) {

    // recorre el array asumiendo que el primer valor ya está ordenado
    for ( int i = 1; i < size; i++ ) {
        
        // si el valor en i es menor al valor anterior en i
        if ( values[i] < values[i - 1] ) {
            
            // usa i como pivote
            int piv = values[i];
            
            // crea una variable temporal para i
            int temp = i;
            
            // desplaza los valores a la izquierda mientras que no sean 
            // temp 0 para eviar un outOfBounds
            // values[temp - 1] > piv para que no reemplace un valor menor al pivote actual
            while ( temp > 0 && values[temp - 1] > piv ) {
                
                // toma el valor anterior y lo reemplaza con el actual
                values[temp] = values[temp - 1]; 
                
                temp--;
                
            }
            
            // reemplaza la ubicacion actual de temp con el pivote
            // "lo inserta"
            values[temp] = piv;
            
        }
        
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

    // aplica el insertionsort
    printf("= Ordenando Array =\n");
    insertionSort(arrInt, size);

    // imprime el array ordenado
    printf("= Array ordenado =\n");
    printArr(arrInt, size);

}