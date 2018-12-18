//6.-Programa que pide una frase y devuelve el número de palabras que contiene (para saber cuantas palabras tienes contaremos que siempre que hay un espacio,
// se ha terminado una palabra).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	char letra;
	char frase[1024]=" ";
	int cont = 0, i = 0;	
	
	printf("Escribe una frase:\n");
	gets(frase);
	
	while(frase[i]!='\0'){
		if(frase[i] == ' '){
			cont++;
		}
		i++;
	}
	
	printf("Tu frase tiene %i palabras", cont+1);
	
	return 0;
}
