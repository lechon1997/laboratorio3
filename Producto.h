
#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "ICollectible.h"
#include <string>
#include "DtProducto.h"

using namespace std;

class Producto:public ICollectible{
    private:
        string codigo;
        string descripcion;
    public:
        Producto(string,string);
        virtual ~Producto();
        string getCodigo();
        string getDescripcion();
        virtual float getPrecio()=0;
        
            
};

#endif /* PRODUCTO_H */

