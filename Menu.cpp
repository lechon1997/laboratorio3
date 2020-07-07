#include  "Menu.h"
#include "ListaDicc.h"
#include "IIterator.h"
#include "Lista.h"
#include "DtInfoP.h"
#include "DtMenu.h"
#include "Comun.h"
#include "ICollection.h"

Menu::Menu(string codigo, string descripcion):Producto(codigo,descripcion){
    this->productosComun = new ListDicc;
    this->DtinfosP = new ListDicc;
}

Menu::~Menu(){

}

float Menu::getPrecio(){
    float precio=0;
    int cantidad;
    IIterator* it = this->productosComun->getIteratorKey();
    while(it->hasNext()){
        KeyString* key =(KeyString*)it->getCurrent ();
        Comun* c = (Comun*)this->productosComun->find(key);
        DtInfoP* dti = (DtInfoP*)this->DtinfosP->find(key);
        cantidad = dti->getCantidad();
        precio += (c->getPrecio()*cantidad);
        it->next();
    }
    delete it;
    return precio;
}

void Menu::quitarProductos(){
    IIterator* it = this->productosComun->getIteratorObj();
    while(it->hasNext()){
        it->remove();
    }      
    delete it;
}

void Menu::ingresarProducto(Comun* c,KeyString* k){
    
    this->productosComun->add(c,k);
}

void Menu::ingresarDtInfoP(DtInfoP* dt){
    KeyString* key = new KeyString(dt->getCodigo());
    this->DtinfosP->add(dt,key);
}

DtMenu* Menu::getDtMenu(){
    string codigo = this->getCodigo();
    string descripcion = this->getDescripcion();
    float precio = this->getPrecio();
    
    ICollection* dts = new Lista;
    IIterator* it = this->productosComun->getIteratorObj();
    
    while(it->hasNext()){
        Comun* c = (Comun*)it->getCurrent();
        DtProducto* p = c->getDatosProducto();
        dts->add(p);
        it->next();
    }
    DtMenu* dtm = new DtMenu(codigo,descripcion,precio,dts);
    return dtm;
}


DtMenu* Menu::getDtMenu(int cant){
    string codigo = this->getCodigo();
    string descripcion = this->getDescripcion();
    float precio = this->getPrecio();
    
    ICollection* dts = new Lista;
    IIterator* it = this->productosComun->getIteratorObj();
    
    while(it->hasNext()){
        Comun* c = (Comun*)it->getCurrent();
        DtProducto* p = c->getDatosProducto();
        dts->add(p);
        it->next();
    }
    DtMenu* dtm = new DtMenu(codigo,descripcion,precio,cant,dts,this->productosComun);
    return dtm;
}

void Menu::quitarProducto(Comun* c){
    this->productosComun->removeObj(c);
}

bool Menu::menuVacio(){
    int cantidad = this->productosComun->size();
    if(cantidad == 0)
        return true;
    return false;
}

int Menu::vecesQueSeEncuentraElProducto(KeyString* key){
    int cant = 0;
    DtInfoP* dti = (DtInfoP*)this->DtinfosP->find(key);
    if(dti)
        cant = dti->getCantidad();
    return cant;
}