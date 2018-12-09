/**
 * @file alumno.cpp
 * @brief Implementación de los métodos de la clase alumno.
 * @date 27-11-2018
 * 
 * Este fichero forma parte del proyecto realizado para la gestión de alumnos,
 * para la asignatura Ingeniería del Software de la Universidad de Córdoba.
 */

#include <string>
#include "alumno.hpp"

// Constructor de la clase alumno.
alumno::alumno(std::string dni, std::string nombre, std::string apellidos, 
               std::string telefono, std::string email, std::string direccion, 
               std::string fecha_nacimiento, unsigned curso, unsigned grupo, 
               bool es_lider)
{
    set_dni(dni);
    set_nombre(nombre);
    set_apellidos(apellidos);
    set_telefono(telefono);
    set_email(email);
    set_direccion(direccion);
    set_fecha_nacimiento(fecha_nacimiento);
    set_curso(curso);
    set_grupo(grupo);
    set_es_lider(es_lider);
}
