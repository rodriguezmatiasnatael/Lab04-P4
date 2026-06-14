#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"
#include "IControladorUsuario.h"
#include "IControladorViaje.h"

class Fabrica {
private:
    static Fabrica* instancia;
    IControladorUsuario* interfazUsuario;
    IControladorViaje* interfazViaje;
    IControladorFechaActual* interfazFecha;
    Fabrica();
public:
    static Fabrica* getInstance();

    IControladorFechaActual* getIControladorFechaActual();
    IControladorUsuario* getIControladorUsuario();
    IControladorViaje* getIControladorViaje();
};

#endif
