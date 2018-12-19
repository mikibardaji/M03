//8.-Realiza una función que pida una frase y otra función que escriba la frase al revés.

//Ejemplo:

//'Hola que tal' ------> 'lat euq aloH'

#include <stdio.h>
#include <wchar.h>

#include <stdlib.h>
#include <string.h>

void pide_frase(char *);
void cadena_al_reves(char *);

int main(){
		
	
	char frase[1024]=" ";

	
	pide_frase(frase);
	
	cadena_al_reves(frase);
	
	return 0;
}

void pide_frase(char *frase){
	printf("Escribe una frase:\n");
	gets(frase);	
}

void cadena_al_reves(char *frase){
	int i;
	
	for(i = strlen(frase)-1;i>=0; i--){
		printf("%c",frase[i]);
	}
	printf("\n");
}
