**Añadir alumno**

Se realiza una adición de un alumno o varios depende de lo que se quiera por medio de una solicitud del usuario.

Tras realizar la petición, el sistema comprueba que la base de datos tiene capacidad para más alumnos, si es así el usuario introduce los datos del alumno el cual si no tiene ningún dato mal se añadirá a la base de datos. En el caso de que no se pueda ya sea porque no hay espacio o porque hay algun dato mal llegara un mensaje de error al sistema.

**Modificar alumno**

Se realiza una modificacion de un alumno por medio de una solicitud del usuario.

El usuario busca por medio del dni al alumno que desea modificar, luego el sistema busca al alumno en la base de datos y el usuario introduce el parametro que quiere modificar y su modificacion como tal y el sistema guarda este nuevo dato en la base de datos. En el caso de que el dato este mal se enviara un mensaje de error al sistema.

**Eliminar alumno**

Se realiza la eliminación de un alumno por medio de una solicitud del usuario.

El usuario busca por medio del dni al alumno que desea eliminar, y el sistema lo elimina de la base de datos. En el caso de que no exista el alumno se enviara un mensaje de error al sistema.
