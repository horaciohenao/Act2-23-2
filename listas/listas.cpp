#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Crea una funcion para imprimir un vector int
void printVector( vector<int> values ) {

    printf("[ ");
    
    // Recorre el array
    for ( int i = 0; i < values.size(); i++ ) {

        printf("%i, ", values[i]);

    }

    printf("]\n");
    
}

// funcion para generar numero aletatorio
int randomInt( int min, int max ) {

    // retorna un numero aleatorio
    return rand() % max + 2 - min ;

}

// funcion para aplicar un bubblesort
void bubbleSort( vector<int>& values ) {

    // recorre el array
    for ( int index = 0; index < values.size(); index++ ) {
        
        // recorre el arrya menos el ultimo elemento
        for ( int index2 = 0; index2 < values.size() - 1; index2++ ) {

            // si el valor en index2 es mayor al de index2 + 1 los intercambia
            if ( values[index2] > values[index2+1] ) {

                int temp = values[index2];

                values[index2] = values[index2+1];

                values[index2+1] = temp;
                
            }
            
        }

    }

}

// funcion para aplicar un selectionsort
void selectionSort( vector<int>& values ) {

    // recorre el array
    for ( int i = 0; i < values.size(); i++ ) {

        // toma index como pivote
        int minI = i; 

        // recorre el array para buscar un nuevo valor más bajo desde del ultimo más bajo, i
        for ( int j = i; j < values.size(); j++ ) {

            // si valor actual en j es menor a minI actual y actualiza minI
            if ( values[j] < values[minI] ) {

                minI = j;

            }

        }

        // los intercambia
        int temp = values[minI];

        values[minI] = values[i];

        values[i] = temp;

    }

}

// funcion para aplicar un insertionsort
void insertionSort( vector<int>& values ) {

    // recorre el array asumiendo que el primer valor ya está ordenado
    for ( int i = 1; i < values.size(); i++ ) {
        
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
    }

}

int main() {

    // semilla de generacion de numeros
    srand(time(NULL));

    // Crear una lista (vector)
    vector<int> listaPersonalizada(10);

    // Asgina valores aleatorios
    for (int i = 0; i < 10; i++) {

        listaPersonalizada[i] = randomInt(1, 8);

    }

    printf("Lista desordenada: ");
    printVector(listaPersonalizada);
    // Se aplica el bubbleSort
    bubbleSort(listaPersonalizada);
    printf("Lista ordenada con bubbleSort: ");
    printVector(listaPersonalizada);
    printf("=====\n");

    // Asgina valores aleatorios 
    for (int i = 0; i < 10; i++) {
        listaPersonalizada[i] = randomInt(1, 8);
    }

    printf("Lista desordenada: ");
    printVector(listaPersonalizada);
    // Se aplica el selectionSort
    selectionSort(listaPersonalizada);
    printf("Lista ordenada con selectionSort: ");
    printVector(listaPersonalizada);
    printf("=====\n");

    // Asgina valores aleatorios 
    for (int i = 0; i < 10; i++) {
        listaPersonalizada[i] = randomInt(1, 8);
    }

    printf("Lista desordenada: ");
    printVector(listaPersonalizada);
    // Se aplica el insertionSort
    insertionSort(listaPersonalizada);
    printf("Lista ordenada con insertionSort: ");
    printVector(listaPersonalizada);
    printf("=====\n");

    // Asgina valores aleatorios 
    for (int i = 0; i < 10; i++) {
        listaPersonalizada[i] = randomInt(1, 8);
    }

    printf("Lista desordenada: ");
    printVector(listaPersonalizada);

    // Elimina el primer elemento de la lista
    listaPersonalizada.erase(listaPersonalizada.begin());

    // Obtiene el cuarto elemento de la lista
    int index = distance(listaPersonalizada.begin(), find(listaPersonalizada.begin(), listaPersonalizada.end(), 3));

    // Organiza los elementos de la lista
    sort(listaPersonalizada.begin(), listaPersonalizada.end());

    printf("Lista ordenada por metodo del SDK, luego de agregar y elimnar valores: ");
    printVector(listaPersonalizada);

    return 0;
}
