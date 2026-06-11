#include "../include/Usuario.h"
#include "../include/Calificacion.h"

// === Constructor ===
Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
    this->calificaciones.clear();
}

std::string Usuario::getNickname() const {
    return this->nickname;
}

std::string Usuario::getNombre() const {
    return this->nombre;
}

DTUsuario Usuario::getDTUsuario() {
    DTUsuario res = DTUsuario(this->nickname, this->nombre);
    return res;
}

void Usuario::asociarCalificacion(Calificacion *cal) {
    this->calificaciones.insert(cal);
}

float Usuario::getCalificacionPromedio() {
    if (this->calificaciones.empty()) {
        return 0.0f; 
    }

    float suma = 0;
    
    for (auto c : this->calificaciones) {
        if (c != nullptr) {            
            suma += c->getPuntaje(); 
        }
    }

    return suma / this->calificaciones.size();
}

void Usuario::borrarCalificacion(Calificacion* c) {
    this->calificaciones.erase(c);
}