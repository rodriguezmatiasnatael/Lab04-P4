#ifndef VEHICULO_H
#define VEHICULO_H

#include <set>
#include <string>
#include "TipoVehiculo.h"
#include "DTVehiculosConductor.h"
#include "DTUsuarioViaje.h"
#include "DTFecha.h"

class Conductor;
class Viaje;

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
    std::string getMatricula();
    std::string getMarca();
    std::string getModelo();
    int getCapacidad();    
    void setConductor(Conductor*);
    std::string nicknamePropietario();
    std::string nombreConductor();
    float calPromConductor();
    DTUsuarioViaje getDTUsuarioViaje();
    DTVehiculosConductor getDTVehiculoConductor();
    bool hayViajeConductor(DTFecha);
    bool hayViajesFecha(DTFecha);
    void asociarViaje(Viaje*);
};

#endif
