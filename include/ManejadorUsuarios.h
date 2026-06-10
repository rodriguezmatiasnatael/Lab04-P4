#ifndef MANEJADORUSUARIOS_H
#define MANEJADORUSUARIOS_H

#include <iostream>
#include <string>
#include <set>
#include "Conductor.h"
#include "Pasajero.h"
#include "TipoLibreta.h"

class ManejadorUsuarios {
private:
    static ManejadorUsuarios* instancia;
    ManejadorUsuarios();
    std::set<Usuario*> usuarios;
public:
    static ManejadorUsuarios* getInstance();
    bool existeUsuario(std::string);
    void crearPasajero(std::string, std::string, std::string, std::string, std::string);
    void crearConductor(std::string, std::string, std::string, std::string, std::set<TipoLibreta>);
    Usuario* getUsuario(std::string);
    std::set<Usuario*> getUsuarios();
};

#endif