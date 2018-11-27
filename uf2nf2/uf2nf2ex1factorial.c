#include <stdio.h>
#include <stdlib.h>


int fact(int num);

int main()
{
	int facto
	printf("Introduce numero del factorial:");
        scan("%i",&facto);
	printf("El factorial de %i es %i ",facto,fact(5));

	return 0;
	
}

int fact(int num)
{
	//Caso factorial de 1 y 0
	if(num==1 || num==0)
	{
		printf("1\n");
		getchar();
		return 1;
	}
	
	//Caso generico
	
	else
	{
		int var= num*fact(num-1);
		printf("%i\n", var);
		getchar();
		return var;
	}	
}
