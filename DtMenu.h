
#ifndef DTMENU_H
#define DTMENU_H
#include <String>
#include "ICollection.h"
using namespace std;

class DtMenu:public ICollectible{
    private:
        string codigo;
        string descripcio;
        float precio;
        ICollection* infoProductos;
    public:
        DtMenu(string,string,float,ICollection*);
        ~DtMenu();
        string getCodigo();
        string getDescripcion();
        float getPrecio();
        ICollection* getDatosProductos();
        
};


#endif /* DTMENU_H */

