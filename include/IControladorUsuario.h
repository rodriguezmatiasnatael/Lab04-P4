#ifndef ICONTROLADOR_USUARIO_H
#define ICONTROLADOR_USUARIO_H

#include <iostream>
#include <string>
#include <set>
#include "TipoLibreta.h"
#include "TipoVehiculo.h"

class IControladorUsuario {
public:
     virtual ~IControladorUsuario() {};
     virtual bool altaPasajero(std::string, std::string, std::string, std::string, std::string) = 0;
     virtual bool altaConductor(std::string, std::string, std::string, std::string, std::set<TipoLibreta>) = 0;
     virtual int registrarVehiculo(std::string, std::string, int, std::string, std::string, TipoVehiculo) = 0;
};

#endif