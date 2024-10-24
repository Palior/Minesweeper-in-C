// Autor: Pablo Lizama // Rut: 19.930.343-0 // Sección 0-L-7 //
// Fecha de creación: 21/05/2019 //

//BUSCAMINAS//

#include <stdio.h>
#include <stdlib.h>


//Función que analiza el elemento que se encuentra en la parte inferior del elemento que se encuentra en las coordenadas fila, columna
//retornando un 1 si el elemento es igual al buscado y 0 si no lo es
//Entradas: tabla[8][8] es un arreglo de 8 x 8 que contiene todos los elementos de la "matriz", fila y columna son las posiciones del elemento
//que se analizará, buscar es el numero con el cual se está realizando la comparación
//Salida: 1 si se cumple la condición y 0 si no la cumple
int abajo(int tabla[8][8], int fila, int columna, int buscar){ 
	if(tabla[fila+1][columna]==buscar){
		return 1;
	}
	return 0;
}

//Realiza la misma función, recibe las mismas entradas y la misma salida con la diferencia de que se compara el elemento superior
int arriba(int tabla[8][8], int fila, int columna, int buscar){ 
	if(tabla[fila-1][columna]==buscar){
		return 1;
	}
	return 0;
}

//Realiza la misma función, recibe las mismas entradas y la misma salida con la diferencia de que se compara el elemento a la izquierda
int izquierda(int tabla[8][8], int fila, int columna, int buscar){
	if(tabla[fila][columna-1]==buscar){
		return 1;
	}
	return 0;
}

//Realiza la misma función, recibe las mismas entradas y la misma salida con la diferencia de que se compara el elemento a la derecha
int derecha(int tabla[8][8], int fila, int columna, int buscar){
	if(tabla[fila][columna+1]==buscar){
		return 1;
	}
	return 0;
}

//Realiza la misma función, recibe las mismas entradas y la misma salida con la diferencia de que se compara el elemento superior izquierdo
int arrIzq(int tabla[8][8], int fila, int columna, int buscar){
	if(tabla[fila-1][columna-1]==buscar){
		return 1;
	}
	return 0;
}

//Realiza la misma función, recibe las mismas entradas y la misma salida con la diferencia de que se compara el elemento superior derecho
int arrDer(int tabla[8][8], int fila, int columna, int buscar){ 
	if(tabla[fila-1][columna+1]==buscar){
		return 1;
	}
	return 0;
}

//Realiza la misma función, recibe las mismas entradas y la misma salida con la diferencia de que se compara el elemento inferior izquierdo
int abIzq(int tabla[8][8], int fila, int columna, int buscar){
	if(tabla[fila+1][columna-1]==buscar){
		return 1;
	}
	return 0;
}

//Realiza la misma función, recibe las mismas entradas y la misma salida con la diferencia de que se compara el elemento inferior derecho
int abDer(int tabla[8][8], int fila, int columna, int buscar){
	if(tabla[fila+1][columna+1]==buscar){
		return 1;
	}
	return 0;
}
	


