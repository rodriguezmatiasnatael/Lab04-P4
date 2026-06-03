#ifndef VEHICULO_H
#define VEHICULO_H

#include <set>
#include <string>
#include "TipoVehiculo.h"
#include "DTVehiculosConductor.h"
#include "Viaje.h"
#include "DTUsuarioViaje.h"
#include "DTFecha.h"

class Conductor;

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    Conductor * conductor;
    std::set<Viaje*> viajes;
public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    ~Vehiculo();
    void setConductor(Conductor&);
    void asociarViaje(Viaje&);
    std::string nicknamePropietario();
    std::string nombreConductor();
    float calPromConductor();
    DTUsuarioViaje getDTUsuarioViaje();
    DTVehiculosConductor getDTVehiculoConductor();
    bool hayViajeConductor(DTFecha);
    bool hayViajesFecha(DTFecha);
};

#endif
