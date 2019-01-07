#include <stdio.h>
#include <string.h>
#define GALO "ix"
#define ROMANO1 "us"
#define ROMANO2 "um"

char introducir_si_no();
void mostrar_resultados(int, int);
/*devolvera 0 si no es de la procedencia del segundo parametro*/
int procedencia(char *nombre,char *termina);
int procedencia_mejorada(char *nombre,char *termina);

int main()
	{
		
		char nombre_introducido[50];
		int num_nombre_galo=0,num_nombre_romano=0;
		char seguir;
		
		do
		{
			printf("Introduce un nombre y te dire si es romano o galo:\n");
			gets(nombre_introducido);
			printf("Has introducido %s \n",nombre_introducido);
			
			/*saber de donde es el nombre*/
			if (procedencia(nombre_introducido,GALO))
				{
					++num_nombre_galo;
				}
			else if(procedencia(nombre_introducido,ROMANO1) || procedencia(nombre_introducido,ROMANO2))
				{
					++num_nombre_romano;
				}
			
			printf("Vas a introducir otro nombre (S/N)");
			fflush(stdin);
			seguir = introducir_si_no();
		}while(seguir!='N');
		
		mostrar_resultados(num_nombre_galo,num_nombre_romano);
		
	}
	
	
	
	char introducir_si_no()
		{
			char letra;
			do
			{
				fflush(stdin);
				scanf("%c",&letra);
				fflush(stdin);
				if (letra=='S' || letra == 'N')
					{
						return letra;
					}
				else 
					{
						printf("Introduce letra S o N mayuscula... ");
					}
			}while(letra!='S' && letra != 'N');
		}
		
		
	void mostrar_resultados(int galo, int romano)
		{
			
			printf("Has introducido: ");
			printf("%i nombres galos ",galo);
			printf("%i nombres romanos ",romano);
		}
		
	/*li passo el nom i la procedencia, el suposit es que la terminacio sempre es de 2 paraules sino, no funciona la funció
	retorna 1 si te la terminació
	retorna 0 si no te la terminació*/
		
	int procedencia(char *nombre,char *termina)
		{
			int long_nombre = strlen(nombre); /* aqui tendre lo largo del nombre introducido*/
			if (long_nombre<2) /* no pot tenir la procedencia*/
				{
					return 0;		
				}
			else
				{
					int long_terminacion =  strlen(termina); /*aqui tendre largo de la introducción, en estos casos siempre es 2*/
					printf("%s tiene la longitud %i\n",nombre, long_nombre);
					printf("%s tiene la longitud %i\n",termina, long_terminacion);
					int indice=0;
					while(indice<=long_terminacion)
						{
							printf("indice ->%c \n",termina[indice]);
							indice++;
						}
					printf("terminado");
					if (nombre[long_nombre-2] == termina[0] && nombre[long_nombre-1] == termina[1])
						return 1;
					else
						return 0;	
				}
			
		}
		

/*Aquest es igual que procedencia, pero millora que si la terminació enlloc de dos paraules fossin terminacions variables pues ho aceptaria*/
	int procedencia_mejorada(char *nombre,char *termina)
		{
			int long_nombre = strlen(nombre); /* aqui tendre lo largo del nombre introducido*/
			int long_terminacion =  strlen(termina); /*aqui tendre largo de la introducción, en estos casos siempre es 2*/
			printf("%s tiene la longitud %i\n",nombre, long_nombre);
			printf("%s tiene la longitud %i\n",termina, long_terminacion);
			int indice=0;
			printf("%c <--> %c\n", termina[indice],nombre[long_nombre-long_terminacion+indice]);
			while(termina[indice]==nombre[long_nombre-long_terminacion+indice] && indice<long_terminacion)
				{
					/*es igual aumento el indice*/
					++indice;					
					printf("%c <--> %c \n", termina[indice],nombre[long_nombre-long_terminacion+indice]);
				}
			if (indice==long_terminacion) /*los he recorrido todos*/
				return 1;
			else
				return 0;
		}
