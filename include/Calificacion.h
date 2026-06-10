#ifndef CALIFICACION_H
#define CALIFICACION_H

#include <iostream>
#include <string>
#include "DTFecha.h"

class Usuario;

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Usuario *realiza;
    Usuario *califica;
public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();
    int getPuntaje();
    bool calificacionEncontrada(std::string Calificador, std::string Calificado);
    void setRealiza(Usuario* ur);
    void setCalifica(Usuario* uc);
};

#endif
