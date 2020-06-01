# Ejercicio 2 Comparacion de algoritmos OpenMPI

## Diferencias
### ¿Qué diferencia hay en la ejecución de estos dos programas?
- En la Ejecución del primer algoritmo se ejecuta el for en todos los procesos 10 veces, es decir los 5 procesos ejecutan el ciclo "for" 10 veces (40 carteles por pantalla en total).

- En la ejecucion del segundo algoritmo el ciclo "for" se divide en todos los threads creados por lo tanto hay 10 carteles por pantalla divididos en los 5 threads creados.

### ¿Qué sucedería si la variable n no fuera privada?
- En el caso del primero programa utlizando la clausula "shared" donde la variable n deja de ser privada, el loop for se ejecuta 14 veces, es decir que un proceso realiza las 10 iteraciones y luego cada proceso hace una iteracion. Esto se debe a que la variable n se encuentra en una region paralela de memoria que es comun para todos los procesos.

- En el 2do algotimo funciona exactamente igual, ya que al tener la variable compartida, divide de igual manera la iteración.


**Nota:** Preguntar sobre como funciona el caso de una variable shared en un for.
