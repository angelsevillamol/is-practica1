/**
 * @file profesor.hpp
 * @brief Implementación de los métodos de la clase profesor.
 * @date 27-11-2018
 *
 * Este fichero forma parte del proyecto realizado para la gestión de alumnos,
 * para la asignatura Ingeniería del Software de la Universidad de Córdoba.
 */

#include <string>
#include "alumno.hpp"
#include "basedatos.hpp"
#include "profesor.hpp"

bool stringToBool(std::string str){
  if (str == "true" || str == "TRUE") {return true;}
  else {return false;}
}

bool profesor::identificar(std::string usuario, std::string password){
  std::ifstream credenciales("credenciales.bin", std::ios::binary);
  std::string nombreProfesor, contrProfesor;

  while (!credenciales.eof()) {
    getline(credenciales, nombreProfesor, ',');
    getline(credenciales, contrProfesor, '\n');

    if ((usuario == nombreProfesor) && (password == contrProfesor)) {
      return true;
    }
  }
  credenciales.close();
  return false;
}

bool profesor::guardarCopia(std::string fichero) {
    std::ofstream copiaSeguridad(fichero, std::ios::binary);
    std::list<alumno> alumnos = bbdd_.buscarAlumnos();
    std::list<alumno>::iterator iter;

    if (copiaSeguridad.is_open()) {
        for (iter = alumnos.begin(); iter != alumnos.end(); iter++) {
            copiaSeguridad << iter->getDni() + ',' 
                           << iter->getNombre() + ',' 
                           << iter->getApellidos() + ',' 
                           << iter->getTelefono() + ','
                           << iter->getEmail() + ',' 
                           << iter->getDireccion() + ',' 
                           << iter->getCurso() + ',' 
                           << iter->getFechaNacimiento() + ','
                           << iter->getGrupo() + ',' 
                           << iter->getEsLider() + '\n';
        }
        
        copiaSeguridad.close();
        return true;
    }
    else {
        return false;
    }
}

bool profesor::cargarCopia(std::string fichero) {
    std::ifstream copiaSeguridad(fichero, std::ios::binary);
    std::string dni; 
    std::string nombre;
    std::string apellidos;
    std::string telefono; 
    std::string email; 
    std::string direccion; 
    std::string fechaNacimiento;
    unsigned curso;
    unsigned grupo;  
    bool esLider;
    std::string aux;

    if (copiaSeguridad.is_open()) {
        while (getline(copiaSeguridad, dni, ',')) {
            getline(copiaSeguridad, nombre, ',');
            getline(copiaSeguridad, apellidos, ',');
            getline(copiaSeguridad, telefono, ',');
            getline(copiaSeguridad, email, ',');
            getline(copiaSeguridad, direccion, ',');
            getline(copiaSeguridad, aux, ',');
            curso = atoi(aux.c_str());
            getline(copiaSeguridad, fechaNacimiento, ',');
            getline(copiaSeguridad, aux, ',');
            grupo = atoi(aux.c_str());
            getline(copiaSeguridad, aux, '\n');
            esLider = stringToBool(aux);

            bbdd_.anadirAlumno(dni, nombre, apellidos, telefono, email, 
                direccion, fechaNacimiento, curso, grupo, esLider);
        }

        copiaSeguridad.close();
        return true;
    }
    else {
        return false;
    }
}

bool coordinador::addProfesor(std::string usuario, std::string password){
  if(identificar(usuario, password) == true){
    return false;
  }

  std::ofstream credenciales("credenciales.bin", std::ios::binary);
  credenciales << usuario + ", " + password;

  credenciales.close();
  return true;
}
