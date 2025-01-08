# Preguntas y Respuestas:

1. ¿Qué efecto produce la función rand_r() en la función funcion_coche() que ejecuta cada hilo?
rand_r() genera un número aleatorio utilizando una semilla única por hilo, asegurando que cada hilo tenga resultados independientes y evitando condiciones de carrera al no compartir variables globales.

2. ¿Qué ocurre si el hilo inicial (que ejecuta la función main()) no espera la finalización del resto de hilos?
Si el hilo principal no usa pthread_join para esperar la finalización de los hilos, el programa puede terminar antes de que los hilos completen su ejecución, causando resultados incompletos o inconsistentes.

3. ¿Es correcto pensar en obtener la clasificación mediante una solución en la que el padre, a medida que vaya finalizando cada hilo (coche), imprima el identificador del coche que ha finalizado?
No, esto no garantiza un orden correcto de llegada. La impresión se realiza en el orden en que pthread_join devuelve, que no necesariamente corresponde al orden real de llegada.

4. Al finalizar cada hilo coche la carrera, ¿qué problemas podrían ocurrir si no se controla el acceso a las variables compartidas?
Si no se usa un mutex para sincronizar el acceso al array clasificacionFinal, podrían ocurrir condiciones de carrera, sobrescribiendo posiciones o generando errores en la clasificación.

5. ¿Cómo solucionaría los problemas de acceso concurrente?
Se deben usar las funciones pthread_mutex_lock y pthread_mutex_unlock para garantizar que solo un hilo modifique las variables compartidas a la vez, asegurando exclusión mutua.