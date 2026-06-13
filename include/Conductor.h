#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include <set>
#include "Usuario.h"
#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include "DTVehiculosConductor.h"
#include "DTFecha.h"

class Vehiculo;

class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;
    std::set<Vehiculo*> vehiculos;
public:
    ~Conductor();
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    TipoUsuario getTipo();
    bool estaHabilitado(TipoVehiculo tipo);
    void asociarVehiculo(Vehiculo* v);
    int getCantCalificaciones();
    float getCalificacionPromedio();
    std::set<DTVehiculosConductor> listarVehiculos();
    bool hayViajesFechaConductor(DTFecha);
    void borrarVehiculo(Vehiculo*);
};

#endif
