
#ifndef DTMENU_H
#define DTMENU_H
#include <String>
#include "ICollection.h"
#include "IDictionary.h"
using namespace std;

class DtMenu:public ICollectible{
    private:
        string codigo;
        string descripcio;
        float precio;
        int cantidadVend;
        ICollection* infoProductos;
        IDictionary* dtinfosp;
    public:
        DtMenu(string,string,float,ICollection*);
        DtMenu(string,string,float,int,ICollection*,IDictionary*);
        ~DtMenu();
        string getCodigo();
        string getDescripcion();
        float getPrecio();
        int getCantidadVend();
        ICollection* getDatosProductos();
        IDictionary* getDtInfosP();
};


#endif /* DTMENU_H */

