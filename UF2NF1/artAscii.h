void linea_ASCII(char car,int ancho)
{
 int i;
 
 for(i = 0 ; i < ancho ; ++i) 
 {
  printf("%c", car);
 }
 
 printf("\n");
}

void marco_ASCII(char car,int ancho, int alto)
{
 int i,j;
 
 for(i = 0 ; i < alto; ++i )
 {
  for(j = 0 ; j < ancho  ; ++j )
  {
   if( (i == 0) || (i==(alto-1)) )
   {
    printf("%c", car);
   }
   else
   {
    if( (j == 0) || (j == (ancho-1)) )
     printf("%c", car);
    else
     printf("%c", " ");
   }
  }
  printf("\n");
 }
}

void rectangulo_ASCII(char car,int ancho, int alto)
{
 int i,j;
 
 for(i = 0 ; i < alto; ++i )
 {
  for(j = 0 ; j < ancho  ; ++j )
  	 { printf("%c", car);
	  }
   
  
  printf("\n");
 }
}

void X_ASCII(char car,int ancho)
{
 int i,j;
 
 for(i = 0 ; i < ancho; ++i )
 {
  for(j = 0 ; j < ancho  ; ++j )
  {
   if( ( i == j) || (ancho-1-i == j) )
   {
    printf("%c", car);
   }
   else
   {
    printf("%c", " ");
   }
  }
  printf("\n");
 }
}

void circulo_ASCII(char car,int ancho)
{
 int i,j;
 int centro = ancho/2;
 for(i = 0 ; i < ancho+1; ++i )
 {
  for(j = 0 ; j < ancho+1  ; ++j )
  {
   if( sqrt(( i - centro)*( i - centro) +  ( j - centro)*( j - centro)) <= centro )
   {
    printf("%c", car);
   }
   else
   {
    printf("%c", " ");
   }
  }
  printf("\n");
 }
}
 
 /*funcio que imprimeix la ma del facebook com el like*/
 void holamundo()
 {
 	     printf("%c%c%c%c%c%c%c%c%c%c%c%c HOLA\n",176,176,176,176,176,176,176,176,178,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c MUNDO!!\n",176,176,176,176,176,176,178,178,178,176,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,178,178,176,176,176,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,178,178,176,176,176,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,178,178,176,176,176,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,178,178,176,176,176,176,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,178,178,178,178,178,178,178,176,176,176,176,178,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,178,178,178,178,178,178,176,176,176,176,176,176,176,176,176,178,178,178,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",178,178,176,176,176,176,178,178,178,178,176,176,176,176,176,176,176,176,176,178,178,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",178,178,176,176,178,178,178,178,176,176,178,178,178,176,176,176,176,176,176,176,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",178,178,176,176,176,176,176,176,176,176,178,178,178,176,176,176,176,176,176,176,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,178,178,178,178,178,178,178,178,178,178,176,178,178,178,176,176,176,176,176,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,178,178,176,176,176,176,176,176,176,176,178,178,178,178,176,176,176,176,176,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,178,178,178,178,178,178,178,178,178,178,178,176,176,178,178,176,176,176,176,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,178,178,176,176,176,176,176,176,176,178,178,178,178,176,176,178,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,178,178,178,178,178,178,178,178,178,178,176,178,178,176,178,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,178,178,176,176,176,176,176,178,178,178,176,178,178,178,178);
       printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,178,178,178,178,178,178,178,178,178,178,178,178,178,178);
 }
