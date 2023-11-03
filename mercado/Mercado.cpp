#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>

#define IVA 0.19

using namespace std;

// Crea un struct con los valores de un producto
struct productValues{

    int codigo;
    string nombre;
    string marca;
    string color;
    int preVenta;
    float descMax;
    int unidades;
    string medida;
    string categoria;

};

struct productInfo{

    string fecha;
    string proveedor;
    int codigo;
    int preCompra;
    int cantidad;
    int pagoTotal;
    int pagoTotalnoIVA;

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
    cout << "Ingrese un Codigo: ";
    cin >> inCodigo;
    nuevoProducto.codigo = inCodigo;
    nuevoProductoInfo.codigo = inCodigo;

    // Repite lo mismo con cada valor

    string inNombre;
    cout << "Ingrese un Nombre: ";
    cin >> inNombre;
    nuevoProducto.nombre = inNombre;

    string inMarca;
    cout << "Ingrese una Marca: ";
    cin >> inMarca;
    nuevoProducto.marca = inMarca;

    string inColor;
    cout << "Ingrese un Color: ";
    cin >> inColor;
    nuevoProducto.color = inColor;

    int inPreVenta;
    cout << "Ingrese un Precio de Venta: ";
    cin >> inPreVenta;
    nuevoProducto.preVenta = inPreVenta;

    float inDescMax;
    cout << "Ingrese un %s Descuento Maximo: ", "%";
    cin >> inDescMax;
    nuevoProducto.descMax = inDescMax;

    int inUnidades;
    cout << "Ingrese una cantidad de Unidades: ";
    cin >> inUnidades;
    nuevoProducto.unidades = inUnidades;

    string inMedida;
    cout << "Ingrese una Medida: ";
    cin >> inMedida;
    nuevoProducto.medida = inMedida;

    string inCategoria;
    cout << "Ingrese una Categoria: ";
    cin >> inCategoria;
    nuevoProducto.categoria = inCategoria;

    // *

    string inFecha;
    cout << "Ingrese una fecha[dd/mm/aaaa]: ";
    cin >> inFecha;
    nuevoProductoInfo.fecha = inFecha;

    string inProveedor;
    cout << "Ingrese un Proveedor: ";
    cin >> inProveedor;
    nuevoProductoInfo.proveedor = inProveedor;
    
    int inCodigoVenta;
    cout << "Ingrese un Codigo de venta: ";
    cin >> inCodigoVenta;
    nuevoProducto.codigo = inCodigoVenta;
    
    int inPreCompra;
    cout << "Ingrese un Precio de compra: ";
    cin >> inPreCompra;
    nuevoProductoInfo.preCompra = inPreCompra;
    
    int inCantidad;
    cout << "Ingrese la cantidad total (segun unidad de medida): ";
    cin >> inCantidad;
    nuevoProductoInfo.cantidad = inCantidad;
    
    int inPagoTotal;
    cout << "Ingrese el Pago total (Sin contar IVA): ";
    cin >> inPagoTotal;
    // Aplica las operaciones del IVA
    nuevoProductoInfo.pagoTotal = (inPagoTotal + (inPagoTotal * IVA));
    nuevoProductoInfo.pagoTotalnoIVA = inPagoTotal;

    // Agregar un nuevo producto con la estructura de datos creada al final del vector vectorValue
    vectorValue.push_back(nuevoProducto);
    vectorValueInfo.push_back(nuevoProductoInfo);

}

// Funcion para buscar un codigo
void findProduct( vector<productValues> &vectorValue ){

    // Obtiene el codigo
    int inCodigo;
    cout << "Ingrese un Codigo para buscar: ";
    cin >> inCodigo;

    // Recorre el tamaño del vectorValue
    for ( int index = 0; index < vectorValue.size(); index++ ) {

        // Compara los codigos la caracteristica codigo de cada posicion con el codigo introducido
        if ( vectorValue[index].codigo == inCodigo ) {

            cout << "El producto ya fue comprado! | Codigo: "<< inCodigo << "\n";

            return;
            
        }

    }

    cout << "El producto no se encontro, quizas aun no fue comprado | Codigo: " << inCodigo << "\n";

}

