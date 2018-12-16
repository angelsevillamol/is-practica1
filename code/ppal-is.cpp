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

int main(void)
{
    alumno alumnoAux;
    baseDatos alumnos;
    unsigned option;

    do {
        switch(option = escribirMenu(false)) {
            case ADD_ALUMNO:
                if (alumnos.getNumeroAlumnos() >= MAX_ALUMNOS) {
                    std::cout << "El número máximo de alumnos ha sido alcanzado. Pulse ENTER para continuar. ";
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
                break;

            case BORRAR:
                break;

            case MOSTRAR:
                std::cout << alumnos.getNumeroAlumnos() << " resultados coincidentes. "
                          << "Pulse Enter para continuar. ";
                std::cin.ignore();
                std::cin.ignore();
                break;

            case GUARDAR:
                break;

            case CARGAR:
                break;

            case GUARDAR_COPIA:
                break;

            case CARGAR_COPIA:
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

    std::cout << "DNI: ";
    std::cin >> aux;
    a.setDni(aux);

    std::cout << "Nombre: ";
    std::cin >> aux;
    a.setNombre(aux);

    std::cout << "Apellidos: ";
    std::cin >> aux;
    a.setApellidos(aux);

    std::cout << "Telefono: ";
    std::cin >> aux;
    a.setTelefono(aux);

    std::cout << "e-mail: ";
    std::cin >> aux;
    a.setEmail(aux);

    std::cout << "Dirección postal: ";
    std::cin >> aux;
    a.setDireccion(aux);

    std::cout << "Fecha de nacimiento: ";
    std::cin >> aux;
    a.setFechaNacimiento(aux);

    std::cout << "Curso más alto matriculado: ";
    std::cin >> aux;
    a.setCurso(atoi(aux.c_str()));

    std::cout << "Grupo: ";
    std::cin >> aux;
    a.setGrupo(atoi(aux.c_str()));

    std::cout << "¿Es líder del grupo? (S/N): ";
    std::cin >> aux;
    a.setEsLider(aux == "S" or aux == "s"? true : false);
}

