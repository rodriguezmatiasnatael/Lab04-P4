#include "../include/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::string matricula, std::string modelo, int capacidad){
    this->matricula = matricula;
    this->modelo = modelo;
    this->capacidad = capacidad;
}
std::string DTVehiculosConductor::getMatricula(){
    return this->matricula;
}
std::string DTVehiculosConductor::getModelo(){
    return this->modelo;
}
int DTVehiculosConductor::getCapacidad(){
    return this->capacidad;
}