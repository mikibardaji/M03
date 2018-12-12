#include <stdio.h>

int pide_valor_positivo();
int potes(int aranyes);

int main()

{
	printf("Cuantes aranyes li vols contar les potes?:");
	int aranyes=pide_valor_positivo();
	int num_potes=potes(aranyes);
	printf("les potes que tenen les aranyes son: %i",num_potes);
	return 0;
}


int potes(int aranyes)
	{
		/*caso base*/
		if (aranyes==1)
			{
				return 8;
			}
		else
			{
				return patas(aranyes-1) + 8;
			}
			
		/*caso recursivo*/
	}
	
	
int potes_deformes(int aranyes)
	{
		/*caso base*/
		if (aranyes==1)
			{
				return 8;
			}
		else
			{
				if (aranyes%2==0)
				 	return patas(aranyes-1) + 6;
				else
					return patas(aranyes-1) + 8;
			}
			
		/*caso recursivo*/
	}







int pide_valor_positivo(){
	int valor;
	
	do {
		fflush(stdin);
		scanf("%i",&valor);
		if(valor < 0){
			printf("El valor ha de ser positivo. Escríbelo de nuevo: ");
		}
	}while(valor<0);
	
		return valor;
}
