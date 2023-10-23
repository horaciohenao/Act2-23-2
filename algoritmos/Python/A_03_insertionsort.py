import random

# Crea un funcion para imprimir una lista
def printList(values):

    print("[ ", end = "")

    # recorre la lista
    for x in values:

        print(x, end = " ")

    print("]")

#  funcion para aplicar un insertionSort
def insertionSort ( values ):

    lenVar = len(values)

    # recorre la lista desde 1 asumiendo que el primer elemento ya esta ordenado
    for i in range(1, lenVar):

        # si el valor en i es menor al valor anterior en i
        if values[i] < values[i-1]:

            # usa i como pivote
            piv = values[i]

            # crea una variable temporal para i
            temp = i

            # desplaza los valores a la izquierda mientras que no sean 
            # temp 0 para eviar un outOfBounds
            # values[temp - 1] > piv para que no reemplace un valor menor al pivote actual
            while temp > 0 and values[temp-1] > piv:

                # toma el valor anterior y lo reemplaza con el actual
                values[temp] = values[temp - 1]

                temp-=1

            # reemplaza la ubicacion actual de temp con el pivote
            # "lo inserta"
            values[temp] = piv

        printList(values) 


# crea una lista int de 10 espacios
listInt = [0] * 10

# asgina valores aleatorios 
index = 0

for x in range(10):

    listInt[index] = random.randint(1, 9)

    index += 1

# imprime la lista original
print("= Lista original =")
printList(listInt)

# aplica el insertionSort
print("= Ordenando Lista =")
insertionSort(listInt)

# imprime la lista ordenada
print("= Lista ordenada =")
printList(listInt)
