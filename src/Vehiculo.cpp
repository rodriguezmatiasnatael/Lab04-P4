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
Vehiculo::~Vehiculo() {
    if(this->conductor != nullptr){ //borramos conductor
        delete this->conductor;
    }
    for (auto v : this->viajes) { //borramos set de viajes //hay que ver si cambiamos este iterador
        if (v != nullptr) {
            delete v;
        }
    }    
    this->viajes.clear();
}

void Vehiculo::setConductor(Conductor& c){
    this->conductor = &c;
}


std::string Vehiculo::nicknamePropietario(){
    std::string nickname = this->conductor->getNickname();
    return nickname;
}

std::string Vehiculo::nombreConductor(){
    std::string nombre = this->conductor->getNombre();
    return nombre;
}
float Vehiculo::calPromConductor(){
    float calProm = this->conductor->getCalificacionPromedio();
    return calProm;
}

DTUsuarioViaje Vehiculo::getDTUsuarioViaje(){ //esta bien asi o tendria que usar punteros?
    DTUsuarioViaje dt = DTUsuarioViaje(this->conductor->getNombre(),TipoUsuario::T_Conductor);
    return dt;
}

DTVehiculosConductor Vehiculo::getDTVehiculoConductor(){
    DTVehiculosConductor dt = DTVehiculosConductor(this->matricula,this->marca,this->capacidad);
    return dt;
}

bool Vehiculo::hayViajeConductor(DTFecha fecha){
    return this->conductor->hayViajesFechaConductor(fecha);
}


//pongo las dos formas de iterar sobre un set
bool Vehiculo::hayViajesFecha(DTFecha fecha){
    for(Viaje* v : this->viajes){
        if(v->getFecha() == fecha){
            return true;
        }
    }
    return false;
}
bool Vehiculo::hayViajesFecha(DTFecha fecha){
    std::set<Viaje*>::iterator it;

    for (it = this->viajes.begin(); it != this->viajes.end(); ++it) {

        Viaje* v = *it;

        if (v->getFecha() == fecha) {
            return true;
        }
    }

    return false;
}

void Vehiculo::asociarViaje(Viaje& v){
    this->viajes.insert(&v);
}
