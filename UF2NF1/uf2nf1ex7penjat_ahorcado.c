#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void iniciarSistema(char *palabra, char *marcador, int *errores) {
    *errores = 0;
    
    time_t t;
    srand((unsigned) time(&t));
    int aleatorio = rand()%4;
    
    char *palabras[4] = {"ANA", "PABLO", "JULIAN", "ROBERTO"};
    
    strcpy(palabra, palabras[aleatorio]);
    
    for(int i=0; i<=strlen(palabra)-1; i++) {
        marcador[i] = '-';
    }
    marcador[strlen(palabra)] = '\0';
}

void imprimirAhorcado(int errores) {
    switch(errores) {
        case 0: printf("=======\n");
                printf("|\n");
                printf("|\n");
                printf("|\n");
                printf("|\n");
                printf("|\n");
                printf("============\n");
                break;
        case 1: printf("=======\n");
                printf("|     |\n");
                printf("|     O\n");
                printf("|\n");
                printf("|\n");
                printf("|\n");
                printf("============\n");
                break;   
        case 2: printf("=======\n");
                printf("|     |\n");
                printf("|     O\n");
                printf("|   --|\n");
                printf("|\n");
                printf("|\n");
                printf("============\n");
                break;
        case 3: printf("=======\n");
                printf("|     |\n");
                printf("|     O\n");
                printf("|   --|--\n");
                printf("|\n");
                printf("|\n");
                printf("============\n");
                break; 
        case 4: printf("=======\n");
                printf("|     |\n");
                printf("|     O\n");
                printf("|   --|--\n");
                printf("|     |\n");
                printf("|    /\n");
                printf("============\n");
                break;
        case 5: printf("=======\n");
                printf("|     |\n");
                printf("|     O\n");
                printf("|   --|--\n");
                printf("|     |\n");
                printf("|    /\\\n");
                printf("============\n");
                break;
    }
}

void imprimirPantalla(int errores, char *marcador) {
    system("clear");
    imprimirAhorcado(errores);
    printf("Errores: %d\n", errores);
    printf("Palabra: %s\n", marcador);    
}

void jugada(char *palabra, char *marcador, int *errores) {
    char letra;
    int letra_encontrada = 0; // false
    
    
    printf("Escribe una letra: ");
    scanf("%c%*c", &letra);
    letra=toupper(letra);
    
    for(int i=0; i<strlen(palabra); i++) {
        if (letra == palabra[i]) {
            marcador[i] = letra;
            letra_encontrada = 1; // true
        }
    }
    
    if(letra_encontrada == 0) {
        (*errores)++;
    }
}

int main(int argc, char** argv) {
    
    char palabra[20], marcador[20];
    int errores;
    
    iniciarSistema(palabra, marcador, &errores);
    
    while(errores<=4 && strcmp(palabra, marcador)!=0) {
        imprimirPantalla(errores, marcador);
        jugada(palabra, marcador, &errores);
        if(strcmp(palabra, marcador) == 0) {
            printf("\nFelicidades has descubierto la palabra %s", palabra);
        }
    }
    
    if(errores==5) {
        system("clear");
        imprimirAhorcado(errores);
        printf("GAME OVER. Has superado los intentos permitidos.\n");
        printf("La palabra era %s", palabra);
    }
    
    return (EXIT_SUCCESS);
}

