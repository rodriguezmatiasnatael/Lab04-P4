#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include <iostream>
#include <string>
#include <set>
#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include "Conductor.h"
#include "Vehiculo.h"
#include "ManejadorUsuarios.h"
#include "ManejadorVehiculos.h"

class ControladorUsuario {
private:
    static ManejadorUsuarios* mu;
    static ManejadorVehiculos* mve;
public:
    bool altaPasajero(std::string, std::string, std::string, std::string, std::string);
    bool altaConductor(std::string, std::string, std::string, std::string, std::set<TipoLibreta>);
    int registrarVehiculo(std::string, std::string, int, std::string, std::string, TipoVehiculo);
};

#endif
