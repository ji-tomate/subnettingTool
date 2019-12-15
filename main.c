#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1  // definimos una constante llamada true con valor de 1
#define false !(true) // definimos una constante llamada false con el valor inverso de true es decir 1
int ip[4]; // definimos un vector de 4 enteros para almacenar los 4 octetos de una direccion ip
char clase; // variable para guardar la clase de la ip
char obtenerClase(int octeto){
	//funcion que debuelve la clase de una ip
	//verificando el primer octeto de la direccion ip
	if(octeto >=0 && octeto <=127){
		return 'A';
	}else if(octeto >=128 && octeto <= 191){
		return 'B';
	}else{
		return 'C';
	}
	
}

void inicializarVector(char *vector, int tam){{
	// esta funcion permite inicar los valores de un vector de tipo char 
	// el valor '\0'  hace referencia a vacio, el equivalente a 0 en los enteros
	int i;
	//la variable tam nos sirve para saber el tamaño del vector que estamos
	//inicializando
	for(i = 0; i<tam; i++){
		vector[i] = '\0';
	}
}
	
}
int octetoValido(int o, int primero){
	//esta funcion valida sin un octeto esta dentro del rango de 0 - 255
	if (primero){
		// en el primer octeto decidimos que no empieza en 1
		if (o >= 1 && o<= 255){
			return true;
	}
	return false;
		
	}
	if (o >= 0 && o<= 255){
		return true;
	}
	return false;
}

int esnumero(char c){
	//esta funcion recive un caracter y debuelve si es un numero 
	// ya que no es lo mismo 4 que '4'
	if (c >= 48 && c<=57){ 
	// en el codigo ascii los caracteres entre 48 y 57 corresponden a
	// los numeros del 0 al 9
		return true;
	}
	return false;
}

int espunto(char c){
	// esta funcion recive un caracter y debuelve si es un '.'
	// en el codigo ascii el caracter '.' es el ascii 46
	if ( c == 46){
		return true;
	}
	return false;
}

int validarIp(char *c){
	// esta funcion nos permite validar una direccion ip 
	// ip = [1-255].[0-255].[0-255].[0-255]
	char *octeto;
	//creamos un puntero de tipo char
	// recordemos que un puntero guarda una direccion de un tipo primitivo
	// los tipos primitivos son: int,char,dooble,float
	
	octeto = (char*)malloc(sizeof(char)*3);
	//una vez que creamos el puntero reservamos los 2 lugares a la derecha en
	//la memoria ram, es decir tenemos 3 direcciones de tipo char consecutivas
	inicializarVector(octeto,3);
	//iniciamos el valor de las 3 direcciones a vacio
	

	
	int nocteto = 0;
	//variable que nos sirve para saber que octeto estamos trabajando
	// recordemos que una direccion tiene 4 octetos separados por un '.'
	int k =0;	
	// k es una variable auxiliar que nos sirve para contar 
	// los valores de k son 0,1 y 2
	int i;
	int longitud = strlen(c);
	//obtener la longitud de la cadena c
	if (longitud >=7 && longitud <= 15){
		//una direccion tiene como minimo 7 caracteres
		//ej. 1.1.1.1 y como maximo tiene 15 caracteres
		//ej. 255.255.255.255s
		for (i = 0; i <= longitud; i++){
			//recorremos la cadena donde esta guarda la ip
			if (esnumero(c[i])){
				octeto[k++] = c[i];
				// si es un numero vamos guardando ese numero en octeto
				
			}else if (espunto(c[i]) || i == (longitud)){
				//cuando encontramos un punto quiere decir que hemos
				//terminado de leer un octeto
				ip[nocteto++] = atoi(octeto);
				//guardamos el octeto en una posicion del vector ip
				// e incrementamos la posicion que para este caso es nocteto
				k = 0;
				//cuando guardamos un octeto en la direccion ip
				//debemos reiniciar a k 
				// la variable k solo puede valer 0,1 y 2
				// ya que el numero mas pequeño es 0 y el mas grande es 255
				//lo que significa que puede haber de 1 a 3 caracteres en 
				//un octeto
				inicializarVector(octeto,3);
				//reiniciamos los valores del vector octeto donde vamos 
				//guardando el octeto que estamos leyendo

				
			}
		}
	}
	if(octetoValido(ip[0],1) &&
		octetoValido(ip[1],0) &&
		octetoValido(ip[2],0) && 
		octetoValido(ip[3],0)){
		//verificamos los 4 octetos de la direccion ip guardada
		
	   	return true;
	   }
	   return false;
	
}

int main(){
	int op;
	char cadip[20];
	//creamos un vector de char para almacenar la ip del usuario
	
	
	while(true){
		printf("Ip: ");
		scanf("%s",&cadip);
		//guardamos la ip del usuario
		system("cls");
		//limpiamos la pantalla
		
	
		if(validarIp(cadip)){
		printf("Ip valida, clase %c ",obtenerClase(ip[0]));
		//verificamos que la ip sea una ip valida
		
	}else{
		printf("Ip No valida ");
	}
			printf("Ip:%d.%d.%d.%d\n",ip[0],ip[1],ip[2],ip[3]);
		//imprimos la ip que nos proporciono el usuario
		
		printf("\nPresione 1 para salir");
		scanf("%d",&op);
		if(op){
			break;
		}
		system("cls");
	}
	
	
	
	//se espera que se precione una tecla
	
	
	return 0;
}
