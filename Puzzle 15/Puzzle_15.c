#include <stdio.h>  // printf(), scanf()
#include <stdlib.h> // rand(), srand()
#include <unistd.h> // getpid(), sleep()

#define LARGO_MATRICES 4     // Largo De Las Matrices (4x4)
#define CANTIDAD_MATRICES 20 // La Cantidad De Matrices (Partidas Posibles)
#define ESPACIO_VACIO 0      // Elemento Que Representa El Espacio Vacio
#define PARTIDAS_MAXIMAS 10  // Cantidad De Partidas Maximas
#define APUESTA_MINIMA 40    // Apuesta Minima
#define APUESTA_MAXIMA 200   // Apuesta Maxima

void imprimirMatriz(int matriz[LARGO_MATRICES][LARGO_MATRICES]) // Funcion Para Imprimir La Matriz
{
    printf("\n");
    for (int i = 0; i < LARGO_MATRICES; i++)
    {
        for (int j = 0; j < LARGO_MATRICES; j++)
        {
            if (matriz[i][j] == 0) // Si El Elemento Es 0, Imprime Espacio Vacio
                printf("[   ] ");
            else                                // Si El Elemento No Es 0, Imprime El Elemento
                printf("[%3i] ", matriz[i][j]); // %3i Para Que Imprima Con 3 Espacios De Ancho
        }
        printf("\n");
    }
    printf("\n");
}

void intercambiarElementos(int *elementoUno, int *elementoDos) // Funcion Para Intercambiar Dos Elementos
{
    int auxiliar = *elementoUno; // Variable Auxiliar Para Intercambiar Los Elementos
    *elementoUno = *elementoDos; // Intercambia Elemento A Por Elemento B
    *elementoDos = auxiliar;     // Intercambia Elemento B Por Elemento A
}

int Movimiento(int matriz[LARGO_MATRICES][LARGO_MATRICES], int direccionMovimiento) // Funcion Para Mover El Espacio Vacio En La Matriz
{
    int filaVacia, columnaVacia; // Variables Para Almacenar La Posicion Del Espacio Vacio
    for (int i = 0; i < LARGO_MATRICES; i++)
    {
        for (int j = 0; j < LARGO_MATRICES; j++)
        {
            if (matriz[i][j] == ESPACIO_VACIO) // Si El Elemento Es 0, Almacena La Posicion Del Espacio Vacio
            {
                filaVacia = i;    // Almacena La Fila Del Espacio Vacio
                columnaVacia = j; // Almacena La Columna Del Espacio Vacio
                break;
            }
        }
    }
    if (direccionMovimiento == 1 && columnaVacia > 0) // Movimiento Hacia La Izquierda
    {
        intercambiarElementos(&matriz[filaVacia][columnaVacia], &matriz[filaVacia][columnaVacia - 1]); // Intercambia Elemento Vacio Con El Elemento De La Columna De La Izquierda
        return 1;
    }
    else if (direccionMovimiento == 5 && filaVacia > 0) // Movimiento Hacia Arriba
    {
        intercambiarElementos(&matriz[filaVacia][columnaVacia], &matriz[filaVacia - 1][columnaVacia]); // Intercambia Elemento Vacio Con El Elemento De La Fila De Arriba
        return 1;
    }
    else if (direccionMovimiento == 3 && columnaVacia < LARGO_MATRICES - 1) // Movimiento Hacia La Derecha
    {
        intercambiarElementos(&matriz[filaVacia][columnaVacia], &matriz[filaVacia][columnaVacia + 1]); // Intercambia Elemento Vacio Con El Elemento De La Columna De La Derecha
        return 1;
    }
    else if (direccionMovimiento == 2 && filaVacia < LARGO_MATRICES - 1) // Movimiento Hacia Abajo
    {
        intercambiarElementos(&matriz[filaVacia][columnaVacia], &matriz[filaVacia + 1][columnaVacia]); // Intercambia Elemento Vacio Con El Elemento De La Fila De Abajo
        return 1;
    }
    return 0;
}

