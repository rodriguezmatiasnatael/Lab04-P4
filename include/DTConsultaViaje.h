#ifndef DT_CONSULTA_VIAJE_H
#define DT_CONSULTA_VIAJE_H

#include "DTFecha.h"
#include <string>

class DTConsultaViaje {
private:
  int codigo;
  std::string marca;
  std::string modelo;
  std::string conductor;
  float calificacionProm;
  float precioTotal;

public:
  DTConsultaViaje(int codigo, std::string marca, std::string modelo, std::string conductor, float calificacionProm, float precioTotal);

  int getCodigo();
  std::string getMarca();
  std::string getModelo();
  std::string getConductor();
  float getCalificacionProm();
  float getPrecioTotal();
};

//SOBRECARGAR EL OPERADOR < para que inserte los DTConsultaViaje ordenados.
// El listado se presenta ordenado de menor a
// mayor precio total, y en caso de empate se debe mostrar primero el de mayor
// calificación promedio.

#endif
