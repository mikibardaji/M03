/*2.Realiza un programa recursivo donde el usuario introduce una frase y un caràcter.El programa nos indica cuantas veces
 aparece dicho caràcter en la frase y además lo canvia por una @.(5p)*/


#include <stdio.h>
#include <conio.h>
#include <string.h>

int veces(char[], char, int, int);

main ()
{
	char frase[20], letra;
	int i=0, cont=0, total=0;
	
	//pedimos datos 
	printf("Introduzca una frase: ");
	gets(frase);
	printf("Introduzca un caracter a buscar: ");
	scanf("%c",&letra);
	
	//invocamos a la funcion 
	total=veces(frase,letra,i, cont);  
	
	//imprimimos el total de veces que se repite 
	printf("El numero de %c es %i\n",letra,total);
	puts(frase);
}


//funcion recursiva veces
int veces(char frase[], char letra, int i, int cont)
{
	if (frase[i]=='\0') return cont; //coso base cuando llegue al final de la cadena 
	
	//caso recursivo
	else         //comparamos cada caracter con la letra i sumamos el contador de veces
	{
		if (frase[i]==letra)
	 	{
	 		cont=cont+1;
	 		frase[i]='@'; //sustituimos el caracter por @
	 	}
		veces(frase,letra,i+1,cont); //llamamos de forma recursiva para recorrer la frase
	}
}
