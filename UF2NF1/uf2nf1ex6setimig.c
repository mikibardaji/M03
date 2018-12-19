// Juego del 7 y medio

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numero_carta_aleatori() {
    return rand() % 10 + 1;
}

int pal_carta_aleatori() {
    return rand() % 4 + 1;
}

float punts_carta(int numero) {
    return numero < 8 ? numero : 0.5;
    // Operador ternario
    // condicion ? caso true : caso false;
}

int banca_demana_carta(float puntos_jugador, float puntos_banca) {
    if (puntos_jugador <= 7.5 &&
            (puntos_banca < puntos_jugador || puntos_banca < 5)) {
        return 1;
    } else {
        return 0;
    }

    // return puntos_jugador<=7.5 && (puntos_banca < puntos_jugador || puntos_banca < 5);
}

void imprimir_carta(int numero, int palo) {
    switch (numero) {
        case 8: printf("Sota de ");
            break;
        case 9: printf("Caballo de ");
            break;
        case 10: printf("Rey de ");
            break;
        default: printf("%d de ", numero);
    }

    switch (palo) {
        case 1: printf("OROS\n");
            break;
        case 2: printf("BASTOS\n");
            break;
        case 3: printf("ESPADAS\n");
            break;
        case 4: printf("COPAS\n");
    }
}

int guanya_jugador(float puntos_jugador, float puntos_banca) {
    if (puntos_jugador <= 7.5 &&
            (puntos_jugador > puntos_banca || puntos_banca > 7.5)) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char** argv) {
    float puntos_banca = 0, puntos_jugador = 0;
    int continua_jugando_jugador=1;
    int continua_jugando_banca=1;
    
    time_t t;
    srand((unsigned) time(&t));
    do {
        int numero_banca, numero_jugador;
        int pal_banca, pal_jugador;
        
        if(continua_jugando_jugador) {
            numero_jugador = numero_carta_aleatori();
            pal_jugador = pal_carta_aleatori();
            printf("Jugador\t:");
            imprimir_carta(numero_jugador, pal_jugador);
            puntos_jugador = puntos_jugador + punts_carta(numero_jugador);
        }
        
        if(continua_jugando_banca) {
            numero_banca = numero_carta_aleatori();
            pal_banca = pal_carta_aleatori();
            printf("Banca\t:");
            imprimir_carta(numero_banca, pal_banca);
            puntos_banca = puntos_banca + punts_carta(numero_banca);
        }

        printf("\nPuntos del jugador: %.1f\n", puntos_jugador);
        printf("Puntos de la Banca: %.1f\n\n", puntos_banca);

        if (puntos_jugador > 7.5) continua_jugando_jugador = 0;
        if (puntos_banca > 7.5) continua_jugando_banca = 0;
        
        if (continua_jugando_jugador){
            printf("Quieres seguir jugando? (1: SI / 0: NO): ");
            scanf("%d", &continua_jugando_jugador);
        }
        
        if (continua_jugando_banca) {
            continua_jugando_banca = banca_demana_carta(puntos_jugador, puntos_banca);
        }
        
        printf("\n-----------\n");
    } while (continua_jugando_jugador || continua_jugando_banca);

    
    if (puntos_jugador == puntos_banca) {
        printf("\nEMPATE!!!");
    } else if(guanya_jugador(puntos_jugador, puntos_banca)) {
        printf("\nHas ganado a la banca :)");
    } else {
        printf("\nHas perdido :(");
    }

}

