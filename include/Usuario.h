#ifndef USUARIO_H
#define USUARIO_H

#include <set>
#include <string>
#include "DTUsuario.h"
#include "TipoUsuario.h"

class Calificacion;

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    std::set<Calificacion*> calificaciones;
public:
    virtual ~Usuario();
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    std::string getNickname() const;
    std::string getNombre() const;
    virtual TipoUsuario getTipo();
    DTUsuario getDTUsuario();
    void asociarCalificacion(Calificacion*);
    void borrarCalificacion(Calificacion*);
};

#endif
