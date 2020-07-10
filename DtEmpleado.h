
#ifndef DtEMPLEADO_H
#define DtEMPLEADO_H
#include "ICollectible.h"
#include "String"
using namespace std;
class DtEmpleado:public ICollectible{
    private:
        int numero;
        string nombre;
    public:
        DtEmpleado(int,string);
        virtual ~DtEmpleado();
        string getNombre();
        int getNumero();
        void setNombre(string);
        void setNumero(int);
};

#endif /* EMPLEADO_H */

