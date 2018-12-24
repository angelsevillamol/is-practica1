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

bool existeProfesor(std::string nombreFichero, std::string usuario)
{
    std::ifstream infile(nombreFichero, std::ios::in | std::ios::binary);
    std::string aux;
    unsigned len;
    bool existe = false;

    if (infile.is_open()) {
        // Lee el fichero hasta el final o hasta encontrar coincidencia.
        while (infile.read(reinterpret_cast<char *>(&len), sizeof(unsigned)) and not existe) {
            aux.resize(len);
            infile.read(&aux[0], aux.size());

            // Si el profesor existe, lo señala para terminar la ejecución.
            existe = (aux == usuario);

            // Lee la contraseña para continuar por el siguiente profesor.
            infile.read(reinterpret_cast<char *>(&len), sizeof(unsigned));
            aux.resize(len);
            infile.read(&aux[0], aux.size()); 
        }

        infile.close();
    }

    return existe;
}

profesor::profesor()
{
    nombreUsuario_ = "";
    esCoordinador_ = false;
}

bool profesor::iniciarSesion(std::string nombreFichero, std::string usuario, 
    std::string password)
{
    bool esCoordinador = true;
    bool encontrado = false;
    std::ifstream infile(nombreFichero, std::ios::in | std::ios::binary);
    std::string nombreProfesor, contrProfesor;
    unsigned len;

    if (infile.is_open()) {
        while (infile.read(reinterpret_cast<char *>(&len), sizeof(unsigned)) and not encontrado) {
            nombreProfesor.resize(len);
            infile.read(&nombreProfesor[0], nombreProfesor.size());

            // Lectura del nombre.
            infile.read(reinterpret_cast<char *>(&len), sizeof(unsigned));
            contrProfesor.resize(len);
            infile.read(&contrProfesor[0], contrProfesor.size());         

            // Si el profesor se ha encontrado, lo señala para terminar la ejecución.
            if ((usuario == nombreProfesor) and (password == contrProfesor)) {
                encontrado = true;
                nombreUsuario_ = nombreProfesor;
                esCoordinador_ = esCoordinador;
            }

            // El primer profesor del registro es el coordinador.
            esCoordinador = false;
        }

        infile.close();
    }

    return encontrado;
}

void profesor::cerrarSesion() 
{
    nombreUsuario_ = "";
    esCoordinador_ = "";
    bbdd_.borrarAlumnos();
}

bool profesor::anadirProfesor(std::string nombreFichero, std::string usuario, 
    std::string password) const
{
    // Si el profesor no es coordinador no puede registrar otros profesores.
    // También impide crear dos profesores con el mismo nombre de usuario.
    if (not getEsCoordinador() or existeProfesor(nombreFichero, usuario)) {
        return false;
    }

    std::ofstream outfile(nombreFichero, std::ios::app | std::ios::binary);
    unsigned len;

    if (outfile.is_open()) {
        // Escritura del nombre.
        len = usuario.length();
        outfile.write(reinterpret_cast<char *>(&len), sizeof(unsigned));
        outfile.write(usuario.c_str(), len);

        // Escritura de la contraseña.
        len = password.length(); 
        outfile.write(reinterpret_cast<char *>(&len), sizeof(unsigned));
        outfile.write(password.c_str(), len);

        outfile.close();
        return true;
    }
    else {
        return false;
    }
}
