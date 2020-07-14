/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ModificarFechaHora.h"
#include "Fabrica.h"
#include <string>
using namespace std;

void ModificarFechaHora() {
    system("cls");
    Fabrica* fabrica;
    int hora, minuto, dia, mes, anio;
    cout << "###Modificar fecha del sistema\n\n";
        cout << "Ingrese nro de dia: ";
        cin>>dia;
        cout << "Ingrese nro de mes: ";
        cin>>mes;
        cout << "Ingrese anio ";
        cin>>anio;
        cout << "Ingrese hora actual: ";
        cin>>hora;
        cout << "Ingrese minutos: ";
        cin>>minuto;

        FechaHora* fecha = new FechaHora(dia, mes, anio, hora, minuto);

        fabrica->getISistema()->ModificarFechaHora(fecha);
        fabrica->getISistema()->ModificarFechaHora(fecha);
        fabrica->getISistema()->ModificarFechaHora(fecha);

        cout << "--Fecha actualizada...\n";
        system("pause");
    }