int victoriaPartida(int matrizUno[LARGO_MATRICES][LARGO_MATRICES], int matrizDos[LARGO_MATRICES][LARGO_MATRICES]) // Funcion Para Verificar Si Ha Ganado La Partida
{
    for (int i = 0; i < LARGO_MATRICES; i++)
    {
        for (int j = 0; j < LARGO_MATRICES; j++)
        {
            if (matrizUno[i][j] != matrizDos[i][j]) // Si Los Elementos De Las Matrices No Son Iguales
            {
                return 0; // Retorna 0 Para Indicar Que El Jugador No Ha Ganado
            }
        }
    }
    return 1; // Retorna 1 Para Indicar Que El Jugador Ha Ganado
}

int calcularPuntuacion(int movimientosRealizados, int movimientosApuesta) // Funcion Para Calcular Puntuacion Del Jugador
{
    if (movimientosRealizados == movimientosApuesta) // Si Los Movimientos Realizados Son Iguales A Los Movimientos Apostados
    {
        return 1000;
    }
    else if (movimientosRealizados > movimientosApuesta && movimientosRealizados <= movimientosApuesta + 10) // Si Los Movimientos Realizados Son Mayores A Los Movimientos Apostados Y Menores O Iguales A Los Movimientos Apostados Mas 10
    {
        return 500;
    }
    else if (movimientosRealizados < movimientosApuesta - 10) // Si Los Movimientos Realizados Son Menores A Los Movimientos Apostados Menos 10
    {
        return 1500;
    }
    else if (movimientosRealizados > movimientosApuesta + 10) // Si Los Movimientos Realizados Son Mayores A Los Movimientos Apostados Mas 10
    {
        return 0;
    }
    else // Si Los Movimientos Realizados Son Menores A Los Movimientos Apostados
    {
        return 1200;
    }
}

