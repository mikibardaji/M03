#include <stdio.h>
#include <string.h>
#define GALO "ix"
#define ROMANO1 "us"
#define ROMANO2 "um"
#define ESCOCES_NOM "Mac"

char introducir_si_no();
void mostrar_resultados(int, int,int,int);
/*devolvera 0 si no es de la procedencia del segundo parametro*/
int procedencia(char *nombre,char *termina);
int procedencia_mejorada(char *nombre,char *termina);
void actualizar_contador_correcto(int *, int *, int *, int *, int);
int main()
	{
		
		char nombre_introducido[50];
		int num_galo=0,num_romano=0,num_escoces=0, num_mulato=0;
		char seguir;
		/*procedencia 1 galo
		procedencia 2 romano
		procedencia 3 griego
		procedencia 4 escoces
		procedencia 5 mulato*/
		int procede;
		do
		{
			procede = 0;
			printf("Introduce un nombre y te dire si es romano o galo:\n");
			gets(nombre_introducido);
			printf("Has introducido %s \n",nombre_introducido);
			
			/*saber de donde es el nombre*/
			if (procedencia(nombre_introducido,GALO))
				{
					procede=1;
				}
			else if(procedencia(nombre_introducido,ROMANO1) || procedencia(nombre_introducido,ROMANO2))
				{
					procede=2;
				}
			if(escoces(nombre_introducido))	
				{
					if (procede==0) /* no es origen anterior*/
						procede = 4;
					else
						procede = 5;
				}
			actualizar_contador_correcto(&num_galo,&num_romano,&num_escoces,&num_mulato,procede);
			printf("Vas a introducir otro nombre (S/N)");
			fflush(stdin);
			seguir = introducir_si_no();
		}while(seguir!='N');
		
		mostrar_resultados(num_galo,num_romano,num_escoces,num_mulato);
		
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
		
		
	void mostrar_resultados(int galo, int romano, int escoces, int mulato)
		{
			
			printf("Has introducido: ");
			printf("%i nombres galos ",galo);
			printf("%i nombres romanos ",romano);
			printf("%i nombres escoceces ",escoces);
			printf("%i nombres mulato ",mulato);
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

void actualizar_contador_correcto(int *galo,int *romano, int *escoces, int *mulato, int procedencia)
	{
		switch(procedencia)
		{
			case 1:
				*galo = *galo+1;
				break;
			case 2:
				*romano = *romano+1;
				break;
			case 4:
				*escoces = *escoces+1;				
				break;
			case 5:
				*mulato = *mulato+1;
				break;
		}
		
	}
	
	
	int escoces(char *nombre)
		{
			int long_nombre = strlen(nombre); /* aqui tendre lo largo del nombre introducido*/
			if (long_nombre<3) /* no pot tenir la procedencia*/
				{
					return 0;		
				}
			else
				{
					if (nombre[0] == ESCOCES_NOM[0] && nombre[1] == ESCOCES_NOM[1] && nombre[2] == ESCOCES_NOM[2]  )
						return 1;
					else
						return 0;	
				}
			
		}
