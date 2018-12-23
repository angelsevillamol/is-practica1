/**
 * @file main.cpp
 * @brief Programa que permite la gestión de prof.getBaseDatos() de una asignatura.
 * @date 11-12-2018
 *
 * Este fichero forma parte del proyecto realizado para la gestión de prof.getBaseDatos(),
 * para la asignatura Ingeniería del Software de la Universidad de Córdoba.
 */

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "is.hpp"

#define MAX_ALUMNOS 150
#define FILE_CREDENCIALES "../data/credenciales.bin"
#define FILE_BBDD_LOCAL "../data/localdata.bin"

enum MENU_OPTS
{
    ADD_ALUMNO = 1,
    MODIFICAR = 2,
    BORRAR = 3,
    MOSTRAR = 4,
    GUARDAR = 5,
    CARGAR = 6,
    GUARDAR_COPIA = 7,
    CARGAR_COPIA = 8,
    ADD_PROFESOR = 9,
    SALIR = 0
};


// Funciones auxiliares de comparación para la ordenación.
bool compararDni(const alumno &a, const alumno &b) { return a.getDni() < b.getDni(); }
bool compararApellidos(const alumno &a, const alumno &b) { return a.getApellidos() < b.getApellidos(); }
bool compararCurso(const alumno &a, const alumno &b) { return a.getCurso() < b.getCurso(); }

void pulseEnter();
bool acceder(profesor &prof);
bool registrar(const profesor &prof);
unsigned escribirMenu(bool esCoordinador);
void obtenerAlumno(alumno &a);
void mostrarAlumnoTerminal(const alumno &a);
unsigned getCriteriosBusqueda(unsigned numeroAlumnos, std::string dni, 
    std::string apellidos, unsigned grupo, bool asc, unsigned criterio, 
    bool formato_md);
void setCriteriosBusqueda(unsigned option, std::string &dni, std::string &apellidos, 
    unsigned &grupo, bool &asc, unsigned &criterio, bool &formato_md);
void ordenarAlumnos(std::list<alumno> &alumnos, unsigned criterio, bool asc);
void mostrarAlumnosMarkdown(const std::list<alumno> &alumnos);
void mostrarAlumnosHTML(const std::list<alumno> &alumnos);
void listarAlumnos(const profesor &prof);

int main(void)
{
    profesor prof;
    bool b;
    alumno alumnoAux;
    std::string stringAux;
    std::list<alumno> resultado;
    unsigned option;

    // Inicio de sesión del usuario.
    do {
        b = acceder(prof);
        if (not b) {
            std::cout << "Datos erróneos. Por favor, inténtelo otra vez. ";
            pulseEnter();
        }
    } while (not b);

    do {
        switch(option = escribirMenu(prof.getEsCoordinador())) {
            case ADD_ALUMNO:
                if (prof.getBaseDatos().getNumeroAlumnos() >= MAX_ALUMNOS) {
                    std::cout << "El número máximo de alumnos ha sido alcanzado. ";
                }
                else {
                    obtenerAlumno(alumnoAux);
                    if (prof.getBaseDatos().anadirAlumno(alumnoAux) == true) {
                        std::cout << "Alumno añadido correctamente. ";
                    }
                    else {
                        std::cout << "Ha ocurrido algún problema durante la inserción. ";
                    }
                }
                pulseEnter();
                break;

            case MODIFICAR:
                if (prof.getBaseDatos().getNumeroAlumnos() == 0) {
                    std::cout << "La lista de alumnos está vacía. ";
                    pulseEnter();
                }
                break;

            case BORRAR:
                if (prof.getBaseDatos().getNumeroAlumnos() == 0) {
                    std::cout << "La lista de alumnos está vacía. ";
                }
                else {
                    std::system("clear");
                    std::cout << "BORRAR ALUMNO: " << std::endl;
                    std::cout << "\tDNI del alumno a eliminar: ";
                    std::cin >> stringAux;

                    b = prof.getBaseDatos().getAlumno(stringAux, alumnoAux);
                    if (b == true) {
                        std::cout << "El alumno seleccionado es el siguiente:" << std::endl;
                        mostrarAlumnoTerminal(alumnoAux);
                        std::cout << "¿Desea eliminarlo de la base de datos? (S/N): ";
                        std::cin >> stringAux;
                        if (stringAux == "S" or stringAux == "s") {
                            prof.getBaseDatos().eliminarAlumno(alumnoAux.getDni());
                            std::cout << "Alumno eliminado correctamente. ";
                        }
                    }
                    else {
                        std::cout << "No se ha encontrado al alumno. ";
                    }
                }
                pulseEnter();
                break;

            case MOSTRAR:
                listarAlumnos(prof);
                pulseEnter();
                break;

            case GUARDAR:
                prof.getBaseDatos().guardarFichero(FILE_BBDD_LOCAL);
                std::cout << "Cambios guardados correctamente. ";
                pulseEnter();
                break;

            case CARGAR:
                prof.getBaseDatos().cargarFichero(FILE_BBDD_LOCAL);
                std::cout << "Datos cargados correctamente. ";
                pulseEnter();
                break;

            case GUARDAR_COPIA:
                if (prof.getEsCoordinador()) {
                    std::cout << "Indique el nombre de la copia de seguridad: ";
                    std::cin >> stringAux;
                    prof.getBaseDatos().guardarFichero("../data/" + stringAux + ".bin");
                    std::cout << "Copia de seguridad guardada correctamente. ";
                    pulseEnter();
                }
                break;

            case CARGAR_COPIA:
                if (prof.getEsCoordinador()) {
                    std::cout << "Indique el nombre de la copia de seguridad: ";
                    std::cin >> stringAux;
                    prof.getBaseDatos().cargarFichero("../data/" + stringAux + ".bin");
                    std::cout << "Datos cargados correctamente. ";
                    pulseEnter();
                }
                break;

            case ADD_PROFESOR:
                if (prof.getEsCoordinador()) {
                    b = registrar(prof);
                    if (not b) {
                        std::cout << "Error al añadir el nuevo usuario. Puede que ya exista. ";
                    }
                    else {
                        std::cout << "Usuario añadido correctamente. ";
                    }
                    pulseEnter();
                }
                break;

            case SALIR:
                break;
        }
    } while (option != SALIR); 

	exit(EXIT_SUCCESS);	
}

