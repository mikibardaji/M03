#include <stdio.h>

/*int jugada(): genera un numero entre 0 y 2 (0 piedra, 1 papel, 2 tijera) 0,5 ptos*/
int jugada(){
	int jugada;
	jugada=rand()%3;
	return jugada;
}


/*void imp_jugada(int player): imprime por pantalla Piedra, papel o 
tijera en función del parametro de entrada*/
void imp_jugada(int jug, int player)
{
	if(player==0)
	{
		printf("\nJugador %i Ha  sacado piedra",jug);
		
	}
	else if(player==1)
	{
		printf("\nJugador %i Ha sacado papel",jug);
	}
	else
	 {
	 	printf("\nJugador %i Ha sacado tijeras",jug);
	 }	

}

/*int ganador(int player1, int player2): devuelve 0 si hay empate, 
1 si gana el jugador 1 y 2 si gana el jugador 2*/
int ganador(int player1, int player2)
{
	/*
	if(player1==player2)
		{
			return 0;
		}
	else if(player1==2 && player2==1)//2=tijeras - 1=papel == gana el jugador 1
		{
			return 1;
		}
	else if(player1==0 && player2==2)//0=piedra - 2=tijeras == gana jugador 1
		{
			return 1;
		}
	else if(player1==1 && player2==0)//1=papel - 0=piedra == gana jugador 1
		{
			return 1;
		}
	else
		{
			return 2;
		}
*/
	if(player1==player2)
		{
			return 0;
		}
	else if(player1==0 && player2==1)//0=piedra - 1=papel == gana jugador 2
		{
			return 2;
		}
	else if(player1==0 && player2==2)//0=piedra - 2=tijeras == gana jugador 1
		{
			return 1;
		}
	else if(player1==1 && player2==0)//1=papel - 0=piedra == gana jugador 1
		{
			return 1;
		}
	else if(player1==1 && player2==2)//1=papel - 2=tijeras == gana el jugador 2
		{
			return 2;
		}
	else if(player1==2 && player2==0)//2=tijeras - 0=piedra == gana el jugador 2
		{
			return 2;
		}
	else if(player1==2 && player2==1)//2=tijeras - 1=papel == gana el jugador 1
		{
			return 1;
		}
}
/*void imp_ganador(int ganador): 
imprime la frase que jugador ha ganado*/
void imp_ganador(int ganador)
{
	if(ganador==0)
	{
		printf("\nEmpate");
	}
	else
	{
		printf("\nGana jugador %i",ganador);
	}

}

/*void marcador(int player1, int player2): 
imprime la puntuación de cada jugador.*/
void marcador(int player1,int player2)
{
	printf("\nLos puntos del jugador 1 es : %d\n",player1);
	
	printf("Los puntos del jugador 2 es : %d\n",player2);
	
}

int main()
	{	int jugador1, jugador2, gana,cont1=0,cont2=0;
		
		srand(time(NULL));
		do{
		
		jugador1 = jugada();
		imp_jugada(1,jugador1);
	    jugador2 = jugada();
		imp_jugada(2,jugador2);
		gana = ganador(jugador1,jugador2);
	    imp_ganador(gana);
	    if (gana==1)  /*cuento puntos*/
	    	{
	    		cont1++;
			}
		else if (gana==2)
			{
				cont2++;
			}
		marcador(cont1,cont2);
		getch();	
	    }while(cont1<3 && cont2<3) ;
	    
	    if (cont1==3)
	    	{
	    		printf("Felicidades jugador 1!!! jugador 2 matado");
			}
		else
		   {
	    		printf("Felicidades jugador 2!!! jugador 1 matado");
			}
		return 0;
	}
