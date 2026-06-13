#include "../include/ControladorUsuario.h"

ManejadorUsuarios* ControladorUsuario::mu = nullptr;
ManejadorVehiculos* ControladorUsuario::mve = nullptr;
ManejadorViajes* ControladorUsuario::mvi = nullptr;

ControladorUsuario::ControladorUsuario(){
    this->mu = ManejadorUsuarios::getInstance();
    this->mve = ManejadorVehiculos::getInstance();
    this->mvi = ManejadorViajes::getInstance();
}

bool ControladorUsuario::altaPasajero(std::string nickname,std::string nombre,std::string password, std::string email,std::string ci){
    bool estaUsuario = this->mu->existeUsuario(nickname);
    if(!estaUsuario){
        mu->crearPasajero(nickname,nombre,password,email,ci);
    }
    return !estaUsuario;
}

bool ControladorUsuario::altaConductor(std::string nickname,std::string nombre,std::string password, std::string email,std::set<TipoLibreta> libretas){
    bool estaUsuario = this->mu->existeUsuario(nickname);
    if(!estaUsuario){
        mu->crearConductor(nickname,nombre,password,email,libretas);
    }
    return !estaUsuario;
}

int ControladorUsuario::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo){
    bool estaV = this->mve->existeVehiculo(matricula);
    if(!estaV){
        Usuario* u = this->mu->getUsuario(nickname);
        Conductor* cond = dynamic_cast<Conductor*>(u);
        bool estaHab = cond->estaHabilitado(tipo);
        if(estaHab){
            Vehiculo* v = mve->crearVehiculo(matricula, capacidad, marca, modelo, tipo);
            v->setConductor(cond);
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

void ControladorUsuario::eliminarUsuario(std::string nickname) {
    Usuario* u = this->mu->getUsuario(nickname);
    if (u->getTipo() == TipoUsuario::T_Pasajero) {
        for (auto vi : this->mvi->getViajes()) {
            if (vi->esPasajero(nickname)) {
                std::set<Reserva*> reservasP = vi->getReservas(nickname);
                for (auto r : reservasP) delete r;
            }
        }
    }
    delete u;
}