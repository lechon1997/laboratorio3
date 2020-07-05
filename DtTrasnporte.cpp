#include "DtTransporte.h"

DtTransporte::DtTransporte(){
    this->bici = "Bici";
    this->moto = "Moto";
    this->pie = "Pie";
}

DtTransporte::~DtTransporte(){

}

string DtTransporte::getBici(){
    return this->bici;
}

string DtTransporte::getPie(){
    return this->pie;
}

string DtTransporte::getmoto(){
    return this->moto;
}
