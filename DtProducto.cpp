#include "DtProducto.h"

 DtProducto::DtProducto(string codigo,string descripcion,float precio){
     this->codigo = codigo;
     this->descripcion = descripcion;
     this->precio = precio;
 }
 
 DtProducto::~DtProducto(){
 
 }
 
 string DtProducto::getCodigo(){
     return this->codigo;
 }

string DtProducto::getDescripcion(){
    return this->descripcion;
}

float DtProducto::getPrecio(){
    return this->precio;
}