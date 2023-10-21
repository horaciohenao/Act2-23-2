import random

def isSort ( values ):

    lenVar = len(values)

    # recorre el array 
    for i in range(1, lenVar):

        # si el valor en i es menor al valor anterior entonces no esta ordenado
        if values[i] < values[i-1]:

            return False
        
        # si al recorrer el array no se cumple el if está ordenado
    return True

#  funcion para aplicar un bogoSort
def bogoSort ( values ):

    lenVar = len(values)
    
    isSortVar = False

    while isSortVar == False:

        # recorre el array 
        for i in range(lenVar-1):

            temp = random.randint(0, lenVar-1)

            # intercambia valores aleatorios
            values[i], values[temp] = values[temp], values[i]
            
            isSortVar = isSort(values)

            # imprime el estado actual del array en esa interacion
            print(values)

# crea un array int de 10 espacios
arrInt = [0] * 5

# asgina valores aleatorios 
index = 0

for x in range(5):

    arrInt[index] = random.randint(1, 9)

    index += 1

# imprime el array original
print("= Array original =\n" + str(arrInt))

# aplica el bogoSort
print("\n= Ordenando Array =")
bogoSort(arrInt)

# imprime el array ordenado
print("\n= Array ordenado =\n" + str(arrInt))
