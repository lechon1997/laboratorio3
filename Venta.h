
#ifndef VENTA_H
#define VENTA_H
#include "ICollectible.h"
#include "IDictionary.h"
#include "Factura.h"
#include "Comun.h"
#include "Menu.h"
#include <String>

using namespace std;
class Venta:public ICollectible{
private:
    IDictionary* productosEnLaVenta;
    IDictionary* cantidadDeCadaProducto;
    IDictionary* mesasInvolucradas;
    Factura* factura;
    int numero;
    float montoTotal;
    float iva;
    float subtotal;
    float descuento;
public:
    Venta(int);
    ~Venta();
    int getNumero();
    float getMontoTotal();
    float getIva();
    float getSubtotal();
    float getDescuento();
    int cantVecesVendidoElProducto(Producto*);
    bool ventaFacturada();
    void agregarProductoAlaVenta(Producto*,int);
    void facturarLaVenta();
    bool YoVendoEsto(Producto*);
    ICollection* obtenerProductosVenta();
    void quitarProducto(int,string);
};

#endif /* VENTA_H */

