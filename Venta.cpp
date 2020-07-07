#include "Venta.h"
#include "ListaDicc.h"
#include "DtInfoP.h"
Venta::Venta(int numero){
    this->productosEnLaVenta = new ListDicc;
    this->cantidadDeCadaProducto = new ListDicc;
    this->factura = NULL;
    this->numero = numero;
}

Venta::~Venta(){

}

int Venta::getNumero(){
    return this->numero;
}

float Venta::getDescuento(){
    return this->descuento;
}

float Venta::getMontoTotal(){
    return this->getMontoTotal();
}

float Venta::getSubtotal(){
    return this->subtotal;
}

bool Venta::ventaFacturada(){
    if(this->factura==NULL)
        return false;
    return true;
}

int Venta::cantVecesVendidoElProducto(Producto* p){
    int cant = 0;
    Comun* c = dynamic_cast<Comun*>(p);
    
    if(c){
        KeyString* key = new KeyString(c->getCodigo());
        DtInfoP* dtp = (DtInfoP*)this->cantidadDeCadaProducto->find(key);
        if(dtp){
            cant += dtp->getCantidad();
        }
    IIterator* it = this->productosEnLaVenta->getIteratorObj();
    while(it->hasNext()){
        Menu* m = dynamic_cast<Menu*>(it->getCurrent());
        if(m){
            cant += m->vecesQueSeEncuentraElProducto(key);
        }
        it->next();
    }
    delete it;
    }else{
        Menu* m = (Menu*)p;
        KeyString* key = new KeyString(m->getCodigo());
        DtInfoP* dtp = (DtInfoP*)this->cantidadDeCadaProducto->find(key);
        cant = dtp->getCantidad();
    }
    return cant;
}

bool Venta::YoVendoEsto(Producto* p){
    int cantidad = 0;
    KeyString* key = new KeyString(p->getCodigo());
    ICollectible* cole = this->productosEnLaVenta->find(key);
    if(cole)
        return true;
    else{
        Menu* m2 = dynamic_cast<Menu*>(cole);
        if(m2)
            return false;
        IIterator* it = this->productosEnLaVenta->getIteratorObj();
        while(it->hasNext()){
            Menu* m = dynamic_cast<Menu*>(it->getCurrent());
            cantidad = m->vecesQueSeEncuentraElProducto(key);
            if(cantidad > 0)
                return true;
            it->next();
        }
        delete it;
    }
    return false;
}

void Venta::agregarProductoAlaVenta(Producto* p,int cantidad){
    //falta chequear que no haya sido agregado antes
    Comun* c = dynamic_cast<Comun*>(p);
    if(c){
        KeyString* key = new KeyString(c->getCodigo());
        DtInfoP* dt = new DtInfoP(c->getCodigo(),cantidad); 
        this->productosEnLaVenta->add(c,key);
        this->cantidadDeCadaProducto->add(dt,key);
    }
       
    else{
        Menu* m = (Menu*)p;
        KeyString* key = new KeyString(m->getCodigo());
        DtInfoP* dt = new DtInfoP(m->getCodigo(),cantidad); 
        this->productosEnLaVenta->add(m,key);
        this->cantidadDeCadaProducto->add(dt,key);
    }
}

void Venta::facturarLaVenta(){
    this->factura = new Factura();
}