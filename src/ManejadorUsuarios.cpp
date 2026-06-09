#include "../include/ManejadorUsuarios.h"
#include <algorithm>
ManejadorUsuarios * ManejadorUsuarios::instancia = NULL;
ManejadorUsuarios::ManejadorUsuarios(){

}
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
// }

bool ManejadorUsuarios::existeUsuario(std::string nickname){
    bool existe = false;
    for (auto u : this->usuarios){
        if (u != nullptr){
            if(u->getNickname() == nickname){
                existe = true;
            }
        }
    }
    return existe;
}


void ManejadorUsuarios::crearPasajero(std::string nickname, std::string nombre, std::string email, std::string password, std::string ci){
    Usuario* p = new Pasajero(nickname,nombre,email,password,ci);
    this->usuarios.insert(p);
}

//precondicion: nickname existe en usuarios
Usuario* ManejadorUsuarios::getUsuario(std::string nickname){
    for (auto u : this->usuarios){
        if (u != nullptr){
            if(u->getNickname() == nickname){
                return u;
            }
        }
    }
}

std::set<Usuario*> ManejadorUsuarios::getUsuarios(){
    return this->usuarios;
}
