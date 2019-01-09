//Algoritmo de Insercion directa:Ordena los elementos del vector 

#include <stdio.h>
#include <conio.h>

//#define N 5

void rellenar_vector(int vector[],int N);
void imprimir_vector(int vector[],int N);
void ordena_insert(int vector[],int N);


int main(){
	int N=4;
	int vec[N];
	
	
	rellenar_vector(vec,N);
	imprimir_vector(vec,N);
	printf("\nEl vector ordenado:\n");
	ordena_insert(vec,N);
	imprimir_vector(vec,N);
	
	return 0;
}

void ordena_insert(int vector[],int N){
	int aux;
	int j;
		
	for (int i=1;i<N;i++){
		
		aux=vector[i];
		j=i-1;   	//nos pone el j en el indice 0
		
		while (vector[j]>aux && j>=0){
			vector[j+1]=vector[j];
			j=j-1;
		}
		
	if (vector[j]>aux){
		
		vector[j+1]=vector[j];
		vector[j]=aux;
	}
	else 
		{vector[j+1]=aux;
		}	
		
	//printf("\nejecucion %i",i);
	//imprimir_vector(vector,N);
	//getch();
	}
	
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
