//5.-Programa que pide una frase y un carácter y nos dice cuantas veces aparece ese carácter en la frase.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cuenta_letra(char *, char);

int main(){
	char letra;
	char frase[1024]=" ";
	
	printf("Escribe una frase:\n");
	gets(frase);
	printf("Ahora el caracter a buscar:");
	scanf("%c",&letra);
	
	printf("Tu letra aparece %i veces", cuenta_letra(frase, letra));
	
	return 0;
}

int cuenta_letra(char *frase, char letra){
	int cont = 0, i = 0;
		
	for(i=0;i<strlen(frase);++i){
		if(frase[i] == letra){
			cont++;
		}
	}
	
	return cont;
}

