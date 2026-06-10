#include "../include/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
}
void Reserva::setPasajero(Pasajero* p){
    this->pasajero = p;
}

bool Reserva::laRealizo(std::string nickname){
    return this->pasajero->getNickname() == nickname;
}

DTUsuarioViaje Reserva::getDTUsuarioViaje() {
    return DTUsuarioViaje(this->pasajero->getNickname(), T_Pasajero);
}

bool Reserva::hayCalificacion(std::string nickCalificador,std::string nickCalificado) {
    for (auto cal : this->calificaciones){
        if (cal->calificacionEncontrada(nickCalificador, nickCalificado)){
            return true;
        }
    }
    return false;
}

Calificacion* Reserva::calificar(Usuario* puntua, Usuario* recibe, int puntaje){
    DTFecha fechaActual = ControladorFechaActual::getInstance()->getFecha();  
    Calificacion* cal = new Calificacion(fechaActual, puntaje);
    cal->setRealiza(puntua);
    cal->setCalifica(recibe);
    this->calificaciones.insert(cal);
    return cal;
}

Reserva::~Reserva() {
    for (auto cal : this->calificaciones){
        delete cal;
    }
    this->calificaciones.clear();
}
