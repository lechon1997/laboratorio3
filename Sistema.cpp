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
#include "Venta.h"
#include "DtEmpleado.h"
#include <cstddef>
#include <iostream>
#include <valarray>
//#include <bits/unordered_set.h>
#include "Mesa.h"


Sistema* Sistema::sistema = NULL;

Sistema::Sistema() {
    this->menuRecordado=NULL;
    this->numeroEmpleado=1;
    this->numeroVenta=1;
    this->cantidad = 0;
    this->productos = new ListDicc;
    this->empleados = new ListDicc;
    this->mesas= new ListDicc;
    this->ventas = new ListDicc;
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
    
    Comun* c2 = new Comun("2","Pan",25);
    KeyString* key2 = new KeyString(c2->getCodigo());
    this->productos->add(c2,key2);
    
    Comun* c3 = new Comun("3","Churrasco",350);
    KeyString* key3 = new KeyString(c3->getCodigo());
    this->productos->add(c3,key3);
    
    Venta* v = new Venta(1);
    KeyInt* key4 = new KeyInt(1);
    v->agregarProductoAlaVenta(c,3);
    v->agregarProductoAlaVenta(c2,2);
    //v->facturarLaVenta();
    this->ventas->add(v,key4);
    cout<<"1";
    //mozo y mesas de prueba
    Mozo* m1= new Mozo(1,"Sergio Vergara Telechea");
    m1->setTipo(true);
    KeyInt* keym1 = new KeyInt(m1->getNumero());
    this->empleados->add(m1,keym1);
    

  //  IDictionary* mesas1 = new ListDicc;
    Mesa* mesa1 = new Mesa(1);
    KeyInt* keymesa1 = new KeyInt(1);
    this->mesas->add(mesa1,keymesa1);
   // mesas1->add(mesa1,keymesa1);

    Mesa* mesa2 = new Mesa(2);
    KeyInt* keymesa2 = new KeyInt(2);
    this->mesas->add(mesa2,keymesa2);
   // mesas1->add(mesa2,keymesa2);

    Mesa* mesa3 = new Mesa(14);
    KeyInt* keymesa3 = new KeyInt(14);
    this->mesas->add(mesa3,keymesa3);
  //  mesas1->add(mesa3,keymesa3);

   // m1->setMesas(mesas1);
    
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
    KeyString* key = new KeyString(cod);
    ICollectible* p = this->productos->find(key);
    delete key;
    if(!p)
        throw invalid_argument("\nEl producto no existe\n");
}

