#ifndef CALIFICACION_H
#define CALIFICACION_H

#include <iostream>
#include <string>
#include "DTFecha.h"
#include "Usuario.h"

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    const Usuario *realiza;
    const Usuario *califica;
public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();
    int getPuntaje();
    bool calificacionEncontrada(std::string Calificador, std::string Calificado);
    void setRealiza(Usuario* ur);
    void setCalifica(Usuario* uc);
};

#endif
