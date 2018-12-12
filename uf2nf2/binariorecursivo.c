#include <stdio.h>

int pide_valor_positivo();
void binario(int num);
void invertir(int num);

int main()
{
	
	printf("pon un valor que transformare en positivo: ");
	int valor=pide_valor_positivo();
	invertir(valor);

	return 0;	
}


void invertir(int num)
{
	int residuo;
	/*caso base*/
	if (num<10)
		{
			printf("%i",num); /*imprimir el valor en binario*/
		}
	else /*mayor que 9*/ 	/*caso recursivo*/
		{
			residuo = num%10;
			printf("%i", residuo);	
			
			invertir(num/10);
		
			}	
	
}




void binario(int num)
{
	int residuo;
	/*caso base*/
	if (num<2)
		{
			printf("%i",num); /*imprimir el valor en binario*/
		}
	else /*mayor que 1*/ 	/*caso recursivo*/
		{
			binario(num/2);
			residuo = num%2;
			printf("%i", residuo);	
			}	
	
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
