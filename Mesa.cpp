/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Mesa.h"
#include "VentaLocal.h"

Mesa::Mesa(int numero){
    this->numero=numero;
}

int Mesa::getNumero(){
    return this->numero;
}

VentaLocal* Mesa::getVentaL(){
    return this->ventaL;
}
void Mesa::setVentaL(VentaLocal* vl){
    this->ventaL = vl;
}