//Trasforma el arreglo que contiene los 0 y 9 de las bombas en un arreglo que ahora contentrá a las bombas, y los espacios vacios contendran
//un numero que representa las bombas cercanas
//Entrada: arreglo de arreglos que contienen las bombas representadas por un 9 y los espacios vacios representados por 0
//Salida: arreglo de arreglos e contiene bomas y numeros que simbolizan las bombas cercanas pero sin retornarlas, sino que edita la informacion
//guardada en memoria
void transformarTablero(int tabla[8][8]){
	int fila=0;
	while(fila<8){
		int columna=0;
		while(columna<8){
			if(tabla[fila][columna]!=9){
				int cantidadMinas=0;
				if(fila==0){ //fila superior
					cantidadMinas=cantidadMinas + abajo(tabla, 0, columna, 9);
					if(columna!=0){
						cantidadMinas=cantidadMinas + izquierda(tabla, 0, columna, 9);
						cantidadMinas=cantidadMinas + abIzq(tabla, 0, columna, 9);
					}
					if(columna!=7){
						cantidadMinas=cantidadMinas + derecha(tabla, 0, columna, 9);
						cantidadMinas=cantidadMinas + abDer(tabla, 0, columna, 9);
					}
				}else if(fila==7){ //fila inferior
					cantidadMinas=cantidadMinas + arriba(tabla,7,columna, 9);
					if(columna!=0){
						cantidadMinas=cantidadMinas + izquierda(tabla,7,columna, 9);
						cantidadMinas=cantidadMinas + arrIzq(tabla,7,columna, 9);
					}
					if(columna!=7){
						cantidadMinas=cantidadMinas + derecha(tabla,7,columna, 9);
						cantidadMinas=cantidadMinas + arrDer(tabla,7,columna, 9);
					}
				}else if(columna==0){
					cantidadMinas=cantidadMinas + arriba(tabla,fila,0, 9);
					cantidadMinas=cantidadMinas + abajo(tabla,fila,0, 9);
					cantidadMinas=cantidadMinas + derecha(tabla,fila,0, 9);
					cantidadMinas=cantidadMinas + arrDer(tabla,fila,0, 9);
					cantidadMinas=cantidadMinas + abDer(tabla,fila,0, 9);
				}else if(columna==7){
					cantidadMinas=cantidadMinas + arriba(tabla,fila,7, 9);
					cantidadMinas=cantidadMinas + abajo(tabla,fila,7, 9);
					cantidadMinas=cantidadMinas + izquierda(tabla,fila,7, 9);
					cantidadMinas=cantidadMinas + arrIzq(tabla,fila,7, 9);
					cantidadMinas=cantidadMinas + abIzq(tabla,fila,7, 9);
				}else{
					cantidadMinas=cantidadMinas + arriba(tabla,fila,columna, 9);
					cantidadMinas=cantidadMinas + abajo(tabla,fila,columna, 9);
					cantidadMinas=cantidadMinas + derecha(tabla,fila,columna, 9);
					cantidadMinas=cantidadMinas + arrDer(tabla,fila,columna, 9);
					cantidadMinas=cantidadMinas + abDer(tabla,fila,columna, 9);
					cantidadMinas=cantidadMinas + izquierda(tabla,fila,columna, 9);
					cantidadMinas=cantidadMinas + arrIzq(tabla,fila,columna, 9);
					cantidadMinas=cantidadMinas + abIzq(tabla,fila,columna, 9);
				}
				*&tabla[fila][columna]=cantidadMinas;
			}
			

			columna++;
		}
		fila++;

	}

}



