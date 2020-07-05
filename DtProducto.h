

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
    public:
        DtProducto(string,string,float);
        ~DtProducto();
        string getCodigo();
        string getDescripcion();
        float getPrecio();
            
};


#endif /* DTPRODUCTO_H */

