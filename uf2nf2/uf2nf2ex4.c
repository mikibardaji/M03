
/*Implementa un algoritmo recursivo que sume los n primeros numeros impares.
 Es decir si introducimos por teclado un 3, el resultado serà 9  la suma de los 3 primeros numero impares (1+3+5). la suma de n impares del ejemplo es:

suma (3)=2*(3-1)+suma(2)
suma (2)=2*(2-1)+suma(1)
suma (1)= 2*(1-1)+suma(0)
suma (0)= 1*/



#include <stdio.h>

int Sumaimpares(int n);

main(){
	int res,n;
	
	//pido datos
	
	printf("introduce un numero entero positivo");
	scanf("%i",&n);
	
	// llamo a la función 
	res=Sumaimpares(n);
	printf("la suma de los %i primeros impares es %i ",n,Sumaimpares (n));
}

int Sumaimpares(int n){
	//caso base
	if(n==1){
		return 1;
	}
	else{//caso recursivo
	    
		return (2*n-1)+Sumaimpares(n-1);
		
		
		}
}











