#include "../include/ManejadorViajes.h"
#include "../include/Viaje.h"
#include "../include/DTConsultaViaje.h"//

#include <algorithm>
ManejadorViajes * ManejadorViajes::instancia = NULL;

ManejadorViajes::ManejadorViajes(){}

ManejadorViajes *ManejadorViajes::getInstance(){
    if (instancia == nullptr){
        instancia = new ManejadorViajes();
    }
    return instancia;
}

std::set<Viaje*> ManejadorViajes::getViajes(){
    return this->viajes;
}

Viaje *ManejadorViajes::getViaje(int codigo){
    for (auto v : this->viajes){
        if(v->getCodigo() == codigo){
            return v;
        }
    }
}

Viaje* ManejadorViajes::crearViaje(Vehiculo* vehiculo,DTFecha fecha, std::string origen,std::string destino, int asientosPublicados ,float precio){

    Viaje* v = new Viaje(vehiculo,fecha,origen,destino,asientosPublicados,precio);
}

void ManejadorViajes::borrarViaje(Viaje* vi) {
    this->viajes.erase(vi);
}