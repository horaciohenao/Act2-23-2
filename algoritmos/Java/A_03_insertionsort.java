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
    public static void insertionSort(int[] values) {
        
        // recorre el array asumiendo que el primer valor ya está ordenado
        for (int i = 1; i < values.length; i++) {
            
            // si el valor en i es menor al valor anterior en i
            if (values[i] < values[i - 1]) {
                
                // usa i como pivote
                int piv = values[i];
                
                // crea una variable temporal para i
                int temp = i;
                
                // desplaza los valores a la izquierda mientras que no sean 
                // temp 0 para eviar un outOfBounds
                // values[temp - 1] > piv para que no reemplace un valor menor al pivote actual
                while (temp > 0 && values[temp - 1] > piv) {
                    
                    // toma el valor anterior y lo reemplaza con el actual
                    values[temp] = values[temp - 1]; 
                    
                    temp--;
                    
                }
                
                // reemplaza la ubicacion actual de temp con el pivote
                // "lo inserta"
                values[temp] = piv;
                
            }
            
            System.out.print("[ ");
            printArr(values);
        }
        
    }

    public static void main(String[] args) {

        // crea un random
        Random ranInt = new Random();

        // crea un array int de 10 espacios 
        int[] arrInt = new int[10];
        // int[] arrInt = {2, 8, 5, 3, 9, 4};

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