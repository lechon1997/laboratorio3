/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Mesa.h"
#include "VentaLocal.h"

Mesa::Mesa(int numero){
    this->numero=numero;
    this->ventaL = NULL;
    this->venta = NULL;
    this->mozo = NULL;
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

Venta* Mesa::getVenta(){
    return this->venta;
}

void Mesa::setMozo(Mozo* mozo) {
    this->mozo = mozo;
}

Mozo* Mesa::getMozo() const {
    return mozo;
}
