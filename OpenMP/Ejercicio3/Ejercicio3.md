# Ejercicio 3 Suceptibilidad de paralelización

## Código 1
 ~~~
 DO i=1,N
    a[i]= a[i+1] + x
END DO
 ~~~

 En este caso este codigo, el bucle es totalmente independiente por lotanto no sufre suceptiblidad al ser paralelzado.
## Código 2

 ~~~
DO i=1,N
    a[i]= a[i] + b[i]
END DO
 ~~~

 En este caso este codigo, el bucle es totalmente independiente por lotanto no sufre suceptiblidad al ser paralelzado.

## Código 3

 ~~~
ix = base
DO i=1,N
    a ( ix ) = a ( ix ) - b ( i )
    ix = ix + stride
END DO
 ~~~
En este caso, en el bulcle no es independeinte debido a la base "ix", por lo tanto, al ser paralelizado, ambos threads acederan a la misma base por lo tanto modifican el mismo valor de la estructura "a".
## Código 4

 ~~~
DO i=1, n
    b ( i ) = ( a ( i ) - a (i-1) )*0.5
END DO
 ~~~

 En este caso, el bucle sobre la estructura "a" es independiente, por lo tanto es paralelizable, el unico inconveniente es que si a(0) no tiene nada, el compilador daria como resultado un error.

 
