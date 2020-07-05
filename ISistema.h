
#ifndef ISISTEMA_H
#define ISISTEMA_H
#include <String>
#include "ICollection.h"
#include "DtTransporte.h"
#include "tipoTransporte.h"
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
};



#endif /* ISISTEMA_H */

