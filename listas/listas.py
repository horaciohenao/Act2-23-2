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

# Crea una lista
listaPersonalizada = []

# Asgina valores aleatorios 
for i in range(10):

    listaPersonalizada.append(random.randint(1, 8))

print("Lista desordenada:", listaPersonalizada)
# Se aplica el bubbleSort
bubbleSort(listaPersonalizada)
print("Lista ordenada con bubbleSort:", listaPersonalizada)
print("=====")

# Asigna valores aleatorios
for i in range(10):
    listaPersonalizada[i] = random.randint(1, 8)

print("Lista desordenada:", listaPersonalizada)
# Se aplica el selectionSort
selectionSort(listaPersonalizada)
print("Lista ordenada con selectionSort:", listaPersonalizada)
print("=====")

# Asigna valores aleatorios
for i in range(10):
    listaPersonalizada[i] = random.randint(1, 8)

print("Lista desordenada:", listaPersonalizada)
# Se aplica el insertionSort
insertionSort(listaPersonalizada)
print("Lista ordenada con insertionSort:", listaPersonalizada)
print("=====")

# Asigna valores aleatorios
for i in range(10):
    listaPersonalizada[i] = random.randint(1, 8)

print("Lista desordenada:", listaPersonalizada)

# Elimina el primer elemento de la lista
listaPersonalizada.pop(0)

# Obtiene el cuarto elemento de la lista
listaPersonalizada.index(3)

# Organiza los elementos de la lista
listaPersonalizada.sort()

print("Lista ordenada por el metodo del SDK, luego de agregar y eliminar valores:", listaPersonalizada)
