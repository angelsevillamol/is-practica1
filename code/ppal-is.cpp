/**
 * @file main.cpp
 * @brief Programa que permite la gestión de alumnos de una asignatura.
 * @date 11-12-2018
 *
 * Este fichero forma parte del proyecto realizado para la gestión de alumnos,
 * para la asignatura Ingeniería del Software de la Universidad de Córdoba.
 */


#include <iostream>
#include <string>
#include "is.hpp"

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

/**
 * @brief Imprime por pantalla el menu de opciones.
 * @param esCoordinador indica si el profesor actual es profesor coordinador.
 * @return opcion del programa escogida.
 */
unsigned escribirMenu(bool esCoordinador);

/**
 * @brief Muestra y realiza las funciones que permite el menú hasta que 
 *        el usuario salga del programa.
 * @param esCoordinador indica si el profesor actual es profesor coordinador.
 */
void ejecutarMenu(bool esCoordinador);

int main(void)
{
    bool esCoordinador = true;

    ejecutarMenu(esCoordinador);
	exit(EXIT_SUCCESS);	
}

// Imprime por pantalla el menu de opciones.
unsigned escribirMenu(bool esCoordinador) 
{
    unsigned option;

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

// Muestra y realiza las funciones que permite el menú hasta que el usuario 
// salga del programa.
void ejecutarMenu(bool esCoordinador)
{
    unsigned option;

    do {
        switch(option = escribirMenu(esCoordinador)) {
            case ADD_ALUMNO:
                break;

            case MODIFICAR:
                break;

            case BORRAR:
                break;

            case MOSTRAR:
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
}
