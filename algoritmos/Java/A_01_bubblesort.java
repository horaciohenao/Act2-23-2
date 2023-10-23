import java.util.Random;

class A_01_bubblesort {
    
    // Crea un funcion para imprimir un array int
    public static void printArr ( int[] values ) {

        System.out.print("[ ");

        // Recorre el array
        for ( int i = 0; i < values.length; i++ ) {

            System.out.print(values[i] + " ");

        }

        System.out.print("]\n");
        
    }

    // funcion para aplicar un bubblesort
    public static void bubbleSort ( int[] values ) {

        // recorre el array
        for ( int index = 0; index < values.length; index++ ) {
            
            // recorre el arrya menos el ultimo elemento
            for ( int index2 = 0; index2 < values.length - 1; index2++ ) {

                // si el valor en index2 es mayor al de index2 + 1 los intercambia
                if ( values[index2] > values[index2+1] ) {

                    int temp = values[index2];

                    values[index2] = values[index2+1];

                    values[index2+1] = temp;
                    
                }

                // imprime el estado actual del array en esa interacion
                printArr(values);
                
            }

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

        // aplica el bubblesort
        System.out.println("= Ordenando Array =");
        bubbleSort(arrInt);

        // imprime el array ordenado
        System.out.println("= Array ordenado =");
        printArr(arrInt);
        
    }

}