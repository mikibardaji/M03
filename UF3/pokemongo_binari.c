#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXPOK 50


typedef struct
	{
		char nombre[20];
		int CP;
	}pokemon;
	

void mostrar_fichero(char *nombrefichero); //kle pasare un string con el nombre
int menu();
void cazar_pokemon();
void guardar_mochila(pokemon pikachu);
void listar_mochila();
void intercambiar(char *num1, char *num2);
void burbuja(pokemon lista[MAXPOK], int tamanyo);	
void ordenar_mochila(char *nombrefichero);
int guardar_array_mochila(pokemon lista[MAXPOK], int tamanyo,char *nombrefichero)	;


int main()
	{
		srand(time(NULL));
		int men;
		char caracter;
		int num2[2];
		printf("men ocupa %i bytes, caracter ocupa %i bytes",sizeof(men),sizeof(caracter));
		printf("num2 ocupa %i bytes, caracter ocupa %i bytes",sizeof(num2),sizeof(char));
		printf("pokemon ocupa %i bytes",sizeof(pokemon));
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
			//				ordenar_mochila("mochila.txt");
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



void mostrar_fichero_binario(char *nombrefichero)
	{
		FILE *cab;
		char cabecera;
		pokemon elegido;
		cab = fopen(nombrefichero,"rb");
		
		if(cab==NULL)
			{
				printf("\nHa habido un error al abrir el fichero %s \n",nombrefichero);
				exit(1);
			}
		cabecera = '\n'; //le pongo a vacio para el primer printf que no tenga basura 
		fread(&elegido,sizeof(pokemon),1,cab);
		while(!feof(cab))
			{	
				printf(" %s CP : %i\n",elegido.nombre,elegido.CP);
				fread(&elegido,sizeof(pokemon),1,cab);
			}
		
		fclose(cab);
		
	}



void ordenar_mochila(char *nombrefichero)
	{
		FILE *cab;
		pokemon lista_pokemons[MAXPOK]; //[numero de pokemons][longitud del nombre pokemon]
		
		cab = fopen(nombrefichero,"rb");
		
		if(cab==NULL)
			{
				printf("\nHa habido un error al abrir el fichero %s \n",nombrefichero);
				exit(1);
			}
		int num=0;
		do
			{
				
				fread(&lista_pokemons[num],sizeof(pokemon),1,cab);
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

void burbuja(pokemon lista[MAXPOK], int tamanyo)	
	{
		int i,j;
		
		int penultima = tamanyo-1;
		pokemon aux; //variable para poder intercambiar posiciones
		for(i=0;i<penultima;++i)
			{
				for(j=0;j<penultima-i;j++)
					{
						if (strcmp(lista[j].nombre,lista[j+1].nombre)>0) /*intercambiar valores para dejar el mayor a la derecha*/
							{
								aux = lista[j];
								lista[j]=lista[j+1];
								lista[j+1]=aux;
							}
					}	
				
			}		
	}

/*devuelve -1 si ha habido algun error
devuelve 0 para decir que se ha guardado bien*/	
int guardar_array_mochila(pokemon lista[MAXPOK], int tamanyo,char *nombrefichero)	
	{
		int i;
		
		FILE *fmochila;
		
		fmochila = fopen(nombrefichero,"wb"); //modo escritura borrando lo que haya
		if (fmochila==NULL)
			{
				return -1; //error abrir fichero
			}
		//for(i=0;i<tamanyo;++i)
		//	{
				//fwrite(&lista[i],sizeof(pokemon),1,fmochila);
		//	}		
			fwrite(lista,sizeof(pokemon),tamanyo,fmochila);
			
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
		int pokemon2,  caza, cazado,num;
		pokemon2 = aleatorio(1, 3);
		//char nombre_pokemon[20];
		pokemon pikachu;
		
		printf("TE HA SALIDO UN...\n\n");
		getch();
		if(pokemon2 == 1)
			{
				strcpy(pikachu.nombre,"Charizard");
				printf("\n%s!!!\n\n",pikachu.nombre);
				mostrar_fichero("charizard.txt");
			}
		else if(pokemon2 == 2)
			{
				strcpy(pikachu.nombre,"Charmander");
				printf("\n%s!!!\n\n",pikachu.nombre);
				mostrar_fichero("charmander.txt");
			}
		else if(pokemon2 == 3)
			{
				strcpy(pikachu.nombre,"Squirtle");
				printf("\n%s!!!\n\n",pikachu.nombre);
				mostrar_fichero("squirtle.txt");
			}
			
		pikachu.CP=aleatorio(100, 599);
		printf("\nTiene un nivel de %i ",pikachu.CP);
		caza=pikachu.CP/100;
		cazado=aleatorio(1, caza);
		printf("\nEl numero para cazarlo es %i\n", cazado);
		printf("\nDigite un numero: ");
		scanf("%i",&num);
		if(cazado == num)
			{
				printf("\nPOKEMON CAZADO!!!\n");
				guardar_mochila(pikachu);
			}
		else
			{
				printf("\nSE HA ESCAPADO EL POKEMON!!!\n");
			}
		getch();
	}
void guardar_mochila(pokemon pikachu)
	{
		FILE *mochila;
		
		mochila = fopen("Mochila_b.txt","ab");
		
		if(mochila==NULL)
			{
				printf("Ha habido un error al abrir la mochila\n");
				exit(1);
			}
		else
			{
				fwrite(&pikachu,sizeof(pokemon),1,mochila);
				printf("Se ha guardado tu pokemon en la mochila\n\n");
			}
		fclose(mochila);	
	}


void listar_mochila()
	{
		printf("\n\nTu mochila contiene estos pokemons: \n\n");
		mostrar_fichero_binario("Mochila_b.txt");
	}
