#ifndef ICONTROLADOR_VIAJE_H
#define ICONTROLADOR_VIAJE_H

#include <iostream>
#include <string>
#include <set>

#include "DTUsuarioViaje.h"
#include "DTVehiculosConductor.h"
#include "DTFecha.h"
#include "DTUsuario.h"
#include "DTConsultaViaje.h"
#include "DTListarViaje.h"

class IControladorViaje {
public:
    virtual std::set<std::string> listarPasajeros();
    virtual std::set<DTConsultaViaje> consultarViajes(DTFecha,std::string,std::string,int);
    virtual bool generarReserva(std::string,int,int);
    virtual std::set<DTUsuario> listarUsuarios();
    virtual std::set<DTListarViaje> listarViajes(std::string);
    virtual std::set<DTUsuarioViaje> listarUsuariosViaje(int);
    virtual bool calificarUsuario(std::string,int);
    virtual std::set<DTVehiculosConductor> listarVehiculos(std::string);
    virtual bool altaViaje(std::string,DTFecha,std::string,std::string,int,float);
};

#endif