/**
 * @file baseDatos.hpp
 * @brief Declaración de la clase baseDatos.
 * @date 27-11-2018
 *
 * Este fichero forma parte del proyecto realizado para la gestión de alumnos,
 * para la asignatura Ingeniería del Software de la Universidad de Córdoba.
 */

#ifndef BASEDATOS_HPP
#define BASEDATOS_HPP

#include <string>
#include <list>
#include "alumno.hpp"

class baseDatos 
{
private:
  std::list<alumno> alumnos_;

public:
  unsigned getNumeroAlumnos() const {return alumnos_.size(); }
  bool anadirAlumno(const alumno &nuevoAlumno);
  bool anadirAlumno(std::string dni, std::string nombre, std::string apellidos, 
      std::string telefono, std::string email, std::string direccion, 
      std::string fechaNacimiento, unsigned curso, unsigned grupo, bool esLider);
  bool modificarAlumno(std::string dni, alumno alumno);
  bool eliminarAlumno(std::string dni);
  void borrarAlumnos() { alumnos_.clear(); }
  bool getAlumno(std::string dni, alumno &a) const;
  void buscarAlumnos(std::list<alumno> &resultado, std::string apellidos = "", 
       std::string dni = "", unsigned grupo = 0) const;
  void guardarFichero(std::string nombreFichero) const;
  void cargarFichero(std::string nombreFichero); 
};

#endif // BASEDATOS_HPP
