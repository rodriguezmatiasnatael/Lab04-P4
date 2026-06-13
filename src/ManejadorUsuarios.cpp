#include "../include/ManejadorUsuarios.h"
#include <algorithm>

ManejadorUsuarios * ManejadorUsuarios::instancia = NULL;

ManejadorUsuarios::ManejadorUsuarios(){}

ManejadorUsuarios * ManejadorUsuarios::getInstance(){
    if (instancia == NULL){
        instancia = new ManejadorUsuarios();
    }
    return instancia;
}

// bool ManejadorUsuarios::existeUsuario(std::string nickname){
//     return std::any_of(this->usuarios.begin(), this->usuarios.end(), [&nickname](Usuario* u) {
//         return u != nullptr && u->getNickname() == nickname;
//     });
// }s

bool ManejadorUsuarios::existeUsuario(std::string nickname){
    for (auto u : this->usuarios){
        if(u->getNickname() == nickname){
            return true;
        }
    }
    return false;
}

void ManejadorUsuarios::crearPasajero(std::string nickname, std::string nombre,std::string password, std::string email, std::string ci){
    Usuario* p = new Pasajero(nickname, nombre, password, email, ci);
    this->usuarios.insert(p);
}

void ManejadorUsuarios::crearConductor(std::string nickname, std::string nombre, std::string password, std::string email, std::set<TipoLibreta> libretas) {
    Usuario* c = new Conductor(nickname, nombre,password, email, libretas);
    this->usuarios.insert(c);
}

//precondicion: nickname existe en usuarios
Usuario* ManejadorUsuarios::getUsuario(std::string nickname){
    for (auto u : this->usuarios){
        if(u->getNickname() == nickname){
            return u;
        }
    }
    return nullptr;
}

std::set<Usuario*> ManejadorUsuarios::getUsuarios(){
    return this->usuarios;
}
