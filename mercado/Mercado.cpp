#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define IVA 0.19

using namespace std;

// Crea un struct con los valores de un producto
struct productValues{

    vector<int> codigo;
    vector<string> nombre;
    vector<string> marca;
    vector<string> color;
    vector<int> preVenta;
    vector<float> descMax;
    vector<int> unidades;
    vector<string> medida;
    vector<string> categoria;

};

struct productInfo{

    vector<string> fecha;
    vector<string> proveedor;
    vector<int> codigo;
    vector<int> preCompra;
    vector<float> cantidad;
    vector<int> pagoTotal;
    vector<int> pagoTotalnoIVA;

};

// Funcion para agregar un producto
void addProduct( vector<productValues> &vectorValue, vector<productInfo> &vectorValueInfo ){

    // Crea un struct a base de productValues
    productValues nuevoProducto;
    productInfo nuevoProductoInfo;
    
    // Crea una variable
    // Hace un output simple
    // Guarda el input del usuario
    // En el struct creado, en la parte de codigo hace un push_back
    int inCodigo;
    printf("Ingrese un Codigo: ");
    cin >> inCodigo;
    nuevoProducto.codigo.push_back(inCodigo);

    // Repite lo mismo con cada valor

    char inNombre[100];
    printf("Ingrese un Nombre: ");
    cin >> inNombre;
    nuevoProducto.nombre.push_back(inNombre);

    char inMarca[100];
    printf("Ingrese una Marca: ");
    cin >> inMarca;
    nuevoProducto.marca.push_back(inMarca);

    char inColor[100];
    printf("Ingrese un Color: ");
    cin >> inColor;
    nuevoProducto.color.push_back(inColor);

    int inPreVenta;
    printf("Ingrese un Precio de Venta: ");
    cin >> inPreVenta;
    nuevoProducto.preVenta.push_back(inPreVenta);

    float inDescMax;
    printf("Ingrese un Descuento Maximo: ");
    cin >> inDescMax;
    nuevoProducto.descMax.push_back(inDescMax);

    int inUnidades;
    printf("Ingrese una cantidad de Unidades: ");
    cin >> inUnidades;
    nuevoProducto.unidades.push_back(inUnidades);

    char inMedida[100];
    printf("Ingrese una Medida: ");
    cin >> inMedida;
    nuevoProducto.medida.push_back(inMedida);

    char inCategoria[100];
    printf("Ingrese una Categoria: ");
    cin >> inCategoria;
    nuevoProducto.categoria.push_back(inCategoria);


    // *

    char inFecha[100];
    printf("Ingrese una fecha[dd/mm/aaaa]: ");
    cin >> inFecha;
    nuevoProductoInfo.fecha.push_back(inFecha);

    char inProveedor[100];
    printf("Ingrese un Proveedor: ");
    cin >> inProveedor;
    nuevoProductoInfo.proveedor.push_back(inProveedor);
    
    int inCodigoVenta;
    printf("Ingrese un Codigo de venta: ");
    cin >> inCodigoVenta;
    nuevoProducto.codigo.push_back(inCodigoVenta);
    
    int inPreCompra;
    printf("Ingrese un Precio de compra: ");
    cin >> inPreCompra;
    nuevoProductoInfo.preCompra.push_back(inPreCompra);
    
    float inCantidad;
    printf("Ingrese la cantidad total (segun unidad de medida): ");
    cin >> inCantidad;
    nuevoProductoInfo.cantidad.push_back(inCantidad);
    
    int inPagoTotal;
    printf("Ingrese el Pago total (Sin contar IVA): ");
    cin >> inPagoTotal;
    // Aplica las operaciones del IVA
    nuevoProductoInfo.pagoTotal.push_back(inPagoTotal + (inPagoTotal * IVA));
    nuevoProductoInfo.pagoTotalnoIVA.push_back(inPagoTotal);

    // Agregar un nuevo producto con la estructura de datos creada al final del vector vectorValue
    vectorValue.push_back(nuevoProducto);
    vectorValueInfo.push_back(nuevoProductoInfo);

}

// Funcion para buscar un codigo
void findProduct( vector<productValues> &vectorValue ){

    // Obtiene el codigo
    int inCodigo;
    printf("Ingrese un Codigo para buscar: ");
    cin >> inCodigo;

    // Recorre el tamaño del vectorValue
    for ( int index = 0; index < vectorValue.size(); index++ ) {

        // Compara los codigos en el index
        if ( vectorValue[index].codigo[index] == inCodigo ) {

            printf("El producto ya fue comprado! | Codigo: %d", inCodigo);
            
        }


    }

    printf("El producto no se encontro, quizas aun no fue comprado | Codigo: %d", inCodigo);

}

int main(){

    // Crea un vector que usa el struct productValues y productInfo
    vector<productValues> Productos;
    vector<productInfo> ProductosInfo;

    addProduct( Productos, ProductosInfo );

    findProduct( Productos );

}