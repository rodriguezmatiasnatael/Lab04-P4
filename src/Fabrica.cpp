#include "../include/Fabrica.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorUsuario.h"
#include "../include/ControladorViaje.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IControladorFechaActual* Fabrica::getIControladorFechaActual() {
    return ControladorFechaActual::getInstance();
}

IControladorUsuario* Fabrica::getIControladorUsuario(){
    if (this->interfazUsuario == NULL) {
        this->interfazUsuario = new ControladorUsuario();
    }
    return this->interfazUsuario;
}

IControladorViaje* Fabrica::getIControladorViaje(){
    if (this->interfazViaje == NULL) {
        this->interfazViaje = new ControladorViaje();
    }
    return this->interfazViaje;
}