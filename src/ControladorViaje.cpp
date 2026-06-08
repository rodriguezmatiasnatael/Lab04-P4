#include "../include/ControladorViaje.h"

ControladorViaje::ControladorViaje(){
    this->mu = ManejadorUsuarios::getInstance();
    this->mve = ManejadorVehiculos::getInstance();
    this->mvi = ManejadorViajes::getInstance();
}

std::set<std::string> ControladorViaje::listarPasajeros(){
    std::set<Usuario*> usuarios = mu->getUsuarios();
    std::set<std::string> res;
    for (auto us : usuarios){
        Pasajero* pas = dynamic_cast<Pasajero*>(us);
        if (pas != nullptr){
            res.insert(pas->getNickname());
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
            DTConsultaViaje nodo = v->getDTConsultaViaje(fecha, origen, destino, asientos);
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
    bool hayReserva = viaje->existeReservaUsuario(nickname);
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

/*
std::set<DTListarViaje> ControladorViaje:: listarViajes(std::string nickname){
    std::set<Viaje*> viajes = mvi->getViajes();
    Pasajero* pas = dynamic_cast<Pasajero*>()
    for (auto v : viajes) {

    }
}


std::set<DTUsuarioViaje> listarUsuariosViaje(int);
bool calificarUsuario(std::string,int);
std::set<DTVehiculosConductor> listarVehiculos(std::string);
bool altaViaje(std::string,DTFecha,std::string,std::string,int,float);




bool ControladorUsuario::altaPasajero(std::string nickname,std::string nombre,std::string email,std::string password,std::string ci){
    this->mu = ManejadorUsuarios::getInstance();
    bool estaUsuario = mu->existeUsuario(nickname);
    if(!estaUsuario){
        mu->crearPasajero(nickname,nombre,email,password,ci);
    }
    return !estaUsuario;
}

bool ControladorUsuario::altaConductor(std::string nickname,std::string nombre,std::string email,std::string password,std::set<TipoLibreta> libretas){
    this->mu = ManejadorUsuarios::getInstance();
    bool estaUsuario = mu->existeUsuario(nickname);
    if(!estaUsuario){
        mu->crearConductor(nickname,nombre,email,password,libretas);
    }
    return !estaUsuario;
}

int ControladorUsuario::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo){
    this->mu = ManejadorUsuarios::getInstance();
    this->mve = ManejadorVehiculos::getInstance();
    bool estaV = mve->existeVehiculo(matricula);
    if(!estaV){
        Usuario* c = mu->getUsuario(nickname);
        Conductor* cond = (Conductor*)c;
        bool estaHab = cond->estaHabilitado(tipo);
        if(estaHab){
            Vehiculo* v = mve->crearVehiculo(matricula,capacidad,marca,modelo,tipo);
            v->setConductor(*cond);
            cond->asociarVehiculo(v);
            return 0;
        }
        else{
            return -2;
        }
    }
    else{
        return -1;
    }
}
*/