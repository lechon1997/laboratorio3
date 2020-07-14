
#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "ICollectible.h"
#include "String"
using namespace std;
class Empleado:public ICollectible{
    private:
        int numero;
        string nombre;
        bool tipo;
    public:
        Empleado(int,string);
        virtual ~Empleado();
         string getNombre();
         int getNumero();
         bool getTipo();
         void setTipo(bool);

};

#endif /* EMPLEADO_H */

