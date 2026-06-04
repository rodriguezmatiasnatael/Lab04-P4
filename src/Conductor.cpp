#include "../include/Conductor.h"
#include "../include/Vehiculo.h"
#include "../include/Calificacion.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

Conductor::~Conductor() {
    for (auto veh : this->vehiculos) {
        if (veh != nullptr) {
            delete veh;
        }
    }    
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

void Conductor::asociarVehiculo(Vehiculo* v){
    this->vehiculos.insert(v);
}

int Conductor::getCantCalificaciones(){
    return this->calificaciones.size();
}

float Conductor::getCalificacionPromedio(){
    float total = 0;
    if (this->calificaciones.size() == 0){
        return total;
    }
    float suma = 0;
    for (auto cal : this->calificaciones){
        suma = suma + cal->getPuntaje(); //Aca da error porque queremos usar metodo de Calificacion con un forward declaration
    }
    total = suma / this->calificaciones.size();
    return total;
}

std::set<DTVehiculosConductor> Conductor::listarVehiculos(){
    std::set<DTVehiculosConductor> res; 
    if (this->vehiculos.size() == 0 ){
        return res;
    }
    
    for (auto veh : this->vehiculos){
        std::string mat;
        std::string mod;
        int cap;
        mat = veh->getMatricula(); 
        mod = veh->getModelo();
        cap = veh->getCapacidad();
        DTVehiculosConductor DTVeh = DTVehiculosConductor(mat, mod, cap);
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
