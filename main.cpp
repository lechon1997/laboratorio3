#include "Fabrica.h"
#include "ICollection.h"
#include "IIterator.h"
#include "DtProducto.h"
#include "DtMenu.h"
#include "tipoTransporte.h"
#include "DtMozo.h"
#include "DtEmpleado.h"
#include "Mesa.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include "KeyInt.h"
#include "ListaDicc.h"

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
void IniciarVentasEnMesas();
void AsignarMozosAMesas();
void QuitarProductoDeUnaVenta();

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
                    cout<<"4.Informacion de un producto"<<endl;
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
                        case 4:
                            InformacionDeUnProducto();
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
                    
                    cout<<"1.Asignar automáticamente mozos a mesas"<<endl;
                    cout<<"2.Iniciar venta en mesas"<<endl;
                    cin>>opcion2;
                    switch(opcion2){
                        case 1:
                            AsignarMozosAMesas();
                            break;
                        case 2:
                            IniciarVentasEnMesas();
                            break;
                        case 3:
                            QuitarProductoDeUnaVenta();
                            break;
                    }   
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
    string codigo;
    int opcion = 0;
    bool estado = false,existe;
    
    while(estado == false){
        cout<<"\n-----Informacion de un producto-----\n"<<endl;
        ICollection* dts = Sistema->listarTodo();
        IIterator* it = dts->iterator();
    
        cout<<"\n----PRODUCTOS----\n"<<endl;
    
        while(it->hasNext()){
            DtMenu* m = dynamic_cast<DtMenu*>(it->getCurrent());
            if(m){
                cout<<"Codigo: "<<m->getCodigo()<<endl;
                cout<<"Descripcion: "<<m->getDescripcion()<<endl;
            }else{
                 DtProducto* c = (DtProducto*)it->getCurrent();
                 cout<<"Codigo: "<<c->getCodigo()<<endl;
                 cout<<"Descripcion: "<<c->getDescripcion()<<endl;
            }   
        cout<<endl;
        it->next();
        } 
    
        cout<<"Ingresar codigo: ";
        cin>>codigo;
        existe = Sistema->seleccionarProductoInfo(codigo);
        if(existe){
            estado = Sistema->ComunOMenu();
            if(estado){
                 DtProducto* dtp = Sistema->DatosProductoComun();
                 cout<<"\nCodigo: "<<dtp->getCodigo()<<endl;
                 cout<<"Descripcion: "<<dtp->getDescripcion()<<endl;
                 cout<<"Precio: "<<dtp->getPrecio()<<endl;
                 cout<<"Unidades vendidas: "<<dtp->getUnidadesVendidas()<<endl;
            }else{
                 DtMenu* dtm = Sistema->DatosProductoMenu();
                 cout<<"\nCodigo: "<<dtm->getCodigo()<<endl;
                 cout<<"Descripcion :"<<dtm->getDescripcion()<<endl;
                 cout<<"Precio: "<<dtm->getPrecio()<<endl;
            
                 ICollection* dtsp = dtm->getDatosProductos();
                 IIterator* it = dtsp->iterator();
                 cout<<"   \n----Productos del menu----\n"<<endl;
            
                 while(it->hasNext()){
                    DtProducto* p = (DtProducto*)it->getCurrent();
                    cout<<"     Codigo:"<<p->getCodigo()<<endl;
                    cout<<"     Descripcion:"<<p->getDescripcion()<<endl;
                    cout<<"     Precio:"<<p->getPrecio()<<endl;
                    cout<<endl;
                    it->next();
                }
            }
        }else{
            cout<<"\nCodigo ingresado incorrecto"<<endl;
            cout<<"Desea volver a intentarlo?\n1.Si\n2.No\nIngresar Opcion :";
            cin>>opcion;
            if(opcion == 2){
                estado = Sistema->Salir();
            }
        }
    }
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

         cout<<"\nDesea dar de alta al empleado?"<<endl;
         cout<<"1.Confirmar\n2.Cancelar\nIngresar opcion: ";
         cin>>opcion;
         if(opcion == 1){
             Sistema->confirmarEmpleado();
             cout<<"\nEmpleado dado de alta con exito\n"<<endl;
         }else{
             Sistema->cancelarEmpleado();
             cout<<"\nEmpleado cancelado\n"<<endl;    
         }
         
         cout<<"\ndesea dar de alta otro emppleado?"<<endl;
         cout<<"1.SI\n2.No\nIngresar opcion: ";
         cin>>opcion;
         if(opcion == 2)
             cout<<endl;break;
    }
}

