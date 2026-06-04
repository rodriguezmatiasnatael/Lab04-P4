#include "../include/ControladorUsuario.h"

ControladorUsuario::ControladorUsuario(){
    this->mu = ManejadorUsuarios::getInstance();
    this->mve = ManejadorVehiculos::getInstance();
}

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
