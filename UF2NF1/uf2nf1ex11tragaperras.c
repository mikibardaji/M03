#include <stdio.h>

char simbolo();
int saber_premio(char disco1, char disco2, char disco3, int mon);
int main()
	{
		srand(time(NULL));
		char disco1,disco2,disco3;
		int monedas = 10;
		printf("**Frase optativa** Empiezas a jugar siempre con 10 monedas..\n");
		do {
			monedas--;
			disco1 = simbolo();
			disco2 = simbolo();
			disco3 = simbolo();
			printf("Te ha salido -> %c%c%c \n",disco1,disco2,disco3);
			monedas = monedas + saber_premio(disco1,disco2,disco3,monedas);
			printf("Aun te quedan %i...\n", monedas);
		}while(monedas >0 && monedas <=20);
		
		if (monedas==0)
			printf("PERDISTE TODO EL DINERO LOOOSER");
		else
			printf("TE FORRASTE TIENES %i", monedas);
			
		getch();
		return 0;
	}
	
	
char simbolo()
	{
		int opcion = rand()%4;
			if (opcion==0)
				return 'A';
			else if (opcion==1)
				return 'B';
			else if (opcion==0)
				return 'C';
			else
				return 'D';
	}
	
int saber_premio(char d, char e, char f, int mon)
	{
		if (d=='A' && e=='A' && f == 'A')
			return 15;
		else if (d=='B' && e=='B' && f == 'B')
			return 10;
		else if (d=='C' && e=='C' && f == 'C')
			return 5;
		else if (d=='D' && e=='D' && f == 'D')
			return mon;
		else 
			return 0;
	}