//Función que guarda en un arreglo auxiliar las posiciones ya reveladas al haber un 0 en la posicion indicada y a la vez muestra los
//numeros que lo rodean, si uno de esos es cero, se repite el proceso en el denuevo
//Entradas: una lista auxiliar que contiene la matriz que se ha revelado, sin incluir las posiciones que no se han revelado, la matriz oculta 
//que contiene toda la informacion, fila y columna de la posicion y un arreglo que contiene las posiciones ya reveladas
//Salida: reemplaza en la memoria de la lista auxiliar, las posiciones que fueron reveladas y hace lo mismo con las posiciones
void alrededorCero(int listaAux[8][8], int tabla[8][8], int fila, int columna, int revelados[128],int x){
	*&x=*&x+2;
	int i=0;
	int condicion=0;//condicion que se usara mas abajo para entrar al ciclo
	while(i<128){
		if(fila==revelados[i] && columna==revelados[i+1]){
			condicion=1;
		}
		i++;		
	}
	if(condicion==0){
		revelados[x]=fila;
		revelados[x+1]=columna;
		*&listaAux[fila][columna]=tabla[fila][columna];
		if(fila==0){ //analiza fila superior
			if(abajo(tabla, 0, columna, 0)==1){ //analiza elemento de abajo
				*&listaAux[fila+1][columna]=tabla[fila+1][columna];
				alrededorCero(listaAux, tabla, fila+1, columna, revelados, x);
			}else{
				*&listaAux[fila+1][columna]=tabla[fila+1][columna];
			}
			if(columna!=0){ // no columna izquierda
				if(izquierda(tabla, 7, columna, 0)==1){ //analiza elemento de izquierda
					alrededorCero(listaAux, tabla, fila, columna-1,revelados, x);
				}else{
					*&listaAux[fila][columna-1]=tabla[fila][columna-1];
				}
				if(abIzq(tabla, 0, columna, 0)==1){  //analiza elemento de abajo a la izquierda
					alrededorCero(listaAux, tabla, fila+1, columna-1, revelados, x);
				}else{
					*&listaAux[fila+1][columna-1]=tabla[fila+1][columna-1];
				}
			}
			if(columna!=7){ //columna no derecha
				if(derecha(tabla, 0, columna, 0)==1){ //analiza elemento de la derecha
					alrededorCero(listaAux, tabla, fila, columna+1,revelados, x);
				}else{
					*&listaAux[fila][columna+1]=tabla[fila][columna+1];
				}
				if(abDer(tabla, 0, columna, 0)==1){ //analiza elemento de abajo a la derecha
					alrededorCero(listaAux, tabla, fila+1, columna+1,revelados, x);
				}else{
					*&listaAux[fila+1][columna+1]=tabla[fila+1][columna+1];
				}
			}
		}else if(fila==7){ //fila inferior
			if(arriba(tabla,7,columna, 0)==1){ //analiza elemento de arriba
				alrededorCero(listaAux, tabla, fila-1, columna,revelados, x);
			}else{
				*&listaAux[fila-1][columna]=tabla[fila-1][columna];
			}
			if(columna!=0){ //columna no izquierda
				if(izquierda(tabla, 7, columna, 0)==1){ //analiza elemento de izquierda
					alrededorCero(listaAux, tabla, fila, columna-1,revelados, x);
				}else{
					*&listaAux[fila][columna-1]=tabla[fila][columna-1];
				}
				if(arrIzq(tabla,7,columna, 0)==1){  //analiza elemento de arriba a la izquierda
					alrededorCero(listaAux, tabla, fila-1, columna-1,revelados, x);
				}else{
					*&listaAux[fila-1][columna-1]=tabla[fila-1][columna-1];
				}
			}
			if(columna!=7){ //columna no derecha
				if(derecha(tabla, 7, columna, 0)==1){ //analiza elemento a la derecgha
					alrededorCero(listaAux, tabla, fila, columna+1,revelados, x);
				}else{
					*&listaAux[fila][columna+1]=tabla[fila][columna+1];
				}
				if(arrDer(tabla,7,columna, 0)==1){  //analiza elemento de arriba a la derecha
					alrededorCero(listaAux, tabla, fila-1, columna+1,revelados, x);
				}else{
					*&listaAux[fila-1][columna+1]=tabla[fila-1][columna+1];
				}
			}
		}else if(columna==0){ //columna izquierda
			if(arriba(tabla,fila, 0, 0)==1){  //analiza elemento de arriba
				alrededorCero(listaAux, tabla, fila-1, columna,revelados, x);
			}else{
				*&listaAux[fila-1][columna]=tabla[fila-1][columna];
			}
			if(abajo(tabla, fila, 0, 0)==1){ //analiza elemento de abajo
				alrededorCero(listaAux, tabla, fila+1, columna,revelados, x);
			}else{
				*&listaAux[fila+1][columna]=tabla[fila+1][columna];
			}
			if(derecha(tabla, fila, 0, 0)==1){ //analiza elemento de la derecha
				alrededorCero(listaAux, tabla, fila, columna+1,revelados, x);
			}else{
				*&listaAux[fila][columna+1]=tabla[fila][columna+1];
			}
			if(arrDer(tabla,fila, 0, 0)==1){  //analiza elemento de arriba a la derecha
				alrededorCero(listaAux, tabla, fila-1, columna+1,revelados, x);
			}else{
				*&listaAux[fila-1][columna+1]=tabla[fila-1][columna+1];
			} 
			if(abDer(tabla, fila, 0, 0)==1){  //analiza elemento de abajo a la derecha
				alrededorCero(listaAux, tabla, fila+1, columna+1,revelados, x);
			}else{
				*&listaAux[fila+1][columna+1]=tabla[fila+1][columna+1];
			}
		}else if(columna==7){ //columna derecha
			if(arriba(tabla,fila,7, 0)==1){ //analiza elemento de arriba
				alrededorCero(listaAux, tabla, fila-1, columna,revelados, x);
			}else{
				*&listaAux[fila-1][columna]=tabla[fila-1][columna];
			}
			if(abajo(tabla, fila, 7, 0)==1){ //analiza elemento de abajo
				alrededorCero(listaAux, tabla, fila+1, columna,revelados, x);
			}else{
				*&listaAux[fila+1][columna]=tabla[fila+1][columna];
			}
			if(izquierda(tabla, fila, 7, 0)==1){ //analiza elemento de la izquierda
					alrededorCero(listaAux, tabla, fila, columna-1,revelados, x);
			}else{
				*&listaAux[fila][columna-1]=tabla[fila][columna-1];
			}
			if(arrIzq(tabla,fila,7, 0)==1){ //analiza elemento de arriba a la izquierda
				alrededorCero(listaAux, tabla, fila-1, columna-1,revelados, x);
			}else{
				*&listaAux[fila-1][columna-1]=tabla[fila-1][columna-1];
			}
			if(abIzq(tabla, fila, 7, 0)==1){  //analiza elemento de abajo a la izquierda
				alrededorCero(listaAux, tabla, fila+1, columna-1,revelados, x);
			}else{
				*&listaAux[fila+1][columna-1]=tabla[fila+1][columna-1];
			}
		}else{ //cualquier posicion que no este en lo anterior, osea no en los bordes
			if(arriba(tabla, fila, columna, 0)==1){ //analiza elemento de arriba
				alrededorCero(listaAux, tabla, fila-1, columna,revelados, x);
			}else{
				*&listaAux[fila-1][columna]=tabla[fila-1][columna];
			}
			if(abajo(tabla, fila, columna, 0)==1){  //analiza elemento de abajo
				alrededorCero(listaAux, tabla, fila+1, columna,revelados, x);
			}else{
				*&listaAux[fila+1][columna]=tabla[fila+1][columna];
			}
			if(derecha(tabla, fila, columna, 0)==1){  //analiza elemento de la derecha
				alrededorCero(listaAux, tabla, fila, columna+1,revelados, x);
			}else{
				*&listaAux[fila][columna+1]=tabla[fila][columna+1];
			}
			if(arrDer(tabla,fila,columna, 0)==1){  //analiza elemento de arriba a la derecha
				alrededorCero(listaAux, tabla, fila-1, columna+1,revelados, x);
			}else{
				*&listaAux[fila-1][columna+1]=tabla[fila-1][columna+1];
			}
			if(abDer(tabla, fila, columna, 0)==1){  //analiza elemento de abajo a la derecha
				alrededorCero(listaAux, tabla, fila+1, columna+1,revelados, x);
			}else{
				*&listaAux[fila+1][columna+1]=tabla[fila+1][columna+1];
			}
			if(izquierda(tabla, fila, columna, 0)==1){  //analiza elemento de la izquierda
					alrededorCero(listaAux, tabla, fila, columna-1,revelados, x);
			}else{
				*&listaAux[fila][columna-1]=tabla[fila][columna-1];
			}
			if(arrIzq(tabla,fila,columna, 0)==1){  //analiza elemento de arriba a la izquierda
				alrededorCero(listaAux, tabla, fila-1, columna-1,revelados, x);
			}else{
				*&listaAux[fila-1][columna-1]=tabla[fila-1][columna-1];
			}
			if(abIzq(tabla, fila, columna, 0)==1){  //analiza elemento de abajo a la izquierda
				alrededorCero(listaAux, tabla, fila+1, columna-1,revelados, x);
			}else{  
				*&listaAux[fila+1][columna-1]=tabla[fila+1][columna-1];
			}
		}
	}
}

