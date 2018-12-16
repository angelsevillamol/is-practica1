/**
 * @file profesor.hpp
 * @brief Declaración de la clase profesor.
 * @date 27-11-2018
 *
 * Este fichero forma parte del proyecto realizado para la gestión de alumnos,
 * para la asignatura Ingeniería del Software de la Universidad de Córdoba.
 */

#ifndef PROFESOR_HPP
#define PROFESOR_HPP

#include <string>
#include <list>
#include "alumno.hpp"
#include "basedatos.hpp"

class profesor
{
  private:
    std::string nombreUsuario_;
    bool esCoordinador_;
    baseDatos bbdd_;
  public:
    profesor(std::string usuario);  //Constructor de la clase Profesor.
    bool getEsCoordinador() { return esCoordinador_; }  //Devuelve si el profesor es coordinador o no.
    baseDatos& getBaseDatos() { return bbdd_; }
    bool identificar(std::string nombreFichero, std::string usuario, std::string password);  //Devuelve si el usuario introducido existe.
    bool anadirProfesor(std::string nombreFichero, std::string usuario, std::string password);  //Añade un profesor ayudante.
};

#endif // PROFESOR_HPP
