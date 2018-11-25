# Leeme

* **SD001 Añadir alumno:** Se realiza una adición de un alumno por medio de una solicitud del usuario.

  Tras realizar la petición, el sistema comprueba que la base de datos tiene capacidad para más alumnos, si es así el usuario introduce los datos del alumno el cual si no tiene ningún dato mal se añadirá a la base de datos.
* **SD002 Modificar alumno:** Se realiza una modificacion de un alumno por medio de una solicitud del usuario.

  El usuario busca por medio de un parametro al alumno que desea modificar, luego el sistema busca al alumno en la base de datos y el usuario introduce el parametro que quiere modificar y su modificacion como tal y el sistema guarda este nuevo dato en la base de datos.
* **SD003 Eliminar alumno:** Se realiza la eliminación de un alumno por medio de una solicitud del usuario.

  El usuario busca por medio de un parametro al alumno que desea eliminar, y el sistema lo elimina de la base de datos.
* **SD004 Buscar alumnos:** Se realiza la búsqueda filtrada de alumnos registrados en el sistema.

  Una vez seleccionados los filtros de la búsqueda (apellidos, dni y número de grupo), la base de datos busca aquellos usuarios coincidentes y los almacena en una lista resultado de la búsqueda. La carencia de filtro se ve reflejada con los parámetros por defecto, por lo que para cada parámetro debe hacerse una doble comprobación. En caso de no encontrar alumnos la lista devuelta estará vacía, siendo esa la forma de mostrar el error.
* **SD005 Mostrar alumnos:** Se realiza la muestra de alumnos mediante la creación de un fichero de salida.

  La operación de muestra realiza una búsqueda interna, seleccionando aquellos alumnos que compartan unos criterios determinados por el usuario, ordena los resultados por un parámetro seleccionado (parámetro opt) de forma ascendente o descendente, y crea un fichero donde se almacenan los datos de los alumnos obtenidos en la búsqueda. En caso de no haber alumnos que mostrar el fichero estará vacío, siendo esa la forma de mostrar el error.
* **SD006 Guardar copia de seguridad:** Se realiza un guardado de seguridad de la base de datos por medio de una solicitud por parte del usuario o de forma periódica por el sistema. 

  Tras realizar la petición, el sistema comprobaría la existencia de una base de datos con información, mandando un mensaje de error en caso de no encontrarla, y realizando dicha copia de seguridad sobreescribiendo cualquier otra posible copia anterior. Al finalizar mostraría un mensaje de confirmación de la operación al usuario.
* **SD007 Cargar copia de seguridad:** Se realiza una carga de la copia de seguiridad de la base de datos por medio de una solicitud por parte del usuario al iniciar el sistema. 

  Tras realizar la petición, el sistema comprobaría la existencia de una copia de seguridad con información, mandando un mensaje de error en caso de no encontrarla, y realizando la carga de dicha copia de seguridad sobreescribiendo cualquier posible base de datos presente. Al finalizar mostraría un mensaje de confirmación de la operación al usuario.
* **SD008 Identificar:** Se realiza la operación de identificación del profesor en el sistema.

  Tras realizar la petición, el sistema comprueba en el fichero de credenciales posibles coincidencias con los datos aportados por el usuario. Si la identificación es correcta, entonces el usuario podrá hacer uso de las funcionalidades del sistema (indicando si es coordinador o ayudante). En caso de no haber coincidencias (porque el usuario no existe o porque la contraseña sea incorrecta), devuelve un mensaje de error y vuelve a solicitar que valide sus credenciales.
* **SD009 Añadir profesor:** Se realiza una adición de un profesor en el registro de profesores.

  Tras realizar la petición, el sistema comprueba si el usuario ya existe en el registro de profesores. En caso de existir, se devuelve un mensaje de error y se finaliza la operación. Si no existe dicho usuario se añaden sus datos al final del fichero y se devuelve un mensaje de confirmación al usuario.