void IniciarVentasEnMesas(){
    int IDMozo,IDMesa,cantmesas;
    DtMozo* dtMozo1;
    string ingresarMesa="si",comfirmar;
    
    cout<<"\n-----Iniciar Venta En mesas-----\n"<<endl;
    
        cout<<"\nIngresar Identificador del mozo:\n"<<endl;
        cin>>IDMozo;
        dtMozo1 = Sistema->ObtenerMozo(IDMozo);
        if(dtMozo1){
            
            cout<<"\nNombre del Mozo: \n"<<dtMozo1->getNombre()<<endl;
            cout<<"\nMesas Asignadas:\n"<<endl;
            IIterator* itmesas= dtMozo1->getMesas()->getIteratorObj();
            
            
            cantmesas=0;
            while(itmesas->hasNext()){
                Mesa* MozoMesa= (Mesa*)itmesas->getCurrent();
                if(MozoMesa->getVentaL()==NULL){
                cout<<"\n Mesa numero: "<<MozoMesa->getNumero()<<"\n"<<endl;
                cantmesas++;
                }
                itmesas->next();
            }
            
            
            if(cantmesas>0){
            
                
            IDictionary * mesasSeleccionadas = new ListDicc;
            while(ingresarMesa=="si"){
                cout<<"\nQue mesa desea asignar la venta? (Nro de mesa) \n"<<endl;
                cin>>IDMesa;
                KeyInt* keym = new KeyInt(IDMesa);
                Mesa* MesaAAsignar = (Mesa*)dtMozo1->getMesas()->find(keym);
                if(MesaAAsignar){
                mesasSeleccionadas->add(MesaAAsignar,keym);

                cout<<"\nDesea Seguir Asignando? (si/no)\n"<<endl;
                cin>>ingresarMesa;
                }else{
                    throw invalid_argument("la mesa no existe");
                }
                
            }
            
            IIterator* itmesel=mesasSeleccionadas->getIteratorObj();
            
            cout<<"\nMesas Seleccionadas: \n"<<endl;
            
            while(itmesel->hasNext()){
                Mesa* mesaSeleccionada = (Mesa*) itmesel->getCurrent();
                
                cout<<"\n Mesa numero: "<<mesaSeleccionada->getNumero()<<"\n"<<endl;
                itmesel->next();
            }
            
            cout<<"\n Comfirmar? (si/no) \n"<<endl;
            cin>>comfirmar;
            
            if(comfirmar=="si"){
                
                 Sistema->AsignarMesas(dtMozo1,mesasSeleccionadas);
                 cout<<"\n ----Ventas iniciadas---- \n"<<endl;
                 
            }else{
                
            }
            
            }else{
                 cout<<"\n No tienes ninguna mesa disponible para iniciarle una venta.\n"<<endl;
            }              
        
        }else{
            cout<<"\nEl codigo identificador es incorrecto\n"<<endl;
        }
        
}

void AsignarMozosAMesas(){
    
    Sistema->AsignarMozosAMesasAuto();
    
    cout<<"\n Mesas asignadas correctamente.\n"<<endl;
}

void QuitarProductoDeUnaVenta(){
    int numeroMesa,cantidad,opcion,opcion2;
    bool seguir = true;
    string codigo;
    
    cout<<"\n----Quitar producto de una venta----.\n"<<endl;
    cout<<"Ingresar numero de mesa: ";
    cin>>numeroMesa;
    Sistema->seleccionarMesa(numeroMesa);
    
    cout<<"\nProductos de la venta\n"<<endl;
    
    ICollection* dtsproductos  = Sistema->listarProductosVenta();
    IIterator* it = dtsproductos->iterator();
    
    while(it->hasNext()){
        DtProducto* dtp = dynamic_cast<DtProducto*>(it->getCurrent());
        if(dtp){
            cout<<"Codigo: "<<dtp->getCodigo()<<endl;
            cout<<"Descripcion: "<<dtp->getDescripcion()<<endl;
        }else{
            DtMenu* dtm =(Menu*)it->getCurrent();
            cout<<"Codigo: "<<dtm->getCodigo();
            cout<<"Descripcion: "<<dtm->getDescripcion()<<endl;
        }
        cout<<endl;
        it->next();
    }
    
    while(seguir){
        cout<<"Ingresar codigo producto: ";
        cin>>codigo;
        fflush(stdin);
        Sistema->seleccionarProducto(codigo);
        cout<<"Ingresar cantidad a remover: ";
        cin>>cantidad;
        Sistema->ingresarCantidad(cantidad);

        cout<<"\nDesea condirmar?\n1.Si\n2.No\nIngresar opcion: ";
        cin>>opcion;
        if(opcion == 1){
            Sistema->confirmarQuitarProducto();
            cout<<"\nProducto quitado de la venta con exito\n"<<endl;
        }else{
            Sistema->cancelarQuitarProducto();
            cout<<"\nEl producto no se quito de la venta\n"<<endl;
        }
        
        cout<<"\nDesea seguir quitando productos de la venta?\n1.Si\n2.No\nIngresar Opcion: ";
        cin>>opcion2;
        
        if(opcion2 == 2){
            seguir == false;
        }
    }
    Sistema->olvidarMesa();
}   