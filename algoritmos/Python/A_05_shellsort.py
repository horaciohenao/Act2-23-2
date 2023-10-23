import random

# Crea un funcion para imprimir una lista
def printList(values):

    print("[ ", end = "")

    # recorre la lista
    for x in values:

        print(x, end = " ")

    print("]")

# funcion para aplicar un shellsort
def shellSort(values):

    lenVar = len(values)

    for x in range(3):

        # un bucle for que recorre el array pero mientras que gap sea mayor que 0 y en cada intreacion su tamaño se reduce a la mitad
        gap = lenVar // 2
        while gap > 0:

            # recorre el array hasta la longitud - el gap actual para evitar un outOfBounds
            index = 0
            while index < lenVar - gap:

                # si i actual es mayor a gap, osea no hay posibilidad de outOfBounds
                if index > gap:

                    # si el valor en i-gap es mayor que i los intercambia
                    if values[index-gap] > values[index]:

                        values[index], values[index-gap] = values[index-gap], values[index]

                # si el valor en i es mayor que i + gap los intercambia
                if values[index] > values[index + gap]:

                    values[index], values[index+gap] = values[index+gap], values[index]
                
                # aumenta el index para verificar el siguiente valor
                index += 1
                    
            # en cada intreacion su tamaño se reduce a la mitad
            gap //= 2

            # imprime el estado actual del array luego de modificarlo
            print(values)


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

# aplica el shellsort
print("= Ordenando Lista =")
shellSort(listInt)

# imprime la lista ordenada
print("= Lista ordenada =")
printList(listInt)