void pulseEnter() 
{
    std::cout << "Pulse ENTER para continuar. ";
    std::cin.ignore();
    std::cin.ignore();
}

bool acceder(profesor &prof) 
{
    std::string usuario;
    std::string password;

    std::system("clear");
    std::cout << "ACCEDER:" << std::endl;

    std::cout << "\tNombre de usuario: ";
    std::cin >> usuario;

    std::cout << "\tContraseña: ";
    std::cin >> password;

    return prof.iniciarSesion(FILE_CREDENCIALES, usuario, password);
}

bool registrar(const profesor &prof)
{
    std::string usuario;
    std::string password;

    std::system("clear");
    std::cout << "REGISTRAR USUARIO:" << std::endl;

    std::cout << "\tNombre de usuario: ";
    std::cin >> usuario;

    std::cout << "\tContraseña: ";
    std::cin >> password;

    return prof.anadirProfesor(FILE_CREDENCIALES, usuario, password);
}

// Imprime por pantalla el menu de opciones.
unsigned escribirMenu(bool esCoordinador) 
{
    unsigned option;

    std::system("clear");
    std::cout << "MENÚ DE OPCIONES:" << std::endl;
    std::cout << "\t1. Añadir alumno." << std::endl;
    std::cout << "\t2. Modificar alumno." << std::endl;
    std::cout << "\t3. Eliminar alumno." << std::endl;
    std::cout << "\t4. Mostrar alumno." << std::endl;
    std::cout << "\t5. Guardar cambios." << std::endl;
    std::cout << "\t6. Cargar cambios." << std::endl;

    // Opciones reservadas a los profesores coordinadores.
    if (esCoordinador) {
        std::cout << "\t7. Guardar copia de seguridad." << std::endl;
        std::cout << "\t8. Cargar copia de seguridad." << std::endl;
        std::cout << "\t9. Añadir profesor colaborador." << std::endl;
    }
    std::cout << "\t0. Salir del programa." << std::endl;

    // Se pide la opción al usuario.
    std::cout << "Seleccione opción: ";
    std::cin >> option;

    return option;
}

void obtenerAlumno(alumno &a)
{
    std::string aux;

    std::system("clear");
    std::cout << "AÑADIR ALUMNO: " << std::endl;

    std::cout << "\tDNI: ";
    std::cin >> aux;
    a.setDni(aux);

    std::cout << "\tNombre: ";
    std::cin >> aux;
    a.setNombre(aux);

    std::cout << "\tApellidos: ";
    std::cin.ignore();
    std::getline(std::cin, aux);
    a.setApellidos(aux);

    std::cout << "\tTelefono: ";
    std::cin >> aux;
    a.setTelefono(aux);

    std::cout << "\te-mail: ";
    std::cin >> aux;
    a.setEmail(aux);

    std::cout << "\tDirección postal: ";
    std::cin >> aux;
    a.setDireccion(aux);

    std::cout << "\tFecha de nacimiento (dd/mm/aaaa): ";
    std::cin >> aux;
    a.setFechaNacimiento(aux);

    std::cout << "\tCurso más alto matriculado: ";
    std::cin >> aux;
    a.setCurso(atoi(aux.c_str()));

    std::cout << "\tGrupo: ";
    std::cin >> aux;
    a.setGrupo(atoi(aux.c_str()));

    if (a.getGrupo() != 0) {
        std::cout << "\t¿Es líder del grupo? (S/N): ";
        std::cin >> aux;
        a.setEsLider(aux == "S" or aux == "s"? true : false);
    }
}

