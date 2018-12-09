#ifndef BASEDATOS_H
#define  BASEDATOS_H

#include <string>
#include "Alumno.h"
#include <list>

class BaseDatos: public Alumno{

private:
  std::list <Alumno> alumno_;

public:
  bool añadirAlumno(std::string dni, std::string nombre, std::string apell, std::string telefono, std::string email, std::string dir, int curso, std::string fechaNac, int grupo, bool lider);
  bool modificarAlumno(std:string dni, Alumno alumno);
  bool eliminarAlumno(std::string dni);
}
#endif
