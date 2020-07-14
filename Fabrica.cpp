#include "Fabrica.h"


Fabrica* Fabrica::fabrica = NULL;


Fabrica::Fabrica() {
 
}
ISistema* Fabrica::getISistema() {
    return Sistema::getInstance();
}




Fabrica* Fabrica::getInstance() {
    if (fabrica == NULL)
        fabrica = new Fabrica();
    return fabrica;
}


void Fabrica::cargarDatosDePrueba(){
    
          
       
}
