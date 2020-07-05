#include "Sistema.h"
#include "ListaDicc.h"
#include "IIterator.h"
#include "Lista.h"
#include "KeyString.h"
#include "DtProducto.h"
#include "Producto.h"
#include "KeyInt.h"
#include "Mozo.h"
#include "Repartidor.h"
#include "Comun.h"
#include <cstddef>
#include <iostream>


Sistema* Sistema::sistema = NULL;

Sistema::Sistema() {
    this->numeroEmpleado=1;
    this->productos = new ListDicc;
    this->empleados = new ListDicc;
    this->comunRecorado = NULL;
    this->menuRecordado = NULL;
    this->tipoProductoRecordado="";
    this->codigoRecordado="";
    this->nombreEmpleado="";
    this->tipoEmpleado="";
    this->tipo=PIE;
    //PRODUCTO DE PRUEBA,LUEGO BORRAR
    Comun* c = new Comun("1","milanesa",300);
    KeyString* key = new KeyString(c->getCodigo());
    this->productos->add(c,key);
    /*
    Comun* c2 = new Comun("2","Pan",25);
    KeyString* key2 = new KeyString(c2->getCodigo());
    this->productos->add(c2,key2);
    
    Comun* c3 = new Comun("3","Churrasco",350);
    KeyString* key3 = new KeyString(c3->getCodigo());
    this->productos->add(c3,key3);
    */
}


Sistema* Sistema::getInstance() {
    if (sistema == NULL)
        sistema = new Sistema();
    return sistema;
}

void Sistema::holaMundo(){
    cout<<"Hola mundo :)"<<endl;
}

void Sistema::prueba(){
    
    
    
    IIterator* it2 = this->productos->getIteratorObj();
    while(it2->hasNext()){
        this->productos->removeObj(it2->getCurrent());
    }
    
    ICollection* setDtProductos = this->listarProductos();
        IIterator* it = setDtProductos->iterator();
        
        cout<<"------PRODUCTOS------"<<endl<<endl;
        
        while(it->hasNext()){
            DtProducto* dtp = (DtProducto*)it->getCurrent();
            
            cout<<"Codigo: "<<dtp->getCodigo()<<endl;
            cout<<"Descripcion: "<<dtp->getDescripcion()<<endl;
            cout<<"Precio: "<<dtp->getPrecio()<<endl;
            cout<<endl;
            it->next();
        }
}
//ALTA PRODUCTO

int Sistema::cantProductos(){
    int cantidad = 0;
    IIterator* it =this->productos->getIteratorObj();
    while(it->hasNext()){
        Comun* c = (Comun*)it->getCurrent();
        if(c)
            cantidad++;
       
        it->next();
    }
    return cantidad;
}

int Sistema::seleccionarTipoProducto(string tipo){
    this->tipoProductoRecordado=tipo;
    if(tipo =="Comun")
        return 1;
    else if(tipo =="Menu")
        return 2;
    throw invalid_argument("\ntipo de Producto incorrecto");
    
}

void Sistema::ingresarProductoComun(string codigo,string descripcion ,float precio){
   Comun* c = NULL;
   if(precio<=0)
       throw invalid_argument("Precio debe ser mayor a 0");
       
   KeyString* key = new KeyString(codigo);
   
   if(this->productos->find(key)){
       delete key;
       throw invalid_argument("\nEl producto ya existe\n");
   }
   
   c = new Comun(codigo,descripcion,precio);
   this->comunRecorado = c;
}

void Sistema::ingresarMenu(string codigo, string descripcion){
    KeyString* key = new KeyString(codigo);
    if(this->productos->find(key)){
        delete key;
        throw invalid_argument("\nCodigo ingresado ya existe\n");
    }
    
    Menu* m = new Menu(codigo,descripcion);
    this->menuRecordado = m; 
}

ICollection* Sistema::listarProductos(){
    ICollection* DtProductos = new Lista;
    IIterator* it = this->productos->getIteratorObj();
    while(it->hasNext()){
        Comun* c = dynamic_cast<Comun*>(it->getCurrent());
        if(c){
            DtProducto* p = c->getDatosProducto();
            DtProductos->add(p);
        }
        it->next();
    }
    delete it;
    return DtProductos;
}

