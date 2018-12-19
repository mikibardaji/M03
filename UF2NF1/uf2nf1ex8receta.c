#include <stdio.h>

int cuadrados_tableta(int filas, int columnas);
int tabletas(int receta, int super);
char si_no();

int main()
{
	int cuadros_receta, filas, columnas, cont;
	char respuesta;
	
	
	do
	{
		printf("Cuantos cuadrados tiene una receta?  ");
		scanf("%i",&cuadros_receta);
		printf("Cuantas filas tiene tu  tableta? ");
		scanf("%i",&filas);
		printf("Cuantas columnas tiene tu  tableta? ");
		scanf("%i",&columnas);
		
		int cuadros_tableta = cuadrados_tableta(filas, columnas);
		printf("**optativo** los cuadrados de tu tableta son: %i\n",cuadros_tableta);
		int num_tabletas = tabletas(cuadros_receta,cuadros_tableta);
		printf("Las tabletas mínimas para esta receta son: %i\n",num_tabletas);
		printf("Quieres calcular otra receta (S/N)? ");
		respuesta = si_no();
		cont++;
	}while(respuesta!='N');
	
	printf("has calculado %i recetas",cont);
	getch();
	
	return 0;
}

int cuadrados_tableta(int filas, int columnas)
	{
		return filas*columnas;
	}
	
	
int tabletas(int receta, int super)
	{
		int i=0;
		for (i=0;i*super<receta;i++)
			{
				
			}
		
		return i;
		
	}
	
char si_no()
	{
		char respuesta;
		do{
			fflush(stdin);	
			scanf("%c",&respuesta);
			if (respuesta != 'S' && respuesta != 'N')
				{
					printf("Escribe S o N\n");
				}
		}while(respuesta!='S' && respuesta !='N');
		return respuesta;
	}
