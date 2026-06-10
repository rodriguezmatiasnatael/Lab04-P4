#include "../include/Vehiculo.h"
#include "../include/Conductor.h"
#include "../include/Viaje.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
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

DTUsuarioViaje Vehiculo::getDTUsuarioViaje(){ //esta bien asi o tendria que usar punteros?
    return DTUsuarioViaje(this->conductor->getNombre(),TipoUsuario::T_Conductor);
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
