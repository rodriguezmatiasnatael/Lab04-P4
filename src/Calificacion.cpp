#include "../include/Calificacion.h"
#include "../include/Usuario.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

Calificacion::~Calificacion() {
    this->califica->eliminarCalificacion(this);
}

int Calificacion::getPuntaje(){
    return this->puntaje;
}

bool Calificacion::calificacionEncontrada(std::string nickCalificador, std::string nickCalificado){
    bool coincideCalificador = this->realiza->getNickname() == nickCalificador;
    bool coincideCalificado = this->califica->getNickname() == nickCalificado;
    return (coincideCalificado && coincideCalificador);
}

void Calificacion::setRealiza(Usuario* ur){
    this->realiza = ur;
}

void Calificacion::setCalifica(Usuario* uc){
    this->califica = uc;
}