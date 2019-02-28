/*
Recorre un array de enteros de tamaño tope y los muestra por pantalla.
n array de una dimension con los valores a mostrar
tope numero de valores a mostrar
*/
void muestra_array (int *n, int tope)
	{
		int i;
		
		for(i=0;i<tope;i++)
			{
				printf(" %i ",n[i]);
			}
		printf("\n\n");
	}
	

/*intercambiar valor de dos variables numericas por referencia
num1,num2 valores por referencia a cambiar
*/
void intercambiar(int *num1, int *num2)
	{
		
		int aux= *num1;
		*num1 = *num2;
		*num2 = aux;
	}	
/*metode burbuja de ordenacio
ordena anar recorrent un array a cada volta del segon for, coloca el mes gran al final del array
la segona volta el segon mes gran i aixi successivament
n array de una dimension con los valores a mostrar
tamanyo numero de enteros que hay en el array para ordenar
*/
void burbuja(int *num, int tamanyo)	
	{
		int i,j;
		
		int penultima = tamanyo-2;
		int aux;
		for(i=0;i<=penultima;++i)
			{
				for(j=0;j<=penultima-i;j++)
					{
						if (num[j]>num[j+1]) /*intercambiar valores para dejar el mayor a la derecha*/
							{
								intercambiar(&num[j],&num[j+1]);
							
							}
					}	
				
			}		
	}

	
/*dar un numero aleatori entre 1 i el valor tope
tope valor maximo que queremos que de aleatoria
RECORDAR EN PROGRAMA PRINCIPAL PONER srand(time(NULL)) al principio de todo
*/

int aleatorio (int tope)
	{
		int n;
		n = (rand()%tope)+1;
			
		return n;
	}
	
/*pide un numero y valida  si es positivo sino se debe repetir la entrada*/	
int introduce_positivo()
	{
		int num=0;
		do
		{
			printf("Introduce numero positivo: ");
			scanf("%i",&num);
		}while(num<0);
		return num;
	}
	
/*pide una letra para seguir o no
solo devuelve s o n sino pide que repitas la entrada*/
char introduce_s_n()
	{
		char letra;
		do
		{
			printf("Introduce s o n");
			scanf("%c",&letra);
		}while(toupper(letra)!='S' && toupper(letra) != 'N');
		
		return letra;		
		
	}
	
	
/*busqueda de un valor en un array
numeros array con valores enteros no ordenados
tam tamaño del array o posicion hasta la que buscar
num_buscar valor buscado*/
int busqueda_lineal(int *numeros,int tam, int num_buscar)
	{
		int i, pos, encontrar=0;
		i=0;
		pos=-1; /*no encontrado*/
		while (i<tam && (encontrar==0))
			{
				if (numeros[i]==num_buscar)
					{
						pos = i;
						encontrar=1;/*ciertp*/
					}
				else
					{
						i = i+1;
					}
			}

		return pos;
	}



/*busqueda de un valor en un array
numeros array con valores enteros ordenados
tam tamaño del array o posicion hasta la que buscar
num_buscar valor buscado*/
int busqueda_lineal_ordenado(int *numeros,int tam, int num_buscar)
	{
		int i, pos, encontrar=0;
		i=0;
		pos=-1; /*no encontrado*/
		while (i<tam && numeros[i]<num_buscar)
			{
						i = i+1;
			}
			
		if (numeros[i]==num_buscar) /* si es el numero informo la variable posicion*/
			{
				pos = i;
			}
		return pos;	
		
	}

/*imprime opciones y devuelve la opción escogida*/
int imprimirOpciones() {

    int opcion;
    printf("\n\n");
    printf("0. Salir \n");
    printf("1. A%cadir Moto. \n",164);
    printf("2. Listar Motos disponibles. \n",162);
    printf("3. Cambiar estado Moto. \n");
    printf("4. Mostrar calendario. \n");
    printf("5. Eliminar Moto. \n");
    printf("6. Alquilar Moto. \n");
    printf("7. Alquilar Moto por intervalos. \n");
    opcion = opcion_valida(1,7);

int opcion_valida(int min, int max)
{
	int opcion;
	do{
	    printf("Escoge opci%cn",162);
    	    scanf("%i",&opcion);	
	}while(opcion<min || opcion>max);
	return opcion;
}
