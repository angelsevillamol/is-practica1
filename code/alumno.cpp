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

// Constructor por defecto.
alumno::alumno()
{
    dni_ = "";
    nombre_ = "";
    apellidos_ = "";
    telefono_ = "";
    email_ = "";
    direccion_ = "";
    fechaNacimiento_ = "";
    curso_ = 0;
    grupo_ = 0;
    esLider_ = false;
}

// Constructor de la clase alumno.
alumno::alumno(std::string dni, std::string nombre, std::string apellidos, 
               std::string telefono, std::string email, std::string direccion, 
               std::string fechaNacimiento, unsigned curso, unsigned grupo, 
               bool esLider)
{
    setDni(dni);
    setNombre(nombre);
    setApellidos(apellidos);
    setTelefono(telefono);
    setEmail(email);
    setDireccion(direccion);
    setFechaNacimiento(fechaNacimiento);
    setCurso(curso);
    setGrupo(grupo);
    setEsLider(esLider);
}
