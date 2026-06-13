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
#include "DTDetalleViaje.h"
class IControladorViaje{
public:
    virtual ~IControladorViaje() {};
    virtual std::set<std::string> listarPasajeros() = 0;
    virtual std::set<DTConsultaViaje> consultarViajes(DTFecha,std::string,std::string,int) = 0;
    virtual bool generarReserva(std::string,int,int) = 0;
    virtual std::set<DTUsuario> listarUsuarios() = 0;
    virtual std::set<DTListarViaje> listarViajes(std::string) = 0;
    virtual std::set<DTUsuarioViaje> listarUsuariosViaje(int) = 0;
    virtual bool calificarUsuario(std::string,int) = 0;
    virtual std::set<DTVehiculosConductor> listarVehiculosConductor(std::string) = 0;
    virtual bool altaViaje(std::string,DTFecha,std::string,std::string,int,float) = 0;
    virtual std::set<DTListarViaje> listarViajes() = 0;
    virtual DTDetalleViaje detalleViaje(int) = 0;
    virtual void eliminarViaje() = 0;
    virtual void cancelarEliminarViaje() = 0;
};

#endif