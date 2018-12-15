#include "BaseDatos.hpp"
#include "alumno.hpp"
#include <list>
#include <string>
#include <iostream>

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
bool modificarAlumno(std::string dni,alumno alumno){
  alumno=buscarAlumnos("",dni,0);
  int opcion;
  std::cout<<"¿Que parametro quieres modificar?"<<"\n";
  std::cout<<"1.Modificar dni"<<"\n"
  <<"2.Modificar nombre"<<"\n"
  <<"3.Modificar apellidos"<<"\n"
  <<"4.Modificar telefono"<<"\n"
  <<"5.Modificar email"<<"\n"
  <<"6.Modificar direccion"<<"\n"
  <<"7.Modificar fecha de nacimiento"<<"\n"
  <<"8.Modificar curso"<<"\n"
  <<"9.Modificar grupo"<<"\n"
  <<"10.Modificar si es lider o no"<<"\n";
  std::cin>>opcion;
  if(opcion==1){
    std::string dniaux;
    std::cout<<"Introduce el nuevo dni"<<"\n";
    std::cin>>dniaux;
    alumno.set_dni(dniaux);
    return true;
  }
  if(opcion==2){
    std::string nombreaux;
    std::cout<<"Introduce el nuevo nombre"<<"\n";
    std::cin>>nombreaux;
    alumno.set_nombre(nombreaux);
    return true;
  }
  if(opcion==3){
    std::string apellidosaux;
    std::cout<<"Introduce los nuevos apellidos"<<"\n";
    std::cin>>apellidosaux;
    alumno.set_apellidos(apellidosaux);
    return true;
  }
  if(opcion==4){
    std::string tlfaux;
    std::cout<<"Introduce el nuevo telefono"<<"\n";
    std::cin>>tlfaux;
    alumno.set_telefono(tlfaux);
    return true;
  }
  if(opcion==5){
    std::string emailaux;
    std::cout<<"Introduce el nuevo email"<<"\n";
    std::cin>>emailaux;
    alumno.set_email(emailaux);
    return true;
  }
  if(opcion==6){
    std::string direccionaux;
    std::cout<<"Introduce la nueva direccion"<<"\n";
    std::cin>>direccionaux;
    alumno.set_direccion(direccionaux);
    return true;
  }
  if(opcion==7){
    std::string fechaaux;
    std::cout<<"Introduce la nuevo fecha de nacimiento"<<"\n";
    std::cin>>fechaaux;
    alumno.set_fecha_nacimiento(fechaaux);
    return true;
  }
  if(opcion==8){
    unsigned cursoaux;
    std::cout<<"Introduce el nuevo curso"<<"\n";
    std::cin>>cursoaux;
    alumno.set_curso(cursoaux);
    return true;
  }
  if(opcion==9){
    unsigned grupoaux;
    std::cout<<"Introduce el nuevo grupo"<<"\n";
    std::cin>>grupoaux;
    alumno.set_grupo(grupoaux);
    return true;
  }
  if(opcion==10){
    bool es_lideraux;
    int opcionaux;
    std::cout<<"Introduce si es lider o no"<<"\n"<<"0.No es lider"<<"\n"<<"1.Es lider"<<"\n";
    std::cin>>opcionaux;
    if(opcionaux==0){es_lideraux=false;};
    if(opcionaux==1){es_lideraux=true;};
    alumno.set_es_lider(es_lideraux);
    return true;
  }

if(opcion<1 || opcion>10){return false;};

}
bool BaseDatos::eliminarAlumno(std::string dni){
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
