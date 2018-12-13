#include <stdio.h>
#include <string.h>

void imprimir_reves_nombre(char *);

int main()
{
	char animal[] = "gato"; //vector de longitud 5
	char altre_animal[] = {'l','o','b','o','\0'}; //vector de longitud 5
	char tercer_animal[] = {'l','o','r','o'}; //vector de 4 posiciones 
	char animal_llarg[100] = "ornitorrinco";
	char buit[] = "";
	
	char *p = animal_llarg;
	
	puts(p); //imprime toda la cadena
	p = altre_animal;
	puts(p); //imprime toda la cadena
	
	printf("Terminado el put\n");
	printf("%s",animal);
	
	printf("Escribe tu animal preferido\n");
	gets(buit); //cadena de string
	printf("Has escrito\n");
	puts(buit);
	int recorrer;

	/*recorrer uno a uno la cadena string*/
	for (recorrer=0;recorrer<strlen(buit);recorrer++)
		{
			printf("%c \n",buit[recorrer]);
		}

	printf("========= y ahora al reves============\n");
	/*recorrer uno a uno de final a principiostring*/
	for (recorrer=strlen(buit);recorrer>=0;--recorrer)
		{
			printf("%c \n",buit[recorrer]);
		}

	printf("========= y ahora las vocales las pondre a espacios ============\n");
	/*recorrer uno a uno de final a principiostring*/
	for (recorrer=0;recorrer<strlen(buit);recorrer++)
		{
			if (buit[recorrer]=='a' || buit[recorrer]=='e' || buit[recorrer]=='i' || buit[recorrer]=='o')
				{
					buit[recorrer] = ' ';
				}
			printf("%c \n",buit[recorrer]);
		}

	printf("========= y ahora las vocales todas las pasare a  ============\n");
	/*recorrer uno a uno de final a principiostring*/
	for (recorrer=0;recorrer<strlen(buit);recorrer++)
		{
			if (buit[recorrer]==' ')
				{
					buit[recorrer] = 'a';
				}
			printf("%c \n",buit[recorrer]);
		}
		
	
	
	for (recorrer=strlen(buit);recorrer>=0;--recorrer)
		{
			printf("%c \n",buit[recorrer]);
		}


	imprimir_reves_nombre(buit);
	puts(buit);

}


void imprimir_reves_nombre(char *nombre)
{
	int recorrer;
	printf("========= LA FUNCION QUE DA EL TEXTO AL REVES ============\n");
	/*recorrer uno a uno de final a principiostring*/
	for (recorrer=strlen(nombre)-1;recorrer>=0;--recorrer)
		{
			printf("%c \n",nombre[recorrer]);
			nombre[recorrer]='x';
		}
	
}



