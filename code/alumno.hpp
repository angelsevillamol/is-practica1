/**
 * @file alumno.hpp
 * @brief Declaración de la clase Alumno.
 * @date 27-11-2018
 *
 * Este fichero forma parte del proyecto realizado para la gestión de alumnos,
 * para la asignatura Ingeniería del Software de la Universidad de Córdoba.
 */

#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <string>

/**
 * @brief Almacena la información de un alumno de la Universidad de Córdoba.
 */
class alumno {
  public:

    alumno(std::string dni, std::string nombre, std::string apellidos, 
           std::string telefono, std::string email, std::string direccion, 
           std::string fecha_nacimiento, unsigned curso, unsigned grupo = 0, 
           bool es_lider = false);
    std::string get_dni() const { return dni_; }
    std::string get_nombre() const { return nombre_; }
    std::string get_apellidos() const { return apellidos_; }
    std::string get_telefono() const { return telefono_; }
    std::string get_email() const { return email_; }
    std::string get_direccion() const { return direccion_; }
    std::string get_fecha_nacimiento() const { return fecha_nacimiento_; }
    unsigned get_curso() const { return curso_; }
    unsigned get_grupo() const { return grupo_; }
    bool get_es_lider() const { return es_lider_; }
    void set_dni(std::string dni) { dni_ = dni; }
    void set_nombre(std::string nombre) { nombre_ = nombre; }
    void set_apellidos(std::string apellidos) { apellidos_ = apellidos; }
    void set_telefono(std::string telefono) { telefono_ = telefono; }
    void set_email(std::string email) { email_ = email; }
    void set_direccion(std::string direccion) { direccion_ = direccion; }
    void set_fecha_nacimiento(std::string fecha_nacimiento) { fecha_nacimiento_ = fecha_nacimiento; }
    void set_curso(unsigned curso) { curso_ = curso; }
    void set_grupo(unsigned grupo) { grupo_ = grupo; }
    void set_es_lider(bool es_lider) { es_lider_ = es_lider; }

  private:
    std::string dni_; //!< DNI del alumno.
    std::string nombre_; //!< Nombre del alumno.
    std::string apellidos_; //!< Ambos apellidos del alumno.
    std::string telefono_; //!< Teléfono de contacto.
    std::string email_; //!< Dirección de correo electrónico.
    std::string direccion_; //!< Dirección postal.
    std::string fecha_nacimiento_; //!< Fecha de nacimiento.
    unsigned curso_; //!< Curso mas alto matriculado.
    unsigned grupo_; //!< Numero de grupo de`practicas.
    bool es_lider_; //!< Determina si es lider o no del grupo.
}; // class alumno.

#endif // ALUMNO_HPP
