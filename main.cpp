#include "Fabrica.h"
#include "ICollection.h"
#include "IIterator.h"
#include "DtProducto.h"
#include "DtMenu.h"
#include "tipoTransporte.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/*
 * 
 */

Fabrica* fabrica=Fabrica::getInstance();
ISistema* Sistema=fabrica->getISistema();
    
void AltaProducto();
void AltaEmpleado();
void BajaProducto();
void InformacionDeUnProducto();
int main(int argc, char** argv) {
    
    int opcion=0,opcion2=0;    
    //Sistema->prueba();
    while(1){

            cout << "1.Administrador" <<endl;
            cout << "2.Mozo" << endl;
            cout << "3.Cargar datos de pruba" << endl;
            cout << "4.Salir" << endl;
            cout << "Ingresar opcion: ";
            cin>>opcion;
            cout<<endl;
            switch(opcion){
                case 1:
                     while(1){
                         try{
                    cout<<"1.Alta producto"<<endl;
                    cout<<"2.Baja producto"<<endl;
                    cout<<"3.Alta empleado"<<endl;
                    cout<<"Ingrese opcion: ";
                    cin>>opcion2;
                    switch(opcion2){
                        case 1:
                            AltaProducto();
                            break;
                        case 2:
                            BajaProducto();
                            break; 
                        case 3:
                            AltaEmpleado();
                            break;
                        default:
                            cout<<"Vaciar el buffer"<<endl;
                            break;
                    }
                    }catch(invalid_argument &error){
                    cout<< error.what() << endl;
                    cout<< endl;
                }
                }
                    break;
                case 2 :
                    cout<<"Opcion 2"<<endl;
                    break;
            }
           
    }
    return 0;
}

void AltaProducto(){
    int total,opcion,opcion2,opcion3,cantidad;
    string tipoP,codigo,descripcion;
    float precio;
    bool estado = true;
    
    total = Sistema->cantProductos();
    cout<<"\nIngresar tipo de  Producto: ";    
    cin>>tipoP;
    
    opcion = Sistema->seleccionarTipoProducto(tipoP);
    
    if(opcion==1){
        cout<<"\nIngresar codigo: ";
        cin>>codigo;
        cout<<"Ingresar descripcion: ";
        cin>>descripcion;
        
        fflush(stdin);
        cout<<"Ingresar precio: ";
        cin>>precio;
        Sistema->ingresarProductoComun(codigo,descripcion,precio);
    }else if (opcion == 2 && total > 0){
        cout<<"\nIngresar codigo: ";
        cin>>codigo;
        cout<<"Ingresar descripcion: ";
        cin>>descripcion;
        cout<<endl;
        fflush(stdin);
        
        Sistema->ingresarMenu(codigo,descripcion);
        ICollection* setDtProductos = Sistema->listarProductos();
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
        
        cout<<"\n----Agregar productos al menu----"<<endl;
            
        while(estado){
            
            cout<<"Ingresar codigo: ";
            cin>>codigo;
            cout<<"Ingresar cantidad: ";
            cin>>cantidad;
            Sistema->agregarProductoAlMenu(codigo,cantidad);
            cout<<"\nProducto agregado al menu con exito\n"<<endl;
            
            cout<<"Desea seguir ingresando productos al menu?"<<endl;
            cout<<"1.Si\n2.No\nIngresar opcion: ";
            cin>>opcion3;
            if(opcion3 == 2)
                estado = false;
            else
                cout<<"\n----Agregar productos al menu----"<<endl;
            
        }
    }
    
    cout<<"\n1.Confirmar\n2.Cancelar\nIngresar opcion: ";
    cin>>opcion2;
    if(opcion2 == 1){
        Sistema->confirmar();
        cout<<"Producto creado exitosamente\n"<<endl;
    }
    else
        Sistema->cancelar();
}

void BajaProducto(){
    string codigo;
    int opcion;
    
    ICollection* dts = Sistema->listarTodo();
   
    IIterator* it = dts->iterator();
    cout<<"\n----PRODUCTOS----\n"<<endl;
    while(it->hasNext()){
        DtMenu* m = dynamic_cast<DtMenu*>(it->getCurrent());
        if(m){
            cout<<"Codigo: "<<m->getCodigo()<<endl;
            cout<<"Descripcion: "<<m->getDescripcion()<<endl;
            cout<<"Precio: "<<m->getPrecio()<<endl;
        }else{
            DtProducto* c = (DtProducto*)it->getCurrent();
            cout<<"Codigo: "<<c->getCodigo()<<endl;
            cout<<"Descripcion: "<<c->getDescripcion()<<endl;
            cout<<"Precio: "<<c->getPrecio()<<endl;
        }
        cout<<endl;
        it->next();
    }   
    
    cout<<"Ingresar codigo: ";
    cin>>codigo;
    Sistema->seleccionarProducto(codigo);
    
    
    cout<<"\nDesea eliminar el producto?";
    cout<<"\n1.Confirmar\n2.Cancelar\nIngresar opcion: ";
    cin>>opcion;
    if(opcion == 1)
        Sistema->confirmarE();
    else 
        Sistema->cancelarE();
    
}   

void InformacionDeUnProducto(){
    
}


void AltaEmpleado(){
    Transportes tipoT;
    string nombre,tipo,tipoTransporte;
    int opcion;
    bool tipoEmp;
    while(true){
         cout<<"\n-----Alta Empleado-----\n"<<endl;
         
         cout<<"\nSeleccionar tipo de empleado: ";
         cin>>tipo;
         tipoEmp = Sistema->seleccionarTipoEmpleado(tipo);
         fflush(stdin);
         
         if(tipoEmp == true){
             cout<<"Ingresar nombre: ";
             cin>>nombre;
             Sistema->ingresarNombre(nombre);
             fflush(stdin);
         }else{
             cout<<"Ingresar nombre: ";
             cin>>nombre;
             Sistema->ingresarNombre(nombre);
             fflush(stdin);
         
             cout<<"\n----Seleccionar tipo de transporte----\n"<<endl;
             
             DtTransporte* t = Sistema->listarTransportes();
             cout<<t->getPie()<<endl;
             cout<<t->getBici()<<endl;
             cout<<t->getmoto()<<endl;
             cout<<"Ingresar transporte: ";
             cin>>tipoTransporte;
             if(tipoTransporte=="Bici")
                 tipoT = BICI;
             else if (tipoTransporte == "Pie")
                 tipoT = PIE;
             else if (tipoTransporte == "Moto")
                 tipoT = MOTO;
             else
                 throw invalid_argument("Tipo de transporte no disponible");
             
             fflush(stdin);
             Sistema->seleccionarTransporte(tipoT);
            
         }         

         cout<<"Desea dar de alta al empleado?"<<endl;
         cout<<"1.SI\n2.No\nIngresar opcion: ";
         cin>>opcion;
         if(opcion==1)
             
    }
}