// Funcion para actualizar un producto
void updateProduct( vector<productValues> &vectorValue, vector<productInfo> &vectorValueInfo ){

    int fIndex = -1;
    // Obtiene el codigo
    int inCodigo;
    cout << "Ingrese un Codigo para buscar: ";
    cin >> inCodigo;

    // Recorre el tamaño del vectorValue
    for ( int index = 0; index < vectorValue.size(); index++ ) {

        // Compara los codigos en el index
        if ( vectorValue[index].codigo == inCodigo ) {

            cout << "El producto fue encontrado! | Codigo: "<< inCodigo <<"\n" ;

            fIndex = index;

            break;
            
        }

    }

    // Si fIndex se actualizo y ya no es -1 entonces
    if ( fIndex != -1 ) {

        // Crea un struct a base de productValues
        productValues nuevoProducto = vectorValue[fIndex];
        productInfo nuevoProductoInfo = vectorValueInfo[fIndex];

        float inDescMax;
        cout << "Ingrese un nuevo % de Descuento Maximo: ";
        cin >> inDescMax;
        nuevoProducto.descMax = inDescMax;

        int inUnidades;
        cout << "Ingrese nuevo numero de unidades: ";
        cin >> inUnidades;
        nuevoProducto.unidades = inUnidades + vectorValue[fIndex].unidades;

        // *

        int inPreCompra;
        cout << "Ingrese un nuevo Precio de Venta: ";
        cin >> inPreCompra;
        nuevoProductoInfo.preCompra = inPreCompra;

        // *

        nuevoProducto.preVenta = inPreCompra * 0.40 ;

        // Asignar valores un nuevo producto con la estructura de datos creada al final del vector vectorValue
        vectorValue[fIndex] = nuevoProducto;
        vectorValueInfo[fIndex] = nuevoProductoInfo;

        return;

    }
    
    cout << "El producto no se encontro, quizas aun no fue comprado | Codigo:" << inCodigo << "\n" ;

}

// Funcion para filtrar ventas
void filtProduct( vector<productValues> &vectorValue, vector<productInfo> &vectorValueInfo, vector<productValues> &vectorValueDestiny, vector<productInfo> &vectorValueDestinyInfo ){

    // Recorre el tamaño del vectorValue
    for ( int i = 0; i < vectorValue.size(); i++ ) {

        // Compara los codigos la caracteristica codigo de cada posicion con el codigo introducido
        if ( vectorValue[i].unidades > 0 ) {

            // Crea un struct a base de productValues
            productValues nuevoProducto = vectorValue[i];
            productInfo nuevoProductoInfo = vectorValueInfo[i];

            // Agregar un nuevo producto con la estructura de datos creada al final del vector vectorValueDestiny
            vectorValueDestiny.push_back(nuevoProducto);
            vectorValueDestinyInfo.push_back(nuevoProductoInfo);
            
        }

    }

}

// Funcion para ordenar alfabeticamente
void sortProduct(vector<productValues> &vectorValue, vector<productInfo> &vectorValueInfo) {

    // funcion sort con el rango de valores desde el inicio y final de vectorValue, y usa dos valores para comprarse
    sort(vectorValue.begin(), vectorValue.end(), [](const productValues &a, const productValues &b) {

        // retorna los valores del vectorValue ordenados alfabeticamente usando los nombres
        return a.nombre < b.nombre;

    });

}

// Funcion para exportar archivo
void exportFile( vector<productValues> &vectorValue, vector<productInfo> &vectorValueInfo ) {

    // Crea un "ofstream" con el archivo que va a escribir
    ofstream fileWrite("productos.txt");

    // toma la primera categoria del primer vector
    string categoria = vectorValue[0].categoria;

    fileWrite << "\n - Categoria: " << categoria << " - \n";

    // recorre el vector enviado
    for (size_t i = 0; i < vectorValue.size(); i++) {

        // si el valor del vector en i en la seccion categoria no es igual a la categoria actual la cambia
        if ( vectorValue[i].categoria != categoria ) {
            
            fileWrite << "\n - Categoria: " << categoria << " - \n";

            categoria = vectorValue[i].categoria;

        }

        // escribe en el archivo el valor de las secciones del vector en i 
        fileWrite << "Codigo: " << vectorValue[i].codigo << ", Nombre: " << vectorValue[i].nombre << 
        ", Marca: " << vectorValue[i].marca << ", Color: " << vectorValue[i].color << 
        ", Precio de Venta: " << vectorValue[i].preVenta << ", Descuento Maximo: " << vectorValue[i].descMax << 
        ", Unidades: " << vectorValue[i].unidades << ", Medida: " << vectorValue[i].medida <<
        ", Medida: " << vectorValue[i].medida <<

        "Fecha: " << vectorValueInfo[i].fecha << ", Proveedor: " << vectorValueInfo[i].proveedor <<
        ", Codigo: " << vectorValueInfo[i].codigo << ", Precio de Compra: " << vectorValueInfo[i].preCompra <<
        ", Cantidad: " << vectorValueInfo[i].cantidad << ", Pago Total: " << vectorValueInfo[i].pagoTotal <<
        ", Pago Total sin IVA: " << vectorValueInfo[i].pagoTotalnoIVA << "\n";
        
    }

    fileWrite.close();

}

int main(){

    // Crea un vector que usa el struct productValues y productInfo
    vector<productValues> Productos;
    vector<productInfo> ProductosInfo;

    // Crea un vector que usa el struct productValues y productInfo que almacena los productos con mas de 0 unidades
    vector<productValues> ProductosExistentes;
    vector<productInfo> ProductosExistentesInfo;



    addProduct( Productos, ProductosInfo );

    findProduct( Productos );


    
    updateProduct( Productos, ProductosInfo );



    filtProduct( Productos, ProductosInfo, ProductosExistentes, ProductosExistentesInfo );



    sortProduct( ProductosExistentes, ProductosExistentesInfo );



    exportFile( ProductosExistentes, ProductosExistentesInfo );


}