void Sistema::confirmarE(){
    bool yaMeMovi = false,vendoEsto,facturada;
    KeyString* key = new KeyString(this->codigoRecordado);
    Menu* m = dynamic_cast<Menu*>(this->productos->find(key));
    
    //verifico si esta facturada
    
    
    if(m != NULL){
        IIterator* it = this->ventas->getIteratorObj();
        while(it->hasNext()){
            Venta* v = (Venta*)it->getCurrent();
            vendoEsto = v->YoVendoEsto(m);
            if(vendoEsto){
                facturada = v->ventaFacturada();
                if(!facturada)
                    throw invalid_argument("\nEl producto se encuentra en ventas sin facturar");
            }
            it->next();
        }
        
        m->quitarProductos();
        this->productos->removeObj(m);
        delete m;
    }else{
        Comun* c = (Comun*) this->productos->find(key);
        
        IIterator* it2 = this->ventas->getIteratorObj();
        while(it2->hasNext()){
            Venta* v = (Venta*)it2->getCurrent();
            vendoEsto = v->YoVendoEsto(c);
            if(vendoEsto){
                facturada = v->ventaFacturada();
                if(!facturada)
                    throw invalid_argument("\nEl producto se encuentra en ventas sin facturar");
            }
            it2->next();
        }
        
        
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

bool Sistema::seleccionarProductoInfo(string codigo){
  
    KeyString* key = new KeyString(codigo);
    ICollectible* cole = this->productos->find(key);
    delete key;
    if(cole){
        this->codigoRecordado = codigo;
        return true;
    }
    return false;
}

bool Sistema::ComunOMenu(){
    KeyString* key = new KeyString(this->codigoRecordado);
    Comun* c = dynamic_cast<Comun*>(this->productos->find(key));
    if(c)
        return true;
    return false;
}

DtProducto* Sistema::DatosProductoComun(){
    int cantUniVendidas=0;
    KeyString* key = new KeyString(this->codigoRecordado);
    Comun* c = (Comun*)this->productos->find(key);
    IIterator* it = this->ventas->getIteratorObj();
    
    while(it->hasNext()){
        Venta* v = (Venta*)it->getCurrent();
        if(v->ventaFacturada()){
            cantUniVendidas += v->cantVecesVendidoElProducto(c);
        }
        it->next();
    }
    delete it;
    return new DtProducto(c->getCodigo(),c->getDescripcion(),c->getPrecio(),cantUniVendidas);
}

DtMenu* Sistema::DatosProductoMenu(){
    int cantUniVendidas=0;
    KeyString* key = new KeyString(this->codigoRecordado);
    Menu* m = (Menu*)this->productos->find(key);
    IIterator* it = this->ventas->getIteratorObj();
    
    while(it->hasNext()){
       Venta* v = (Venta*)it->getCurrent();
       if(v->ventaFacturada()){
           cantUniVendidas += v->cantVecesVendidoElProducto(m);
       }
       it->next();
    }
    delete it;
    return m->getDtMenu(cantUniVendidas);
}

bool Sistema::Salir(){
    this->codigoRecordado="";
    return true;
}

DtMozo* Sistema::ObtenerMozo(int ID){
    KeyInt* key = new KeyInt(ID);

 
    Mozo* m =dynamic_cast<Mozo*>(this->empleados->find(key));

    if(m){

        return m->toDTMozo();

    }else{
        throw invalid_argument("el mozo no existe");
        return NULL;
    }

}
    
    
void Sistema::AsignarMesas(DtMozo* dtmozo1,IDictionary* mesas){
    KeyInt* key = new KeyInt(dtmozo1->getNumero());
    Mozo* mozo = (Mozo*)this->empleados->find(key);
    
    IIterator* it= mesas->getIteratorObj();
    
    while(it->hasNext()){
        
        Mesa* me2 = (Mesa*)it->getCurrent();
        int cod = (int)ventas->size();
        cod=cod++;
        KeyInt* keycod = new KeyInt(cod);
        
        VentaLocal* vl= new VentaLocal(cod);
        ventas->add(vl,keycod);
        me2->setVentaL(vl);
        
        it->next();
    }
    
}

void Sistema::AsignarMozosAMesasAuto(){
    int mozos=0, mesas, result;
    IDictionary* mozosDic = new ListDicc;
    IIterator* it= this->empleados->getIteratorObj();
    while(it->hasNext()){
        Empleado* e = (Empleado*) it->getCurrent();
        if(e->getTipo()==true){
            mozos++;
            Mozo* m = (Mozo*) it->getCurrent();
            KeyInt* mKey= new KeyInt(m->getNumero());
            mozosDic->add(m,mKey);
        }
        it->next();
    }
    
    mesas=this->mesas->size();
    
    result=floor(mesas/mozos);
    
    IIterator* itmozos= mozosDic->getIteratorObj();
    IIterator* itmesas = this->mesas->getIteratorObj();
    
    while(itmozos->hasNext()){
        
        Mozo* mozo = (Mozo*) itmozos->getCurrent();
        if(itmesas->hasNext()){
        
        for(int i=0; i<result; i++){
            Mesa* mesa = (Mesa*) itmesas->getCurrent();    
            
            mozo->addMesa(mesa,mesa->getNumero());
            itmesas->next();
        }
        
        }
        
        itmozos->next();
        
    }
    
    //while(result)
}

void Sistema::seleccionarMesa(int numeroM){
    KeyInt* key = new KeyInt(numeroM);
    Mesa* m = (Mesa*)this->mesas->find(key);
    this->mesaRecordada = m;
}

ICollection* Sistema::listarProductosVenta(){
    Venta* v = this->mesaRecordada->getVenta();
    return v->obtenerProductosVenta();
}

void Sistema::ingresarCantidad(int cantidad){
    this->cantidad = cantidad;
}

void Sistema::confirmarQuitarProducto(){
    Venta* v = this->mesaRecordada->getVenta();
    v->quitarProducto(this->cantidad,this->codigoRecordado);
    
    this->codigoRecordado="";
    this->cantidad = 0;
}

void Sistema::cancelarQuitarProducto(){
    this->codigoRecordado="";
    this->cantidad = 0;
}

void Sistema::olvidarMesa(){
    this->mesaRecordada = NULL;
}
