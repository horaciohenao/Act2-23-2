import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class listas { 
    
    // funcion para aplicar un bubblesort
    public static void bubbleSort ( List<Integer> values ) {

        // recorre el array
        for ( int index = 0; index < values.size(); index++ ) {
            
            // recorre el arrya menos el ultimo elemento
            for ( int index2 = 0; index2 < values.size() - 1; index2++ ) {

                // si el valor en index2 es mayor al de index2 + 1 los intercambia
                if ( values.get(index2) > values.get(index2+1) ) {

                    int temp = values.get(index2);

                    values.set(index2, values.get(index2+1));

                    values.set(index2+1, temp);
                    
                }
                
            }

        }
        
    }

    // funcion para aplicar un selectionsort
    public static void selectionSort ( List<Integer> values ) {

        // recorre el array
        for ( int i = 0; i < values.size(); i++ ) {
    
            // toma index como pivote
            int minI = i; 
    
            // recorre el array para buscar un nuevo valor más bajo desde del ultimo más bajo, i
            for ( int j = i; j < values.size(); j++ ) {
    
                // si valor actual en j es menor a minI actual y actualiza minI
                if ( values.get(j) < values.get(minI) ) {

                    minI = j;

                }
    
            }
    
            // los intercambia
            int temp = values.get(minI);
    
            values.set(minI, values.get(i));
    
            values.set(i, temp);

        }

    }

    // funcion para aplicar un insertionSort
    public static void insertionSort ( List<Integer> values ) {
    
    // recorre el array asumiendo que el primer valor ya está ordenado
    for ( int i = 1; i < values.size(); i++ ) {
        
        // si el valor en i es menor al valor anterior en i
        if ( values.get(i) < values.get(i - 1) ) {
            
            // usa i como pivote
            int piv = values.get(i);
            
            // crea una variable temporal para i
            int temp = i;
            
            // desplaza los valores a la izquierda mientras que no sean 
            // temp 0 para eviar un outOfBounds
            // values[temp - 1] > piv para que no reemplace un valor menor al pivote actual
            while ( temp > 0 && values.get(i - 1) > piv ) {
                
                // toma el valor anterior y lo reemplaza con el actual
                values.set(temp, values.get(i - 1)); 
                
                temp--;
                
            }
            
            // reemplaza la ubicacion actual de temp con el pivote
            // "lo inserta"
            values.set(temp, piv);
            
        }
    }
    
}

    public static void main(String[] args) {
        
        // Crea una lista
        List<Integer> listaPersonalizada = new ArrayList<>();

        // Crea un random
        Random ranInt = new Random();

        // Asgina valores aleatorios 
        for ( int i = 0; i < 10; i++ ) {
            
            listaPersonalizada.add(ranInt.nextInt(8)+1);

        }

        System.out.println("Lista desordenada: " + listaPersonalizada);
        // Se aplica el bubbleSort
        bubbleSort(listaPersonalizada);
        System.out.println("Lista ordenada con bubbleSort: " + listaPersonalizada);
        System.out.println("=====");

        // Asgina valores aleatorios 
        for ( int i = 0; i < 10; i++ ) {
            
            listaPersonalizada.set(i , ranInt.nextInt(8)+1);

        }
        
        System.out.println("Lista desordenada: " + listaPersonalizada);
        // Se aplica el selectionSort
        selectionSort(listaPersonalizada);
        System.out.println("Lista ordenada con selectionSort: " + listaPersonalizada);
        System.out.println("=====");

        // Asgina valores aleatorios 
        for ( int i = 0; i < 10; i++ ) {
            
            listaPersonalizada.set(i , ranInt.nextInt(8)+1);

        }
        
        System.out.println("Lista desordenada: " + listaPersonalizada);
        // Se aplica el insertionSort
        insertionSort(listaPersonalizada);
        System.out.println("Lista ordenada con insertionSort: " + listaPersonalizada);
        System.out.println("=====");

        // Asgina valores aleatorios 
        for ( int i = 0; i < 10; i++ ) {
            
            listaPersonalizada.set(i , ranInt.nextInt(8)+1);

        }
        
        System.out.println("Lista desordenada: " + listaPersonalizada);

        // Elimina el primer elemento de la lista
        listaPersonalizada.remove(0);

        // Obtiene el cuarto elemento de la lista
        listaPersonalizada.indexOf(3);

        // Organiza los elementos de la lista
        Collections.sort(listaPersonalizada);
        
        System.out.println("Lista ordenada por metodo del SDK, luego de agregar y elimnar valores: " + listaPersonalizada);

    }

}