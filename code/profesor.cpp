/**
 * @file profesor.hpp
 * @brief Implementación de los métodos de la clase profesor.
 * @date 27-11-2018
 *
 * Este fichero forma parte del proyecto realizado para la gestión de alumnos,
 * para la asignatura Ingeniería del Software de la Universidad de Córdoba.
 */

#include <fstream>
#include <string>
#include "alumno.hpp"
#include "basedatos.hpp"
#include "profesor.hpp"

profesor::profesor()
{
    nombreUsuario_ = "";
    esCoordinador_ = false;
}

bool profesor::iniciarSesion(std::string nombreFichero, std::string usuario, 
    std::string password)
{
    bool esCoordinador = true;
    std::ifstream infile(nombreFichero, std::ios::binary);
    std::string nombreProfesor, contrProfesor;

    if (infile.is_open()) {
        while (!infile.eof()) {
            getline(infile, nombreProfesor, ',');
            getline(infile, contrProfesor);

            if ((usuario == nombreProfesor) and (password == contrProfesor)) {
                nombreUsuario_ = usuario;
                esCoordinador_ = esCoordinador;
                infile.close();
                return true;
            }

            esCoordinador = false;
        }

        infile.close();
    }

    return false;
}

void profesor::cerrarSesion() {
    nombreUsuario_ = "";
    esCoordinador_ = "";
    bbdd_.borrarAlumnos();
}

bool profesor::anadirProfesor(std::string nombreFichero, std::string usuario, 
    std::string password)
{
    if (not getEsCoordinador()) {
        return false;
    }

    std::ofstream outfile(nombreFichero, std::ios::binary);
    outfile << usuario + ", " + password;

    outfile.close();
    return true;
}
