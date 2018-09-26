**Comandos Ramas III**
  *Almacenar cambios temporales:*
  `git stash save "Mensaje"`

  *Listar cambios:*
  `git stash list`

  *Ver contenido de un cambio temporal:*
  `git stash show -p nombre_stash`

  *Eliminar un cambio temporal:*
  `git stash drop nombre_stash`

  *Aplicar cambio del stash:*
  ~~~
  git stash apply nombre_stash
  git stash pop nombre_stash
  ~~~

**Comandos GitHub I**
  *Añadir repositorio remoto:*
  `git remote add origin url`

  *Ver repositorios remotos:*
  `git remote -v`

  *Eliminar repositorio remoto:*
  `git remote rm origin`

  *A˜nadir cambios del repositorio local al remoto:*
  `git push -u origin master`

  *A˜nadir cambios del repositorio remoto al local:*
  `git pull`
