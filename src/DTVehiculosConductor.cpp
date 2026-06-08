#include "../include/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::string matricula, std::string marca, int capacidad){
    this->matricula = matricula;
    this->marca = marca;
    this->capacidad = capacidad;
}
std::string DTVehiculosConductor::getMatricula(){
    return this->matricula;
}
std::string DTVehiculosConductor::getMarca(){
    return this->marca;
}
int DTVehiculosConductor::getCapacidad(){
    return this->capacidad;
}