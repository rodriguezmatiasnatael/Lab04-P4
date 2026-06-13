#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include <string>

class Pasajero : public Usuario {
private:
    std::string ci;
public:
    Pasajero(std::string, std::string, std::string, std::string, std::string);
    ~Pasajero();
    TipoUsuario getTipo();
    
};

#endif
