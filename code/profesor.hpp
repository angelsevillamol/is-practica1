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
#include <fstream>
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
    inline bool getCoordinador() {return (esCoordinador_);};  //Devuelve si el profesor es coordinador o no.
    bool identificar(std::string usuario, std::string password);  //Devuelve si el usuario introducido existe.
    bool mostrarAlumnos(int opcion, bool ascendente = false);  //Devuelve la lista de alumnos completa.
    bool guardarCopia(std::string ficheroCopia = "default");  //Guarda en un fichero binario la lista de alumnos.
    bool cargarCopia(std::string ficheroCopia = "default");  //Carga en la base de datos los alumnos desde un fichero binario.
};

class coordinador : profesor {
    coordinador(std::string usuario);  //Constructor de la calse Coordinador.
    bool addProfesor(std::string usuario, std::string password);  //Añade un profesor ayudante.
};

#endif // PROFESOR_HPP
