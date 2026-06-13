#include <iostream>
#include "../include/CargaDatos.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorUsuario.h"
#include "../include/ControladorViaje.h"

CargaDatos* CargaDatos::instancia = nullptr;

CargaDatos::CargaDatos() {
    datosCargados = false;
}

CargaDatos* CargaDatos::getInstance() {
    if (instancia == nullptr) {
        instancia = new CargaDatos();
    }
    return instancia;
}

void CargaDatos::cargarDatos() {
    if (datosCargados) {
        std::cout << "Error: Los datos ya han sido cargados anteriormente.\n";
        return;
    }

    ControladorUsuario* cu = new ControladorUsuario();
    ControladorViaje* cv =  new ControladorViaje();


    // Conductores
    std::set<TipoLibreta> set1;
    set1.insert(TipoLibreta::AutoAmateur);
    cu->altaConductor("matil92", "Matias Lopez", "m4t14s92", "matias.lopez.92@gmail.com", set1);

    // Conductor 1
    std::set<TipoLibreta> set2;
    set2.insert(TipoLibreta::AutoProfesional);
    cu->altaConductor("ana_silva", "Ana Silva", "asilva2026", "anasilva.m@outlook.com", set2);

    // Conductor 2
    std::set<TipoLibreta> set3;
    set3.insert(TipoLibreta::MotoAmateur);
    cu->altaConductor("greg_m", "Diego Rodriguez", "drodriguez88", "diegorodriguez@fing.edu.uy", set3);

    // Conductor 3
    std::set<TipoLibreta> set4;
    set4.insert(TipoLibreta::MotoAmateur);
    cu->altaConductor("lau_vaz", "Laura Vazquez", "lvazquezQ7", "laura.vazquez@fing.edu.uy", set4);

    // Conductor 4
    std::set<TipoLibreta> set5;
    set4.insert(TipoLibreta::AutoProfesional);
    set4.insert(TipoLibreta::MotoAmateur);
    cu->altaConductor("carlos_r", "Carlos Rossi", "crossi99x", "carlos.rossi.uy@gmail.com", set5);

    // Pasajeros
    cu->altaPasajero("santi_90", "Santiago Acosta", "sacosta90", "santiago.acosta@gmail.com", "1.492.304-2");
    cu->altaPasajero("mari_b", "Maria Noel Barreto", "maribarreto6", "mari.barreto@outlook.com", "4.103.859-1");
    cu->altaPasajero("nacho_f", "Ignacio Figueroa", "ifigueroa26", "ignacio.figueroa@fing.edu.uy", "3.847.112-5");
    cu->altaPasajero("valen_uy", "Valentina Mendez", "vmendezQ2", "valen.mendez@fing.edu.uy", "2.956.403-0");
    cu->altaPasajero("joaco_r", "Joaquin Rivero", "jrivero99x", "joaquin_rivero@hotmail.com", "5.021.784-3");
    
    // Vehiculos de matil92
    cu->registrarVehiculo("matil92", "ABJ4586", 4, "Chevrolet", "Onix", TipoVehiculo::Auto);
    cu->registrarVehiculo("matil92", "ACM4455", 6, "Toyota", "Rush", TipoVehiculo::Auto);

    // Vehiculos de ana_silva
    cu->registrarVehiculo("ana_silva", "BAS7895", 4, "Fiat", "Argo", TipoVehiculo::Auto);
    cu->registrarVehiculo("ana_silva", "BCS4105", 9, "Hyundai", "H1", TipoVehiculo::Auto);

    // Vehiculos de greg_m
    cu->registrarVehiculo("greg_m", "LDA4875", 1, "Honda", "CB Twist", TipoVehiculo::Auto);

    // Vehiculos de lau_vaz
    cu->registrarVehiculo("lau_vaz", "PDB1205", 1, "Yumbo", "Max 110", TipoVehiculo::Auto);

    // Vehiculos de carlos_r
    cu->registrarVehiculo("carlos_r", "SBJ4874", 4, "Volkswagen", "Gol", TipoVehiculo::Auto);
    cu->registrarVehiculo("carlos_r", "SCF2469", 1, "Yamaha", "FZ S", TipoVehiculo::Auto);

    // Viaje 1
    DTFecha fecha1(21, 10, 2026);
    cv->altaViaje("ABJ4586", fecha1, "montevideo", "mercedes", 4, 200.0f);

    // Viaje 2
    DTFecha fecha2(20, 10, 2026);
    cv->altaViaje("ACM4455", fecha2, "young", "montevideo", 5, 250.0f);

    // Viaje 3
    DTFecha fecha3(20, 10, 2026);
    cv->altaViaje("BAS7895", fecha3, "young", "montevideo", 4, 200.0f);

    // Viaje 4
    DTFecha fecha4(21, 10, 2026);
    cv->altaViaje("BCS4105", fecha4, "montevideo", "mercedes", 9, 200.0f);

    // Viaje 5
    DTFecha fecha5(21, 10, 2026);
    cv->altaViaje("LDA4875", fecha5, "montevideo", "mercedes", 1, 300.0f);

    // Viaje 6
    DTFecha fecha6(21, 10, 2026);
    cv->altaViaje("PDB1205", fecha6, "montevideo", "mercedes", 1, 350.0f);

    // Viaje 7
    DTFecha fecha7(21, 10, 2026);
    cv->altaViaje("SBJ4874", fecha7, "montevideo", "mercedes", 4, 260.0f);

    // Viaje 8
    DTFecha fecha8(20, 10, 2026);
    cv->altaViaje("SCF2469", fecha8, "montevideo", "cerro chato", 1, 150.0f);

    // Viaje 9
    DTFecha fecha9(15, 3, 2026);
    cv->altaViaje("ABJ4586", fecha9, "montevideo", "colonia", 4, 140.0f);

    // Viaje 10
    DTFecha fecha10(15, 3, 2026);
    cv->altaViaje("BCS4105", fecha10, "montevideo", "colonia", 9, 180.0f);

    // Viaje 11
    DTFecha fecha11(15, 3, 2026);
    cv->altaViaje("SBJ4874", fecha11, "montevideo", "colonia", 1, 100.0f);

    // Viaje 12
    DTFecha fecha12(14, 3, 2026);
    cv->altaViaje("SBJ4874", fecha12, "montevideo", "colonia", 4, 600.0f);

    // Viaje 13
    DTFecha fecha13(20, 10, 2026);
    cv->altaViaje("LDA4875", fecha13, "young", "montevideo", 1, 250.0f);


    // Reserva 1
    cv->generarReserva("santi_90", 9, 2);

    // Reserva 2
    cv->generarReserva("mari_b", 9, 1);

    // Reserva 3
    cv->generarReserva("nacho_f", 10, 5);

    // Reserva 4
    cv->generarReserva("valen_uy", 10, 3);

    // Reserva 5
    cv->generarReserva("joaco_r", 10, 1);

    // Reserva 6
    cv->generarReserva("mari_b", 12, 1);

    // Reserva 7
    cv->generarReserva("nacho_f", 12, 1);

    // Reserva 8
    cv->generarReserva("mari_b", 1, 2);

    // Reserva 9
    cv->generarReserva("nacho_f", 9, 1);

    // Calificacion 1
    cv->setNickname("santi_90");
    cv->setCodigo(9);
    cv->calificarUsuario("matil92", 4);

    // Calificacion 2
    cv->setNickname("mari_b");
    cv->setCodigo(9);
    cv->calificarUsuario("matil92", 4);

    // Calificacion 3
    cv->setNickname("matil92");
    cv->setCodigo(9);
    cv->calificarUsuario("mari_b", 3);

    // Calificacion 4
    cv->setNickname("ana_silva");
    cv->setCodigo(10);
    cv->calificarUsuario("valen_uy", 5);

    // Calificacion 5
    cv->setNickname("ana_silva");
    cv->setCodigo(10);
    cv->calificarUsuario("joaco_r", 5);

    // Calificacion 6
    cv->setNickname("mari_b");
    cv->setCodigo(12);
    cv->calificarUsuario("carlos_r", 5);

    // Calificacion 7
    cv->setNickname("carlos_r");
    cv->setCodigo(12);
    cv->calificarUsuario("nacho_f", 5);


    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}
