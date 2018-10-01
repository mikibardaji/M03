/*programa que reconegui que el usuari ha introduit una lletra a*/
#include <stdio.h>

int main()
{
	char letra;
	printf("Introduce una letra:");
	scanf("%c",&letra);
	/*letra == 'a'
	letra == 'A'*/
	/* || --> or
	&& --> and */
	
	if (letra == 'a')
		{
			printf("\n Muy bien has introducido la letra que queria %c",letra);
		}
	else if(letra == 'A')
		{
			printf("\n Muy bien has introducido la letra que queria %c en mayuscula",letra);
		}
	else
		{
			printf("\n no es la letra que quiero");
		}
	
	
	printf("\n Termino el programa");
	
	
	return 0;
}







/*char letra;
	printf("Hola, introduce una letra:");
	scanf("%c",&letra);
	printf("has introducido la letra : %c", letra);
	/* letra == 'a' o letra == 'A'*/
//	if (letra == 'a')
//		{
//			printf("\n Muy bien has introducido una letra %c", letra);
//		}
//	else if ( letra == 'A')
//		{
//			printf("\n Muy bien has introducido una letra %c", letra);
//		}
//	else
//		{
//			printf("\n No es la letra que queria");
//		}
	
//	printf ("termino programa");*/
