#ifndef MANEJADORVEHICULOS_H
#define MANEJADORVEHICULOS_H

#include <iostream>
#include <string>
#include <set>
#include "Vehiculo.h"
#include "TipoVehiculo.h"

class ManejadorVehiculos{
private:
    static ManejadorVehiculos* instancia;
    ManejadorVehiculos();
    std::set<Vehiculo*> vehiculos;
public:
    ManejadorVehiculos* getInstance();
    bool existeVehiculo(std::string);
    Vehiculo* crearVehiculo(std::string,int,std::string,std::string,TipoVehiculo);
};

#endif