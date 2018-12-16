/**
 * @file basedatos.hpp
 * @brief Implementación de los métodos de la clase baseDatos.
 * @date 27-11-2018
 *
 * Este fichero forma parte del proyecto realizado para la gestión de alumnos,
 * para la asignatura Ingeniería del Software de la Universidad de Córdoba.
 */

#include <list>
#include <string>
#include <iostream>
#include "alumno.hpp"
#include "basedatos.hpp"

bool baseDatos::anadirAlumno(std::string dni, std::string nombre, 
    std::string apellidos, std::string telefono, std::string email, 
    std::string direccion, std::string fechaNacimiento, unsigned curso, 
    unsigned grupo, bool esLider) {

    if (getNumeroAlumnos() >= 150) {
        return false;
    }

    alumno nuevoAlumno(dni, nombre, apellidos, telefono, email, direccion, fechaNacimiento, 
        curso, grupo, esLider);

    alumnos_.push_back(nuevoAlumno);
    return true;
}

bool baseDatos::modificarAlumno(std::string dni, alumno nuevoAlumno) {
    std::list<alumno>::iterator iter;

	if (getNumeroAlumnos() == 0) {
	    return false;
	}

	for (iter = alumnos_.begin(); iter != alumnos_.end(); iter++) {
		if (iter->getDni() == dni) {
			iter->setDni(nuevoAlumno.getDni());
            iter->setNombre(nuevoAlumno.getNombre());
            iter->setApellidos(nuevoAlumno.getApellidos());
            iter->setTelefono(nuevoAlumno.getTelefono());
            iter->setEmail(nuevoAlumno.getEmail());
            iter->setDireccion(nuevoAlumno.getDireccion());
            iter->setFechaNacimiento(nuevoAlumno.getFechaNacimiento());
            iter->setCurso(nuevoAlumno.getCurso());
            iter->setGrupo(nuevoAlumno.getGrupo());
            iter->setEsLider(nuevoAlumno.getEsLider());
			return true;
		}

	}

    return false;
}

bool baseDatos::eliminarAlumno(std::string dni){
    std::list<alumno>::iterator iter;

	if (getNumeroAlumnos() == 0) {
	    return false;
	}

	for (iter = alumnos_.begin(); iter != alumnos_.end(); iter++) {
		if (iter->getDni() == dni){
			alumnos_.erase(iter);
			return true;
		}

	}

	return false;
}

std::list<alumno> baseDatos::buscarAlumnos(std::string apellidos, std::string dni, 
    unsigned grupo) {
    std::list<alumno> resultado;
    std::list<alumno>::iterator iter;
    alumno nuevoAlumno;

    for (iter = alumnos_.begin(); iter != alumnos_.end(); iter++) {
        if (apellidos == "" or apellidos == iter->getApellidos()) {
            if (dni == "" or dni == iter->getDni()) {
                if (grupo == 0 or grupo == iter->getGrupo()) {
                    nuevoAlumno.setDni(iter->getDni());
                    nuevoAlumno.setNombre(iter->getNombre());
                    nuevoAlumno.setApellidos(iter->getApellidos());
                    nuevoAlumno.setTelefono(iter->getTelefono());
                    nuevoAlumno.setEmail(iter->getEmail());
                    nuevoAlumno.setDireccion(iter->getDireccion());
                    nuevoAlumno.setFechaNacimiento(iter->getFechaNacimiento());
                    nuevoAlumno.setCurso(iter->getCurso());
                    nuevoAlumno.setGrupo(iter->getGrupo());
                    nuevoAlumno.setEsLider(iter->getEsLider());

                    resultado.push_back(nuevoAlumno);
                }
            }
        }
    }

    return resultado;
}
