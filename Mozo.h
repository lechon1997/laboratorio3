
#ifndef MOZO_H
#define MOZO_H
#include "Empleado.h"
#include "DtMozo.h"
#include "IDictionary.h"

class Mozo:public Empleado{
    private:
        IDictionary* mezas;
        public:
            DtMozo* toDTMozo();
            Mozo(int,string);
            ~Mozo();
            void setMesas(IDictionary*);
            IDictionary* getMesas();
           
};                      


#endif /* MOZO_H */

