#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
	{
		char titulo[30];
		int segundos;
		int precio;
	}Cancion;

int menu();
int num_canciones_disco(char *titulo);
void pedir_titulo_disco(char *disco);
void nombre_fichero(char *disco, char * fichero);
void anyadir_cancion_fichero();
void comprobar_anyadir_disco(char *nom_disc);
void listado_canciones(char *disco);
void listado_discos();
void reproduccion_aleatoria();
void listado_discografia_total();
void canciones_por_precio(char *disco);


int main(int argc, char **argv)
{
	srand (time(NULL)); 
	int opcion, fitxer, vocals, paraules;
	char disco[30];	
	do
	{
		opcion = menu();
		printf("\n");
		switch(opcion)
		{
			case 1:
				anyadir_cancion_fichero();
				break;
				
				
			case 2:
				pedir_titulo_disco(disco);
				listado_canciones(disco);
				break;
				
				
			case 3:
				listado_discos();
				/*printf("Hi ha %i paraules",paraules);*/
				printf("\n");
				break;
				
				
			case 4:
				pedir_titulo_disco(disco);
				canciones_por_precio(disco);
				printf("\n");
				break;
				
				
			case 5:
				reproduccion_aleatoria();
				printf("\n");
				break;
				
				
			case 6:
				listado_discografia_total();
				printf("\n");
				break;
				
				
			case 7:
				//anyadir_frase("exercici2.txt");
				printf("Saliendo del programa...\n");
				break;
				
				
			case 8:
			//salir	
				break;
			default:
				break;
		}
				
	}
	while(opcion<7);
		
}
	
int menu()
{
	int opcion;
	printf("*******************\n");
	printf("1.- Anyadir canci%cn al disco\n",162);
	printf("2.- Listar canciones del disco\n");
	printf("3.- Listado de discos\n");
	printf("4.- Listado canciones por precio\n");
	printf("5.- Reproducci%cn aleatoria\n",162);
	printf("6.- Discografia completa\n");
	printf("7.- Salir\n");
	printf("*******************\n");
	printf("Escoge opcion:");
	scanf("%i",&opcion);
	return opcion;
}

void canciones_por_precio(char *disco)
	{
		printf("Opcion no implementada aun\n");
	}

void reproduccion_aleatoria()
	{
		int num_cancion;
		
		char nombref[35],disco[30];
		pedir_titulo_disco(disco);
		
		nombre_fichero(disco,nombref);
		
		num_cancion = num_canciones_disco(disco);
		
		int escogida = rand()%num_cancion+1;
		
		printf("fichero a abrir del disco %s\n",nombref);
		FILE *fdisco;
		Cancion leer;
		fdisco = fopen(nombref,"rb");
		if (fdisco==NULL)
			{
				printf("Error en disco\n");
			}
		else
			{
				fread(&leer,sizeof(Cancion),1,fdisco);
				int i=0;
				while(!feof(fdisco))
					{	
						i++;
						if (i==escogida)
							{
								printf("Canci%cn escogida al azar la numero %i - %s\n",162,i,leer.titulo);
							}
						
						fread(&leer,sizeof(Cancion),1,fdisco);
					}
					//printf("Canciones :%i\n",i);
				fclose(fdisco);
				getch();
			}
		
	}


void comprobar_anyadir_disco(char *nom_disc)
	{
		FILE *flista;
		char titulo[30];
		
		flista = fopen("lista_discos.txt","r");
		strcat(nom_disc,"\n");
		if (flista == NULL)
			{
				printf("lista_discos.txt mo anyadido \n");
				flista = fopen("lista_discos.txt","a+t");
				fputs(nom_disc,flista);
				printf("Anyadido el titulo %s a la lista_discos.txt",nom_disc);
				fclose(flista);
			}
		else
			{
				fgets(titulo,30,flista);
				int found=0;
				while(!feof(flista) && found==0) 
					{
						if(strcmp(titulo,nom_disc)==0)
							{
								printf("Disco ya existente\n");
								found=1;
							}
						else
							{
								fgets(titulo,30,flista);
							}
				    }
				    fclose(flista);
					if (found==0 && strcmp(titulo,nom_disc)!=0)
							{
								flista = fopen("lista_discos.txt","a+t");
								fputs(nom_disc,flista);
								fputc('\n',flista);
								printf("Anyadido el titulo '%s' a la lista_discos.txt\n",nom_disc);
								fclose(flista);
							}
				
			}
	}
	
	
