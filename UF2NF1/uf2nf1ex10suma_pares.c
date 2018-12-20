#include <stdio.h>

int suma_pares(int num);
int pedir_positivo();

int main()
	{
		int num;
		printf("Pon el numero y sumare todos los pares que hay hasta el 0... ");
		num = pedir_positivo();


		int suma = suma_pares(num);
		if (suma < 0) 
			{
				printf ("Has metido un impar que te he dicho par!!");
			}
		else
			{
				printf("La suma de todos los pares hasta el %i es %i",num,suma);
			}
		
		getch();
	}
	
int suma_pares(int num)
	{
		if (num%2!=0)
			{
				return -1;
			}
		else if (num==2)
			{
				return 2;
			}
		else
			{
				return num + suma_pares(num-2);
			}
		
	}

int pedir_positivo()
	{
	int valor;
	do
	{
	scanf("%i",&valor);
	if (valor<=0)
		{
		printf("introducir valor positivo\n");
		}
	}while(valor<=0);
}