void mostrarAlumnoTerminal(const alumno &a) 
{
    std::cout << "\tDNI: " << a.getDni() << std::endl;
    std::cout << "\tNombre: " << a.getNombre() << std::endl;
    std::cout << "\tApellidos: " << a.getApellidos() << std::endl;
    std::cout << "\tTelefono: " << a.getTelefono() << std::endl;
    std::cout << "\te-mail: " << a.getEmail() << std::endl;
    std::cout << "\tDirección postal: " << a.getDireccion() << std::endl;
    std::cout << "\tFecha de nacimiento: " << a.getFechaNacimiento() << std::endl;
    std::cout << "\tCurso más alto matriculado: " << a.getCurso() << std::endl;
    std::cout << "\tGrupo: " << a.getGrupo() << std::endl;
    std::cout << "\tLider del Grupo: " << (a.getEsLider()? "Si" : "No") << std::endl;
}

unsigned getCriteriosBusqueda(unsigned numeroAlumnos, std::string dni, 
    std::string apellidos, unsigned grupo, bool asc, unsigned criterio, 
    bool formato_md)
{
    unsigned option;

    std::system("clear");
    std::cout << "MOSTRAR ALUMNOS: " << std::endl;
    std::cout << numeroAlumnos << " resultados coincidentes." << std::endl;
    std::cout << "\t1. DNI: " << dni << std::endl;
    std::cout << "\t2. Apellidos: " << apellidos << std::endl;
    std::cout << "\t3. Grupo: " << grupo << std::endl;
    std::cout << "\t4. Orden: " << (asc? "ascendente" : "descendente") << std::endl;

    std::cout << "\t5. Criterio de orden: ";
    switch (criterio) {
        case 0: 
            std::cout << "por orden de inserción." << std::endl;
            break;

        case 1:
            std::cout << "por dni." << std::endl;
            break;
        
        case 2:
            std::cout << "por apellidos." << std::endl;
            break;

        case 3:
            std::cout << "por curso." << std::endl;
            break;

        default:
            std::cout << "error." << std::endl;
            break;
    }

    std::cout << "\t6. Formato: " << (formato_md? ".md" : ".html") << std::endl;
    std::cout << "\t0. Salir." << std::endl;

    std::cout << "Seleccione opción: ";
    std::cin >> option;

    return option;
}


void setCriteriosBusqueda(unsigned option, std::string &dni, std::string &apellidos, 
    unsigned &grupo, bool &asc, unsigned &criterio, bool &formato_md)
{
    unsigned aux;

    switch (option) {
        case 1:
            std::cout << "DNI: ";
            std::cin >> dni;
            std::cout << "Campo modificado. ";
            pulseEnter();
            break;
            
        case 2:
            std::cout << "Apellidos: ";
            std::getline(std::cin, apellidos);
            std::cout << "Campo modificado. ";
            pulseEnter();
            break;
            
        case 3:
            std::cout << "Grupo: ";
            std::cin >> grupo;
            std::cout << "Campo modificado. ";
            pulseEnter();
            break;

        case 4:
            asc = not asc;
            std::cout << "Campo modificado. ";
            pulseEnter();
            break;

        case 5:
            std::cout << "Posibles criterios: " << std::endl;
            std::cout << "\t1. por orden de inserción." << std::endl;
            std::cout << "\t2. por dni." << std::endl;
            std::cout << "\t3. por apellidos." << std::endl;
            std::cout << "\t4. por curso." << std::endl;
            std::cout << "Criterio de orden: ";
            std::cin >> aux;
            if (aux > 0 and aux < 5) {
                std::cout << "Campo modificado. ";
                criterio = aux;
            }
            else {
                std::cout << "Valor incorrecto. ";
            }
            pulseEnter();
            break;

         case 6:
            formato_md = not formato_md;
            std::cout << "Campo modificado. ";
            pulseEnter();
            break;
    }
}

void ordenarAlumnos(std::list<alumno> &alumnos, unsigned criterio, bool asc)
{
    switch (criterio) {
        case 2:
            alumnos.sort(compararDni);
            break;

        case 3:
            alumnos.sort(compararApellidos);
            break;

        case 4:
            alumnos.sort(compararCurso);
            break;
    }

    if (not asc) {
        alumnos.reverse();
    }
}

