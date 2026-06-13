#ifndef CONTROLADORVIAJE_H
#define CONTROLADORVIAJE_H

#include <iostream>
#include <string>
#include <set>

#include "ManejadorVehiculos.h"
#include "ManejadorUsuarios.h"
#include "ManejadorViajes.h"

#include "Vehiculo.h"
#include "Usuario.h"
#include "Reserva.h"
#include "Viaje.h"

#include "ControladorFechaActual.h"
#include "IControladorViaje.h"

class ControladorViaje: public IControladorViaje {
private:
    static ManejadorVehiculos* mve;
    static ManejadorUsuarios* mu;
    static ManejadorViajes* mvi;
    std::string nickname;
    int codigo;
    std::string getNickname();
    int getCodigo();
    void setNickname(std::string);
    void setCodigo(int);
public:
    ControladorViaje();
    std::set<std::string> listarPasajeros();
    std::set<DTConsultaViaje> consultarViajes(DTFecha,std::string,std::string,int);
    bool generarReserva(std::string,int,int);
    std::set<DTUsuario> listarUsuarios();
    std::set<DTListarViaje> listarViajes(std::string);
    std::set<DTUsuarioViaje> listarUsuariosViaje(int);
    bool calificarUsuario(std::string,int);
    std::set<DTVehiculosConductor> listarVehiculos(std::string);
    bool altaViaje(std::string,DTFecha,std::string,std::string,int,float);
    std::set<DTVehiculosConductor> listarVehiculosConductor(std::string);
    std::set<DTListarViaje> listarViajes();
    DTDetalleViaje detalleViaje(int);
    void eliminarViaje();
    void cancelarEliminarViaje();
};

#endif