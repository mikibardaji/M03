#include <stdio.h>
#define TOPE 7

void mostrar_array_unidimensional_int(int *, int longitud_array);
float temperatura_media(int *, int dias);

int main()
{
	int numeros[TOPE];
	int indice=0;
	/*pedir numeros*/
	for(indice=0;indice<TOPE;indice++)
		{
			printf("Pon la temperatura para el dia %i: ", indice);
			scanf("%i",&numeros[indice]);
		}
	
	
	
	mostrar_array_unidimensional_int(numeros,TOPE);
	
	float resultado = temperatura_media(numeros,TOPE);
	printf("La temperatura media es %.2f",resultado);
	
	
	return 0;
}


/*
muestra por pantalla todo los valores del array
longitud_array: es el tamaño del array
void mostrar_array_unidimensional_int(int num[], int longitud_array)
*/
void mostrar_array_unidimensional_int(int *num, int longitud_array)
	{
		int indice;
		for (indice=0;indice<longitud_array;++indice)
			{
				printf("%i-",num[indice]);
			}
			printf("\n");
	}
	
/* entrada: Array con todas las temperatura
   variable dias con todos los dias de la temperatura
   devuelve la temperatura media*/
   
float temperatura_media(int *temp, int dias)
	{
		int indice=0;
		int acum = 0;
		for (indice=0;indice<dias;indice++)
			{
				acum = acum + temp[indice];
			}
		/*tengo la suma completa de las tempereturaas*/
		float res = acum/dias;
		return res;
		
	}
