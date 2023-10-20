import java.util.Random;

class A_02_bogosort {

    // Crea un funcion para imprimir un array int
    public static void printArr ( int[] values ) {

        // Recorre el array
        for ( int i = 0; i < values.length; i++ ) {

            System.out.print(values[i] + " ");

        }

        System.out.print("]\n");
        
    }

    // funcion "esta ordenado?"
    public static boolean isSort ( int[] values ) {

        // recorre el array
        for ( int i = 1; i < values.length; i++ ) {
            
            // si el valor en i es menor al valor anterior entonces no esta ordenado
            if ( values[i] < values[i - 1] ) {

                return false;

            }

        }

        // si al recorrer el array no se cumple el if está ordenado
        return true;
        
    }

    // funcion para aplicar un bogosort
    public static void bogoSort ( int[] values ) {

        // crea un random
        Random ranIntIns = new Random();

        // mientras isSort sea falso
        while ( isSort(values) == false ) {

        // recorre el array
        for ( int index = 0; index < values.length; index++ ) {

            int random = ranIntIns.nextInt(values.length);

                // si el valor en random es mayor al de index los intercambia
                if ( values[random] > values[index] ) {

                    int temp = values[random];

                    values[random] = values[index];

                    values[index] = temp;
                    
                }

            System.out.print("[ ");

            // imprime el estado actual del array luego de modificarlo
            printArr(values);

        }
            
    }

}

    public static void main(String[] args) {

        // crea un random
        Random ranInt = new Random();

        // crea un array int de 5 espacios 
        int[] arrInt = new int[3];

        // asgina valores aleatorios 
        for ( int i = 0; i < arrInt.length; i++ ) {
            
            arrInt[i] = ranInt.nextInt(8)+1;

        }

        // imprime el array original
        System.out.print("= Array original =\n[ ");
        printArr(arrInt);

        // aplica el bogosort
        System.out.print("= Ordenando Array =\n");
        bogoSort(arrInt);

        // imprime el array ordenado
        System.out.print("= Array ordenado =\n[ ");
        printArr(arrInt);
        
    }

}