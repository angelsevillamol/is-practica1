/**
 * @file profesor.hpp
 * @brief Implementación de los métodos de la clase profesor.
 * @date 27-11-2018
 *
 * Este fichero forma parte del proyecto realizado para la gestión de alumnos,
 * para la asignatura Ingeniería del Software de la Universidad de Córdoba.
 */

#include <fstream>
#include <string>
#include "alumno.hpp"
#include "basedatos.hpp"
#include "profesor.hpp"

bool profesor::identificar(std::string usuario, std::string password){
  std::ifstream credenciales("credenciales.bin", std::ios::binary);
  std::string nombreProfesor, contrProfesor;

  while (!credenciales.eof()) {
    getline(credenciales, nombreProfesor, ',');
    getline(credenciales, contrProfesor, '\n');

    if ((usuario == nombreProfesor) && (password == contrProfesor)) {
      return true;
    }
  }
  credenciales.close();
  return false;
}

bool coordinador::addProfesor(std::string usuario, std::string password){
  if(identificar(usuario, password) == true){
    return false;
  }

  std::ofstream credenciales("credenciales.bin", std::ios::binary);
  credenciales << usuario + ", " + password;

  credenciales.close();
  return true;
}