//Revela e imprime el tablero que el usuario ve, ademas de condicionar la derrota y victoria, y con esto salir del ciclo
//Entradas: una lista auxiliar que contiene la matriz que se ha revelado, sin incluir las posiciones que no se han revelado, la matriz oculta 
//que contiene toda la informacion, fila y columna de la posicion y un arreglo que contiene las posiciones ya reveladas, el valor de x que 
//simboliza la posicion del arreglo con las coordenadas y la cantidad de bombas que contiene el arreglo
//Salidas: Reemplaza en la memoria el valor que condiciona el ciclo que hace que se repita, al ganar o perder, e imprime por pantalla el 
//tablero actual 
void tableroActual(int listaAux[8][8], int tabla[8][8], int fila, int columna, int * mina, int revelados[128], int x, int bombas){
	int incognitas=0;
	if(tabla[fila][columna]==9){
		printf("\n\n\n\n\n		GAME OVER\n\n\n\n\n");
		*mina=1;
	}else{
		listaAux[fila][columna]=tabla[fila][columna];
		if(tabla[fila][columna]==0){

			alrededorCero(listaAux, tabla, fila, columna, revelados, x);
		}
		int i=0;
		printf("\n\n  1 2 3 4 5 6 7 8\n");
		while(i<8){
			int j=0;
			printf("%d", i+1);
			while(j<8){
				if(listaAux[i][j]==10){
					printf(" X");
					*&incognitas=*&incognitas+1;
				}else{
					printf(" %d", listaAux[i][j]);
				}
				j++;
			}
			i++;
			printf("\n");
		}
		printf("\n\n\n");
	}
	if(incognitas==bombas){
		printf("\n\n\n			FELICITACIONES, HAS GANADO\n\n\n");
		*mina=1;
	}
}

