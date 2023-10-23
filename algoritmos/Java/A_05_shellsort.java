import java.util.Random;

public class A_05_shellsort {

    // Crea un funcion para imprimir un array int
    public static void printArr ( int[] values ) {
            
        System.out.print("[ ");

        // Recorre el array
        for ( int i = 0; i < values.length; i++ ) {

            System.out.print(values[i] + " ");

        }

        System.out.print("]\n");
        
    }

    // funcion para aplicar un shellSort
    public static void shellSort ( int[] values ) {

        
        for ( int pass = 0; pass != 3; pass++ ) {
        
            // un bucle for que recorre el array pero mientras que gap sea mayor que 0 y en cada intreacion su tamaño se reduce a la mitad
            for ( int gap = values.length / 2; gap > 0; gap /= 2 ) {
    
                // recorre el array hasta la longitud - el gap actual para evitar un outOfBounds
                for ( int i = 0; i < values.length - gap; i++ ) {
                        
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
                    printArr(values);
                    
                }
    
            }
        
        }

    }

    public static void main(String[] args) {

        // crea un random
        Random ranInt = new Random();

        // crea un array int de 10 espacios 
        int[] arrInt = new int[10];
        // int[] arrInt = {9, 0,3,0,0,1,9, 0,3,0,0,1};

        // asgina valores aleatorios 
        for ( int i = 0; i < arrInt.length; i++ ) {
            
            arrInt[i] = (ranInt.nextInt(8)+1) * 1;

        }

        // imprime el array original
        System.out.println("= Array original =");
        printArr(arrInt);

        // aplica el shellSort
        System.out.println("= Ordenando Array =");
        shellSort(arrInt);

        // imprime el array ordenado
        System.out.println("= Array ordenado =");
        printArr(arrInt);
        
    }

}