void listado_discos()
	{
		FILE *flista;
		char titulo[30];
		
		flista = fopen("lista_discos.txt","r");
		if (flista == NULL)
			{
				printf("fichero no existente\n");
			}
		else
			{
				int ndisco=0;
				fgets(titulo,30,flista);
				printf("Lista de discos****\n");
				while(!feof(flista)) 
					{
						ndisco++;
						printf("%s",titulo);
						fgets(titulo,30,flista);
				    }
				    printf("%s\n",titulo);
				    ndisco++;
				    printf("Discos %i\n",ndisco);
					fclose(flista);
					getch();
			}
		
	}
	

void pedir_titulo_disco(char *disco)
	{
		printf("Pon el nombre del disco al que quieres anyadir canci%cn :",162);
		fflush(stdin);
		gets(disco);
		fflush(stdin);
	}
	

void listado_canciones(char *disco)
	{
	char  fichero[35];
	
	nombre_fichero(disco,fichero);
	printf("fichero a abrir del disco %s\n",fichero);
	FILE *fdisco;
	Cancion leer;
	fdisco = fopen(fichero,"rb");
	if (fdisco==NULL)
		{
			printf("Error en disco\n");
		}
	else
		{
			fread(&leer,sizeof(Cancion),1,fdisco);
			int i=0;
			while(!feof(fdisco))
				{	
					i++;
					printf("%i-%s\n",i,leer.titulo);
					fread(&leer,sizeof(Cancion),1,fdisco);
				}
				printf("Canciones :%i\n",i);
			fclose(fdisco);
			getch();
		}
	}	
	
void anyadir_cancion_fichero()
	{
		char disco[30], fichero[35];
		Cancion add;
		pedir_titulo_disco(disco);
				
		printf("Pon el título de la canci%cn :",162);
		fflush(stdin);
		gets(add.titulo);
		fflush(stdin);
		printf("Pon la duraci%cn en segundos :",162);
		scanf("%i",&add.segundos);
		fflush(stdin);
		printf("Pon el precio en itunes:");
		scanf("%i",&add.precio);
		fflush(stdin);
		
		FILE *disco_abrir;
		int num_canciones = num_canciones_disco(disco);
		printf("numero cancines existentes en este disco...%i \n", num_canciones);
		if (num_canciones<10)
			{
				nombre_fichero(disco,fichero);
				disco_abrir = fopen(fichero,"a+b");
				fwrite(&add,sizeof(Cancion),1,disco_abrir);
				fclose(disco_abrir);				
				printf("Canci%cn anyadida...\n",162);
				comprobar_anyadir_disco(disco);
			}
		else
			{
				printf("El disco ya contiene 10 canciones no se puede anyadir mas...\n");
			}
		
	}
	
int num_canciones_disco(char *titulo)
	{
		char fichero[35];
		
		nombre_fichero(titulo,fichero);
		FILE *disco_bin;
		Cancion leer;
		int canciones=0;
		disco_bin = fopen(fichero,"rb");
		if (disco_bin == NULL)
			{
				printf("No existe el archivo consultado\n");
				canciones=0;
			}
		else
			{
				fread(&leer,sizeof(Cancion),1,disco_bin);
				while (!feof(disco_bin))
					{
						canciones++;
						fread(&leer,sizeof(Cancion),1,disco_bin);
					}
				fclose(disco_bin);
				
			}
		
		return canciones;
		
	}
	
	
void nombre_fichero(char *disco, char *fichero)
	{
		strcpy(fichero,disco);
		strcat(fichero,".bin");
	}
	
	
void listado_discografia_total()
	{
		FILE *flista;
		char titulo[30];
		printf("Discografia completa****\n");
		flista = fopen("lista_discos.txt","r");
		if (flista == NULL)
			{
				printf("fichero no existente\n");
			}
		else
			{
				int ndisco=0;
				fgets(titulo,30,flista);
				
				while(!feof(flista)) 
					{
						
						ndisco++;
						printf("%s",titulo);
						titulo[strlen(titulo)]='\0';
						listado_canciones(titulo);
						char fitxer[35];
						nombre_fichero(titulo,fitxer);
						fgets(titulo,30,flista);
				    }
				    printf("%s\n",titulo);
				    ndisco++;
				    printf("Discos %i\n",ndisco);
					fclose(flista);
					getch();
			}
		
	}
