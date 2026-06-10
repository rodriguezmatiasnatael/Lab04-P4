#include "../include/ManejadorViajes.h"
#include "../include/Viaje.h"
#include "../include/DTConsultaViaje.h"//


#include <algorithm>
ManejadorViajes * ManejadorViajes::instancia = NULL;

ManejadorViajes::ManejadorViajes(){

}

ManejadorViajes *ManejadorViajes::getInstance(){
    if (instancia == NULL){
        instancia = new ManejadorViajes();
    }
    return instancia;
}

std::set<Viaje*> ManejadorViajes::getViajes(){
    return this->viajes;
}

Viaje *ManejadorViajes::getViaje(int codigo){
  for (auto v : this->viajes){
      if (v != nullptr){
        if(v->getDTListarViaje().getCodigo() == codigo){
              return v;
          }
      }
  }
}
/*
Viaje ManejadorViajes::crearViaje(Vehiculo vehiculo,DTFecha fecha, std::string origen,std::string destino, int asientosPublicados ,float precio){
//necesito asociar vehiculo y codigo a ese viaje

  int cod;
  Viaje v = Viaje(cod,fecha,origen,destino,asientosPublicados,precio);

  return v;
} */