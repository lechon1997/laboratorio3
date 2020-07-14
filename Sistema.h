
#ifndef SISTEMA_H
#define SISTEMA_H

#include "ISistema.h"
#include "DtMozo.h"
#include "IDictionary.h"
#include "Comun.h"
#include "Menu.h"
#include "Mozo.h"
#include "Mesa.h"
class Sistema:public ISistema{

private:
    
    static Sistema* sistema;
    IDictionary* productos;
    IDictionary* empleados;
    IDictionary* ventas;
    Transportes tipo;
    IDictionary* mesas;
    Mesa* mesaRecordada;
    string nombreEmpleado;
    string tipoEmpleado;
    string codigoRecordado;
    string tipoProductoRecordado;
    Comun* comunRecorado;
    Menu* menuRecordado;
    int numeroEmpleado;
    int numeroVenta;
    int cantidad;
    int deskRecordado;
    FechaHora* FechaHoraActual;
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
    DtMozo* ObtenerMozo(int);
    void AsignarMesas(DtMozo*,IDictionary*);
    void AsignarMozosAMesasAuto();
    void seleccionarMesa(int);
    ICollection* listarProductosVenta();
    void ingresarCantidad(int);
    void confirmarQuitarProducto();
    void cancelarQuitarProducto();
    void olvidarMesa();
    void Sistema::FacturacionDeUnaVenta();
    void Sistema::ingresarDescuento(int);
    void Sistema::generarFactura();
    void Sistema::ModificarFechaHora(FechaHora *);
    void setFechaHoraActual(FechaHora* FechaHoraActual);
    FechaHora* getFechaHoraActual() const;
};
 


#endif /* SISTEMA_H */

