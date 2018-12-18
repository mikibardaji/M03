//7.- Pide una palabra y luego una función codifica cada letra sumandole 3 , devuelve la palabra "codificada"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void codifica(char *);

int main(){
	char letra;
	char palabra[1024]=" ";
	int i = 0;	
	
	printf("Escribe una palabra:\n");
	gets(palabra);
	
	codifica(palabra);
	printf("\nTu palabra codificada es: %s", palabra);
	
	return 0;
}

void codifica(char *palabra){
	int i = 0;
	
	while(palabra[i]!='\0'){
		palabra[i] +=3;
		i++;
	}
}