void mostrarAlumnosMarkdown(const std::list<alumno> &alumnos)
{
    std::list<alumno>::const_iterator iter;
    std::ofstream outfile("../output.md");

    if (outfile.is_open()) {

        outfile << "**LISTA DE ALUMNOS**" << std::endl << std::endl;
        outfile << "---" << std::endl << std::endl;

        for (iter = alumnos.begin(); iter != alumnos.end(); iter++) {
            if (iter->getEsLider()) {
                outfile << "* **Nombre: " << iter->getApellidos() << ", " << iter->getNombre() << "**" << std::endl;
            } else {
                outfile << "* Nombre: " << iter->getApellidos() << ", " << iter->getNombre() << std::endl;
            }
            outfile << "* DNI: " << iter->getDni() << std::endl;
            outfile << "* Telefono: " << iter->getTelefono() << std::endl;
            outfile << "* e-mail: " << iter->getEmail() << std::endl;
            outfile << "* Direccion: " << iter->getDireccion() << std::endl;
            outfile << "* Fecha de nacimiento: " << iter->getFechaNacimiento() << std::endl;
            outfile << "* Curso mas alto matriculado: " << iter->getCurso() << std::endl;
            outfile << "* Grupo: " << iter->getGrupo() << std::endl;
            outfile << "* Lider del grupo: " << (iter->getEsLider()? "Si" : "No") << std::endl;
            outfile << "---" << std::endl;
        }

        outfile.close();
    }
}

void mostrarAlumnosHTML(const std::list<alumno> &alumnos)
{
    std::list<alumno>::const_iterator iter;
    std::ofstream outfile("../output.html");

    if (outfile.is_open()) {
        // Se imprime la cabecera.
        outfile << "<!DOCTYPE html>" << std::endl;
        outfile << "<html>" << std::endl;
        outfile << "<body>" << std::endl << std::endl;
        outfile << "<h1>LISTA DE ALUMNOS</h1>" << std::endl << std::endl;

        for (iter = alumnos.begin(); iter != alumnos.end(); iter++) {
            outfile << "<ul>" << std::endl;
            if (iter->getEsLider()) {
                outfile << "<li><b>Nombre: " << iter->getApellidos() << ", " << iter->getNombre() << "</b></li>" << std::endl;
            } else {
                outfile << "<li>Nombre: " << iter->getApellidos() << ", " << iter->getNombre() << "</li>" << std::endl;
            }
            outfile << "<li>DNI: " << iter->getDni() << "</li>" << std::endl;
            outfile << "<li>Telefono: " << iter->getTelefono() << "</li>" << std::endl;
            outfile << "<li>e-mail: " << iter->getEmail() << "</li>" << std::endl;
            outfile << "<li>Direccion: " << iter->getDireccion() << "</li>" << std::endl;
            outfile << "<li>Fecha de nacimiento: " << iter->getFechaNacimiento() << "</li>" << std::endl;
            outfile << "<li>Curso mas alto matriculado: " << iter->getCurso() << "</li>" << std::endl;
            outfile << "<li>Grupo: " << iter->getGrupo() << "</li>" << std::endl;
            outfile << "<li>Lider del grupo: " << (iter->getEsLider()? "Si" : "No") << "</li>" << std::endl;
            outfile << "</ul>" << std::endl << std::endl;
        }

        outfile << "</body>" << std::endl;
        outfile << "</html>" << std::endl;

        outfile.close();
    }
}

void listarAlumnos(const profesor &prof) 
{
    std::string dni;
    std::string apellidos;
    unsigned grupo = 0;
    unsigned criterio = 0;
    bool asc = true;
    bool formato_md = true;
    unsigned option;
    std::list<alumno> resultado;

    do {
        // Se selecciona el criterio de búsqueda a modificar.
        option = getCriteriosBusqueda(prof.getBaseDatos().getNumeroAlumnos(), 
            dni, apellidos, grupo, asc, criterio, formato_md);
        
        // Se modifica dicho criterio de búsqueda.
        setCriteriosBusqueda(option, dni, apellidos, grupo, asc, criterio, formato_md);

        // Se buscan los alumnos con los criterios actualizados.
        prof.getBaseDatos().buscarAlumnos(resultado, apellidos, dni, grupo);

        // Se ordena el resultado.
        ordenarAlumnos(resultado, criterio, asc);

        // Se muestran en el formato seleccionado.
        if (formato_md) {
            mostrarAlumnosMarkdown(resultado);
        }
        else {
            mostrarAlumnosHTML(resultado);
        }
        
    } while (option != 0);
}
