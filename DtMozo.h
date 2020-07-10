
#ifndef DtMOZO_H
#define DtMOZO_H
#include "DtEmpleado.h"
#include "IDictionary.h"

class DtMozo:public DtEmpleado{
    private:
        IDictionary* mezas;
        public:
            DtMozo(int,string);
            ~DtMozo();
            void setMesas(IDictionary*);
            IDictionary* getMesas();
};                      


#endif /* MOZO_H */


