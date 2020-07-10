
#ifndef ISISTEMA_H
#define ISISTEMA_H
#include <String>
#include "ICollection.h"
#include "DtTransporte.h"
#include "tipoTransporte.h"
#include "DtProducto.h"
#include "DtMenu.h"
#include "DtMozo.h"
#include "Mesa.h"
using namespace std;
class ISistema{
public:

    virtual void holaMundo()=0;
    virtual int cantProductos()=0;
    virtual int seleccionarTipoProducto(string)=0;
    virtual void ingresarProductoComun(string,string,float)=0;
    virtual void ingresarMenu(string,string)=0;
    virtual ICollection* listarProductos()=0;
    virtual void agregarProductoAlMenu(string,int)=0;
    virtual void confirmar()=0;
    virtual void cancelar()=0;
    virtual ICollection* listarTodo()=0;
    virtual void seleccionarProducto(string)=0;
    virtual void confirmarE()=0;
    virtual void cancelarE()=0;
    virtual void prueba()=0;
    virtual void ingresarNombre(string)=0;
    virtual bool seleccionarTipoEmpleado(string)=0;
    virtual DtTransporte* listarTransportes()=0;
    virtual void seleccionarTransporte(Transportes)=0;
    virtual void confirmarEmpleado()=0;
    virtual void cancelarEmpleado()=0;
    virtual DtProducto* DatosProductoComun()=0;
    virtual bool seleccionarProductoInfo(string)=0;
    virtual DtMenu* DatosProductoMenu()=0;
    virtual bool ComunOMenu()=0;
    virtual bool Salir()=0;
    virtual DtMozo* ObtenerMozo(int)=0;
    virtual void AsignarMesas(DtMozo*,IDictionary*)=0;
    virtual void AsignarMozosAMesasAuto()=0;
};



#endif /* ISISTEMA_H */

