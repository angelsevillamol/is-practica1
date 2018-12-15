#ifndef BASEDATOS_H
#define  BASEDATOS_H

#include <string>
#include "alumno.hpp"
#include <list>

class BaseDatos: public alumno{

private:
  std::list <alumno> alumno_;

public:
  bool anadirAlumno(std::string dni, std::string nombre, std::string apellidos, std::string telefono, std::string email, std::string direccion, std::string fecha_nacimiento, int curso, unsigned grupo,bool es_lider);
  bool modificarAlumno(std::string dni, alumno alumno);
  bool eliminarAlumno(std::string dni);
  alumno buscarAlumnos(std::string apellidos="",std::string dni="",unsigned grupo=0);
};
#endif
