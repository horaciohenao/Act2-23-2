import random

# Crea un funcion para imprimir una lista
def printList(values):

    print("[ ", end = "")

    # recorre la lista
    for x in values:

        print(x, end = " ")

    print("]")

# funcion "esta ordenado?"
def isSort ( values ):

    lenVar = len(values)

    # recorre la lista desde 1 asumiendo que el primer elemento ya esta ordenado
    for i in range(1, lenVar):

        # si el valor en i es menor al valor anterior entonces no esta ordenada
        if values[i] < values[i-1]:

            return False
        
    # si al recorrer la lista no se cumple el if está ordenada
    return True

#  funcion para aplicar un bogoSort
def bogoSort ( values ):

    lenVar = len(values)
    
    isSortVar = False

    while isSortVar == False:

        # recorre la lista
        for i in range(lenVar-1):

            temp = random.randint(0, lenVar-1)

            # intercambia valores aleatorios
            values[i], values[temp] = values[temp], values[i]

            temp = random.randint(0, lenVar-1)

            # intercambia valores aleatorios
            values[temp], values[temp] = values[temp], values[temp]
            
            isSortVar = isSort(values)

            # imprime el estado actual de la lista en esa interacion
            printList(values)

# crea una lista int de 10 espacios
listInt = [0] * 5

# asgina valores aleatorios 
index = 0

for x in range(5):

    listInt[index] = random.randint(1, 9)

    index += 1

# imprime la lista original
print("= Lista original =")
printList(listInt)

# aplica el bogosort
print("= Ordenando Lista =")
bogoSort(listInt)

# imprime la lista ordenada
print("= Lista ordenada =")
printList(listInt)
