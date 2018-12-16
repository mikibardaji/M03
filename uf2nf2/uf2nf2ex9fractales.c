#include <stdio.h>

int fractales(int longitud)
{
	if (longitud==1)
		{
			return 4*longitud;
		}
	else
		{
			return (4*longitud + 4*fractales(longitud/2));
		}
}


int main()
	{
		int metros, numero;
		printf("Pon la longitud del cuadrado madre? ");
		scanf("%i",&metros);
		
		numero=fractales(metros);
		
		printf("Los metros totales de los cuadrados son  %i",numero);
		return 0;
	}
