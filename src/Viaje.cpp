#include "../include/Viaje.h"
#include "../include/Vehiculo.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
}

Viaje::~Viaje() {}


int Viaje::lugaresDisponibles(int cant) const {
    return 0;
}

bool Viaje::cumpleRequisitos(DTFecha f, std::string orig, std::string dest, int cantAsientos) const {
    return false;
}

DTConsultaViaje Viaje::getDTConsultaViaje(DTFecha f, std::string orig, std::string dest, int cantAsientos) const {
    return DTConsultaViaje();
}

bool Viaje::existeReservaUsuario(std::string nickname) const {
    return false;
}

Reserva Viaje::agregarReserva(int cantAsientos, DTFecha f) {
    return Reserva();
}

bool Viaje::esConductor(std::string nickname) const {
    return false;
}

bool Viaje::esPasajero(std::string nickname) const {
    return false;
}

DTListarViaje Viaje::getDTListarViaje() const {
    return DTListarViaje();
}

std::set<DTUsuarioViaje> Viaje::getSetDTUsuarioViaje(std::string nickname, TipoUsuario tipo) const {
    std::set<DTUsuarioViaje> conjuntoResultado;
    return conjuntoResultado;
}

bool Viaje::existeCalificacion(std::string nickCalificador, std::string nickCalificado) const {
    return false;
}

Reserva Viaje::obtenerReserva(std::string nickCalificador, std::string nickCalificado, TipoUsuario tipo) const {
    return Reserva();
