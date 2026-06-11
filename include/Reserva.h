#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include <string>

#include "ControladorFechaActual.h"

#include "Pasajero.h"
#include "Calificacion.h"

#include "DTUsuarioViaje.h"
#include "DTFecha.h"
#include "DTDetalleReserva.h"

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Pasajero *pasajero;
    std::set <Calificacion*> calificaciones;
public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();
    int getAsientosReservados();
    void setPasajero(Pasajero* p);
    bool laRealizo(std::string);
    DTUsuarioViaje getDTUsuarioViaje();
    bool hayCalificacion(std::string calificador, std::string calificado);
    Calificacion* calificar(/*std::string nickname,*/ Usuario* puntua, Usuario* recibe, int puntaje);
    DTDetalleReserva getDTDetalleReserva();
};

#endif
