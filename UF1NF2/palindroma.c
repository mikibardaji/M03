#include <stdio.h>
#include <string.h>
#define TOPE 50

int palindroma_ainhoa(char *);



int main()
{
	char palabra[TOPE];
	int palind;
	/*recorrer frase*/
	printf("Escribe palabra:");
	gets(palabra);
	printf("has escrito:");
	puts(palabra);
	
	palind = palindroma_ainhoa(palabra);
	
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


int palindroma_ainhoa(char *palabra)
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
