#include <stdio.h>
#define TOPE 10
int aleatorio (int tope);
void muestra_array (int *n, int tope);
int sumar_numeros_array (int *n, int tope);
int main()
	{
		srand(time(NULL));
		int n[TOPE];
		int i, final, acum=0;
		
		final= TOPE-1;
		
		
		for(i=0;i<final;i++)
			{
				n[i]=aleatorio(TOPE);
			}
			
			
		n[final]=sumar_numeros_array(n,TOPE);
		
		
		muestra_array (n,TOPE);
		
		return 0;
	}
int aleatorio (int tope)
	{
		int n;
		n = (rand()%tope)+1;
			
		return n;
	}
	
int sumar_numeros_array (int *n, int tope)
	{
			int i, acum=0;
		
		for(i=0;i<tope-1;i++)
			{
				acum= acum + n[i];
			}
			return acum;
	}
	
void muestra_array (int *n, int tope)
	{
		int i;
		
		for(i=0;i<tope;i++)
			{
				printf("\nEn la posicion %i esta el numero: %i\n", i+1, n[i]);
			}
	}
