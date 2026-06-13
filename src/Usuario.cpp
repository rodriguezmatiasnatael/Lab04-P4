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

void Usuario::borrarCalificacion(Calificacion* c) {
    this->calificaciones.erase(c);
}