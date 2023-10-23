import random

# Crea un funcion para imprimir una lista
def printList(values):

    print("[ ", end = "")

    # recorre la lista
    for x in values:

        print(x, end = " ")

    print("]")

# funcion para aplicar un selectionsort
def selectionSort(values):

    lenVar = len(values)

    # recorre la lista 
    for i in range(lenVar):

        # toma index como pivote
        minI = i

        # recorre el array para buscar un nuevo valor más bajo desde del ultimo más bajo, i
        for j in range(i, lenVar):

            # si valor actual en j es menor a minI actual y actualiza minI
            if values[j] < values[minI]:

                minI = j

        # los intercambia
        values[minI], values[i] = values[i], values[minI]

        # imprime el estado actual del array luego de modificarlo
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

# aplica el selectionsort
print("= Ordenando Lista =")
selectionSort(listInt)

# imprime la lista ordenada
print("= Lista ordenada =")
printList(listInt)
