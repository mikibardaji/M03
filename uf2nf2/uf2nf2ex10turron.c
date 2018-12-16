#include <stdio.h>

int virus(int dias)
{
	if (dias==1)
		{
			return 1;
		}
	else
		{
			return 3*virus(dias-1);
		}
}


int main()
	{
		int dias, numero;
		printf("En que dia nos encontramos de estudio del virus? ");
		scanf("%i",&dias);
		
		numero=virus(dias);
		
		printf("En la muestra va a haber %i virus",numero);
		return 0;
	}
