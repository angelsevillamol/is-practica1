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
#include <fstream>
#include "alumno.hpp"
#include "basedatos.hpp"


bool baseDatos::anadirAlumno(const alumno &nuevoAlumno) {
    if (getNumeroAlumnos() >= 150) {
        return false;
    }

    alumnos_.push_back(nuevoAlumno);
    return true;
}

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

bool baseDatos::eliminarAlumno(std::string dni)
{
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

bool baseDatos::getAlumno(std::string dni, alumno &a) const
{
    std::list<alumno>::const_iterator iter;

    for (iter = alumnos_.begin(); iter != alumnos_.end(); iter++) {
        if (dni == iter->getDni()) {
            a.setDni(iter->getDni());
            a.setNombre(iter->getNombre());
            a.setApellidos(iter->getApellidos());
            a.setTelefono(iter->getTelefono());
            a.setEmail(iter->getEmail());
            a.setDireccion(iter->getDireccion());
            a.setFechaNacimiento(iter->getFechaNacimiento());
            a.setCurso(iter->getCurso());
            a.setGrupo(iter->getGrupo());
            a.setEsLider(iter->getEsLider());
            return true;
        }
    }

    return false;
}

void baseDatos::buscarAlumnos(std::list<alumno> &resultado, 
    std::string apellidos, std::string dni, unsigned grupo) const
{
    std::list<alumno>::const_iterator iter;
    alumno nuevoAlumno;

    resultado.clear();
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
}

void baseDatos::guardarFichero(std::string nombreFichero) const
{
    std::ofstream outfile(nombreFichero, std::ios::out | std::ios::binary);
    std::list<alumno>::const_iterator iter;
    unsigned len;

    if (outfile.is_open()) {
        for (iter = alumnos_.begin(); iter != alumnos_.end(); iter++) {
            // Escritura del dni.
            len = iter->getDni().length();
            outfile.write(reinterpret_cast<char *>(&len), sizeof(unsigned));
            outfile.write(iter->getDni().c_str(), len);

            // Escritura del nombre.
            len = iter->getNombre().length();
            outfile.write(reinterpret_cast<char *>(&len), sizeof(unsigned));
            outfile.write(iter->getNombre().c_str(), len);

            // Escritura de los apellidos.
            len = iter->getApellidos().length(); 
            outfile.write(reinterpret_cast<char *>(&len), sizeof(unsigned));
            outfile.write(iter->getApellidos().c_str(), len);

            // Escritura del telefono.
            len = iter->getTelefono().length();
            outfile.write(reinterpret_cast<char *>(&len), sizeof(unsigned));
            outfile.write(iter->getTelefono().c_str(), len);

            // Escritura del e-mail.
            len = iter->getEmail().length();
            outfile.write(reinterpret_cast<char *>(&len), sizeof(unsigned));
            outfile.write(iter->getEmail().c_str(), len);

            // Escritura de la direccion postal.
            len = iter->getDireccion().length();
            outfile.write(reinterpret_cast<char *>(&len), sizeof(unsigned));
            outfile.write(iter->getDireccion().c_str(), len);

            // Escritura del curso mas alto matriculado.
            unsigned curso = iter->getCurso();
            outfile.write(reinterpret_cast<char *>(&curso), sizeof(unsigned));

            // Escritura de la fecha de nacimiento.
            len = iter->getFechaNacimiento().length();
            outfile.write(reinterpret_cast<char *>(&len), sizeof(unsigned));
            outfile.write(iter->getFechaNacimiento().c_str(), len);

            // Escritura del grupo.
            unsigned grupo = iter->getGrupo();
            outfile.write(reinterpret_cast<char *>(&grupo), sizeof(unsigned));

            // Escritura de la condicion de lider.
            unsigned esLider = iter->getEsLider();
            outfile.write(reinterpret_cast<char *>(&esLider), sizeof(unsigned));
        }
        
        outfile.close();
    }
}

void baseDatos::cargarFichero(std::string nombreFichero) {
    std::ifstream infile(nombreFichero, std::ios::in | std::ios::binary);
    std::string dni; 
    std::string nombre;
    std::string apellidos;
    std::string telefono; 
    std::string email; 
    std::string direccion; 
    std::string fechaNacimiento;
    unsigned curso;
    unsigned grupo; 
    unsigned aux;
    bool esLider;
    unsigned len;

    if (infile.is_open()) {
        // Se eliminan la lista de alumnos previa carga.
        alumnos_.clear();

        while (infile.read(reinterpret_cast<char *>(&len), sizeof(unsigned))) {
            dni.resize(len);
            infile.read(&dni[0], dni.size());

            // Lectura del nombre.
            infile.read(reinterpret_cast<char *>(&len), sizeof(unsigned));
            nombre.resize(len);
            infile.read(&nombre[0], nombre.size());

            // Lectura de los apellidos.
            infile.read(reinterpret_cast<char *>(&len), sizeof(unsigned));
            apellidos.resize(len);
            infile.read(&apellidos[0], apellidos.size());

            // Lectura del telefono.
            infile.read(reinterpret_cast<char *>(&len), sizeof(unsigned));
            telefono.resize(len);
            infile.read(&telefono[0], telefono.size());

            // Lectura del e-mail.
            infile.read(reinterpret_cast<char *>(&len), sizeof(unsigned));
            email.resize(len);
            infile.read(&email[0], email.size());

            // Lectura de la direccion postal.
            infile.read(reinterpret_cast<char *>(&len), sizeof(unsigned));
            direccion.resize(len);
            infile.read(&direccion[0], direccion.size());

            // Lectura del curso mas alto matriculado.
            infile.read(reinterpret_cast<char *>(&curso), sizeof(unsigned));

            // Lectura de la fecha de nacimiento.
            infile.read(reinterpret_cast<char *>(&len), sizeof(unsigned));
            fechaNacimiento.resize(len);
            infile.read(&fechaNacimiento[0], fechaNacimiento.size());

            // Lectura del grupo.
            infile.read(reinterpret_cast<char *>(&grupo), sizeof(unsigned));

            // Lectura de la condicion de lider.
            infile.read(reinterpret_cast<char *>(&aux), sizeof(unsigned));
            esLider = aux;

            // Se añade el alumno a la lista.
            anadirAlumno(dni, nombre, apellidos, telefono, email, 
                direccion, fechaNacimiento, curso, grupo, esLider);
        }

        infile.close();
    }
}
