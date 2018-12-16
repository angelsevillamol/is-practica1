/**
 * @file main.cpp
 * @brief Programa que permite la gestión de alumnos de una asignatura.
 * @date 11-12-2018
 *
 * Este fichero forma parte del proyecto realizado para la gestión de alumnos,
 * para la asignatura Ingeniería del Software de la Universidad de Córdoba.
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include "is.hpp"

#define MAX_ALUMNOS 150
#define FILE_CREDENCIALES "credenciales.bin"
#define FILE_BBDD_LOCAL "localdata.bin"

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

unsigned escribirMenu(bool esCoordinador);
void obtenerAlumno(alumno &a);
void mostrarAlumno(const alumno &a);
void mostrarAlumnos(std::list<alumno> &listaAlumnos);

int main(void)
{
    alumno alumnoAux;
    std::string nombreFichero;
    std::list<alumno> resultado;
    baseDatos alumnos;
    unsigned option;

    do {
        switch(option = escribirMenu(false)) {
            case ADD_ALUMNO:
                if (alumnos.getNumeroAlumnos() >= MAX_ALUMNOS) {
                    std::cout << "El número máximo de alumnos ha sido alcanzado. "
                              << "Pulse ENTER para continuar. ";
                    std::cin.ignore();
                    std::cin.ignore();
                }
                else {
                    obtenerAlumno(alumnoAux);
                    if (alumnos.anadirAlumno(alumnoAux) == true) {
                        std::cout << "Alumno añadido correctamente. "
                                  << "Pulse ENTER para continuar. ";
                        std::cin.ignore();
                        std::cin.ignore();
                    }
                    else {
                        std::cout << "Ha ocurrido algún problema durante la inserción. "
                                  << "Pulse ENTER para continuar. ";
                        std::cin.ignore();
                        std::cin.ignore();
                    }
                }
                break;

            case MODIFICAR:
                if (alumnos.getNumeroAlumnos() == 0) {
                    std::cout << "El número máximo de alumnos ha sido alcanzado. Pulse ENTER para continuar. ";
                    std::cin.ignore();
                    std::cin.ignore(); 
                }
                break;

            case BORRAR:
                break;

            case MOSTRAR:
                resultado.clear();
                alumnos.buscarAlumnos(resultado, "", "", 0);
                mostrarAlumnos(resultado);
                std::cout << alumnos.getNumeroAlumnos() << " resultados coincidentes. "
                          << "Pulse Enter para continuar. ";
                std::cin.ignore();
                std::cin.ignore();
                break;

            case GUARDAR:
                alumnos.guardarFichero(FILE_BBDD_LOCAL);
                std::cout << "Cambios guardados correctamente. "
                          << "Pulse ENTER para continuar. ";
                std::cin.ignore();
                std::cin.ignore();
                break;

            case CARGAR:
                alumnos.cargarFichero(FILE_BBDD_LOCAL);
                std::cout << "Datos cargados correctamente. "
                          << "Pulse ENTER para continuar. ";
                std::cin.ignore();
                std::cin.ignore();
                break;

            case GUARDAR_COPIA:
                std::cout << "Indique el nombre de la copia de seguridad: ";
                std::cin >> nombreFichero;
                alumnos.guardarFichero(nombreFichero);
                std::cout << "Copia de seguridad guardada correctamente. "
                          << "Pulse ENTER para continuar. ";
                std::cin.ignore();
                std::cin.ignore();
                break;

            case CARGAR_COPIA:
                std::cout << "Indique el nombre de la copia de seguridad: ";
                std::cin >> nombreFichero;
                alumnos.cargarFichero(nombreFichero);
                std::cout << "Datos cargados correctamente. "
                          << "Pulse ENTER para continuar. ";
                std::cin.ignore();
                std::cin.ignore();
                break;

            case ADD_PROFESOR:
                break;

            case SALIR:
                break;
        }
    } while (option != SALIR); 

	exit(EXIT_SUCCESS);	
}

// Imprime por pantalla el menu de opciones.
unsigned escribirMenu(bool esCoordinador) 
{
    unsigned option;

    std::system("clear");
    std::cout << "Menú de opciones:" << std::endl;
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
    std::cin >> aux;
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

    std::cout << "\t¿Es líder del grupo? (S/N): ";
    std::cin >> aux;
    a.setEsLider(aux == "S" or aux == "s"? true : false);
}

void mostrarAlumno(const alumno &a) {
    std::cout << "\tDNI: " << a.getDni() << std::endl;
    std::cout << "\tNombre: " << a.getNombre() << std::endl;
    std::cout << "\tApellidos: " << a.getApellidos() << std::endl;
    std::cout << "\tTelefono: " << a.getTelefono() << std::endl;
    std::cout << "\te-mail: " << a.getEmail() << std::endl;
    std::cout << "\tDirección postal: " << a.getDireccion() << std::endl;
    std::cout << "\tFecha de nacimiento: " << a.getFechaNacimiento() << std::endl;
    std::cout << "\tCurso más alto matriculado: " << a.getCurso() << std::endl;
    std::cout << "\tGrupo: " << a.getGrupo() << std::endl;
    std::cout << "\tLider del Grupo: " << (a.getEsLider()? "TRUE" : "FALSE") << std::endl;
}

void mostrarAlumnos(std::list<alumno> &listaAlumnos) {
    std::list<alumno>::iterator iter;

    std::cout << "MOSTRAR ALUMNOS:" << std::endl;
    for (iter = listaAlumnos.begin(); iter != listaAlumnos.end(); iter++) {
        mostrarAlumno(*iter);
        std::cout << std::endl;
    }
}