#include "../include/Conductor.h"
#include "../include/Vehiculo.h"
#include "../include/Calificacion.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

Conductor::~Conductor() {
    for (auto ve : this->vehiculos) delete ve;
    this->vehiculos.clear();
}

bool Conductor::estaHabilitado(TipoVehiculo tipo){
    for (auto lib : this->libretas){
        if (tipo == TipoVehiculo::Auto){
            if ((lib == TipoLibreta::AutoProfesional)||(lib == TipoLibreta::AutoAmateur)){
                return true;
            }
        } else {
            if ((lib == TipoLibreta::MotoProfesional)||(lib == TipoLibreta::MotoAmateur)){
                return true;
            }
        }
    }
    return false;
}

TipoUsuario Conductor::getTipo() {
    return TipoUsuario::T_Conductor;
}

void Conductor::asociarVehiculo(Vehiculo* v){
    this->vehiculos.insert(v);
}

int Conductor::getCantCalificaciones(){
    return this->calificaciones.size();
}

float Conductor::getCalificacionPromedio(){
    float total = 0;
    if (this->getCantCalificaciones() == 0){
        return total;
    }
    float suma = 0;
    for (auto cal : this->calificaciones){
        suma = suma + cal->getPuntaje(); //Aca da error porque queremos usar metodo de Calificacion con un forward declaration
    }
    total = suma / this->getCantCalificaciones();
    return total;
}

std::set<DTVehiculosConductor> Conductor::listarVehiculos(){
    std::set<DTVehiculosConductor> res; 
    if (this->vehiculos.size() == 0 ){
        return res;
    }
    
    for (auto veh : this->vehiculos){
        std::string mat = veh->getMatricula(); 
        std::string mar = veh->getMarca();
        int cap = veh->getCapacidad();
        DTVehiculosConductor DTVeh = DTVehiculosConductor(mat, mar, cap);
        res.insert(DTVeh);
    }
    return res;
}

bool Conductor::hayViajesFechaConductor(DTFecha fecha){
    for (auto veh : this->vehiculos){
        if (veh->hayViajesFecha(fecha)){
            return true;
        }
    }
    return false;
}

void Conductor::borrarVehiculo(Vehiculo* ve) {
    this->vehiculos.erase(ve);
}