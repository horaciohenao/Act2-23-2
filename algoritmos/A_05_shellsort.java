import java.util.Random;

public class A_05_shellsort {

    // Crea un funcion para imprimir un array int
    public static void printArr ( int[] values ) {

        // Recorre el array
        for ( int i = 0; i < values.length; i++ ) {

            System.out.print(values[i] + " ");

        }

        System.out.print("]\n");
        
    }

    // funcion para aplicar un shellSort
    public static void shellSort ( int[] values ) {

        // un bucle for que recorre el array pero mientras que gap sea mayor que 0 y en cada intreacion su tamaño se reduce a la mitad
        
        for ( int pass = 0; pass != 3; pass++ ) {
        
            for ( int gap = values.length / 2; gap > 0; gap /= 2 ) {
    
                for ( int i = 0; i < values.length - gap; i++ ) {
                        
                    if ( i > gap ) {
    
                        if ( values[i-gap] > values[i] ) {
        
                            int temp2 = values[i];
        
                            values[i] = values[i-gap];
        
                            values[i-gap] = temp2;
                            
                        }
                        
                    }
                    
                    if ( values[i] > values[i+gap] ) {
    
                        int temp = values[i];
    
                        values[i] = values[i+gap];
    
                        values[i+gap] = temp;
                        
                    }
            
                    System.out.print("[ ");
            
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
        System.out.print("= Array original =\n[ ");
        printArr(arrInt);

        // aplica el shellSort
        System.out.print("= Ordenando Array =\n");
        shellSort(arrInt);

        // imprime el array ordenado
        System.out.print("= Array ordenado =\n[ ");
        printArr(arrInt);
        
    }

}