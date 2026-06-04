#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include <string>
#include "Reserva.h"
#include "DTFecha.h"
#include "DTConsultaViaje.h"
#include "DTListarViaje.h"
#include "TipoUsuario.h"
#include "ControladorFechaActual.h"

class Vehiculo;

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    Vehiculo* vehiculo;
    std::set<Reserva*> resevas;
public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~Viaje();

    DTFecha getFecha();
    int lugaresDisponibles(int);
    bool cumpleRequisitos(DTFecha, std::string, std::string, int);
    DTConsultaViaje getDTConsultaViaje(DTFecha, std::string, std::string, int);
    bool existeReservaUsuario(std::string);
    Reserva* agregarReserva(int, DTFecha);
    bool esConductor(std::string);
    bool esPasajero(std::string);
    DTListarViaje getDTListarViaje();
    std::set<DTUsuarioViaje> getSetDTUsuarioViaje(std::string, TipoUsuario);
    bool existeCalificacion(std::string, std::string);
    Reserva* obtenerReserva(std::string, std::string, TipoUsuario);
};

#endif
