
#ifndef MENU_H
#define MENU_H
#include "Producto.h"
#include "Comun.h"
#include "DtMenu.h"
#include "KeyString.h"
#include "IDictionary.h"

class Menu:public Producto{
    private:
        IDictionary* productosComun;
        IDictionary* DtinfosP;
    public:
        Menu(string,string);
       ~Menu();
       float getPrecio();
       void quitarProductos();
       void quitarProducto(Comun*);
       void ingresarProducto(Comun*,KeyString*);
       void ingresarDtInfoP(DtInfoP*);
       bool menuVacio();
       DtMenu* getDtMenu();
};

#endif /* MENU_H */

