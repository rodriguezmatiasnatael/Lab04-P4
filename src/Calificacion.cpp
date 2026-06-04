#include "../include/Calificacion.h"
#include "../include/Usuario.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

Calificacion::~Calificacion() {}

int Calificacion::getPuntaje(){
    return this->puntaje;
}

bool Calificacion::calificacionEncontrada(std::string Calificador, std::string Calificado){
    bool coincideCalificador = this->realiza->getNickname() == Calificador;
    bool coincideCalificado = this->califica->getNickname() == Calificado;
    return (coincideCalificado && coincideCalificador);
}

void Calificacion::setRealiza(Usuario* ur){
    this->realiza = ur;
}

void Calificacion::setCalifica(Usuario* uc){
    this->califica = uc;
}