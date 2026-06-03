#include "../include/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
}
void Reserva::setPasajero(Pasajero* p){
    this->pasajero = p;
}

bool Reserva::laRealizo(std::string nickname){
    bool laCreo = this->pasajero->getNickname() == nickname;
    return laCreo;
}

DTUsuarioViaje Reserva::getDTUsuarioViaje() {
    std::string nick = this->pasajero->getNickname();
    return DTUsuarioViaje(nick, T_Pasajero);
}

bool Reserva::hayCalificacion(std::string calificador,std::string calificado) {
    for (auto cal : this->calificaciones){
        if (cal->calificacionEncontrada(calificador, calificado)){
            return true;
        }
    }
    return false;
}

Calificacion* Reserva::calificar(/*std::string nickname,*/ Usuario* puntua, Usuario* recibe, int puntaje){
    DTFecha fechaActual = ControladorFechaActual::getInstance()->getFecha();  
    Calificacion * cal = new Calificacion(fechaActual, puntaje);
    this->calificaciones.insert(cal);
    cal->setRealiza(puntua);
    cal->setCalifica(recibe);
    return cal;
}


Reserva::~Reserva() {
    for (auto cal : this->calificaciones){
        if (cal != nullptr){
            delete cal;
        }
    }
    this->calificaciones.clear();
}
