#include <stdio.h>

/*
Programa que toma como datos de entrada el capital C en pesetas depositado en un banco,
 el inter�s R en tanto por ciento y el tiempo T en a�os que estar� el mencionado capital
  depositado y nos calcula y escribe los intereses en euros que recibiremos transcurridos 
  los T a�os. El c�lculo se realizar� por medio de la f�rmula del inter�s simple. I = C�R�T / 100
*/
float intereses(int capital,int tiempo,int interes){
	float rentabilidad;
	rentabilidad = capital * interes * tiempo /100;
	return rentabilidad;
}


float pesetas_euros(float pesetas)
	{
		return pesetas/166;
	}


int main()
	{
    	int capital,tiempo,interes;
		
		printf("introduce capital : ");
		scanf("%i",&capital);
		
		printf("introduce interes : ");
		scanf("%i",&interes);	
		
		printf("introduce tiempo : ");
		scanf("%i",&tiempo);
		
		float rentabilidad;
		rentabilidad = intereses(capital,tiempo,interes);
		rentabilidad = pesetas_euros(rentabilidad);
		printf("los intereses son : %.3f",rentabilidad);
		
		return 0;
	}

