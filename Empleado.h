
#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "ICollectible.h"
#include "String"
using namespace std;
class Empleado:public ICollectible{
    private:
        int numero;
        string nombre;
    public:
        Empleado(int,string);
        virtual ~Empleado();
        virtual string getNombre()=0;
        int getNumero();
};

#endif /* EMPLEADO_H */
