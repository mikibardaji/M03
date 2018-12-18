//3.-Función que cuenta el número de vocales de una frase.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cuantas_vocales(char *);

int main(){
	char frase[1024]="";

	
	printf("Escribe una frase:\n");
	gets(frase);
	
	
	printf("\n\nTu frase tiene %i vocales.",cuantas_vocales(frase));
	
	return 0;
}


int cuantas_vocales(char *frase)
{

int i=0, cuenta_vocales=0;
char letra;

while(frase[i]!='\0'){
		
		letra = toupper(frase[i]);
		switch (letra){
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':	cuenta_vocales++;												
		}
		i++;
	}

	return cuenta_vocales;
}