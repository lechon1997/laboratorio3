
#ifndef DTINFOP_H
#define DTINFOP_H
#include  "ICollectible.h"
#include <String>
using namespace std;
class DtInfoP:public ICollectible{
    private:
        string codigo;
        int cantidad;
    public:
        DtInfoP(string,int);
        ~DtInfoP();
        string getCodigo();
        int getCantidad();
};


#endif /* DTINFOP_H */

