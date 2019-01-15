#include <stdio.h>
#define TOPE 10
int aleatorio (int tope);
void muestra_array (int *n, int tope);
int sumar_numeros_array (int *n, int tope);
int cuantos_alumnos(int vector[],int N,int valor);
int main()
	{
		srand(time(NULL));
		int n[TOPE]; /*Notas*/
		int acum[11];
		int i, final;

		
		for(i=0;i<TOPE;i++)
			{ //pone notas a todos los alumnos
				n[i]=aleatorio(TOPE);
				
			}
				
		muestra_array (n,TOPE);
		int nota=0;
		for(nota=0;nota<=10;nota++)
			{ /*acumulo y guardo en el nuevo array*/
				
				acum[nota] =cuantos_alumnos(n,TOPE,nota); 
				
			}
			/*recorro y muestro el array acumulado*/
		for(nota=0;nota<=10;nota++)
			{
				printf("Alumnos que han sacado un %i son %i\n",nota, acum[nota]);
			}
	
	printf("termino programa");
		
		
		return 0;
	}
	
	
	
	
int aleatorio (int tope)
	{
		int n;
		n = (rand()%tope)+1;
			
		return n;
	}
	

	
void muestra_array (int *n, int tope)
	{
		int i;
		
		for(i=0;i<tope;i++)
			{
				printf("\nEl alumno %i ha sacado un : %i\n", i+1, n[i]);
			}
	}
	
	
	
int cuantos_alumnos(int vector[],int N,int nota){
	int i=0;
	int encontrados=0;
		
	while(i<N && nota<=vector[i]){
		
		if (vector[i]==nota){
			encontrados = encontrados + 1;//cuandl lo encuentro sumo 1 a los encontrados			
		}
		i++;//comparo el siguiente numero del vector		
	}
	return encontrados;
}
