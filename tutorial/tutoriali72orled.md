**Configuracion básica**
Nombre del administrador:
`git config --global user.name "Antonio M Durán Rosal"`
Correo electrónico:
`git config --global user.email aduran@uco.es`
Editor de texto:
`git config --global core.editor "gedit"`
Color de la interfaz:
`git config --global color.ui true`
Listado de la configuración:
`git config --list`

**Comandos básicos**
Iniciar repositorio en un directorio:
`git init`
Agregar cambios al area de staging:
`git add`
Validar cambios en el repositorio:
`git commit -m "Mensaje"`
Hacer los dos pasos anteriores en uno:
`git commit -am "Mensaje"`
Historial de commits:
`git log`
**Comandos básicos II**
Ayuda del listado anterior:
`git help log`
Listar los 5 commits más recientes:
`git log -n 5`
Listar los commits desde una fecha:
`git log --since=2018-09-18`
Listar los commits por autor:
`git log --author="Antonio"`
Ver cambios en el directorio:
`git status`
**Comandos básicos III**
Ver diferencia entre ficheros en el directorio y el repositorio del git:
`git diff`
Ver diferencia entre ficheros en el staging y el repositorio:
`git diff --staged`
Eliminar archivos:
~~~
git rm archivos
git commit -m "Mensaje"
~~~
Mover o renombrar archivos:
~~~
git mv antiguo nuevo
git commit -m "Mensaje"
~~~
**Comandos básicos IV**
Deshacer cambios con git:
`git checkout --nombre_fichero`
Retirar archivos del staging
`git reset HEAD nombre_fichero`
Complementar último commit:
`git commit --amend -m "Mensaje"`
Recuperar version de un fichero de commit antiguo:
`git checkout <id_commit> --nombre_archivo`
Revertir un commit:
`git revert <id_commit>`