//función que recibe las coordenadas por parte del usuario y repite el proceso en conjunto con las funciones descritas arriba
//Entradas: la lista auxiliar con la informacion revelada, el arreglo con la informacion oculta, la lista que contiene las posiciones del
//arreglo auxiliar y la cantidad de bombas
//Salida: Imprime por pantalla el buscaminas con posiciones y matriz 
void jugador(int listaAux[8][8], int tabla[8][8], int revelados[128],int x, int bombas){
	int mina=0;
	while(mina==0){
		int fila;
		printf("ingrese numero de la fila: \n");
		scanf("%d",&fila);
		int columna;
		printf("ingrese numero de la columna: \n");
		scanf("%d",&columna);
		fila=fila-1;
		columna=columna-1;
		if(fila<8 && fila>=0 && columna<8 && columna>=0){
			tableroActual(listaAux, tabla, fila, columna, &mina, revelados, x, bombas);	
		}else{
			printf("coordenadas invalidas, ingrese nuevamente\n\n");		
		}
	}
}


int main(){
	FILE * tablero = fopen("tablero.txt","r");
	if(tablero==NULL){
		printf("No se ha podido abrir el archivo\n");
		return -1;
	}
	//se lee el archivo, se guarda la informacion en un arreglo de enteros y simboliza las bombas con el numero 9
	char lectura[8];
	int fila=0;
	int tabla[8][8];
	while(fila<8){
		int columna=0;
		while(columna<8){
			fscanf(tablero, "%s",lectura);
			tabla[fila][columna]=atoi(lectura);
		
			if(tabla[fila][columna]==1){
				tabla[fila][columna]=9; //ya que no pueden haber mas de 8 minas cercanas asi se representan las minas
			}
			columna++;
		}
		fila++;
	}
		fclose(tablero);
	//funcion que contiene la lista con las minas y minas cercanas
 	transformarTablero(tabla);
 	//cuenta las bombas
	int bombas=0;
	int f=0;
	while(f<8){
		int c=0;
		while(c<8){
			if(tabla[f][c]==9){	
				bombas=bombas+1;
			}
			c++;
		}
		f++;
	}
	//ciclo que no se rompe hasta que se desee dejar el juego
	int jugar=0;
	while(jugar==0){
		printf("\n\n\n		BIENVENIDO AL BUSCAMINAS\n\n\n");
		int opcion=0;
		printf("Para opcion jugador ingrese 1.\nPara modo computadora ingrese 2.\nPara salir ingrese cualquiero otro numero.\n");
		scanf("%d", &opcion);
		if(opcion==1){
			printf("Usted ha escogido la modalidad jugador \n\n");
			printf("  1 2 3 4 5 6 7 8\n");
			int i=0;
			while(i<8){
				int j=0;
				//muestra la matriz inicial con numero de filas, columnas y el tablero solo con "X"
				printf("%d", i+1);
				while(j<8){
					printf(" X");
					j++;
				}	
				i++;
				printf("\n");
			}	
			printf("\n\n\n");
			int listaAux[8][8];  //lista auxiliar para posiciones ya reveladas
			i=0;
			//se cambian los valores de la lista auxiliar por 10, que no contiene ninguna representación, solo uso por comodidad
			while(i<8){
				int j=0;
				while(j<8){
					listaAux[i][j]=10;
					j++;
				}
				i++;
			}  //listaAux ya creada
			int revelados[128]; //lista donde se guardaran las posiciones ya reveladas
			while (i<128){
				revelados[i]=9;
				i++;
			}
			int x=-2;
			jugador(listaAux,tabla, revelados,x, bombas);
			int cerrar;
			printf("\n\nIngrese 1 Para salir o cualquier numero para continuar....\n\n\n\n\n");
			scanf("%d",&cerrar);
			if(cerrar==1){
				jugar=1;		
			}
		}else if(opcion==2){
			printf("Usted ha escogido la modalidad computadora \n\n");
			printf("Esta funcion aún no ha sido implementada \n\n");

			int cerrar;
			printf("\n\nIngrese 1 Para salir o cualquier numero para continuar....\n\n\n\n\n");
			scanf("%d",&cerrar);
			if(cerrar==1){
				jugar=1;		
			}
		}else{
			jugar=1;
		}	

	}	


	return 0;
}
