#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>

#define IVA 0.19

using namespace std;

// Crea un struct con los valores de un producto
struct productValues {

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

// struct con info del producto
struct productInfo {

    string fecha;
    string proveedor;
    int codigo;
    int preCompra;
    int cantidad;
    int pagoTotal;
    int pagoTotalnoIVA;

};

// struct con info clientes
struct clients {

    int cedula;
    string nombre;
    string apellido1;
    string apellido2;
    char genero;
    string fechaNacimiento;
    int numeroTel;
    string email;
    string direccion;
    bool vip;

};

// struct clientes que quiere comprar
struct interestedCustomer {

    string fecha;
    int cedulaCliente;
    string medioPago;
    string modalidad;

};

// struct productos vendidos
struct productPurchase {

    int codigoProducto;
    int precioVenta;
    int cantidad;
    float descuento;
    float valorCobrarSinIVA;
    float valorDescontar;
    float valorCobrarIVA;
    float valorTotalCobrar;
    string estado;
    string estadoMotivo;

};

// struct balanceCuentas
struct salesControl {

    float totalInvertido;
    float totalRecuperado;
    float totalGanancia;
    float totalDescuento;
    float totalImpuestoIVA;

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

// Funcion para agregar un cliente
void addClient( vector<clients> &vectorClients ) {

    // crea un Strct a base nuevoCliente
    clients nuevoCliente;

    // Crea una variable
    // Hace un output simple
    // Guarda el input del usuario
    // En el struct creado, en la parte de codigo hace un push_back
    int inCedula;
    cout << "Ingrese la Cedula: ";
    cin >> inCedula;
    nuevoCliente.cedula = inCedula;

    string inNombre;
    cout << "Ingrese el Nombre: ";
    cin >> inNombre;
    nuevoCliente.nombre = inNombre;

    string inApellido1;
    cout << "Ingrese el Apellido 1: ";
    cin >> inApellido1;
    nuevoCliente.apellido1 = inApellido1;

    string inApellido2;
    cout << "Ingrese el Apellido 2: ";
    cin >> inApellido2;
    nuevoCliente.apellido2 = inApellido2;

    char inGenero;
    cout << "Ingrese el Genero [M/F/O]: ";
    cin >> inGenero;
    nuevoCliente.genero = inGenero;

    string inFechaNacimiento;
    cout << "Ingrese la Fecha de Nacimiento [dd/mm/aaaa]: ";
    cin >> inFechaNacimiento;
    nuevoCliente.fechaNacimiento = inFechaNacimiento;

    int inNumeroTel;
    cout << "Ingrese el Numero de Telefono: ";
    cin >> inNumeroTel;
    nuevoCliente.numeroTel = inNumeroTel;

    string inEmail;
    cout << "Ingrese el Email: ";
    cin >> inEmail;
    nuevoCliente.email = inEmail;

    string inDireccion;
    cout << "Ingrese la Direccion: ";
    cin >> inDireccion;
    nuevoCliente.direccion = inDireccion;

    bool inVip;
    cout << "¿Es VIP? (1: Si, ha comprado algo / 0: No, no hacomprado nada): ";
    cin >> inVip;
    nuevoCliente.vip = inVip;

    // Agregar el nuevo cliente al final del vector
    vectorClients.push_back(nuevoCliente);
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
void sortProduct( vector<productValues> &vectorValue, vector<productInfo> &vectorValueInfo ) {

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
    for ( size_t i = 0; i < vectorValue.size(); i++ ) {

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

// Funcion para registrar clientes interesados
void interestedClient( vector<interestedCustomer> &vectorIntClients ) {
    
    // crea un Strct a base interestedCustomer
    interestedCustomer nuevaIntencion;

    string inFecha;
    cout << "Ingrese la fecha [dd/mm/aaaa]: ";
    cin >> inFecha;
    nuevaIntencion.fecha = inFecha;

    int inCedula;
    cout << "Ingrese la cedula del cliente: ";
    cin >> inCedula;
    nuevaIntencion.cedulaCliente = inCedula;

    string inMedioPago;
    cout << "Ingrese el medio de pago: ";
    cin >> inMedioPago;
    nuevaIntencion.medioPago = inMedioPago;

    string inModalidad;
    cout << "Ingrese la modalidad (directa o domicilio): ";
    cin >> inModalidad;
    nuevaIntencion.modalidad = inModalidad;

    // Agregar la nueva intención de compra al final del vector
    vectorIntClients.push_back(nuevaIntencion);
}

// Funcion para registrar ventas
void registerPurchaseProduct( vector<productPurchase> &vectorValue ) {

    // crea un Strct a base productPurchase
    productPurchase nuevaCompra;

    int inCodigoProducto;
    cout << "Ingrese el codigo: ";
    cin >> inCodigoProducto;
    nuevaCompra.codigoProducto = inCodigoProducto;

    int inPrecioVenta;
    cout << "Ingrese el precio de venta: ";
    cin >> inPrecioVenta;
    nuevaCompra.precioVenta = inPrecioVenta;

    int inCantidad;
    cout << "Ingrese la cantidad: ";
    cin >> inCantidad;
    nuevaCompra.cantidad = inCantidad;

    float inDescuento;
    cout << "Ingrese el descuento: ";
    cin >> inDescuento;
    nuevaCompra.descuento = inDescuento;

    // calculos del IVA
    nuevaCompra.valorCobrarSinIVA = inPrecioVenta * inCantidad * (1 - inDescuento);
    nuevaCompra.valorDescontar = nuevaCompra.valorCobrarSinIVA * inDescuento;
    nuevaCompra.valorCobrarIVA = nuevaCompra.valorCobrarSinIVA * IVA;
    nuevaCompra.valorTotalCobrar = nuevaCompra.valorCobrarSinIVA + nuevaCompra.valorCobrarIVA;

    nuevaCompra.estado = "POR DETERMINAR";
    nuevaCompra.estadoMotivo = "n/a";

    // Agregar la nueva compra al final del vector
    vectorValue.push_back(nuevaCompra);
}

// Funcion para actuzliar estado de venta
void updatePurchase( vector<productPurchase> &vectorValue ) {

    int fIndex = -1;
    
    // Obtener el codigo
    int inCodigoProducto;
    cout << "Ingrese un Codigo para buscar: ";
    cin >> inCodigoProducto;

    // Recorrer el tamaño del vector
    for ( int index = 0; index < vectorValue.size(); index++ ) {

        // Comparar los codigos usando el struct de vectorValue en index y su valor en codigoProducto
        if ( vectorValue[index].codigoProducto == inCodigoProducto ) {

            cout << "La venta fue encontrada! | Codigo: " << inCodigoProducto << "\n";

            fIndex = index;

            break;

        }
    }

    // Si fIndex se actualizo y ya no es -1
    if ( fIndex != -1 ) {

        string estadoNuevo;
        string motivo;

        char opcion;

        // bucle para verificar si se termino la compra
        while ( true ) {

            cout << "La venta se realizo? [y/n]: ";
            cin >> opcion;
            
            if ( opcion == 'y' ) {

                estadoNuevo = "EXITO";

                break;

            } else if ( opcion == 'n' ) {

                estadoNuevo = "COMPRA CANCELADA";
                cout << "Ingrese un breve motivo: ";
                cin >> motivo;

                break;

            }
            
            cout << "El valor no es valido!\n";

        }
        

        // Actualizar el estado y el motivo de la venta
        vectorValue[fIndex].estado = estadoNuevo;
        vectorValue[fIndex].estadoMotivo = motivo;

        return;
    }

    cout << "La venta no se encontro, quizas no se ha realizado todavia | Código: " << inCodigoProducto << "\n";

}

// funcion para reducir numero de unidades en inventario 
void updateInventory( vector<productPurchase> &vectorValuesVentas, vector<productValues> &vectorValuesProductos ) {

    int codigoProducto = 0;

    while (codigoProducto != -1) {

        int cantidadVendida;
        cout << "Ingrese la cantidad vendida: ";
        cin >> cantidadVendida;

        // recorre el tamaño del vetor de ventas
        for ( size_t i = 0; i < vectorValuesVentas.size(); i++ ) {

            // recorre el vector de productos
            for ( size_t j = 0; j < vectorValuesProductos.size(); j++ ) {
                
                // si el codigo del producto vendido es igual con un producto en el inventario
                if ( vectorValuesProductos[j].codigo == vectorValuesVentas[i].codigoProducto ) {

                    // reduce la cantidad de unidades vendidas del inventario del producto
                    vectorValuesProductos[j].unidades -= cantidadVendida;

                    break;

                }

            }

        }

    }

}

// funcion para cambiar estado VIP de cliente 
void setClientVIP( vector<clients> &vectorValue ) {

    int inCedulaCliente;
    cout << "Ingrese la cedula de un cliente: ";
    cin >> inCedulaCliente;

    // Buscar el cliente en la lista de clientes
    for ( size_t i = 0; i < vectorValue.size(); i++ ) {

        // si la cedula en el vector[i] es igual a la cedula del cliente
        if ( vectorValue[i].cedula == inCedulaCliente ) {

            // Si el cliente no es VIP se modifica el valor
            if ( !vectorValue[i].vip ) {

                cout << "El cliente fue encontrado! | Codigo: "<< inCedulaCliente <<"\n" ;

                vectorValue[i].vip = true;

            } else {

                cout << "El cliente ya es VIP." << "\n";

            }

            return;

        }

    }

    cout << "Cliente no encontrado en la lista | Cedula: " << inCedulaCliente << "\n";
}

// funcion para imprimir productos con cantidades menores a 5
void printProductslt5( vector<productValues> &productos, vector<productInfo> &productosInfo ) {

    cout << "Productos con cantidades menor a 5:\n";

    // recorre el vector de productos
    for ( size_t i = 0; i < productos.size(); i++ ) {

        // si la caracterisitca cantidad del vector en i es menor a 5 imprimirla
        if ( productosInfo[i].cantidad < 5 ) {

            cout << "Codigo: " << productos[i].codigo << ", Nombre: " << productos[i].nombre << ", Existencia: " << productos[i].unidades << " " << productosInfo[i].cantidad << " " << productos[i].medida << endl;

        }

    }

}

// funcion para comprar mas producto
void buyProduct( vector<productValues> &productos, vector<productInfo> &productosInfo ) {

    // recorre el vector de productos
    for ( size_t i = 0; i < productos.size(); i++ ) {

        // si la caracterisitca cantidad del vector en i es menor a 5 imprimirla
        if ( productosInfo[i].cantidad < 5 ) {

            productValues nuevoProducto = productos[i];
            productInfo nuevoProductoInfo = productosInfo[i];

            cout << "Comprando producto " << productos[i].codigo << " debido a cantidades bajas." << endl;

            // aumenta las unidades en 5 y sus cantidades
            productos[i].unidades += 5;
            productosInfo[i].cantidad += 5;
            
            productos[i] = nuevoProducto;
            productosInfo[i] = nuevoProductoInfo;

        }

    }

}

// funcion para aplicar descuento
void averageOff( vector<clients> &listaClientes, vector<productPurchase> &productsVenta ) {

    // calcular promedio de compras
    float sumaTotal = 0;

    for ( int i = 0; i < productsVenta.size(); i++ ) {

        sumaTotal += productsVenta[i].valorTotalCobrar;

    }

    float promedioCompras = sumaTotal / productsVenta.size();

    int cantidadVendida;
    cout << "Ingrese la cantidad vendida: ";
    cin >> cantidadVendida;

    int cedulaCliente;
    cout << "Ingrese la cedula del cliente: ";
    cin >> cedulaCliente;

    if ( cantidadVendida > promedioCompras ) {

        // recorrer lista de clientes
        for ( int i = 0; i < listaClientes.size(); i++ ) {

            int totalComprasCliente = 0;

            // Calcular el total de compras del cliente
            for ( int j = 0; j < productsVenta.size(); ++j ) {

                if ( cedulaCliente  == listaClientes[i].cedula ) {

                    cout << "El cliente fue encontrado! | cedula: " << cedulaCliente << "\n";

                    cout << "Descuento del 10% aplicado para el cliente: " << listaClientes[i].nombre << "\n";

                    return;

                }

            }

        }

        cout << "El cliente no se encontro, quizas aun no comprado ha comprado nada | Cedula: " << cedulaCliente << "\n";

        return;
        
    }

    cout << "El cliente no aplica para la oferta | Cedula: " << cedulaCliente << "\n";

    return;

}

// funcion para descuento extra
void underAverageOff( vector<clients>& listaClientes, const vector<productPurchase>& productsVenta ) {

    // calcular promedio de compras
    float sumaTotal = 0;

    for ( int i = 0; i < productsVenta.size(); i++ ) {

        sumaTotal += productsVenta[i].valorTotalCobrar;

    }

    float promedioCompras = sumaTotal / productsVenta.size();

    int cantidadVendida;
    cout << "Ingrese la cantidad vendida: ";
    cin >> cantidadVendida;

    int cedulaCliente;
    cout << "Ingrese la cedula del cliente: ";
    cin >> cedulaCliente;

    if ( cantidadVendida < promedioCompras ) {

        // recorrer lista de clientes
        for ( int i = 0; i < listaClientes.size(); i++ ) {

            int totalComprasCliente = 0;

            // Calcular el total de compras del cliente
            for ( int j = 0; j < productsVenta.size(); j++ ) {

                if ( cedulaCliente  == listaClientes[i].cedula ) {

                    cout << "El cliente fue encontrado! | cedula: " << cedulaCliente << "\n";

                    cout << "Descuento del 15% aplicado para el cliente: " << listaClientes[i].nombre << "\n";

                    return;

                }

            }

        }

        cout << "El cliente no se encontro, quizas aun no comprado ha comprado nada | Cedula: " << cedulaCliente << "\n";

        return;
        
    }

    cout << "El cliente no aplica para la oferta | Cedula: " << cedulaCliente << "\n";

    return;

}

// funcion para descuento sin compra
void noBuyOff( vector<clients>& listaClientes, const vector<productPurchase>& productsVenta ) {

    int cedulaCliente;
    cout << "Ingrese la cedula del cliente: ";
    cin >> cedulaCliente;

        // recorrer lista de clientes
        for ( int i = 0; i < listaClientes.size(); i++ ) {

            int totalComprasCliente = 0;

            // Calcular el total de compras del cliente
            for ( int j = 0; j < productsVenta.size(); ++j ) {

                if ( cedulaCliente  == listaClientes[i].cedula ) {

                    cout << "El cliente fue encontrado! | cedula: " << cedulaCliente << "\n";

                    cout << "Descuento del 25% aplicado para el cliente: " << listaClientes[i].nombre << "\n";

                    return;

                }

            }

        }

    cout << "El cliente no se encontro, quizas aun no comprado ha comprado nada | Cedula: " << cedulaCliente << "\n";

}

// Función para calcular el balance financiero desde el inicio
salesControl calcSalesControl(const vector<productPurchase>& productsVenta) {

    // crear struct a base de salesControl
    salesControl balance = {0.0, 0.0, 0.0, 0.0, 0.0};

    // recorre las ventas
    for ( size_t i = 0; i < productsVenta.size(); i++ ) {

        // calcular total invertido
        balance.totalInvertido += productsVenta[i].precioVenta * productsVenta[i].cantidad;

        // calcular total recuperado
        balance.totalRecuperado += productsVenta[i].valorTotalCobrar;

        // calcular total en ganancia
        balance.totalGanancia += (productsVenta[i].valorTotalCobrar - balance.totalInvertido);

        // calcular total en descuento
        balance.totalDescuento += productsVenta[i].valorDescontar;

        // calcular total en impuesto iva
        balance.totalImpuestoIVA += productsVenta[i].valorCobrarIVA;
    }

    // retorna el struct
    return balance;

}

int main(){

    // Crea un vector que usa el struct productValues y productInfo
    vector<productValues> Productos;
    vector<productInfo> ProductosInfo;

    // Crea un vector que usa el struct productValues y productInfo que almacena los productos con mas de 0 unidades
    vector<productValues> ProductosExistentes;
    vector<productInfo> ProductosExistentesInfo;
    
    // Crea un vector que usa el struct clients para los clientes
    vector<clients> listaClientes;

    // Crea un vector que usa el struct interestedCustomer para los clientes interesados
    vector<interestedCustomer> listaClientesInteresados;

    // Crea un vector que usa el struct productPurchase para articulo comprado
    vector<productPurchase> listaProductosVenta;

    addProduct( Productos, ProductosInfo );

    addClient( listaClientes );

    findProduct( Productos );
    
    updateProduct( Productos, ProductosInfo );

    filtProduct( Productos, ProductosInfo, ProductosExistentes, ProductosExistentesInfo );

    sortProduct( ProductosExistentes, ProductosExistentesInfo );

    exportFile( ProductosExistentes, ProductosExistentesInfo );

    interestedClient( listaClientesInteresados );

    registerPurchaseProduct( listaProductosVenta );

    updatePurchase( listaProductosVenta );

    updateInventory( listaProductosVenta, Productos );

    setClientVIP( listaClientes );

    printProductslt5( Productos, ProductosInfo );

    averageOff( listaClientes, listaProductosVenta );

    underAverageOff( listaClientes, listaProductosVenta );

    noBuyOff( listaClientes, listaProductosVenta );

    // calcula el balance de cuentas
    salesControl balance = calcSalesControl(listaProductosVenta);

    cout << "Total invertido en productos desde el inicio: $" << balance.totalInvertido << endl;
    cout << "Total recuperado en ventas desde el inicio: $" << balance.totalRecuperado << endl;
    cout << "Total de ganancia desde el inicio: $" << balance.totalGanancia << endl;
    cout << "Total de descuento generado desde el inicio: $" << balance.totalDescuento << endl;
    cout << "Total de impuesto IVA pagado desde el inicio: $" << balance.totalImpuestoIVA << endl;

}