/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mesa.h
 * Author: EMILIANO
 *
 * Created on 8 de julio de 2020, 10:29 PM
 */

#ifndef MESA_H
#define MESA_H
#include "ICollectible.h"
#include "String"
#include "VentaLocal.h"

using namespace std;
class Mesa:public ICollectible{
    private:
        int numero;
        VentaLocal* ventaL = NULL;
    public:
        Mesa(int);
         int getNumero();
         VentaLocal* getVentaL();
         void setVentaL(VentaLocal*);
         
};

#endif