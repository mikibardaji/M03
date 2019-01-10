#include <stdio.h>
#define MAX 10

int busqueda_lineal(int *numeros,int tam, int num_buscar);
int busqueda_lineal_ordenado(int *numeros,int tam, int num_buscar);

int main()
{
	int numeros[MAX] = {2,3,6,8,9,18,24,28,32,110};
	int posicion;
	int num_buscar;
	/*pedir numero a buscar*/
	printf("Que numero quieres buscar?");
	scanf("%i",&num_buscar);
	posicion = busqueda_lineal_ordenado(numeros,MAX,num_buscar);
	
	printf("El numero que buscas esta en la posición %i del array", posicion);
}


int busqueda_lineal(int *numeros,int tam, int num_buscar)
	{
		int i, pos, encontrar=0;
		i=0;
		pos=-1; /*no encontrado*/
		while (i<tam && (encontrar==0))
			{
				if (numeros[i]==num_buscar)
					{
						pos = i;
						encontrar=1;/*ciertp*/
					}
				else
					{
						i = i+1;
					}
			}

		return pos;
	}
	
int busqueda_lineal_ordenado(int *numeros,int tam, int num_buscar)
	{
		int i, pos, encontrar=0;
		i=0;
		pos=-1; /*no encontrado*/
		while (i<tam && numeros[i]<num_buscar)
			{
						i = i+1;
			}
			
		if (numeros[i]==num_buscar) /* si es el numero informo la variable posicion*/
			{
				pos = i;
			}
		return pos;	
		
	}
