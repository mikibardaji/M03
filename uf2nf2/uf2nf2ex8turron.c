#include <stdio.h>

int calorias(int dias)
{
	if (dias==1)
		{
			return 3*dias*91;
		}
	else if (dias%3==0)
		{
			return 1*91 + calorias(dias-1);
	    }
	else
		{
			return 3*91 + calorias(dias-1);
		}
}


int main()
	{
		int dias, dieta;
		printf("En que dia te encuentras de navidad? ");
		scanf("%i",&dias);
		
		dieta=calorias(dias);
		
		printf("llevas %i calorias en turron consumido",dieta);
		return 0;
	}
