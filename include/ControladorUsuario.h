#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "Conductor.h"
#include "Vehiculo.h"
#include "ManejadorUsuarios.h"
#include "ManejadorVehiculos.h"

#include "./IControladorUsuario.h"

class ControladorUsuario: public IControladorUsuario {
private:
    static ManejadorUsuarios* mu;
    static ManejadorVehiculos* mve;
public:
    bool altaPasajero(std::string, std::string, std::string, std::string, std::string);
    bool altaConductor(std::string, std::string, std::string, std::string, std::set<TipoLibreta>);
    int registrarVehiculo(std::string, std::string, int, std::string, std::string, TipoVehiculo);
};

#endif
