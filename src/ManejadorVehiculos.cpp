#include "../include/ManejadorVehiculos.h"
#include "../include/Vehiculo.h"
#include <algorithm>
ManejadorVehiculos * ManejadorVehiculos::instancia = NULL;

ManejadorVehiculos::ManejadorVehiculos(){

}
ManejadorVehiculos * ManejadorVehiculos::getInstance(){
    if (instancia == NULL){
        instancia = new ManejadorVehiculos();
    }
    return instancia;
}


bool ManejadorVehiculos::existeVehiculo(std::string matricula){
    for (auto v : this->vehiculos){
        if (v != nullptr){
            if(v->getMatricula() == matricula){
                return true;
            }
        }
    }
}


Vehiculo* ManejadorVehiculos::crearVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo){
    Vehiculo* v = new Vehiculo(matricula,capacidad,marca,modelo,tipo);
    this->vehiculos.insert(v);
    return v;
}

Vehiculo* ManejadorVehiculos::getVehiculo(std::string matricula){
    for (auto v : this->vehiculos){
        if (v != nullptr){
            if(v->getMatricula() == matricula){
                return v;
            }
        }
    }
    return nullptr;
}