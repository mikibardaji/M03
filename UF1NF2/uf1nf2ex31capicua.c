#include <stdio.h>
#include <string.h>
#define TOPE 4

int capicua(int *);
void descomponer(int, int*);

int main()
{
	int descomposicion_numero[TOPE];
	int numero;
	/*recorrer frase*/
	printf("Escribe numero:");
	scanf("%i",&numero);
	descomponer(numero,descomposicion_numero);
	int cap = capicua(descomposicion_numero);
	
	if (cap==1) /* me ha retornado un 1*/
		{
			printf("Es capicua\n");
		}
	else
		{
			printf("No es capicua\n");
		}
	
	return 0;
}


int capicua(int *numero_desc)
	{
		int posicion_final = TOPE -1 ; 
		/*resto 1 para obteber la ultima letra , strlen da la cantidad de palabras, pero las 
		posiciones empiezan por 0*/
		int indice = 0; /*recorro bucle desde la posicion iniciial*/
		int parte_atras = posicion_final-indice;
		while (indice<parte_atras)
			{
				if (numero_desc[indice]!=numero_desc[parte_atras])
					{
					return 0; /* no es palindroma*/			
					}
				++indice; /*aqui voy adelante*/
				parte_atras = posicion_final-indice; /*aqui voy para atras va decreciendo por el final*/
			}
		/*si he salido del bucle, es que nunca he entrado en el if de desigual por tanto es igual*/
		return 1; /*si lo es*/
	}

void descomponer(int num, int *num_desc)
	{
		int cociente, residuo;
		cociente = num;
		int final= TOPE - 1;
		while(cociente>=10)
			{
				/*el residuo lo voy poniendo pero empezando por el final del array*/
				residuo = cociente%10;
				printf("residuo %i",residuo);
				num_desc[final]=residuo;
				--final;
				/*calculo cociente*/
				cociente = cociente / 10;
			}
		residuo = cociente%10; 
		num_desc[final]=residuo;
		/*hago esto para obtenerlo como residuo
		tambien podia hacer directamente 
		num_desc[final]=cociente;
		*/
	/* comentado para mostrar el array/vector/unidimensional*/
		int i;
		for(i=0;i<final;i++)
			{
				printf("%i\n",num_desc[i]);
			}
}
