#include "../include/Vehiculo.h"
#include "../include/Conductor.h"
#include "../include/Viaje.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
    this->conductor = nullptr; //olvidaste inicializar el puntero del conductor. Es vital que un puntero nazca nulo para evitar que apunte a basura en la memoria.
}


/*
RESPUESTA: En Programación Orientada a Objetos, el uso de delete implica que el objeto actual 
es el "dueño absoluto" de la memoria de esos punteros. Si borras un Vehículo y haces 
delete this->conductor;, ¡estás eliminando al usuario del sistema por completo! 
Lo mismo ocurre con los viajes. Un usuario sigue existiendo aunque su vehículo se destruya.
*/
//    if(this->conductor != nullptr){ //borramos conductor
//        delete this->conductor;
//    }
//    for (auto v : this->viajes) { //borramos set de viajes //hay que ver si cambiamos este iterador
//        if (v != nullptr) {
//            delete v;
//        }
//    }    
Vehiculo::~Vehiculo() {
    this->conductor = nullptr; // Solo rompemos el enlace
    this->viajes.clear();      // Solo vaciamos la colección, sin hacer delete a los viajes
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
/*
Respuesta: Está PERFECTO así. No debes usar punteros.
En C++, los Datatypes (clases que empiezan con DT, como DTUsuarioViaje 
o DTVehiculosConductor) son objetos inmutables de "solo lectura" que se 
usan para transportar información. La regla de oro en este tipo de diseños 
es que los Datatypes siempre se instancian y se retornan por valor, nunca por puntero. 
Si los retornaras con punteros (new DTUsuarioViaje(...)), estarías obligando a la 
interfaz gráfica a usar delete después de mostrarlos, lo cual genera un alto 
riesgo de fugas de memoria (memory leaks).
*/
}

DTVehiculosConductor Vehiculo::getDTVehiculoConductor(){
    DTVehiculosConductor dt = DTVehiculosConductor(this->matricula,this->marca,this->capacidad);
    return dt;
}

bool Vehiculo::hayViajeConductor(DTFecha fecha){
    return this->conductor->hayViajesFechaConductor(fecha);
}


//pongo las dos formas de iterar sobre un set
//RESPUESTA:es preferible dejar la primera opción(se está usando mas formato versión C++11)
bool Vehiculo::hayViajesFecha(DTFecha fecha){
    for(Viaje* v : this->viajes){
        if(v->getFecha() == fecha){
            return true;
        }
    }
    return false;
}
/*
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
*/
void Vehiculo::asociarViaje(Viaje& v){
    this->viajes.insert(&v);
}
