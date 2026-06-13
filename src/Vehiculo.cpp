#include "../include/Vehiculo.h"
#include "../include/Conductor.h"
#include "../include/Viaje.h"

#include "../include/DTDetalleVehiculo.h"
Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
}

Vehiculo::~Vehiculo() {
    this->conductor->borrarVehiculo(this);
    for (auto vi : this->viajes) delete vi;
    this->viajes.clear();
}

std::string Vehiculo::getMatricula(){
    return this->matricula;
}
std::string Vehiculo::getMarca(){
    return this->marca;
}
std::string Vehiculo::getModelo(){
    return this->modelo;
}
int Vehiculo::getCapacidad(){
    return this->capacidad;
}

void Vehiculo::setConductor(Conductor* c){
    this->conductor = c; // por qué & y no *?
}

std::string Vehiculo::nicknamePropietario(){
    return this->conductor->getNickname();
}

std::string Vehiculo::nombreConductor(){
    return this->conductor->getNombre();
}

float Vehiculo::calPromConductor(){
    return this->conductor->getCalificacionPromedio();
}

DTUsuarioViaje Vehiculo::getDTUsuarioViaje(){ 
    return DTUsuarioViaje(this->conductor->getNickname(),TipoUsuario::T_Conductor);
}

DTVehiculosConductor Vehiculo::getDTVehiculoConductor(){
    return DTVehiculosConductor(this->matricula,this->marca,this->capacidad);
}

bool Vehiculo::hayViajeConductor(DTFecha fecha){
    return this->conductor->hayViajesFechaConductor(fecha);
}

bool Vehiculo::hayViajesFecha(DTFecha fecha){
    for(auto v : this->viajes){
        if(v->getFecha() == fecha){
            return true;
        }
    }
    return false;
}

void Vehiculo::asociarViaje(Viaje* v){
    this->viajes.insert(v); // Lo mismo que en setConductor
}

void Vehiculo::borrarViaje(Viaje* vi) {
    this->viajes.erase(vi);
}

DTDetalleVehiculo Vehiculo::getDTDetalleVehiculo(){
    DTDetalleVehiculo dtv = DTDetalleVehiculo(this->matricula, this->capacidad,this->marca, this->modelo, this->tipo);
    return dtv;
}