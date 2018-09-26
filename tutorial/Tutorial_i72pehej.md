**Comandos Ramas III**
  **Almacenar cambios temporales:**
  `git stash save "Mensaje"`

  **Listar cambios:**
  `git stash list`

  **Ver contenido de un cambio temporal:**
  `git stash show -p nombre_stash`

  **Eliminar un cambio temporal:**
  `git stash drop nombre_stash`

  **Aplicar cambio del stash:**
  ~~~
  git stash apply nombre_stash
  git stash pop nombre_stash
  ~~~
