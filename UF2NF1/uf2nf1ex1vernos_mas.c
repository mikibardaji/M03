#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>

#define EDAD_HOMBRE_MAX 80
#define EDAD_MUJER_MAX 86

int anyos_por_verse(int, int, int, int);
int horas_por_verse(int,int,int,char);
void dias_reales(int,int *,int *);
int pide_valor_positivo();
char pide_mes_anyo();
int pide_sexo();

int main(){
	setlocale(LC_ALL, ""); //Para que se puedan printar caracteres especiales (ñ, acentos...)

	int dias, horas, frecuencia;
	int edad_1, sexo_1, edad_2, sexo_2;
	int anyos_quedan, horas_totales, dias_restantes, horas_restantes;
	

	printf("===Vamos a calcular los días que os veréis hasta que uno falte===\n");
	printf("Cuántos días os véis?: ");
	dias= pide_valor_positivo();
	
	printf("Cuántas horas reales os véis esos días?: ");
	horas= pide_valor_positivo();	
	
	printf("Los días indicados son al mes(m) o al año(a)?: ");
	frecuencia = pide_mes_anyo();

	printf("Pon la edad de la primera persona: ");
	edad_1 = pide_valor_positivo();
	
	printf("Pon el sexo de la primera persona (0-hombre/1-mujer): ");
	sexo_1 = pide_sexo();
	
	printf("Pon la edad de la segunda persona: ");
	edad_2 = pide_valor_positivo();
	
	printf("Pon el sexo de la segunda persona (0-hombre/1-mujer): ");
	sexo_2 = pide_sexo();	
			
	printf("\n\n=======CALCULO QUE HACE EL PROGRAMA======\n\n");
	
	anyos_quedan = anyos_por_verse(edad_1, sexo_1, edad_2, sexo_2);
	printf("Años de vida del primero a morirse : %i\n",anyos_quedan);
	
	horas_totales = horas_por_verse(anyos_quedan, dias, horas, frecuencia);
	printf("Horas totales: %i\n", horas_totales);
	
	
	dias_reales(horas_totales, &dias_restantes, &horas_restantes);
	printf("Os queda por veros %i días y %i horas\n", dias_restantes, horas_restantes);
	
			
	return 0;
}


//sexo = 0 -> hombre	sexo = 1 -> mujer
int anyos_por_verse(int edad_1, int sexo_1, int edad_2, int sexo_2){
	int edad_max_1, edad_max_2;
	
	printf("%i-%i-%i-%i\n",edad_1, sexo_1, edad_2, sexo_2);
	
	//Primero calculamos los años que vive la persona 1
	if(sexo_1 == 0){//Es un hombre
		edad_max_1 = EDAD_HOMBRE_MAX - edad_1;	
	}
	else{//Es una mujer
		edad_max_1 = EDAD_MUJER_MAX - edad_1;		
	}
	//Ahora lo mismo para la persona 2
	if(sexo_2 == 0){//Es un hombre
		edad_max_2 = EDAD_HOMBRE_MAX - edad_2;	
	}
	else{//Es una mujer
		edad_max_2 = EDAD_MUJER_MAX - edad_2;		
	}	
	
	//Los años por verse serán los años del que viva menos
	if(edad_max_1 < edad_max_2){
		return edad_max_1;
	}
	else{
		return edad_max_2;
	}
}


int horas_por_verse(int anyos_quedan, int dias,int horas, char frecuencia){
	if(frecuencia == 'm'){//Es por mes. Hemos de multiplicar por 12
		return anyos_quedan*12*dias*horas;
	}
	else
	{
		//Es por año
	return anyos_quedan*dias*horas;
	}
	
}

/*paso por referencia, variables de la rutina que la llaman que al volver van a tener la misma 
variable con el valor cambiado que se hace aquí)*/
void dias_reales(int horas_totales, int *dias, int *horas){
	
	*dias = horas_totales/24; //Será un entero, así que faltarán las horas restantes
	*horas = horas_totales%24;
}

int pide_valor_positivo(){
	int valor;
	
	while(valor<0){
		fflush(stdin);
		scanf("%i",&valor);
		if(valor < 0){
			printf("El valor ha de ser positivo. Escríbelo de nuevo: ");
		}else{
			return valor;
		}
	}
}

char pide_mes_anyo(){
	char letra;
	
	while(letra != 'm' && letra != 'M' && letra != 'a' && letra != 'A'){
		fflush(stdin);
		scanf("%c",&letra);
		if(letra != 'm' && letra != 'M' && letra != 'a' && letra != 'A'){
			printf("m o h. Escribelo de nuevo : ");
		}else{
			return letra;
		}
	}	
}

int pide_sexo(){
	int valor;
	
	while(valor != 0 && valor != 1){
		fflush(stdin);
		scanf("%i",&valor);
		if(valor != 0 && valor != 1){
			printf("El valor ha de ser 0 o 1. Escríbelo de nuevo: ");
		}else{
			return valor;
		}
	}	
}
