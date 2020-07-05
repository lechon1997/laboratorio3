#include <cstddef>
#include "Sistema.h"
#ifndef FABRICA_H
#define FABRICA_H

class Fabrica{
private:
    Fabrica();
    static Fabrica* fabrica;
public:
    static Fabrica* getInstance();
    ISistema* getISistema();
   
    void cargarDatosDePrueba();

    
};

#endif /* FABRICA_H */

