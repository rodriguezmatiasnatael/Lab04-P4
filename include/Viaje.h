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
    static int ultimoCodigo;
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    Vehiculo* vehiculo;
    std::set<Reserva*> reservas;
public:
    Viaje(Vehiculo*,DTFecha, std::string, std::string, int, float);
    ~Viaje();

    int getCodigo();
    DTFecha getFecha();
    DTDetalleViaje getDTDetalleViaje();
    int lugaresDisponibles(int);
    bool cumpleRequisitos(DTFecha, std::string, std::string, int);
    DTConsultaViaje getDTConsultaViaje(int);
    Reserva* agregarReserva(int, DTFecha);
    bool esConductor(std::string);
    bool esPasajero(std::string);
    DTListarViaje getDTListarViaje();
    std::set<DTUsuarioViaje> getSetDTUsuarioViaje(std::string, TipoUsuario);
    bool existeCalificacion(std::string, std::string);
    Reserva* obtenerReserva(std::string, std::string, TipoUsuario);
};

#endif
