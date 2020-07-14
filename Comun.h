
#ifndef COMUN_H
#define COMUN_H
#include "Producto.h"
#include "DtProducto.h"
#include "DtInfoP.h"

class Comun:public Producto{
    private:
        float precio;
    public:
        Comun(string,string,float);
        ~Comun();
        float getPrecio();
        DtProducto* getDatosProducto();
        DtInfoP* obtenerInfoP(int);
};


#endif /* COMUN_H */

