#include <iostream>
#include <vector>
#include <string>
#include <cstring>

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

void agregarProducto(vector<productValues> &vectorValue, vector<productInfo> &vectorValueInfo, int codigo, const string& nombre, const string& marca, const string& color, int preVenta, double descMax, int unidades, const string& medida, const string& categoria, const string& fecha, const string& proveedor, int preCompra, int cantidad, int pagoTotal, int pagoTotalnoIVA) {
    productValues nuevoProducto;
    nuevoProducto.codigo = codigo;
    nuevoProducto.nombre = nombre;
    nuevoProducto.marca = marca;
    nuevoProducto.color = color;
    nuevoProducto.preVenta = preVenta;
    nuevoProducto.descMax = descMax;
    nuevoProducto.unidades = unidades;
    nuevoProducto.medida = medida;
    nuevoProducto.categoria = categoria;

    productInfo nuevaInfo;
    nuevaInfo.fecha = fecha;
    nuevaInfo.proveedor = proveedor;
    nuevaInfo.codigo = codigo;
    nuevaInfo.preCompra = preCompra;
    nuevaInfo.cantidad = cantidad;
    nuevaInfo.pagoTotal = pagoTotal;
    nuevaInfo.pagoTotalnoIVA = pagoTotalnoIVA;

    vectorValue.push_back(nuevoProducto);
    vectorValueInfo.push_back(nuevaInfo);
}

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

    char inNombre[100];
    cout << "Ingrese un Nombre: ";
    cin >> inNombre;
    nuevoProducto.nombre = inNombre;

    char inMarca[100];
    cout << "Ingrese una Marca: ";
    cin >> inMarca;
    nuevoProducto.marca = inMarca;

    char inColor[100];
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

    char inMedida[100];
    cout << "Ingrese una Medida: ";
    cin >> inMedida;
    nuevoProducto.medida = inMedida;

    char inCategoria[100];
    cout << "Ingrese una Categoria: ";
    cin >> inCategoria;
    nuevoProducto.categoria = inCategoria;


    // *

    char inFecha[100];
    cout << "Ingrese una fecha[dd/mm/aaaa]: ";
    cin >> inFecha;
    nuevoProductoInfo.fecha = inFecha;

    char inProveedor[100];
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
void updateProduct( vector<productValues> &vectorValue, vector<productInfo> &vectorValueInfo  ){

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

    if ( fIndex != -1 ) {

        // Crea un struct a base de productValues
        productValues nuevoProducto;
        productInfo nuevoProductoInfo;

        // Copia el valor de fIndex en una variable temporal
        // Crea una variable para almenar ese valor
        // Copia el valor de temp en la variable
        // Lo agrega al struct
        string temp = vectorValue[fIndex].nombre;
        char inNombre[100];
        strcpy(inNombre, temp.c_str());
        nuevoProducto.nombre = inNombre;

        int inCodigo = vectorValue[fIndex].codigo;
        nuevoProducto.codigo = inCodigo;
        
        temp = vectorValue[fIndex].marca;
        char inMarca[100];
        strcpy(inMarca, temp.c_str());
        nuevoProducto.marca = inMarca;
        
        temp = vectorValue[fIndex].color;
        char inColor[100];
        strcpy(inColor, temp.c_str());
        nuevoProducto.color = inColor;

        float inDescMax;
        cout << "Ingrese un nuevo % de Descuento Maximo: ";
        cin >> inDescMax;
        nuevoProducto.descMax = inDescMax;

        int inUnidades;
        cout << "Ingrese nuevo numero de unidades: ";
        cin >> inUnidades;
        nuevoProducto.unidades = inUnidades + vectorValue[fIndex].unidades;
        
        temp = vectorValue[fIndex].medida;
        char inMedida[100];
        strcpy(inMedida, temp.c_str());
        nuevoProducto.medida = inMedida;
        
        temp = vectorValue[fIndex].categoria;
        char inCategoria[100];
        strcpy(inCategoria, temp.c_str());
        nuevoProducto.categoria = inCategoria;

        // *

        temp = vectorValueInfo[fIndex].fecha;
        char inFecha[100];
        strcpy(inFecha, temp.c_str());
        nuevoProductoInfo.fecha = inFecha;
        
        temp = vectorValueInfo[fIndex].proveedor;
        char inProveedor[100];
        strcpy(inProveedor, temp.c_str());
        nuevoProductoInfo.proveedor = inProveedor;

        inCodigo = vectorValue[fIndex].codigo;
        nuevoProducto.codigo = inCodigo;

        int inPreCompra;
        cout << "Ingrese un nuevo Precio de Venta: ";
        cin >> inPreCompra;
        nuevoProductoInfo.preCompra = inPreCompra;

        // *

        nuevoProducto.preVenta = inPreCompra * 0.40 ;

        // *

        int inCantidad = vectorValueInfo[fIndex].cantidad;
        nuevoProductoInfo.cantidad = inCantidad;

        int inPagoTotal = vectorValueInfo[fIndex].pagoTotal;
        nuevoProductoInfo.pagoTotal = inPagoTotal;

        int inPagoTotalnoIVA = vectorValueInfo[fIndex].pagoTotalnoIVA;
        nuevoProductoInfo.pagoTotalnoIVA = inPagoTotalnoIVA;

        // Asignar valores un nuevo producto con la estructura de datos creada al final del vector vectorValue
        vectorValue[fIndex] = nuevoProducto;
        vectorValueInfo[fIndex] = nuevoProductoInfo;

        return;


    }
    

    cout << "El producto no se encontro, quizas aun no fue comprado | Codigo:" << inCodigo << "\n" ;

}

