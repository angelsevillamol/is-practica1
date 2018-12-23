/**
 * @file alumno.hpp
 * @brief Declaración de la clase alumno.
 * @date 27-11-2018
 *
 * Este fichero forma parte del proyecto realizado para la gestión de alumnos,
 * para la asignatura Ingeniería del Software de la Universidad de Córdoba.
 */

#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <string>
#include <assert.h>
#include <ctype.h>

/**
 * @brief Almacena la información de un alumno de la Universidad de Córdoba.
 */
class alumno {
  public:
    alumno();
    alumno(std::string dni, std::string nombre, std::string apellidos,
           std::string telefono, std::string email, std::string direccion,
           std::string fecha_nacimiento, unsigned curso, unsigned grupo = 0,
           bool esLider = false);
    std::string getDni() const { return dni_; }
    std::string getNombre() const { return nombre_; }
    std::string getApellidos() const { return apellidos_; }
    std::string getTelefono() const { return telefono_; }
    std::string getEmail() const { return email_; }
    std::string getDireccion() const { return direccion_; }
    std::string getFechaNacimiento() const { return fechaNacimiento_; }
    unsigned getCurso() const { return curso_; }
    unsigned getGrupo() const { return grupo_; }
    bool getEsLider() const { return esLider_; }
    void setDni(std::string dni) { dni_ = dni;
                                   assert(dni_.length() == 9);
                                   for(int i=0 ; i<8 ; i++){
                                   assert(std::isdigit(dni_[i]));}
                                   assert(std::isalpha(dni_[8]));}
    void setNombre(std::string nombre) { nombre_ = nombre;
                                         for(int i=0 ; i<nombre_.length() ; i++){
                                         assert(std::isalpha(nombre_[i]));} }
    void setApellidos(std::string apellidos) { apellidos_ = apellidos;
                                               for(int i=0 ; i<apellidos_.length() ; i++){
                                               assert(std::isalpha(apellidos_[i]));} }
    void setTelefono(std::string telefono) { telefono_ = telefono;
                                             assert(telefono_.length() == 9);
                                             for(int i=0 ; i<9 ; i++){
                                             assert(std::isdigit(telefono_[i]));}}
    void setEmail(std::string email) { email_ = email; }
    void setDireccion(std::string direccion) { direccion_ = direccion; }
    void setFechaNacimiento(std::string fecha_nacimiento) { fechaNacimiento_ = fecha_nacimiento;
                                                           assert(isdigit(fechaNacimiento_[0,1,3,4,6,7,8,9]));
                                                           assert(fechaNacimiento_[2]=='/');
                                                           assert(fechaNacimiento_[5]=='/');}
    void setCurso(unsigned curso) { curso_ = curso;
                                    assert(curso_<=4);}
    void setGrupo(unsigned grupo) { grupo_ = grupo; }
    void setEsLider(bool esLider) { esLider_ = esLider; }

  private:
    std::string dni_; //!< DNI del alumno.
    std::string nombre_; //!< Nombre del alumno.
    std::string apellidos_; //!< Ambos apellidos del alumno.
    std::string telefono_; //!< Teléfono de contacto.
    std::string email_; //!< Dirección de correo electrónico.
    std::string direccion_; //!< Dirección postal.
    std::string fechaNacimiento_; //!< Fecha de nacimiento.
    unsigned curso_; //!< Curso mas alto matriculado.
    unsigned grupo_; //!< Numero de grupo de`practicas.
    bool esLider_; //!< Determina si es lider o no del grupo.
}; // class alumno.

#endif // ALUMNO_HPP
