#ifndef BASEDATOS_H
#define  BASEDATOS_H

#include <string>
#include "alumno.hpp"
#include <list>

class BaseDatos 
{
private:
  std::list<alumno> alumnos_;

public:
  bool añadirAlumno(std::string dni, std::string nombre, std::string apell, 
                    std::string telefono, std::string email, std::string dir, 
                    int curso, std::string fechaNac, int grupo, bool lider);
  bool modificarAlumno(std::string dni, alumno alumno);
  bool eliminarAlumno(std::string dni);
};

#endif
