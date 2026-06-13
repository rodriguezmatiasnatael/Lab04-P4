#include "../include/Viaje.h"
#include "../include/Vehiculo.h"

int Viaje::ultimoCodigo = 0;
Viaje::Viaje(Vehiculo* v,DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->vehiculo = v;
    this->origen = origen;
    this->fecha = fecha;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->vehiculo = nullptr;
    //seteamos codigo
    this->codigo = ultimoCodigo + 1;
    ultimoCodigo++;
    v->asociarViaje(this);
}

Viaje::~Viaje() {
    this->vehiculo->borrarViaje(this);
    for (auto r : this->reservas) delete r;
    this->reservas.clear();
}

int Viaje::getCodigo() {
    return this->codigo;
}

DTFecha Viaje::getFecha() {
    return this->fecha;
}

int Viaje::lugaresDisponibles(int asientos){
    int asientosReservados = 0;
    for (auto r : this->reservas){
        asientosReservados += r->getAsientosReservados(); 
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

DTConsultaViaje Viaje::getDTConsultaViaje(int cant) {    
    int codigo = this->codigo;
    float precioTotal = this->precio * cant;    
    std::string marca = this->vehiculo->getMarca();
    std::string modelo = this->vehiculo->getModelo();
    std::string conductor = this->vehiculo->nombreConductor(); 
    float calProm = this->vehiculo->calPromConductor();    
    DTConsultaViaje dt = DTConsultaViaje(codigo, marca, modelo, conductor, calProm, precioTotal);
    return dt;
}

Reserva* Viaje::agregarReserva(int cantAsientos, DTFecha f) {    
    Reserva* r = new Reserva(cantAsientos, f);
    this->reservas.insert(r);    
    return r; 
}

bool Viaje::esConductor(std::string nickname) {
    return (this->vehiculo->nicknamePropietario() == nickname);
}

bool Viaje::esPasajero(std::string nickname) {
    for (auto r : this->reservas) {          
        if (r->laRealizo(nickname)) { 
            return true;
        }
    }
    return false;
}

DTListarViaje Viaje::getDTListarViaje() {  
    std::string nickCond = this->vehiculo->nicknamePropietario();
    return DTListarViaje(this->codigo, this->fecha, this->origen, this->destino, nickCond);    
}	

std::set<DTUsuarioViaje> Viaje::getSetDTUsuarioViaje(std::string nickname, TipoUsuario tipo) {
    std::set<DTUsuarioViaje> dtSet;
    for (auto r : this->reservas){
        if (!(r->laRealizo(nickname))) {
            dtSet.insert(r->getDTUsuarioViaje());
        }
    }
    if (tipo == TipoUsuario::T_Pasajero) {
        dtSet.insert(this->vehiculo->getDTUsuarioViaje());
    }
    return dtSet;   
}

bool Viaje::existeCalificacion(std::string nickCalificador, std::string nickCalificado) {
    for (auto r : this->reservas) { 
        if (r->hayCalificacion(nickCalificador, nickCalificado)) {
            return true;
        }
    }
    return false;
}

Reserva* Viaje::obtenerReserva(std::string nickCalificador, std::string nickCalificado, TipoUsuario tipo) {
    std::string nickPasajero;
    
    if (tipo == TipoUsuario::T_Conductor) {
        nickPasajero = nickCalificado;
    } else {
        nickPasajero = nickCalificador;
    }

    for (auto r : this->reservas) {          
        if (r->laRealizo(nickPasajero)) {
            return r; 
        }
    }    
    return nullptr;
}

DTDetalleViaje Viaje::getDTDetalleViaje(){
    DTDetalleVehiculo dtv = this->vehiculo->getDTDetalleVehiculo();
    std::vector<DTDetalleReserva> dtres;
    for (auto r : this->reservas) {
        dtres.push_back(r->getDTDetalleReserva());
    }
    DTDetalleViaje dt = DTDetalleViaje(this->codigo, this->fecha, this->origen, this->destino, this->asientosPublicados, this->precio, dtv, dtres);
    return dt;
}

std::set<Reserva*> Viaje::getReservas(std::string nickname) {
    std::set<Reserva*> res;
    for (auto r : this->reservas) {
        if (r->laRealizo(nickname)) res.insert(r);
    }
    return res;
}