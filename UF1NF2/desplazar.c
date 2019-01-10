#include <stdio.h>
#define TOPE 4

void mover_derecha(int *num, int longitud_array);
void mostrar_array_unidimensional_int(int *, int longitud_array);

int main()
{
	int numeros[TOPE];
	int indice=0;
	/*pedir numeros*/
	for(indice=0;indice<TOPE;indice++)
		{
			printf("Pon el numero para el indice %i: ", indice);
			scanf("%i",&numeros[indice]);
		}
	
	/*invertir derecha*/
	mover_derecha(numeros,TOPE);
	/*mostrar*/
	mostrar_array_unidimensional_int(numeros,TOPE);
	
	
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
	
void mover_derecha(int *num, int longitud_array)
	{
		int final = longitud_array-1;/*posicion final del array*/
		int aux=num[final]; /*guardo el valor de la ultima posicion*/
		int indice;
		/*muevo de la penultima*/

		//recorro y copio valor
		for (indice=final;indice>0;indice--)
			{
				/*copia el valor del indice a la posición superior*/
				num[indice] = num[indice-1];
				printf("indice %i se copia al  %i\n", indice, indice-1);
				mostrar_array_unidimensional_int(num,TOPE);
				getch();	
			}
		/*fuera del for le copio el aux*/
		num[indice]=aux; /*num[0]*/
		}	




