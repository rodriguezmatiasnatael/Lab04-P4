#include "../include/ControladorViaje.h"

ControladorViaje::ControladorViaje(){
    this->mu = ManejadorUsuarios::getInstance();
    this->mve = ManejadorVehiculos::getInstance();
    this->mvi = ManejadorViajes::getInstance();
}

void ControladorViaje::setNickname(std::string nickname){
    this->nickname = nickname;
}

void ControladorViaje::setCodigo(int codigo) {
    this->codigo = codigo;
}

std::set<std::string> ControladorViaje::listarPasajeros(){
    std::set<Usuario*> usuarios = mu->getUsuarios();
    std::set<std::string> res;
    for (auto us : usuarios){
        if (us->getTipo() == T_Pasajero) {
            res.insert(us->getNickname());
        }
    }
    return res;
}

std::set<DTConsultaViaje> ControladorViaje::consultarViajes(DTFecha fecha,std::string origen,std::string destino,int asientos){
    std::set<Viaje*> viajes = mvi->getViajes();
    std::set<DTConsultaViaje> res;
    for (auto v : viajes){
        int lugDisp = v->lugaresDisponibles(asientos);
        bool cumple = v->cumpleRequisitos(fecha, origen, destino, lugDisp);
        if (cumple) {
            DTConsultaViaje nodo = v->getDTConsultaViaje(asientos);
            res.insert(nodo);
        }
    }
    return res;
}

//SOBRECARGAR EL OPERADOR < para que inserte los DTConsultaViaje ordenados.
// El listado se presenta ordenado de menor a
// mayor precio total, y en caso de empate se debe mostrar primero el de mayor
// calificación promedio.


bool ControladorViaje:: generarReserva(std::string nickname,int codigo,int asientos){
    DTFecha fechaActual = ControladorFechaActual::getInstance()->getFecha();
    Viaje *viaje = mvi->getViaje(codigo);
    bool hayReserva = viaje->esPasajero(nickname);
    int lugDisp = viaje->lugaresDisponibles(asientos);
    if (!hayReserva && lugDisp >= 0){
        Reserva* reserva = viaje->agregarReserva(asientos, fechaActual);
        Pasajero* p = dynamic_cast<Pasajero*>(mu->getUsuario(nickname));
        reserva->setPasajero(p);
    }
}

std::set<DTUsuario> ControladorViaje::listarUsuarios(){
    std::set<DTUsuario> res;
    std::set<Usuario*> usuarios = mu->getUsuarios();
    for (auto u : usuarios){
        DTUsuario nodo = DTUsuario(u->getNickname(), u->getNombre());
        res.insert(nodo);
    }
    return res;
}


std::set<DTListarViaje> ControladorViaje:: listarViajes(std::string nickname){
    this->setNickname(nickname);
    std::set<DTListarViaje> res;
    std::set<Viaje*> viajes = mvi->getViajes();
    for (auto v : viajes) {
        bool ec = v->esConductor(nickname);
        bool ep = v->esPasajero(nickname);
        if (ec || ep){
            DTListarViaje nodo = v->getDTListarViaje();
            res.insert(nodo);
        }
    }
    return res;
}


std::set<DTUsuarioViaje> ControladorViaje:: listarUsuariosViaje(int codigo){
    TipoUsuario tipo;
    this->setCodigo(codigo);
    Viaje* viaje = mvi->getViaje(codigo);
    Usuario* us = mu->getUsuario(nickname);
    Conductor* cond = dynamic_cast<Conductor*>(us);
    if (cond = nullptr){
        tipo = T_Pasajero;
    } else {
        tipo = T_Conductor;
    }
    return viaje->getSetDTUsuarioViaje(nickname, tipo);
}

bool ControladorViaje:: calificarUsuario(std::string nicknameCalificado ,int calificacion){
    Viaje* viaje = mvi->getViaje(codigo);
    bool eCalificacion = viaje->existeCalificacion(nickname, nicknameCalificado);
    if (!eCalificacion){
        Usuario* puntua = mu->getUsuario(nickname);
        Usuario* recibe = mu->getUsuario(nicknameCalificado);
        TipoUsuario tPuntua;
        Pasajero* pas = dynamic_cast<Pasajero*>(puntua);
        if (pas = nullptr){
            tPuntua = T_Conductor;
        } else {
            tPuntua = T_Pasajero;
        }
        Reserva* res = viaje->obtenerReserva(nickname, nicknameCalificado, tPuntua);
        Calificacion* cal = res->calificar(puntua, recibe, calificacion);
        recibe->asociarCalificacion(cal);
    }
    nickname = "";
    codigo = -1;
}




std::set<DTVehiculosConductor> ControladorViaje::listarVehiculosConductor(std::string nickname){
    Usuario* usuario = mu->getUsuario(nickname);
    Conductor* cond = dynamic_cast<Conductor*>(usuario);
    return cond->listarVehiculos();
}


bool ControladorViaje:: altaViaje(std::string matricula,DTFecha fecha,std::string origen,std::string destino,int asientos,float precio){
    Vehiculo* veh = this->mve->getVehiculo(matricula);
    int capacidad = veh->getCapacidad();
    if (capacidad >= asientos){
        bool hayVFecha = veh->hayViajeConductor(fecha);
        if (!hayVFecha){
            Viaje* viaje = mvi->crearViaje(veh, fecha, origen, destino, asientos, precio);
            veh->asociarViaje(viaje);
            return true;
        }
    }
    return false;
}

std::set<DTListarViaje> ControladorViaje::listarViajes(){
    std::set<DTListarViaje> s;
    std::set<Viaje*> viajes = mvi->getViajes();
    for (auto v : viajes) {
        s.insert(v->getDTListarViaje());
    }
    return s;
}

DTDetalleViaje ControladorViaje::detalleViaje(int codigo){
    Viaje* v = mvi->getViaje(codigo);
    return v->getDTDetalleViaje();
    setCodigo(codigo);
}

void ControladorViaje::eliminarViaje() {
    int codigo = this->getCodigo();
    Viaje* vi = this->mvi->getViaje(codigo);
    delete vi;
}