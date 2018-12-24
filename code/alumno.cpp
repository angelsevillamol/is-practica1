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

void alumno::setDni(std::string dni) 
{
    dni_ = dni;
    assert(dni_.length() == 9);
    for (unsigned i = 0; i < 8; i++) {
        assert(std::isdigit(dni_[i]));
    }
    assert(std::isalpha(dni_[8]));
}

void alumno::setNombre(std::string nombre) 
{
    nombre_ = nombre;
    for (unsigned i=0 ; i < nombre_.length() ; i++) {
        assert(std::isalpha(nombre_[i]));
    } 
}

void alumno::setApellidos(std::string apellidos) 
{ 
    apellidos_ = apellidos;
    for (unsigned i = 0; i < apellidos_.length(); i++) {
        assert(std::isalpha(apellidos_[i]) or apellidos_[i] == ' ');
    } 
}

void alumno::setTelefono(std::string telefono) 
{ 
    telefono_ = telefono;
    assert(telefono_.length() == 9);
    for (unsigned i = 0 ;i < 9; i++) {
        assert(std::isdigit(telefono_[i]));
    }
}

void alumno::setFechaNacimiento(std::string fecha_nacimiento) 
{ 
    fechaNacimiento_ = fecha_nacimiento;
    assert(isdigit(fechaNacimiento_[0]) and isdigit(fechaNacimiento_[1]) and 
           isdigit(fechaNacimiento_[3]) and isdigit(fechaNacimiento_[4]) and
           isdigit(fechaNacimiento_[6]) and isdigit(fechaNacimiento_[7]) and 
           isdigit(fechaNacimiento_[8]) and isdigit(fechaNacimiento_[9]));
    assert(fechaNacimiento_[2]=='/');
    assert(fechaNacimiento_[5]=='/');
}
