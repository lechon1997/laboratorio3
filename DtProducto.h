

#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H
#include "ICollectible.h"
#include <String>
using namespace std;
class DtProducto:public ICollectible{
    private:
        string codigo;
        string descripcion;
        float precio;
        int unidadesVendidas;
    public:
        DtProducto(string,string,float);
        DtProducto(string,string,float,int);
        ~DtProducto();
        string getCodigo();
        string getDescripcion();
        float getPrecio();
        int getUnidadesVendidas();
            
};


#endif /* DTPRODUCTO_H */

