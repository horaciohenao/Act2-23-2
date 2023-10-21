import random

#  funcion para aplicar un insertionSort
def insertionSort ( values ):

    lenVar = len(values)

    # recorre el array 
    for i in range(lenVar):

        # recorre el arrya menos el ultimo elemento
        for j in range(lenVar-1):

            # si el valor en index2 es mayor al de index2 + 1 los intercambia
            if values[j] > values[j+1]:

                values[j], values[j+1] = values[j+1], values[j]

            # imprime el estado actual del array en esa interacion
            print(values)

# crea un array int de 10 espacios
arrInt = [0] * 10

# asgina valores aleatorios 
index = 0

for x in range(10):

    arrInt[index] = random.randint(1, 9)

    index += 1

# imprime el array original
print("= Array original =\n" + str(arrInt))

# aplica el insertionSort
print("\n= Ordenando Array =")
insertionSort(arrInt)

# imprime el array ordenado
print("\n= Array ordenado =\n" + str(arrInt))
