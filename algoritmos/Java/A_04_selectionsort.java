import java.util.Random;

public class A_04_selectionsort {

    // Crea un funcion para imprimir un array int
    public static void printArr ( int[] values ) {
    
        System.out.print("[ ");

        // Recorre el array
        for ( int i = 0; i < values.length; i++ ) {

            System.out.print(values[i] + " ");

        }

        System.out.print("]\n");
        
    }

    // funcion para aplicar un selectionsort
    public static void selectionSort ( int[] values ) {

        // recorre el array
        for ( int i = 0; i < values.length; i++ ) {
    
            // toma index como pivote
            int minI = i; 
    
            // recorre el array para buscar un nuevo valor más bajo desde del ultimo más bajo, i
            for ( int j = i; j < values.length; j++ ) {
    
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
            printArr(values);

        }

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
        System.out.println("= Array original =");
        printArr(arrInt);

        // aplica el selectionSort
        System.out.println("= Ordenando Array ");
        selectionSort(arrInt);

        // imprime el array ordenado
        System.out.println("= Array ordenado =");
        printArr(arrInt);
        
    }

}