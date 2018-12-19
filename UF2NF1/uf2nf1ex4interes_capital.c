#include <stdio.h>

/*
Programa que toma como datos de entrada el capital C en pesetas depositado en un banco,
 el interés R en tanto por ciento y el tiempo T en años que estará el mencionado capital
  depositado y nos calcula y escribe los intereses en euros que recibiremos transcurridos 
  los T años. El cálculo se realizará por medio de la fórmula del interés simple. I = C·R·T / 100
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

