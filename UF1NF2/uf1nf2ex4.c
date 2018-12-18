//4.- Desenvolupeu un programa que demani a l’usuari el seu nom i escrigui el nombre de caràcters que conté, i quants d’ells són vocals. 
//No cal tenir en compte les vocals accentuades. Es te que utilitzar dues funcions, una que conti caracters que té, i la segona que conti vocals.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cuantas_vocales(char *);
int longitud_frase(char *);


int main(){
	char frase[1024]="";
	
	printf("Escribe tu nombre:\n");
	gets(frase);
	
	printf("Tu nombre tiene %i letras y %i vocales", longitud_frase(frase), cuantas_vocales(frase));
	
	return 0;
}

int longitud_frase(char *frase){
     int longitud=0;
     
	 while(frase[longitud]!='\0'){ 
	 	longitud = longitud + 1;
	 }
	 return longitud;
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
