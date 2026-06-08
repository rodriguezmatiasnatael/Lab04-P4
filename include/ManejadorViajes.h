#ifndef MANEJADORVIAJES_H
#define MANEJADORVIAJES_H

#include <iostream>
#include <string>
#include <set>
#include "Viaje.h"
#include "DTFecha.h"

class ManejadorViajes{
private:
    static ManejadorViajes* instancia;
    ManejadorViajes();
    std::set<Viaje*> viajes;
public:
    static ManejadorViajes* getInstance();
    std::set<Viaje*> getViajes();
    Viaje* getViaje(int);
    Viaje crearViaje(Vehiculo&,DTFecha,std::string,std::string,int,float);
};

#endif