void Sistema::agregarProductoAlMenu(string codigo, int cantidad){
    KeyString* key = new KeyString(codigo);
    Comun* c = (Comun*)this->productos->find(key);
    if(!c){
        delete key;
        throw invalid_argument("\nEl producto no existe\n");
    }else{
        this->menuRecordado->ingresarProducto(c,key);
        this->menuRecordado->ingresarDtInfoP(c->obtenerInfoP(cantidad));
    }
}

bool Sistema::queSoy(){
    if(this->comunRecorado!=NULL)
        return true;
    return false;
    
}

void Sistema::confirmar(){
    bool comun = this->queSoy();
    
    if(comun== true){
        KeyString* key = new KeyString(this->comunRecorado->getCodigo());
        this->productos->add(this->comunRecorado,key);
        this->comunRecorado=NULL;
    }else{
        KeyString* key = new KeyString(this->menuRecordado->getCodigo());
        this->productos->add(this->menuRecordado,key);
        this->menuRecordado=NULL;
    }
    
    this->tipoProductoRecordado="";
}
 
void Sistema::cancelar(){
    if(this->comunRecorado != NULL){
        delete this->comunRecorado;
        this->comunRecorado = NULL;
    }else if(this->menuRecordado != NULL){
        this->menuRecordado->quitarProductos();
        delete this->menuRecordado;
        this->menuRecordado = NULL;
    }
    this->tipoProductoRecordado="";
}

//BAJA PRODUCTO

ICollection* Sistema::listarTodo(){
    ICollection* dts = new Lista;
    IIterator* it = this->productos->getIteratorObj();
    while(it->hasNext()){
        Comun* c = dynamic_cast<Comun*>(it->getCurrent());
        
        if(c)
            dts->add(c->getDatosProducto());
        else{
            Menu* m = (Menu*)it->getCurrent();
            dts->add(m->getDtMenu());
        }

        it->next();
    }
    return dts;
}

void Sistema::seleccionarProducto(string cod){
    this->codigoRecordado = cod;
}

void Sistema::confirmarE(){
    bool yaMeMovi = false;
    KeyString* key = new KeyString(this->codigoRecordado);
    Menu* m = dynamic_cast<Menu*>(this->productos->find(key));
    if(m != NULL){
        m->quitarProductos();
        this->productos->removeObj(m);
        delete m;
    }else{
        Comun* c = (Comun*) this->productos->find(key);
        IIterator* it = this->productos->getIteratorObj();
        while(it->hasNext()){
            Menu* m = dynamic_cast<Menu*>(it->getCurrent());
            if(m){
                m->quitarProducto(c);
                if(m->menuVacio()){
                    this->productos->removeObj(m);
                    delete m;
                    yaMeMovi = true;
                }
            }
            if(yaMeMovi)
                yaMeMovi = false;
            else
                it->next();
        }
        this->productos->removeObj(c);
        delete c;
    }
    this->codigoRecordado="";
}

void Sistema::cancelarE(){
    this->codigoRecordado="";
}

void Sistema::ingresarNombre(string nombre){
    this->nombreEmpleado = nombre;
}

DtTransporte* Sistema::listarTransportes(){
    return new DtTransporte();
}

bool Sistema::seleccionarTipoEmpleado(string tipo){
    if(tipo!="Repartidor" && tipo!="Mozo")
        throw invalid_argument("\nTipo de empleado no existe\n");

    this->tipoEmpleado = tipo;
    
    if(tipo == "Mozo")
        return true;
    return false;
}

void Sistema::seleccionarTransporte(Transportes tipo){
    this->tipo = tipo;
}

void Sistema::confirmarEmpleado(){
    if(this->tipoEmpleado == "Repartidor"){
        Repartidor* r = new Repartidor(this->numeroEmpleado,this->nombreEmpleado,this->tipo);
        KeyInt* key = new KeyInt(this->numeroEmpleado);
        this->empleados->add(r,key);
        
    }else if(this->tipoEmpleado == "Mozo"){
        Mozo* m = new Mozo(this->numeroEmpleado,this->nombreEmpleado);
        KeyInt* key = new KeyInt(this->numeroEmpleado);
        this->empleados->add(m,key);
    }
     this->numeroEmpleado++;
     this->tipoEmpleado="";
}

void Sistema::cancelarEmpleado(){
    this->nombreEmpleado="";
    this->tipo=PIE;
}