#include "../include/DTConsultaViaje.h"

DTConsultaViaje::DTConsultaViaje(int codigo, std::string marca, std::string modelo, std::string conductor, float calificacionProm, float precioTotal) {
    this->codigo = codigo;
    this->marca = marca;
    this->modelo = modelo;
    this->conductor = conductor;
    this->calificacionProm = calificacionProm;
    this->precioTotal = precioTotal;
}

int DTConsultaViaje::getCodigo() { return codigo; }
std::string DTConsultaViaje::getMarca() { return marca; }
std::string DTConsultaViaje::getModelo() { return modelo; }
std::string DTConsultaViaje::getConductor() { return conductor; }
float DTConsultaViaje::getCalificacionProm() { return calificacionProm; }
float DTConsultaViaje::getPrecioTotal() { return precioTotal; }

bool DTConsultaViaje::operator<(const DTConsultaViaje& otro) const {
    if (this->precioTotal != otro.precioTotal) {
        return this->precioTotal < otro.precioTotal;
    } else if (this->calificacionProm != otro.calificacionProm) {
        return this->calificacionProm > otro.calificacionProm;
    } else {
        return this->codigo < otro.codigo;
    }
}