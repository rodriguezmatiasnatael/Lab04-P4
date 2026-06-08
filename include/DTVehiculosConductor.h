#ifndef DT_VEHICULOS_CONDUCTOR_H
#define DT_VEHICULOS_CONDUCTOR_H

#include <string>

class DTVehiculosConductor {
private:
  std::string matricula;
  std::string marca;
  int capacidad;

public:
  DTVehiculosConductor(std::string matricula, std::string marca, int capacidad);

  std::string getMatricula();
  std::string getMarca();
  int getCapacidad();
};

#endif
