#include "../include/Usuario.h"


Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email){
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
    this->calificaciones.clear();
}

/*TipoUsuario Usuario::getTipo(){
    return;
} AL FINAL ESTO NO VA POR EL DINAMIC CAST*/

DTUsuario Usuario::getDTUsuario(){
    DTUsuario res = DTUsuario(this->nickname, this->nombre);
    return res;
}

void Usuario::asociarCalificacion(Calificacion *cal){
    this->calificaciones.insert(cal);
}

Usuario::~Usuario() {
    
}
