
#include "FechaHora.h"
#include <iostream>
using namespace std;
FechaHora::FechaHora(int dia, int mes, int anio, int hora, int minuto) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minutos = minuto;
}

FechaHora::~FechaHora() {
}

int FechaHora::getAnio() {
    return this->anio;
}

int FechaHora::getMes() {
    return this->mes;
}

int FechaHora::getDia() {
    return this->dia;
}

int FechaHora::getHora() {
    return this->hora;
}

int FechaHora::getMinutos() {
    return this->minutos;
}

bool FechaHora::EsMayorFechaHora(FechaHora* fh) {
    if (anio >= fh->getAnio())
        if (mes >= fh->getMes())
            if (dia >= fh->getDia())
                if (hora >= fh->getHora())
                    if (minutos >= fh->getMinutos())
                            return true;
    return false;
}

ostream& operator<<(ostream& os, FechaHora& fechaHora) {
    os << "Fecha: " << fechaHora.dia << "/" << fechaHora.mes << "/" << fechaHora.anio<<"\n";
    os << "Hora: " << fechaHora.hora << "/" << fechaHora.minutos<<endl;
    return os;
}