int main() // Funcion Principal
{
    int opcionMenuJuego, apuestaMovimientos;
    int partidasJugadas = 0;
    int movimientosRealizados, indiceAleatorio;
    int matrizSeleccionada[LARGO_MATRICES][LARGO_MATRICES];
    int matrices[CANTIDAD_MATRICES][LARGO_MATRICES][LARGO_MATRICES] = {
        {{10, 12, 1, 3}, {0, 14, 15, 5}, {4, 6, 2, 9}, {7, 11, 13, 8}}, // Partida Posible N1
        {{15, 11, 8, 14}, {1, 13, 7, 9}, {3, 6, 5, 4}, {12, 0, 2, 10}}, // Partida Posible N2
        {{3, 0, 5, 15}, {7, 4, 11, 1}, {14, 2, 6, 8}, {9, 10, 13, 12}}, // Partida Posible N3
        {{2, 14, 13, 11}, {9, 3, 4, 8}, {15, 5, 7, 0}, {12, 6, 1, 10}}, // Partida Posible N4
        {{7, 9, 13, 14}, {12, 6, 15, 2}, {1, 5, 8, 3}, {4, 10, 11, 0}}, // Partida Posible N5
        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 0}, {13, 14, 15, 12}}, // Partida Posible N6 | Especial para probar la victoria
        {{1, 8, 9, 4}, {3, 2, 11, 14}, {15, 13, 0, 7}, {10, 12, 6, 5}}, // Partida Posible N7
        {{0, 10, 14, 8}, {13, 3, 9, 11}, {7, 15, 5, 6}, {4, 12, 1, 2}}, // Partida Posible N8
        {{5, 1, 2, 14}, {3, 7, 6, 10}, {13, 0, 12, 11}, {4, 15, 9, 8}}, // Partida Posible N9
        {{6, 10, 15, 12}, {5, 9, 11, 0}, {13, 8, 2, 4}, {1, 14, 3, 7}}, // Partida Posible N10
        {{5, 2, 14, 12}, {3, 15, 8, 11}, {10, 1, 6, 13}, {0, 9, 4, 7}}, // Partida Posible N11
        {{11, 3, 15, 8}, {13, 5, 7, 4}, {10, 1, 12, 2}, {6, 14, 9, 0}}, // Partida Posible N12
        {{9, 10, 0, 6}, {4, 14, 5, 3}, {13, 8, 1, 2}, {11, 12, 7, 15}}, // Partida Posible N13
        {{9, 1, 0, 11}, {12, 8, 3, 2}, {5, 4, 10, 15}, {7, 6, 13, 14}}, // Partida Posible N14
        {{13, 15, 7, 2}, {1, 10, 12, 14}, {8, 9, 3, 4}, {0, 11, 5, 6}}, // Partida Posible N15
        {{4, 13, 11, 9}, {7, 15, 14, 3}, {12, 10, 0, 5}, {2, 8, 6, 1}}, // Partida Posible N16
        {{6, 8, 9, 4}, {10, 1, 0, 14}, {15, 11, 13, 12}, {3, 5, 2, 7}}, // Partida Posible N17
        {{9, 13, 10, 11}, {1, 14, 7, 0}, {4, 15, 3, 2}, {5, 8, 6, 12}}, // Partida Posible N18
        {{3, 0, 2, 13}, {11, 4, 5, 7}, {12, 9, 15, 14}, {6, 8, 10, 1}}, // Partida Posible N19
        {{7, 10, 4, 11}, {13, 1, 3, 2}, {6, 8, 12, 5}, {9, 15, 14, 0}}, // Partida Posible N20
    };
    int victoria, direccionMovimiento, respuestaAbandono;
    int matrizGanadora[LARGO_MATRICES][LARGO_MATRICES] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
    int puntajeFinal, nuevaPartida;
    int historialPartidas[PARTIDAS_MAXIMAS], historialPuntajes[PARTIDAS_MAXIMAS], historialMovimientos[PARTIDAS_MAXIMAS];

    do
    {
        printf("\n╔ ═ ═ ═ ═ ═ PUZZLE 15 ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
        printf("\n¡Bienvenido! Estas Por Jugar Una Version Del Puzzle 15 En La Terminal De C.\n");
        printf("\nIngrese El Numero Segun La Opcion Que Desee:\n");
        printf("\n◈ 1. Aprender A Manejarse En El Juego.\n");
        printf("\n◈ 2. Comenzar A Jugar.\n");
        printf("\n◈ 3. Salir Del Juego.\n");
        printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
        printf("\nIngrese Numero ➔  ");
        scanf("%i", &opcionMenuJuego);
        sleep(1);
        switch (opcionMenuJuego)
        {
        case 1: // Opcion 1: Aprender A Manejarse En El Juego
            printf("\n╔ ═ ═ ═ ═ ═ JUGABILIDAD ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
            printf("\n◈ El Puzzle 15 Es Un Juego De Desplazamientos En Una Matriz 4x4, Se Disponen Aleatoriamente Piezas Numeradas Del 1 Al 15 Y Un Espacio Vacio.\n");
            printf("\n◈ El Objetivo Es Ordenarlas De Manera Ascendente, Desde El Numero 1 En La Esquina Superior Izquierda Y El Espacio Vacio En La Esquina Inferior Derecha.\n");
            printf("\n◈ En Cada Movimiento Se Intercambia La Posicion Del Espacio Vacio Con Uno De Los Numeros Adyacentes Tanto Verticales Como Horizontales.\n");
            printf("\n◈ El Juego Se Maneja Con Las Teclas [1, 5, 2 ,3], Mientras Estes Jugando Podras Ver Una Guia En La Parte Superior.\n");
            printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
            sleep(2);
            break;
        case 2: // Opcion 2: Comenzar A Jugar
            nuevaPartida = 1;

            while (partidasJugadas < PARTIDAS_MAXIMAS && nuevaPartida == 1)
            {
                partidasJugadas++; // Incrementa Numero Partidas Jugadas (Va De 1 A PARTIDAS_MAXIMAS)
                printf("\n╔ ═ ═ ═ ═ ═ APUESTA | PARTIDA %i ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n", partidasJugadas);
                printf("\n¡Atencion! Antes De Comenzar El Juego Hay Que Realizar Una Apuesta.\n");
                printf("\n¿En Cuantos Movimientos Crees Que Puedes Resolver El Juego?\n");
                printf("\n◈ Minimo %i Movimientos.\n", APUESTA_MINIMA);
                printf("\n◈ Maximo %i Movimientos.\n", APUESTA_MAXIMA);
                do
                {
                    printf("\nIngrese Numero ➔  ");
                    scanf("%i", &apuestaMovimientos);
                    sleep(1);
                    if (apuestaMovimientos < APUESTA_MINIMA)
                    {
                        printf("\n🜂 Te Veo Muy Confiado, Pero No Creo Que Puedas Resolverlo En Menos De %i Movimientos. Intenta De Nuevo.\n", APUESTA_MINIMA);
                    }
                    else if (apuestaMovimientos > APUESTA_MAXIMA)
                    {
                        printf("\n🜄 Confia Un Poco Mas En Ti, Creo Que Puedes Resolverlo En Menos De %i Movimientos. Intenta De Nuevo.\n", APUESTA_MAXIMA);
                    }
                } while (apuestaMovimientos < APUESTA_MINIMA || apuestaMovimientos > APUESTA_MAXIMA);
                printf("\n¿Asi Que Crees Que Puedes Resolverlo En %i Movimientos? ¡Mucha Suerte Intentandolo!\n", apuestaMovimientos);
                printf("\nTe Aviso Que Dependiendo De Tu Resultado Obtendras Un Puntaje Diferente.\n", apuestaMovimientos);
                printf("\n◈ 1500 Puntos Si Lo Logras En Menos De %i Movimientos.\n", apuestaMovimientos - 10);
                printf("\n◈ 1200 Puntos Si Lo Logras En Una Cantidad De Movimientos Dentro Del Rango [%i, %i)\n", apuestaMovimientos - 10, apuestaMovimientos);
                printf("\n◈ 1000 Puntos Si Lo Logras En Exactamente %i Movimientos\n", apuestaMovimientos);
                printf("\n◈ 500 Puntos Si Lo Logras En Una Cantidad De Movimientos Dentro Del Rango (%i, %i]\n", apuestaMovimientos, apuestaMovimientos + 10);
                printf("\n◈ 0 Puntos En Cualquier Otro Caso\n");
                printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                sleep(4);

                printf("\n╔ ═ ═ ═ ═ ═ CONFIGURANDO | PARTIDA %i ═ ═ ═ ═ ═ ╗\n", partidasJugadas);
                movimientosRealizados = 0;
                printf("\n◈ Restaurando Los Movimientos Realizados...\n");
                srand(getpid());
                indiceAleatorio = rand() % CANTIDAD_MATRICES; // Selecciona Un Indice Aleatorio Entre 0 Y CANTIDAD_MATRICES ( = 5 Para Probar El Programa)
                printf("\n◈ Seleccionando Una Matriz Aleatoria...\n");
                for (int i = 0; i < LARGO_MATRICES; i++)
                {
                    for (int j = 0; j < LARGO_MATRICES; j++)
                    {
                        matrizSeleccionada[i][j] = matrices[indiceAleatorio][i][j]; // Se copia la matriz seleccionada
                    }
                }
                printf("\n◈ Todo Listo Para Comenzar.\n");
                printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                sleep(3);

                victoria = 0;          // 0 = No Hay Victoria | 1 = Hay Victoria
                respuestaAbandono = 0; // 0 = No Abandona | 1 = Abandona
                while (victoria == 0 && respuestaAbandono == 0)
                {
                    printf("\n╔ ═ ═ ═ ═ ═ PUZZLE 15 | PARTIDA %i ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n", partidasJugadas);
                    printf("\nIntercambia Las Piezas Para Ordenar Los Numeros Del 1 Al 15.\n");
                    printf("\nUsa Las Siguientes Teclas Para Mover Las Piezas:\n");
                    printf("\n1 ➔ Izquierda\n");
                    printf("\n5 ➔ Arriba\n");
                    printf("\n3 ➔ Derecha\n");
                    printf("\n2 ➔ Abajo\n");
                    printf("\n◈ Si Desea Abandonar El Juego Ingrese 0.\n");
                    imprimirMatriz(matrizSeleccionada);
                    printf("\n◈ Movimientos Realizados: %i\n", movimientosRealizados);
                    printf("\n◈ Apostaste A Resolverlo En %i Movimientos\n", apuestaMovimientos);
                    printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                    printf("\nIngrese Numero ➔  ");
                    scanf("%d", &direccionMovimiento);
                    sleep(2);
                    if (direccionMovimiento == 0) // Abandono
                    {
                        do
                        {
                            printf("\n╔ ═ ═ ═ ═ ═ ABANDONAR PARTIDA | PARTIDA %i ═ ═ ╗\n", partidasJugadas);
                            printf("\n¿Estas Seguro De Que Quieres Abandonar El Juego?\n");
                            printf("\n1 ➔ Si\n");
                            printf("\n0 ➔ No\n");
                            printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                            printf("\nIngrese Numero ➔  ");
                            scanf("%i", &respuestaAbandono);
                            sleep(2);
                        } while (respuestaAbandono != 1 && respuestaAbandono != 0);
                    }
                    else if (Movimiento(matrizSeleccionada, direccionMovimiento)) // Movimiento Valido
                    {
                        movimientosRealizados++;
                    }
                    else // Movimiento Invalido
                    {
                        printf("\n╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
                        printf("\nMovimiento No Valido, Intentalo De Nuevo.\n");
                        printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                    }

                    victoria = victoriaPartida(matrizSeleccionada, matrizGanadora); // Verifica Si Gano Partida
                }

                printf("\n╔ ═ ═ ═ ═ ═ PUZZLE 15 | FINAL PARTIDA %i ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n", partidasJugadas);
                imprimirMatriz(matrizSeleccionada); // Imprime Matriz Resuelta O No
                if (victoria == 1)                  // Si Gano Partida
                {
                    printf("\n╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
                    printf("\n¡FELICIDADES! ¡HAS GANADO CON %i MOVIMIENTOS!\n", movimientosRealizados);
                    printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                    puntajeFinal = calcularPuntuacion(movimientosRealizados, apuestaMovimientos); // Calcula Puntaje Final
                }
                else // Si Perdio Partida
                {
                    printf("\n╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
                    printf("\n¡QUE LASTIMA! ¡HAS ABANDONADO CON %i MOVIMIENTOS!\n", movimientosRealizados);
                    printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                    puntajeFinal = 0; // Puntaje Final = 0
                }
                printf("\n╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
                printf("\n ¡SU PUNTAJE ES DE %i PUNTOS!\n", puntajeFinal);
                printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                historialPartidas[partidasJugadas - 1] = partidasJugadas;          // Guarda Partida En Historial
                historialPuntajes[partidasJugadas - 1] = puntajeFinal;             // Guarda Puntaje En Historial
                historialMovimientos[partidasJugadas - 1] = movimientosRealizados; // Guarda Movimientos En Historial
                printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                sleep(2);

                printf("\n╔ ═ ═ ═ ═ ═ HISTORIAL PARTIDAS ═ ═ ═ ═ ═ ═ ╗\n");
                printf("\n[ Partida ] | [ Puntaje ] | [ Movimientos ]\n");
                for (int i = 0; i < partidasJugadas; i++)
                {
                    printf("\n[ %i ] | [ %i ] | [ %i ]\n", historialPartidas[i], historialPuntajes[i], historialMovimientos[i]);
                }
                printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                sleep(2);

                do
                {
                    printf("\n╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
                    printf("\n ¿Quieres jugar de nuevo?\n");
                    printf("\n1 ➔ Si\n");
                    printf("\n0 ➔ No\n");
                    printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                    printf("\nIngrese Numero ➔  ");
                    scanf(" %i", &nuevaPartida);
                } while (nuevaPartida != 1 && nuevaPartida != 0);
                sleep(2);
            }

            if (partidasJugadas == PARTIDAS_MAXIMAS)
            {
                printf("\n╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
                printf("\nYa se jugaron todas las partidas posibles, no se puede jugar mas.\n");
                printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                sleep(2);

                printf("\n╔ ═ ═ ═ ═ ═ HISTORIAL PARTIDAS ═ ═ ═ ═ ═ ═ ╗\n");
                printf("\n[ Partida ] | [ Puntaje ] | [ Movimientos ]\n");
                for (int i = 0; i < partidasJugadas; i++)
                {
                    printf("\n[ %i ] | [ %i ] | [ %i ]\n", historialPartidas[i], historialPuntajes[i], historialMovimientos[i]);
                }
                printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                sleep(2);
            }

            break;

        case 3:
            printf("\n╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
            printf("\n¡Gracias por jugar! Hasta luego.\n");
            printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
            sleep(2);
            break;
        default:
            printf("\n╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
            printf("\nOpción inválida. Por favor, selecciona una opción válida.\n");
            printf("\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
            sleep(2);
            break;
        }
    } while (opcionMenuJuego != 3);
    return 0;
}
