
#ifndef MOZO_H
#define MOZO_H
#include "Empleado.h"
#include "IDictionary.h"

class Mozo:public Empleado{
    private:
        IDictionary* mezas;
        public:
            Mozo(int,string);
            ~Mozo();
            string getNombre();
};                      


#endif /* MOZO_H */

