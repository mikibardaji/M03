//Algoritmo de Busqueda lineal:busca el elemento y si lo encuentra
//nos indica en que posicion se encuentra.

#include <stdio.h>
#include <conio.h>

//#define N 5


void rellenar_vector(int vector[],int N);
void imprimir_vector(int vector[],int N);
int busqueda(int vector[],int N,int valor);


int main(){
	int N=5;
	int vec[N];
	int valor=0,pos;
	
	rellenar_vector(vec,N);
	imprimir_vector(vec,N);
	printf("\n Introduce el numero a buscar:");
	scanf("%i",&valor);
	pos=busqueda(vec,N,valor);
	//imprimir pos
	
	if(pos==-1){
		printf("El numero %i no se encuentra en el vector",valor);
	}
	else 
		printf("El numero %i se encuentra en la pos %i",valor,pos);
	
	return 0;
}

int busqueda(int vector[],int N,int valor){
	int i=0,posi=-1;
	int enc=0;//variable booleana
		
	while(i<N && enc==0){
		
		if (vector[i]==valor){
			enc=1;
			posi=i;//guardo la posicion del numero
			
		}
		else 
		i++;//comparo el siguiente numero del vector
		
	}
	return posi;
	
		
	
	
}

void rellenar_vector(int vector[],int N){
	
	for(int i=0;i<N;i++){
		
		printf("Introduce num: ");
		scanf("%i",&vector[i]);
				
	}
}

void imprimir_vector(int vector[],int N){
	
	for(int i=0;i<N;i++){
		
		printf("%i-",vector[i]);
				
	}
}
