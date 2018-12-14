#include "BaseDatos.hpp"
#include "alumno.hpp"
#include <list>
#include <string>

bool BaseDatos::anadirAlumno(std::string dni, std::string nombre, std::string apellidos, std::string telefono, std::string email, std::string direccion, std::string fecha_nacimiento, unsigned curso, unsigned grupo,bool es_lider){
  if(alumno_.size()>=150){
    return false;
  }
  alumno a;
  a.set_dni(dni);
  a.set_nombre(nombre);
  a.set_apellidos(apellidos);
  a.set_telefono(telefono);
  a.set_email(email);
  a.set_direccion(direccion);
  a.set_fecha_nacimiento(fecha_nacimiento);
  a.set_curso(curso);
  a.set_grupo(grupo);
  a.set_es_lider(es_lider);
  alumno_.push_back(a);
  return true;
}
bool BaseDatos::eliminarAlumno(std::string dni){
 buscarAlumnos("",dni,0);

 std::list<alumno>::iterator i;

	if(alumno_.empty()==true){
	return -1;
	}

	for(i=alumno_.begin();i!=alumno_.end();i++){

		if(i->get_dni()==dni){
			alumno_.erase(i);
			return 1;
		}

	}

	return -2;
}
