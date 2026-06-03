#include "../include/Conductor.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

Conductor::~Conductor() {
    for (auto veh : this->vehiculos) {
        if (veh != nullptr) {
            delete veh;
        }
    }    
    this->vehiculos.clear();
}

bool Conductor::estaHabilitado(TipoVehiculo tipo){

}
void Conductor::asociarVehiculo(Vehiculo*){}
int Conductor::getCantCalificaciones(){}
float Conductor::getCalificacionPromedio(){}
std::set<DTVehiculosConductor> Conductor::listarVehiculos(){}
bool Conductor::hayViajesFechaConductor(DTFecha){}
