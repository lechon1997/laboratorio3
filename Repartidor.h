

#ifndef REPARTIDOR_H
#define REPARTIDOR_H
#include "Empleado.h"
#include "tipoTransporte.h"
class Repartidor:public Empleado{
    private:
        Transportes miAltaNave;
    public:
        Repartidor(int,string,Transportes);
        ~Repartidor();

            
};


#endif /* REPARTIDOR_H */

