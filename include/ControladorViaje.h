#ifndef CONTROLADORVIAJE_H
#define CONTROLADORVIAJE_H

#include <iostream>
#include <string>
#include <set>

#include "ManejadorVehiculos.h"
#include "ManejadorUsuarios.h"
#include "ManejadorViajes.h"

#include "ControladorFechaActual.h"
#include "Vehiculo.h"
#include "Usuario.h"
#include "Reserva.h"
#include "Viaje.h"

#include "IControladorFechaActual.h"


class ControladorViaje{
private:
    ManejadorVehiculos* mve;
    ManejadorUsuarios* mu;
    ManejadorViajes* mvi;
    std::string nickname;
    int codigo;
public:
    std::string getNickname();
    int getCodigo();
    void setNickname(std::string);
    void setCodigo(int);
    std::set<std::string> listarPasajeros();
    std::set<DTConsultaViaje> consultarViajes(DTFecha,std::string,std::string,int);
    bool generarReserva(std::string,int,int);
    std::set<DTUsuario> listarUsuarios();
    std::set<DTListarViaje> listarViajes(std::string);
    std::set<DTUsuarioViaje> listarUsuariosViaje(int);
    bool calificarUsuario(std::string,int);
    std::set<DTVehiculosConductor> listarVehiculos(std::string);
    bool altaViaje(std::string,DTFecha,std::string,std::string,int,float);
};

#endif