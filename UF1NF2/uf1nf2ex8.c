//8.-Realiza una funci�n que pida una frase y otra funci�n que escriba la frase al rev�s.

//Ejemplo:

//'Hola que tal' ------> 'lat euq aloH'

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void pide_frase(char *);
void cadena_al_reves(char *);

int main(){
	setlocale(LC_ALL, ""); //Para que se puedan printar caracteres especiales (�, acentos...)		
	
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
