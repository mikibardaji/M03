#include<stdio.h>
#include<stdlib.h>


int binario(int n){
	if(n>1)      
	{
	  binario(n/2);
	}
	printf("%i",n%2);
}

int main(){

int num;
printf("\n\t\t[     RECURSIVIDAD     ]\n");
printf("\t\t------------------\n\n");
printf("  Conversor a binario \n\n");
do{
printf(" PON NUMERO: ");
scanf("%i",&num);
if(num<0) 
	{
		printf("\nEl numero debe ser positivo… \n");
	}
}while(num<0);

printf("\n\n Numero: %i\n",num);
printf("\n Binario:");
    binario(num);
return 0;
}
