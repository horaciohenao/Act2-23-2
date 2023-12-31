import random

# Crea un funcion para imprimir una lista
def printList(values):

    print("[ ", end = "")

    # recorre la lista
    for x in values:

        print(x, end = " ")

    print("]")

# funcion para aplicar un bubblesort
def bubbleSort(values):
    
    lenVar = len(values)

    # recorre la lista 
    for i in range(lenVar):

        # recorre la lista menos el ultimo elemento
        for j in range(lenVar - 1):

            # si el valor en j es mayor al de j + 1 los intercambia
            if values[j] > values[j + 1]:
                values[j], values[j + 1] = values[j + 1], values[j]

            # imprime el estado actual de la lista en esa interacion
            printList(values)

# crea un lista int de 10 espacios
listInt = [0] * 10

# asigna valores aleatorios
index = 0
for x in range(10):
    listInt[index] = random.randint(1, 9)
    index += 1

# imprime la lista original
print("= Lista original =")
printList(listInt)

# aplica el bubblesort
print("= Ordenando Lista =")
bubbleSort(listInt)

# imprime la lista ordenada
print("= Lista ordenada =")
printList(listInt)
