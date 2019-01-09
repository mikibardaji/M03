//Algoritmo de Busqueda lineal:busca el elemento y si lo encuentra
//nos indica en que posicion se encuentra.

#include <stdio.h>
#include <conio.h>

//#define N 5

void rellenar_vector(int vector[],int N);
void imprimir_vector(int vector[],int N);
int bus_binaria(int vector[],int N,int valor);


int main(){
	int N=5;
	int vec[N];
	int valor=0,pos;
	
	rellenar_vector(vec,N);
	imprimir_vector(vec,N);
	printf("\n Introduce el numero a buscar:");
	scanf("%i",&valor);
	pos=bus_binaria(vec,N,valor);
	//imprimir pos
	
	if(pos==-1){
		printf("El numero %i no se encuentra en el vector",valor);
	}
	else 
		printf("El numero %i se encuentra en la pos %i",valor,pos);
	
	return 0;
}

int bus_binaria(int vector[],int N,int valor){
	int posi=-1;
	int enc=0;//variable booleana
	
	int izq=0;
	int dere=N-1;  //primera y ultima posicion
	int centro;
	
	centro=(izq+dere)/2;
	printf("Mitat : %i",centro);
	printf("izq : %i",izq);
	printf("dere : %i",dere);
		
	while(izq<=dere && enc==0) {
		
		centro=(izq+dere)/2;
		
		if (vector[centro]==valor){
			enc=1;
			posi=centro;//guardo la posicion del numero
			printf("\nencontrado");
			return posi;
		}
		else {
			if (vector[centro]>valor){
				dere=centro-1;    
			}
			else
				izq=centro+1;
			
		}
			
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
