#ifndef BASEDATOS_H
#define  BASEDATOS_H

#include <string>
#include "Alumno.h"
#include <list>

class BaseDatos: public Alumno{

private:
  std::list <Alumno> alumno_;

public:
  bool añadirAlumno();
  bool modificarAlumno(std:string dni, Alumno alumno);
  bool eliminarAlumno(std::string dni);
}
#endif
