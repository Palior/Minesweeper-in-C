MINESWEEPER INSTRUCTIONS

The input for this program is a .txt file named "tablero.txt" containing spaces with mines represented by 1 and spaces without mines represented by 0. 
The grid has a fixed size of 8 rows by 8 columns, with no limit on the number of mines. The values are separated by spaces, as shown below:

0 0 1 0 0 1 0 0
0 0 0 0 0 1 0 0
1 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0
0 1 0 0 0 0 0 1
0 0 0 0 0 0 0 0
1 0 0 0 0 1 0 0 
0 0 0 1 0 0 0 0

El cual puede ser editado al abrirlo como documento de texto para cambiar el contenido a transformar a buscaminas, o un archivo de texto con este mismo formato que posea el nombre "tablero.txt".

Al ejecutar el programa de buscaminas se darán las siguientes opciones:
-Para modo jugador, ingresar 1.
-Para modo computadora, ingresar 2.
-Para salir del programa, ingresar cualquier otro numero.

MODO JUGADOR:
Se mostrará en pantalla el buscaminas junto a sus coordenadas en la parte superior y tambien la izquierda, donde las de la parte superior simbolizan las columnas y la izquierda simbolizan las filas, del 1 al 8. Luego se solicitará al usuario las coordenadas deseadas, en caso de estar fuera del largo de lo que se muestra, se pedirá nuevamente, y en el caso de que esté dentro del rango, entonces se mostrara el buscaminas con las posiciones reveladas al elejir esa coordenada o será una derrota en el caso de que encuentre una bomba; Este proceso se repetirá hasta que el usuario encuentre una mina o revele todas las posiciones excepto las que contienen minas.
Al salir de este proceso, se dará la opcion de volver a ejecutar el programa. en el cual ingresar uno será para salir y cualquier otro numero que se ingrese será continuar ejecutando.

MODO COMPUTADORA:
Esta función que resuelve el buscaminas de forma automatica aun no está implementada, por lo que solo se da la opción de volver a ejecutar el programa o salir.

SALIR DEL PROGRAMA:
Al elegir esta opción, el programa se deja de ejecutar.

