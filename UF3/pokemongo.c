#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXPOK 50
void mostrar_fichero(char *nombrefichero); //kle pasare un string con el nombre
int menu();
void cazar_pokemon();
void guardar_mochila(char nombre_pokemon[]);
void listar_mochila();
void intercambiar(char *num1, char *num2);
//void burbuja(char **lista, int tamanyo)	;
void burbuja(char lista[MAXPOK][20], int tamanyo);
void ordenar_mochila(char *nombrefichero);
int guardar_array_mochila(char lista[MAXPOK][20], int tamanyo,char *nombrefichero);


int main()
	{
		srand(time(NULL));
		int men;
		mostrar_fichero("cabecera.txt");
		do
			{
				printf("\n");
				men=menu();
				printf("\n");
				
				switch(men)
					{
						case 1:	cazar_pokemon();
							break;
						case 2: 
							ordenar_mochila("mochila.txt");
							listar_mochila();
							break;
						case 3:
							break;
						default:printf("\nOpcion incorrecta!!\n");
							break;
					}
			}while(men!=3);
		printf("\n---Saliendo del juego...---\n");
		
		return 0;
	}
	
	
void mostrar_fichero(char *nombrefichero)
	{
		FILE *cab;
		char cabecera;
		
		cab = fopen(nombrefichero,"r");
		
		if(cab==NULL)
			{
				printf("\nHa habido un error al abrir el fichero %s \n",nombrefichero);
				exit(1);
			}
		cabecera = '\n'; //le pongo a vacio para el primer printf que no tenga basura 
		do
			{
				printf("%c", cabecera);
				cabecera = fgetc(cab);
/*retrasar		if (cabecera=='\n'  && (strcmp(nombrefichero,"cabecera.txt")!=0))
					{
						sleep(1); //para la ejecución 1 segundo
					}*/
			}while(cabecera != EOF);
		
		fclose(cab);
		
	}


void ordenar_mochila(char *nombrefichero)
	{
		FILE *cab;
		char lista_pokemons[MAXPOK][20]; //[numero de pokemons][longitud del nombre pokemon]
		
		cab = fopen(nombrefichero,"r");
		
		if(cab==NULL)
			{
				printf("\nHa habido un error al abrir el fichero %s \n",nombrefichero);
				exit(1);
			}
		int num=0;
		do
			{
				fgets(lista_pokemons[num],20,cab);
				num++;
			}while(feof(cab)==0);
		//tengo el array con todos los nmbres cargados
		burbuja(lista_pokemons,num);
		//ahora despues de la burbuja los tengo ordenados
		//llamare a una función que sobreescribe la mochila pero ordenada
		//muy parecida a listar pero al inreves en lugar de mostrar por pantalla escribo en fichero
		if (guardar_array_mochila(lista_pokemons,num,nombrefichero)!=0)
			{
				printf("error en guardar pokemons ordenados en mochila\n");
			}
		//burbuja
		fclose(cab);
		
	}

void burbuja(char lista[MAXPOK][20], int tamanyo)	
	{
		int i,j;
		
		int penultima = tamanyo-1;
		char aux[20]; //variable para poder intercambiar posiciones
		for(i=0;i<penultima;++i)
			{
				for(j=0;j<penultima-i;j++)
					{
						if (strcmp(lista[j],lista[j+1])>0) /*intercambiar valores para dejar el mayor a la derecha*/
							{
										strcpy(aux,lista[j]); //guardo en variable auxiliar una de las posiciones
										strcpy(lista[j],lista[j+1]); //la otra posicion machaco la posición j
										strcpy(lista[j+1],aux);//en la j+1 guaro lo que tenia en aux
							}
					}	
				
			}		
	}

/*devuelve -1 si ha habido algun error
devuelve 0 para decir que se ha guardado bien*/	
int guardar_array_mochila(char lista[MAXPOK][20], int tamanyo,char *nombrefichero)	
	{
		int i;
		
		FILE *fmochila;
		
		fmochila = fopen(nombrefichero,"w"); //modo escritura borrando lo que haya
		if (fmochila==NULL)
			{
				return -1; //error abrir fichero
			}
		for(i=0;i<tamanyo;++i)
			{
				fputs(lista[i],fmochila); //escribo de uno en uno
			}		
			
			
		if (fclose(fmochila)!=0)
			{
				//error cerrando fichero;
				return -1;
			}
		return 0;
	}


int menu()
	{
		int opcion;
		printf("\[*****Menu principal*****]\n");
		printf("\n");
		printf("1) Cazar Pokemon\n");
		printf("2) Listar Pokemon cazados en mochila\n");
		printf("3) Salir\n");
		printf("\[************************]\n");
		printf("\n");
		printf("Escoga opcion: ");
		scanf("%i", &opcion);
		return opcion;
	}
int aleatorio(int min, int max)
	{
		int num, div;
		div = max-min+1;
		num=(rand()%div)+min;
		
		return num;
	}

void cazar_pokemon()
	{
		int pokemon, nivel, caza, cazado,num;
		pokemon =aleatorio(1, 3);
		char nombre_pokemon[20];
		
		printf("TE HA SALIDO UN...\n\n");
		getch();
		if(pokemon == 1)
			{
				strcpy(nombre_pokemon,"Charizard\n");
				printf("\n%s!!!\n\n",nombre_pokemon);
				mostrar_fichero("charizard.txt");
			}
		else if(pokemon == 2)
			{
				strcpy(nombre_pokemon,"Charmander\n");
				printf("\n%s!!!\n\n",nombre_pokemon);
				mostrar_fichero("charmander.txt");
			}
		else if(pokemon == 3)
			{
				strcpy(nombre_pokemon,"Squirtle\n");
				printf("\n%s!!!\n\n",nombre_pokemon);
				mostrar_fichero("squirtle.txt");
			}
		nivel=aleatorio(100, 599);
		printf("\nTiene un nivel de %i ",nivel);
		caza=nivel/100;
		cazado=aleatorio(1, caza);
		printf("\nEl numero para cazarlo es %i\n", cazado);
		printf("\nDigite un numero: ");
		scanf("%i",&num);
		if(cazado == num)
			{
				printf("\nPOKEMON CAZADO!!!\n");
				guardar_mochila(nombre_pokemon);
			}
		else
			{
				printf("\nSE HA ESCAPADO EL POKEMON!!!\n");
			}
		getch();
	}
void guardar_mochila(char nombre_pokemon[])
	{
		FILE *mochila;
		char pokemons;
		
		mochila = fopen("Mochila.txt","a+t");
		
		if(mochila==NULL)
			{
				printf("Ha habido un error al abrir la mochila\n");
				exit(1);
			}
		else
			{
				fputs(nombre_pokemon,mochila);
				printf("Se ha guardado tu pokemon en la mochila\n\n");
			}
		fclose(mochila);	
	}
void listar_mochila()
	{
		printf("\n\nTu mochila contiene estos pokemons: \n\n");
		mostrar_fichero("Mochila.txt");
	}
