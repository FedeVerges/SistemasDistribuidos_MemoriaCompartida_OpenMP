# Ejercicio 4 Bloques estructurados.

## Codigo 1

~~~
for (i=0;i<n;i++) {
    a[i] = 2.3*i;
    if (a[i] < b[i]) break;
}
~~~

En el caso del uso del break éste fuerza a que el thread finalice, por lo tanto si corta la ejecución de los otros threads para que todos terminen al mismo tiempo puede causar problemas ya que no se sabe que datos estaban modificando los demas threads, por lo tanto esto podria causar problemas en el codigo, esto provoca que sea suceptible al paralelismo. Cabe destacar que OpenMP no deja utilizar la sentencia break en los "for loop" provistos por OpenMP.
## Codigo 2

~~~
flag = 0;
for (i=0;(i<n) & (!flag);i++){
    a[i] = 2.3*i;
    if (a[i] < b[i]) flag = 1;
}
~~~

En este caso, el thread que ingrese al if, modificará el valor del flag logrando que finalice la ejecucion del ciclo for.