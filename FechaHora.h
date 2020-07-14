
#ifndef FECHAHORA_H
#define FECHAHORA_H
#include <iostream>
using namespace std;
class FechaHora {
public:
    FechaHora(int, int, int, int, int);
    int getAnio();
    int getMes();
    int getDia();
    int getHora();
    int getMinutos();
    bool EsMayorFechaHora(FechaHora *);
    friend ostream& operator<<(ostream&, FechaHora&);
    virtual ~FechaHora();
private:
    int dia;
    int mes;
    int anio;

    int hora;
    int minutos;

};

#endif /* FECHAHORA_H */

