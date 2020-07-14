
#ifndef MOZO_H
#define MOZO_H
#include "Empleado.h"
#include "DtMozo.h"
#include "IDictionary.h"
#include "KeyString.h"
#include "KeyInt.h"
#include "ListaDicc.h"
#include "IIterator.h"
#include "Mesa.h"

class Mozo:public Empleado{
    private:
        IDictionary* mezas;
        public:
            DtMozo* toDTMozo();
            Mozo(int,string);
            ~Mozo();
            void setMesas(Mesa*,KeyInt*);
            IDictionary* getMesas();
            void addMesa(Mesa*,int);
           
};                      


#endif /* MOZO_H */

