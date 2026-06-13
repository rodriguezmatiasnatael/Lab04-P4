#include "../include/Menu.h"
#include "../include/Fabrica.h"
#include "../include/IControladorFechaActual.h"
#include "../include/CargaDatos.h"
#include "../include/DTFecha.h"
#include <iostream>
#include <limits>
#include <string>
#include <set>
#include "../include/IControladorUsuario.h"
#include "../include/IControladorViaje.h"

void Menu::altaUsuario(){
    Fabrica* fabrica = Fabrica::getInstance();
    IControladorUsuario* iControladorUsuario = fabrica->getIControladorUsuario();

    int tipoUsuario;
    std::cout << "1. Alta Pasajero\n";
    std::cout << "2. Alta Conductor\n";
    std::cout << "Seleccione: ";
    std::cin >> tipoUsuario;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (tipoUsuario != 1 && tipoUsuario != 2){
        std::cout << "Opcion invalida.\n";
        return;
    }

    std::string nickname, nombre, contrasena, email;
    std::cout << "Ingrese nickname: "; std::getline(std::cin, nickname);
    std::cout << "Ingrese nombre: "; std::getline(std::cin, nombre);
    std::cout << "Ingrese contrasena: "; std::getline(std::cin, contrasena);
    std::cout << "Ingrese email: "; std::getline(std::cin, email);

    bool usuarioOk = false;

    if (tipoUsuario == 1){
        std::string ci;
        std::cout << "Ingrese CI: "; std::getline(std::cin, ci);
        usuarioOk = iControladorUsuario->altaPasajero(nickname, nombre, contrasena, email, ci);
    }
    else if(tipoUsuario == 2){
        bool tieneMotoProfesional = false;
        bool tieneMotoAmateur = false;
        bool tieneAutoProfesional = false;
        bool tieneAutoAmateur = false;

        int cantLibretas = 0;
        int agregarLibreta = 1;

        while (agregarLibreta == 1 && cantLibretas < 4) {
            int tipoLibreta;
            std::cout << "\n=== Registrar Libreta ===\n";
            std::cout << "0. Moto (Profesional)\n";
            std::cout << "1. Moto (Amateur)\n";
            std::cout << "2. Auto (Profesional)\n";
            std::cout << "3. Auto (Amateur)\n";
            std::cout << "Seleccione el tipo de libreta: ";
            std::cin >> tipoLibreta;
            // std::cin.ignore(std::numeric_limits::max(),'\n'); estaba asi y no compilaba
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            bool yaExiste = false;
            if (tipoLibreta == 0) {
                if (tieneMotoProfesional) {
                    yaExiste = true;
                } else {
                    tieneMotoProfesional = true;
                    cantLibretas++;
                }
            } 
            else if (tipoLibreta == 1) {
                if (tieneMotoAmateur) {
                    yaExiste = true;
                } else {
                    tieneMotoAmateur = true;
                    cantLibretas++;
                }
            } 
            else if (tipoLibreta == 2) {
                if (tieneAutoProfesional) {
                    yaExiste = true;
                } else {
                    tieneAutoProfesional = true;
                    cantLibretas++;
                }
            } 
            else if (tipoLibreta == 3) {
                if (tieneAutoAmateur) {
                    yaExiste = true;
                } else {
                    tieneAutoAmateur = true;
                    cantLibretas++;
                }
            } 
            else {
                std::cout << "Opcion invalida.\n";
                continue;
            }

            if (yaExiste) {
                std::cout << "Esa libreta ya fue ingresada.\n";
            } else {
                std::cout << "Libreta agregada.\n";
            }

            if (cantLibretas < 4) {
                std::cout << "¿Desea agregar otra libreta? (1: Si, 0: No): ";
                std::cin >> agregarLibreta;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else{
                std::cout << "Se ha alcanzado el limite maximo de libretas.\n";
            }
        }

        if (cantLibretas == 0) {
            std::cout << "Debe ingresar al menos una libreta para registrar un conductor.\n";
            return;
        }

        // Ejemplo de como armar el conjunto de libretas utilizando set
        std::set<TipoLibreta> libretas;
        if (tieneMotoProfesional) {
            libretas.insert(TipoLibreta::MotoProfesional);
        }
        if (tieneMotoAmateur) {
            libretas.insert(TipoLibreta::MotoAmateur);
        }
        if (tieneAutoProfesional) {
            libretas.insert(TipoLibreta::AutoProfesional);
        }
        if (tieneAutoAmateur) {
            libretas.insert(TipoLibreta::AutoAmateur);
        }

        usuarioOk = iControladorUsuario->altaConductor(nickname, nombre, contrasena, email, libretas);
        int agregarVehiculo = 1;
        while (usuarioOk == true && agregarVehiculo == 1){
            std::string matricula, marca, modelo;
            int capacidad, tipo;
            std::cout << "\n=== Registrar Vehiculo ===\n";
            std::cout << "Ingrese matricula: "; std::getline(std::cin, matricula);
            std::cout << "Ingrese capacidad: "; std::cin >> capacidad;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese marca: "; std::getline(std::cin, marca);
            std::cout << "Ingrese modelo: "; std::getline(std::cin, modelo);
            std::cout << "Ingrese tipo (0: Auto, 1: Moto): "; std::cin >> tipo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int resultadoRegistrarVehiculo = -3;
    
            //como tipo es int pusimos un if para evaluar cada caso usando TipoVehiculo
            if(tipo == 0){
                resultadoRegistrarVehiculo = iControladorUsuario->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, TipoVehiculo::Auto);
            }
            else if(tipo == 1){
                resultadoRegistrarVehiculo = iControladorUsuario->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, TipoVehiculo::Moto);
            }

            if (resultadoRegistrarVehiculo == -1) {
                std::cout << "Ya existe un vehiculo con esa matricula.\n";
            } else if (resultadoRegistrarVehiculo == -2) {
                std::cout << "El conductor no tiene la libreta necesaria para registrar ese vehiculo.\n";
            } else if (resultadoRegistrarVehiculo == 0) {
                std::cout << "Vehiculo registrado exitosamente.\n";
            }
            std::cout << "¿Desea agregar otro vehiculo? (1: Si, 0: No): ";
            std::cin >> agregarVehiculo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Menu::altaViaje(){
    Fabrica* fabrica = Fabrica::getInstance();
    IControladorViaje* iControladorViaje = fabrica->getIControladorViaje();
    std::string nickname, matricula, origen, destino;
    int dia, mes, anio, asientos;
    float precio;

    std::cout << "Ingrese nickname del conductor: "; std::getline(std::cin, nickname);
    std::set<DTVehiculosConductor> coleccionVehiculos = iControladorViaje->listarVehiculosConductor(nickname);

    //TODO: Recorrer la coleccion y mostrar "> Matricula: xx, Marca: yy, Capacidad: www"
    for (auto v : coleccionVehiculos){
        std::cout << "> Matricula: "<< v.getMatricula() << ", Marca: "<< v.getMarca() << ", Capacidad: " << v.getCapacidad()<< std::endl;
    }

    std::cout << "Ingrese matricula del vehiculo a utilizar: "; std::getline(std::cin, matricula);
    
    bool matriculaValida = false;
    //TODO: Validar matricula en listado
    for (auto v : coleccionVehiculos){
        if(matricula == v.getMatricula()){
            matriculaValida = true;
            break;
        }
    }

    if (!matriculaValida) {
        std::cout << "Matricula invalida.\n";
        return;
    }

    std::cout << "Ingrese fecha del viaje (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos: "; std::cin >> asientos;
    std::cout << "Ingrese precio por asiento: "; std::cin >> precio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool viajeOk = false;

    //TODO: viajeOk = controlador->altaViaje(matricula, DTFecha(dia, mes, anio), origen, destino, asientos, precio)
    viajeOk = iControladorViaje->altaViaje(matricula,DTFecha(dia,mes,anio),origen,destino,asientos,precio);

    if (viajeOk) {
        std::cout << "Viaje registrado exitosamente.\n";

    } else {
        std::cout << "Error al registrar el viaje.\n";
    }
}

void Menu::generarReserva() {
    Fabrica* fabrica = Fabrica::getInstance();
    IControladorViaje* iControladorViaje = fabrica->getIControladorViaje();


    //TODO: Colecion de String = controlador->listarPasajeros()
    std::set<std::string> pasajeros = iControladorViaje->listarPasajeros();

    //TODO: Recorrer la colección y mostrar "> nickname"
    for(auto p: pasajeros){
        std::cout <<"> "<< p <<std::endl;
    }

    std::string nickname;
    std::cout << "Ingrese nickname del pasajero: "; std::getline(std::cin, nickname);

    bool nicknameValido = false;

    //TODO: Validar nickname en listado
    for(auto p: pasajeros){
        if(nickname == p){
            nicknameValido = true;
            break;
        }
    }

    if (!nicknameValido){
        std::cout << "Nickname invalido.\n";
        return;
    }

    int dia, mes, anio, asientos;
    std::string origen, destino;
    std::cout << "Ingrese fecha del viaje a consultar (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos a reservar: "; std::cin >> asientos;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //TODO: Coleccion de DTConsultaViaje = controlador->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos)
    std::set<DTConsultaViaje> consultaViajes = iControladorViaje->consultarViajes(DTFecha(dia,mes,anio),origen,destino,asientos);
    //TODO: Recorrer la coleccion y mostrar: "> Codigo: xx, Marca: yy, Modelo: zzz, Conductor: aaa, CalificacionPromedio: qqq, PrecioTotal: eee"
    for(auto v: consultaViajes){
        std::cout << "> Codigo: "<< v.getCodigo() << ",Marca: "<< v.getMarca()<<",Modelo: "<<v.getModelo()<<
        ",Conductor: "<<v.getConductor()<<v.getCalificacionProm()<<",PrecioTotal: "<<v.getPrecioTotal()<<std::endl;
    }
    bool hayViajes = false;
    //TODO: Validar coleccion vacía
    hayViajes = !consultaViajes.empty();

    if (!hayViajes){
        std::cout << "No hay viajes disponibles.\n";
        return;
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje a reservar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;
    //TODO: Validar codigo en listado
    for( auto v: consultaViajes){
        if(codigo == v.getCodigo()){
            codigoValido = true;
            break;
        }
    }

    if (!codigoValido){
        std::cout << "Codigo invalido.\n";
        return;
    }

    bool reservaOk = false;
    //TODO: reservaOk = controlador->generarReserva(nickname, codigo, asientos)
    reservaOk = iControladorViaje->generarReserva(nickname,codigo,asientos);
    if (reservaOk) {
        std::cout << "Reserva realizada exitosamente.\n";
    } else {
        std::cout << "Error al realizar la reserva.\n";
    }
}

void Menu::calificarUsuario(){
    Fabrica* fabrica = Fabrica::getInstance();
    IControladorViaje* iControladorViaje = fabrica->getIControladorViaje();

    //TODO: Coleccion de DTUsuario = controlador->listarUsuarios()
    std::set<DTUsuario> usuarios = iControladorViaje->listarUsuarios();

    //TODO: Recorrer la coleccion y mostrar "> Nickname: xx, Nombre: yyy"
    for(auto u: usuarios){
        std::cout << "> Nickname: "<< u.getNickname() << ", Nombre: "<< u.getNombre()<< std::endl;
    }


    std::string nickname;
    std::cout << "Ingrese su nickname: "; std::getline(std::cin, nickname);
    bool nicknameValido = false;
    //TODO: Validar nickname en listado
    for(auto u:usuarios){
        if(nickname == u.getNickname()){
            nicknameValido = true;
            break;
        }
    }

    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    //TODO: Coleccion de DTListarViaje = controlador->listarViajes(nickname)
    std::set<DTListarViaje> viajes = iControladorViaje->listarViajes(nickname);

    //TODO: Recorrer la coleccion y mostrar "> Codigo: xx, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Conductor: aaa"
    for(auto v: viajes){
        std::cout << "> Codigo: "<< v.getCodigo() << ",Fecha: "<<v.getFecha().getDia()<<"/"<<v.getFecha().getMes()<<"/"<<v.getFecha().getAnio()<<
        ", Origen: "<< v.getOrigen() << ", Destino: " << v.getDestino() << ", Conductor: " << v.getConductor() << std::endl;
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;

    //TODO: Validar codigo en listado
    for(auto v: viajes){
        if(codigo == v.getCodigo()){
            codigoValido = true;
            break;
        }
    }

    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    //TODO: Coleccion de DTUsuarioViaje = Controlador->listarUsuariosViaje(codigo)
    std::set<DTUsuarioViaje> usuariosViaje = iControladorViaje->listarUsuariosViaje(codigo);

    //TODO: Recorrer la coleccion y mostrar "> Nickname: xx, Tipo: yyy"
    for(auto u: usuariosViaje){
        std::cout << "> Nickname: "<< u.getNickname()<<",Tipo: "<< u.getTipo()<< std::endl;
    }
    std::string nicknameCalificado;
    int calificacion;
    std::cout << "Ingrese nickname del usuario a calificar: "; std::getline(std::cin, nicknameCalificado);
    std::cout << "Ingrese calificacion (1-5): "; std::cin >> calificacion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool nicknameCalificadoValido = false;

    //TODO: Validar nickname en listado
    for(auto u: usuariosViaje){
        if(nicknameCalificado == u.getNickname()){
            nicknameCalificadoValido = true;
            break;
        }
    }

    if (!nicknameCalificadoValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    bool calificacionOk = false;

    //TODO: calificacionOk = Controlador->calificarUsuario(nicknameCalificado, calificacion)
    calificacionOk = iControladorViaje->calificarUsuario(nicknameCalificado,calificacion);

    if (calificacionOk) {
        std::cout << "Calificacion exitosa.\n";
    } else {
        std::cout << "Error al calificar.\n";
    }
}

void Menu::eliminarViaje() {
    Fabrica* fabrica = Fabrica::getInstance();
    IControladorViaje* iControladorViaje = fabrica->getIControladorViaje();

    //TODO: Coleccion de DTListarViaje = controlador->listarViajes()
    std::set<DTListarViaje> viajes = iControladorViaje->listarViajes();
    //TODO: Recorrer la coleccion y mostrar "> Codigo: xx, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Conductor: aaa"
    for(auto v: viajes){
        std::cout << "> Codigo: "<< v.getCodigo() << ",Fecha: "<<v.getFecha().getDia()<<"/"<<v.getFecha().getMes()<<"/"<<v.getFecha().getAnio()<<
        ", Origen: "<< v.getOrigen() << ", Destino: " << v.getDestino() << ", Conductor: " << v.getConductor() << std::endl;
    }
    int codigo;
    std::cout << "Ingrese codigo del viaje a eliminar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;

    //TODO: Validar codigo en listado
    for(auto v: viajes){
        if(codigo == v.getCodigo()){
            codigoValido = true;
            break;
        }
    }
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    //TODO: DTDetalleViaje = controlador->detalleViaje(codigo)
    DTDetalleViaje detalleviaje = iControladorViaje->detalleViaje(codigo);

    //TODO: Mostrar detalle del viaje siguiendo el formato
    //>> Viaje <<
    //--- Matrícula: aa, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Capacidad: bbb, Precio por asiento: qqq
    //>> Vehiculo <<
    //--- Matricula: mm, Capacidad: aa, Marca: bbb, Modelo: ccc, Tipo: ddd
    //>> Reservas <<
    //--- AsientosReservados: xx, Fecha: dd/mm/aaaa, Pasajero: aaa



    std::cout << ">> Viaje <<"<< std::endl << "--- Matrícula: "<< detalleviaje.getVehiculo().getMatricula()<< 
    ",Fecha: "<< detalleviaje.getFecha().getDia()<< "/"<<detalleviaje.getFecha().getMes()<< "/"<<detalleviaje.getFecha().getAnio()<<
    ", Origen: "<<detalleviaje.getOrigen()<< " Destino: "<<detalleviaje.getDestino()<<", Capacidad: "<<detalleviaje.getVehiculo().getCapacidad()<<", Precio por asiento: "<< detalleviaje.getPrecio()<< std::endl;
    
    std::cout << ">> Vehiculo <<"<< std::endl<< "--- Matrícula: "<< detalleviaje.getVehiculo().getMatricula()<<", Capacidad: "<<detalleviaje.getVehiculo().getCapacidad()<<", Marca: "<< detalleviaje.getVehiculo().getMarca()<<
    ", Modelo: "<< detalleviaje.getVehiculo().getModelo()<<", Tipo: "<<detalleviaje.getVehiculo().getTipo()<< std::endl;
    
    std::cout << ">> Reservas <<"<<std::endl;
    for(auto r: detalleviaje.getReservas()){
        std::cout << "--- AsientosReservados: "<< r.getAsientosReservados()<<", Fecha: "<< r.getFecha().getDia()<< "/"<<r.getFecha().getMes()<< "/"<<r.getFecha().getAnio()<<", Pasajero: "<< r.getPasajero()<<std::endl;
    }
    
    int confirmar;
    std::cout << "¿Confirmar eliminacion? (1: Si, 0: No): "; std::cin >> confirmar;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (confirmar == 1) {
        //TODO: controlador->eliminarViaje()
        iControladorViaje->eliminarViaje();

        std::cout << "Viaje eliminado exitosamente.\n";
    } else {
        //TODO: controlador->cancelarEliminarViaje()
        iControladorViaje->cancelarEliminarViaje();

        std::cout << "Eliminacion cancelada.\n";
    }

}

void Menu::administrarFechaActual(){
    int opFecha;
    std::cout << "1. Ver fecha actual\n";
    std::cout << "2. Modificar fecha actual\n";
    std::cout << "Seleccione: ";
    std::cin >> opFecha;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorFechaActual* controladorFecha = fabrica->getIControladorFechaActual();

    if (opFecha == 1) {
        DTFecha fecha = controladorFecha->getFecha();
        std::cout << "Fecha actual: " << fecha << "\n";
    } else if (opFecha == 2) {
        int dia, mes, anio;
        std::cout << "Ingrese dia: "; std::cin >> dia;
        std::cout << "Ingrese mes: "; std::cin >> mes;
        std::cout << "Ingrese anio: "; std::cin >> anio;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        controladorFecha->setFecha(DTFecha(dia, mes, anio));
        std::cout << "Fecha modificada exitosamente a " << controladorFecha->getFecha() << "\n";
    } else {
        std::cout << "Opcion invalida.\n";
    }
}

void Menu::cargarDatos() {
    CargaDatos::getInstance()->cargarDatos();
}

void Menu::mostrarMenu() {
    int opcion = -1;
    while (opcion != 8) {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Alta de Usuario\n";
        std::cout << "2. Alta de Viaje\n";
        std::cout << "3. Generar Reserva\n";
        std::cout << "4. Calificar Usuario\n";
        std::cout << "5. Eliminar Viaje\n";
        std::cout << "6. Administrar Fecha Actual\n";
        std::cout << "7. Cargar Datos\n";
        std::cout << "8. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                altaUsuario();
                break;
            case 2:
                altaViaje();
                break;
            case 3:
                generarReserva();
                break;
            case 4:
                calificarUsuario();
                break;
            case 5:
                eliminarViaje();
                break;
            case 6:
                administrarFechaActual();
                break;
            case 7:
                cargarDatos();
                break;
            case 8:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    }
}
