#include "../include/Viaje.h"
#include "../include/Vehiculo.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->vehiculo = nullptr;
}

Viaje::~Viaje() {
    for (auto r : this->reservas) { 
        if (r != nullptr) {
            delete r;
        }
    }    
    this->reservas.clear();
}

DTFecha Viaje::getFecha() {
    return this->fecha;
}

int Viaje::lugaresDisponibles(int asientos){
    int asientosReservados = 0;
    for (auto r : this->reservas){
        if (r != nullptr){
            asientosReservados += r->getAsientosReservados(); 
        }
    }
    return this->asientosPublicados - (asientosReservados + asientos);
}

bool Viaje::cumpleRequisitos(DTFecha f, std::string orig, std::string dest, int asientos){  
    bool coincideRuta = (this->fecha == f) && (this->origen == orig) && (this->destino == dest);
    bool hayLugar = (this->lugaresDisponibles(asientos) >= 0);
    
    if (coincideRuta && hayLugar) {
        return true;
    }
    return false;
}

DTConsultaViaje Viaje::getDTConsultaViaje(DTFecha f, std::string orig, std::string dest, int cant) {    
    float precioTotal = this->precio * cant;    
    std::string marca = this->vehiculo->getMarca();
    std::string modelo = this->vehiculo->getModelo();
    std::string conductor = this->vehiculo->nombreConductor(); 
    float calProm = this->vehiculo->calPromConductor();    
    DTConsultaViaje dt = DTConsultaViaje(this->codigo, marca, modelo, conductor, calProm, precioTotal);
    return dt;
}

bool Viaje::existeReservaUsuario(std::string nickname) {
    for (auto r : this->reservas) {
        if (r != nullptr) {            
            if (r->laRealizo(nickname)) { 
                return true;
            }
        }
    }
    return false;
}

Reserva* Viaje::agregarReserva(int cantAsientos, DTFecha f) {    
    Reserva* r = new Reserva(cantAsientos, f);
    this->reservas.insert(r);    
    return r; 
}

bool Viaje::esConductor(std::string nickname) {
    if (this->vehiculo != nullptr) {        
        return (this->vehiculo->nicknamePropietario() == nickname);
    }
    return false;
}

bool Viaje::esPasajero(std::string nickname) {
    return this->existeReservaUsuario(nickname);
}

DTListarViaje Viaje::getDTListarViaje() {  
    std::string nombreCond = this->vehiculo->nombreConductor();  
    DTListarViaje dt = DTListarViaje(this->codigo, this->fecha, this->origen, this->destino, nombreCond);
    return dt;
}	

std::set<DTUsuarioViaje> Viaje::getSetDTUsuarioViaje(std::string nickname, TipoUsuario tipo) {
    std::set<DTUsuarioViaje> dtSet;    
    if (this->vehiculo != nullptr) {        
        dtSet.insert(this->vehiculo->getDTUsuarioViaje());
    }    
    for (auto r : this->reservas){
        if (r != nullptr) {
            dtSet.insert(r->getDTUsuarioViaje());
        }
    }
    return dtSet;
}

bool Viaje::existeCalificacion(std::string nick1, std::string nick2) {
    for (auto r : this->reservas) {
        if (r != nullptr) {            
            if (r->hayCalificacion(nick1, nick2)) {
                return true;
            }
        }
    }
    return false;
}

Reserva* Viaje::obtenerReserva(std::string nick1, std::string nick2, TipoUsuario tipo) {
    std::string nickPasajero;
    
    if (tipo == TipoUsuario::T_Conductor) {
        nickPasajero = nick2;
    } else {
        nickPasajero = nick1;
    }

    for (auto r : this->reservas) {
        if (r != nullptr) {            
            if (r->laRealizo(nickPasajero)) {
                return r; 
            }
        }
    }
    
    return nullptr;
}
