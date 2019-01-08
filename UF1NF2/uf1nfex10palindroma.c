#include <stdio.h>
#include <string.h>
#define TOPE 50

int palindroma_copiando_otro_string(char *);
int palindroma(char *);


int main()
{
	char palabra[TOPE];
	int palind;
	/*recorrer frase*/
	printf("Escribe palabra:");
	gets(palabra);
	printf("has escrito:");
	puts(palabra);
	
	palind = palindroma(palabra);
	
	if(palind==1)
		{
			printf("Es palindroma\n");
		}
	else
		{
			printf("No es palindroma\n");
		}
	
	return 0;
}


int palindroma(char *palabra)
	{
		int posicion_final = strlen(palabra) -1 ; 
		/*resto 1 para obteber la ultima letra , strlen da la cantidad de palabras, pero las 
		posiciones empiezan por 0*/
		int indice = 0; /*recorro bucle desde la posicion iniciial*/
		int parte_atras = posicion_final-indice;
		while (indice<parte_atras)
			{
				if (palabra[indice]!=palabra[parte_atras])
					{
					return 0; /* no es palindroma*/			
					}
				++indice; /*aqui voy adelante*/
				parte_atras = posicion_final-indice; /*aqui voy para atras va decreciendo por el final*/
			}
		/*si he salido del bucle, es que nunca he entrado en el if de desigual por tanto es igual*/
		return 1; /*si lo es*/
	}

int palindroma_copiando_otro_string(char *palabra)
	{
		char reves[TOPE];
		int posicion_final = strlen(palabra)-1; /*ultima letra aqui no hay el \0*/
		
		int indice;
		for(indice=0;indice<=posicion_final;indice++)
			{
				reves[posicion_final-indice] = palabra[indice];
			}
		
		indice=0;
		while(indice<=posicion_final)
			{
				
				if(palabra[indice]!=reves[indice])
					{
						return 0;
					}
				++indice;
			}
		return 1; /*si llegue al final sin entrar en el if es que son iguales*/	
}
