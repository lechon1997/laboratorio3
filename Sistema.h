
#ifndef SISTEMA_H
#define SISTEMA_H

#include "ISistema.h"
#include "IDictionary.h"
#include "Comun.h"
#include "Menu.h"
class Sistema:public ISistema{

private:
    
    static Sistema* sistema;
    IDictionary* productos;
    IDictionary* empleados;
    IDictionary* ventas;
    Transportes tipo;
    string nombreEmpleado;
    string tipoEmpleado;
    string codigoRecordado;
    string tipoProductoRecordado;
    Comun* comunRecorado;
    Menu* menuRecordado;
    int numeroEmpleado;
    int numeroVenta;
    Sistema();
    
public:
    static Sistema* getInstance();
    void holaMundo();
    int cantProductos();
    int seleccionarTipoProducto(string);
    void ingresarProductoComun(string,string,float);
    void ingresarMenu(string,string);
    ICollection* listarProductos();
    void agregarProductoAlMenu(string,int);
    void confirmar();
    void cancelar();
    bool queSoy();
    ICollection* listarTodo();
    void seleccionarProducto(string);
    void confirmarE();
    void cancelarE();
    void prueba();
    void ingresarNombre(string);
    bool seleccionarTipoEmpleado(string);
    DtTransporte* listarTransportes();
    void seleccionarTransporte(Transportes);
    void confirmarEmpleado();
    void cancelarEmpleado();
    DtProducto* DatosProductoComun();
    bool seleccionarProductoInfo(string);
    DtMenu* DatosProductoMenu();
    bool ComunOMenu();
    bool Salir();
    
};
 


#endif /* SISTEMA_H */

