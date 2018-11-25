# Análisis de requisitos

## Actores

**Profesor:** El profesor es el único actor del sistema, y es el que gestiona y opera con los datos de los alumnos. El profesor puede ser coordinador o ayudante.

## Datos

El sistema debe permitir un registro histórico de alumnos que gestione la siguiente información: dni, nombre, apellidos, teléfono, e-mail, dirección postal, curso más alto matriculado, fecha de nacimiento, número de equipo, y si es líder o no del equipo.

## Requisitos

### Requisitos funcionales

Los requisitos funcionales son características que debe cumplir el sistema y que expresan la funcionalidad y/o el comportamiento específico que debe tener el sistema ante determinadas situaciones. Estos se codifican con las siglas *RF*, seguidas de un guión y del número de requisito.

* **RF-1:** El sistema permite que el profesor pueda añadir alumnos en la base de datos.
    * **RF-1.1:** Todos los datos son obligatorios excepto el número de grupo y liderazgo.
* **RF-2:** El sistema permite que el profesor pueda modificar la información de los alumnos ya registrados en la base de datos.
* **RF-3:** El sistema permite que el profesor pueda eliminar alumnos de la base de datos.
* **RF-4:** El sistema permite que el profesor pueda buscar alumnos.
	* **RF-4.1:** La búsqueda de alumnos debe poder filtrarse a partir del dni, de los apellidos o del equipo al que pertenece.
	* **RF-4.2:** La búsqueda debe devolver todas las coincidencias obtenidas.
* **RF-5:** El sistema permite que el profesor pueda acceder a la información de uno o varios alumnos.
	* **RF-5.1:** El profesor puede ordenar el mostrado en orden alfabético, por dni, o por curso más alto matriculado.
	* **RF-5.2:** El orden puede ser ascendente o descendente.
* **RF-6:** El sistema permite que el profesor pueda guardar los datos en un fichero de seguridad.
* **RF-7:** El sistema permite que el profesor pueda cargar los datos a partir de un fichero de seguridad.
* **RF-8:** El sistema debe incorporar un proceso de identificación mediante nombre y contraseña para que los profesores puedan hacer uso de las funcionalidades del sistema.
* **RF-9:** El sistema permite que el profesor coordinador pueda añadir ayudantes en el sistema, aportando nombre de profesor y contraseña.


### Requisitos no funcionales

Los requisitos no funcionales son característicos del proceso de desarrollo, del servicio prestado o de cualquier otro aspecto del desarrollo, que debe cumplir el sistema y que indican las restricciones del mismo. Estos se codifican con las siglas *RNF*, seguidas de un guión y del número de requisito.

* **RNF-1:** El lenguaje de programación es C++.
* **RFF-2:** El lenguaje de documentación será Markdown.
* **RNF-3:** Si se hace uso de un IDE, éste será Eclipse.
* **RFF-4:** El proyecto se realizará haciendo uso del sistema de control de versiones Git y la plataforma GitHub para el almacenamiento del repositorio de forma remota.
* **RNF-5:** El historial de cambios queda guardado en las cuentas de Git por lo que la evaluación será incremental y no servirá subir los ficheros de un día para otro en Git.
* **RNF-6:** El sistema debe funcionar en Linux.
* **RNF-7:** El sistema deberá ser rápido ofreciendo los resultados de consulta en un tiempo inferior a dos segundos. Del mismo modo los procesos de actualización de un registro de la base de datos deben ser realizados en menos de un segundo.
* **RNF-7:** Se utilizará la metodología UML durante la fase de desarrollo.
* **RFF-8:** El sistema debe permitir almacenar información histórica.
* **RNF-9:** Se debe tener un alto control de errores, evitando que el profesor introduzca datos inconsistentes, y permitir al profesor la modificación o posibilidad de subsanar otros errores.
* **RNF-10:** El formato de salida de los listados de alumnos debe ser html o Markdown.
* **RNF-11:** El sistema solo puede admitir como máximo a 150 alumnos.
* **RNF-12:** Debe poderse cargar o guardar los datos del registro histórico de alumnos en ficheros binarios.
* **RNF-13:** Todos los datos de un alumno son necesarios, excepto el número de grupo y el liderazgo.
* **RNF-14:** Un alumno solo puede ser líder de un grupo si forma parte de un grupo.
* **RNF-15:** Como máximo puede haber un solo líder por grupo.
* **RNF-16:** En el mostrado, aquellos alumnos que sean líderes de un grupo deben verse remarcados.
* **RNF-17:** Los atributos identificadores de un alumno son el dni, el e-mail, y el agregado que forma el número de grupo y la condición de líder.
* **RNF-18:** La interfaz del sistema deberá ser a través de línea de comandos.
* **RNF-19:** El sistema debe proporcionar mensajes de error que sean informativos y orientados al usuario final.
* **RNF-20:** El sistema debe ser capaz de manejar caracteres del alfabeto latino.
* **RNF-21:** Solo puede existir un coordinador en el sistema, pero este puede tener varios ayudantes. Todo nuevo usuario que el coordinador cree será de tipo ayudante.
* **RNF-22:** Solo los profesores pueden crear y cargar copias de seguridad.
* **RNF-23:** El sistema debe incorporar un fichero binario con las credenciales de los usuarios cifradas para la verificacion de usuarios en el sistema.
* **RNF-24:** Un usuario no identificado no puede hacer uso de las funcionalidades del sistema.
