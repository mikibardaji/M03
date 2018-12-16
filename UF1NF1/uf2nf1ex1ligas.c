#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>

int interes_venda();
int positivo_negativo();
float oferta_total(int, int, int);

int main(){
	setlocale(LC_ALL, ""); //Para que se puedan printar caracteres especiales (�, acentos...)
	srand(time(NULL));
	
	int valor, interes, incremento, dia = 1, oferta;
	char respuesta;
	
	//Pedimos el valor del jugador
	printf("Introduce el valor de mercadode tu jugador: ");
	fflush(stdin);
	scanf("%i",&valor);
	
	do{
		printf("D�a %i:\n", dia);
		interes = interes_venda();//Nuevo inter�s
		incremento = positivo_negativo();
		oferta = oferta_total(valor, interes, incremento);
		printf("La oferta por tu jugador es %i, quieres vender? Si(s)/No(n))\n",oferta);
		fflush(stdin);
		scanf("%c", &respuesta);
		dia++;
	}while(respuesta =='n' || respuesta =='N');
	
	printf("\n=============================\n");
	printf("Has vendido por %i\n", oferta);
	if(valor <= oferta){
		printf("Has ganado %i", oferta - valor);
	}
	else{
		printf("Has perdido %i", valor - oferta);		
	}
	return 0;
}

/* funci�n que devolver� el interes de la oferta
El valor va a estar comprendido entre 1 y 10*/

int interes_venda(){
	
	return rand()%11+1; //Devolver� un valor entre 0 y 10
	
}

//Devolver� un 1 si la oferta es en positivo y -1 si es negativo
//
int positivo_negativo(void){
	if(rand()%2){//Si devuelve un 1 ser� positivo
		return 1;
	}else{//Es un cero, as� que devolvemos un negativo
		return -1;
	}
}


/*
funcion int oferta_total()

Entrada: 
	Valor mercado: int
	interes: int entre 0 y 10
	incremento: int que ser� 1 o -1
Devolver� un n� entero. 
*/

float oferta_total(int valor_mercado, int interes, int incremento)
{
	float sobrecost = (valor_mercado*interes)/100;
	return valor_mercado+incremento*(sobrecost);
}


