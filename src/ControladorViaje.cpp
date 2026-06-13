#include "../include/ControladorViaje.h"

ManejadorUsuarios* ControladorViaje::mu = nullptr;
ManejadorVehiculos* ControladorViaje::mve = nullptr;
ManejadorViajes* ControladorViaje::mvi = nullptr;

ControladorViaje::ControladorViaje(){
    this->mu = ManejadorUsuarios::getInstance();
    this->mve = ManejadorVehiculos::getInstance();
    this->mvi = ManejadorViajes::getInstance();
}

std::string ControladorViaje::getNickname() {
    return this->nickname;
}

int ControladorViaje::getCodigo() {
    return this->codigoE;
}

void ControladorViaje::setNickname(std::string nickname){
    this->nickname = nickname;
}

void ControladorViaje::setCodigo(int codigo) {
    this->codigoE = codigo;
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
    return (!hayReserva && lugDisp >= 0);
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
    this->setCodigo(codigo);
    Viaje* viaje = mvi->getViaje(codigo);
    Usuario* us = mu->getUsuario(nickname);
    TipoUsuario tipo = us->getTipo();
    return viaje->getSetDTUsuarioViaje(nickname, tipo);
}

bool ControladorViaje:: calificarUsuario(std::string nicknameCalificado ,int calificacion){
    Viaje* viaje = mvi->getViaje(codigoE);
    bool eCalificacion = viaje->existeCalificacion(nickname, nicknameCalificado);
    if (!eCalificacion){
        Usuario* puntua = mu->getUsuario(nickname);
        Usuario* recibe = mu->getUsuario(nicknameCalificado);
        TipoUsuario tPuntua = puntua->getTipo(); 
        Reserva* res = viaje->obtenerReserva(nickname, nicknameCalificado, tPuntua);
        Calificacion* cal = res->calificar(puntua, recibe, calificacion);
        recibe->asociarCalificacion(cal);
    }
    this->setNickname("");
    this->setCodigo(-1);
    return !eCalificacion;
}

std::set<DTVehiculosConductor> ControladorViaje::listarVehiculosConductor(std::string nickname){
    Usuario* usuario = mu->getUsuario(nickname);
    Conductor* cond = dynamic_cast<Conductor*>(usuario);
    return cond->listarVehiculos();
}

bool ControladorViaje:: altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio){
    Vehiculo* ve = this->mve->getVehiculo(matricula);
    int capacidad = ve->getCapacidad();
    if (capacidad >= asientos){
        bool hayVFecha = ve->hayViajeConductor(fecha);
        if (!hayVFecha){
            Viaje* viaje = this->mvi->crearViaje(ve, fecha, origen, destino, asientos, precio);
            ve->asociarViaje(viaje);
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
    setCodigo(codigo);
    return v->getDTDetalleViaje();
}

void ControladorViaje::eliminarViaje(){
    //int codigo = this->getCodigo();
    Viaje* vi = this->mvi->getViaje(codigoE);
    this->mvi->borrarViaje(vi);
    delete vi;
    this->setCodigo(-1);
}

void ControladorViaje::cancelarEliminarViaje() {
    this->setCodigo(-1);
}