int main(){

    // Crea un vector que usa el struct productValues y productInfo
    vector<productValues> Productos;
    vector<productInfo> ProductosInfo;

    if(1){

        agregarProducto(Productos, ProductosInfo, 0, "Producto 200", "Marca 1", "Rojo", 50, 0.1, 100, "cm", "Electrónica", "2023/11/15", "Proveedor 1", 30, 20, 500, 400);
        agregarProducto(Productos, ProductosInfo, 1, "Producto 201", "Marca 2", "Azul", 60, 0.2, 0, "cm", "Electrónica", "2023/11/16", "Proveedor 2", 35, 22, 510, 410);
        agregarProducto(Productos, ProductosInfo, 2, "Producto 202", "Marca 3", "Verde", 70, 0.15, 100, "cm", "Electrónica", "2023/11/17", "Proveedor 3", 40, 25, 520, 420);
        agregarProducto(Productos, ProductosInfo, 3, "Producto 203", "Marca 4", "Amarillo", 80, 0.25, 0, "cm", "Electrónica", "2023/11/18", "Proveedor 4", 45, 30, 530, 430);
        agregarProducto(Productos, ProductosInfo, 4, "Producto 204", "Marca 5", "Negro", 90, 0.12, 100, "cm", "Electrónica", "2023/11/19", "Proveedor 5", 50, 35, 540, 440);
        agregarProducto(Productos, ProductosInfo, 5, "Producto 205", "Marca 6", "Blanco", 100, 0.18, 0, "cm", "Electrónica", "2023/11/20", "Proveedor 6", 55, 40, 550, 450);
        agregarProducto(Productos, ProductosInfo, 6, "Producto 206", "Marca 7", "Morado", 110, 0.14, 100, "cm", "Electrónica", "2023/11/21", "Proveedor 7", 60, 45, 560, 460);
        agregarProducto(Productos, ProductosInfo, 7, "Producto 207", "Marca 8", "Naranja", 120, 0.22, 0, "cm", "Electrónica", "2023/11/22", "Proveedor 8", 65, 50, 570, 470);
        agregarProducto(Productos, ProductosInfo, 8, "Producto 208", "Marca 9", "Gris", 130, 0.16, 100, "cm", "Electrónica", "2023/11/23", "Proveedor 9", 70, 55, 580, 480);
        agregarProducto(Productos, ProductosInfo, 9, "Producto 209", "Marca 10", "Plateado", 140, 0.24, 0, "cm", "Electrónica", "2023/11/24", "Proveedor 10", 75, 60, 590, 490);

    }

    // addProduct( Productos, ProductosInfo );

    findProduct( Productos );

    for (size_t i = 0; i < Productos.size(); i++) {

    cout << "Producto " << i << " codigo: " << Productos[i].codigo << "\n";
    cout << "Producto " << i << " nombre: " << Productos[i].nombre << "\n";
    cout << "Producto " << i << " marca: " << Productos[i].marca << "\n";
    cout << "Producto " << i << " color: " << Productos[i].color << "\n";
    cout << "Producto " << i << " preVenta: " << Productos[i].preVenta << "\n";
    cout << "Producto " << i << " descMax: " << Productos[i].descMax << "\n";
    cout << "Producto " << i << " unidades: " << Productos[i].unidades << "\n";
    cout << "Producto " << i << " medida: " << Productos[i].medida << "\n";
    cout << "Producto " << i << " categoria: " << Productos[i].categoria << "\n";

    cout << "\n";

    }
    

    updateProduct( Productos, ProductosInfo );

        for (size_t i = 0; i < Productos.size(); i++) {

    cout << "Producto " << i << " codigo: " << Productos[i].codigo << "\n";
    cout << "Producto " << i << " nombre: " << Productos[i].nombre << "\n";
    cout << "Producto " << i << " marca: " << Productos[i].marca << "\n";
    cout << "Producto " << i << " color: " << Productos[i].color << "\n";
    cout << "Producto " << i << " preVenta: " << Productos[i].preVenta << "\n";
    cout << "Producto " << i << " descMax: " << Productos[i].descMax << "\n";
    cout << "Producto " << i << " unidades: " << Productos[i].unidades << "\n";
    cout << "Producto " << i << " medida: " << Productos[i].medida << "\n";
    cout << "Producto " << i << " categoria: " << Productos[i].categoria << "\n";

    cout << "\n";

    }

}