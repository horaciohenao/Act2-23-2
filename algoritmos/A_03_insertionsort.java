import java.util.Random;

public class A_03_insertionsort {

    // Crea un funcion para imprimir un array int
    public static void printArr ( int[] values ) {

        // Recorre el array
        for ( int i = 0; i < values.length; i++ ) {

            System.out.print(values[i] + " ");

        }

        System.out.print("]\n");
        
    }

    // funcion para aplicar un insertionSort
    public static void insertionSort ( int[] values ) {

        for (int i = 0; i < values.length; i++) {
            
        }
    
            System.out.print("[ ");
    
            // imprime el estado actual del array luego de modificarlo
            printArr(values);


    }

    public static void main(String[] args) {

        // crea un random
        Random ranInt = new Random();

        // crea un array int de 10 espacios 
        int[] arrInt = new int[10];

        // asgina valores aleatorios 
        for ( int i = 0; i < arrInt.length; i++ ) {
            
            arrInt[i] = ranInt.nextInt(8)+1;

        }

        // imprime el array original
        System.out.print("= Array original =\n[ ");
        printArr(arrInt);

        // aplica el insertionsort
        System.out.print("= Ordenando Array =\n");
        insertionSort(arrInt);

        // imprime el array ordenado
        System.out.print("= Array ordenado =\n[ ");
        printArr(arrInt);
        
    }

}