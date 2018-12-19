#include <stdio.h>

/*
Programa que calcula la edad de una persona recibiendo como datos de entrada 
la fecha de nacimiento y la fecha actual, ambas en tres variables que 
recibirán el día (del 1 al 31), el mes (del 1 al 12) y el año en número entero.
*/

int calculo(int a0,int m0,int d0,int Aac, int Mac, int Dac);

int main()
{
	int a0, m0, d0, Aac, Mac, Dac, resultado;
	
	printf("\nDigite el anyo en que nacio: ");
	scanf("%i", &a0);
	printf("\n");
	printf("\nDigite el mes en que nacio: ");
	scanf("%i", &m0);
	printf("\n");
	printf("\nDigite el dia en que nacio: ");
	scanf("%i", &d0);
	printf("\n");
	printf("\nDigite el anyo  actual: ");
	scanf("%i", &Aac);
	printf("\n");
	printf("\nDigite el mes actual: ");
	scanf("%i", &Mac);
	printf("\n");
	printf("\nDigite el dia actual: ");
	scanf("%i", &Dac);
	printf("\n");
	
	resultado = calculo(a0, m0, d0, Aac, Mac, Dac);
	
	printf("\nTienes %i anyos", resultado);
	printf("\n");
		
	return 0;
}

int calculo(int a0,int m0,int d0,int Aac, int Mac, int Dac)
{
	int result;
	
	if(m0==Mac) /*si coincide el mes*/
		{
			if(Dac>=d0)
				{
					result = Aac-a0;
				}
			else if(Dac<d0)
				{
					result = Aac-a0-1;
				}
		}
	else if(Mac<m0) /* mes actual mas pequeño que el mes naciste*/
		{
			result = Aac-a0-1;
		}
	else
		{
			result = Aac-a0;	
		}
	
	
	return result;
}
