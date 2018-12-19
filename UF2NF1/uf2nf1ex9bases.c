#include <stdio.h>
#include <stdlib.h>

#define RETENES 10

int mueren();
void soldados_restantes(int *soldados,int muertos,int reten);

int main()
{
	int bases, soldados, muertos;
	srand(time(NULL));
	
	

		printf("Cuantos soldados dispones?  ");
		scanf("%i",&soldados);
		printf("Cuantas bases vas a asaltar? ");
		scanf("%i",&bases);
		
		while (soldados>0 && bases >0)
			{
				muertos = mueren();
				printf("**FRASE OPTATIVA** En la base %i han muerto %i soldados...\n",bases,muertos);
				soldados_restantes(&soldados,muertos,RETENES);
				printf("**FRASE OPTATIVA** Despues de dejar retenes aun te quedan  %i soldados...\n",soldados);
				if (soldados>0)
					bases--;
			}
	
	if (bases==0)
		{
			printf("Has ganado te quedan %i soldados para celebrarlo!!! FIESTA!!!",soldados);
		}
	else
		{
			printf("Has perdido te quedan %i bases por conquistar ... EL IMPERIO GANA",bases);
		}
	
	getch();
	
	return 0;
}


int mueren()
	{
		int muertos = rand()%20 + 1;
		return muertos;
	}
	
void soldados_restantes(int *soldados,int muertos,int reten)
	{
		if (*soldados<(muertos+reten))
			{
				*soldados = 0;
			}
		else
			{
				*soldados = *soldados - muertos - reten;
			}
	}
	
	
	
