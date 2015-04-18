#include <stdio.h>   // printf, scanf
#include <stdlib.h>  // malloc, srand, rand, NULL
#include <time.h>    // time
#include <windows.h> // Sleep

typedef struct Nodo Nodo;

struct Nodo
{
    int valor;
    Nodo *siguiente;
    Nodo *anterior;
};

int fibonacci(int n)
{
    if (n == 0 || n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void listaDe100NumerosNaturales(void)
{
    // variables
    Nodo *inicio;
    Nodo *final;
    Nodo *iNodo;
    int i;

    // proceso
    inicio = (Nodo *) malloc(sizeof(Nodo));
    iNodo = inicio;
    for (i = 1; i <= 100; ++i) {
        iNodo->valor = i + 1;
        iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
        final = iNodo;
        iNodo = iNodo->siguiente;
    }
    final->siguiente = NULL;

    // salida por pantalla
    iNodo = inicio;
    i = 1;
    while (iNodo != NULL) {
        printf("%d-> %d\n", i, iNodo->valor);
        iNodo = iNodo->siguiente;
        ++i;
    }
}

void listaDe100NumerosPares(void)
{
    // variables
    Nodo *inicio;
    Nodo *final;
    Nodo *iNodo;
    int contador;
    int i;

    // proceso
    inicio = (Nodo *) malloc(sizeof(Nodo));
    iNodo = inicio;
    contador = 0;
    i = 2;
    while (contador < 100) {
        if (i % 2 == 0) {
            iNodo->valor = i;
            iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
            final = iNodo;
            iNodo = iNodo->siguiente;
            ++contador;
        }
        ++i;
    }
    final->siguiente = NULL;

    // salida por pantalla
    iNodo = inicio;
    i = 1;
    while (iNodo != NULL) {
        printf("%d-> %d\n", i, iNodo->valor);
        iNodo = iNodo->siguiente;
        ++i;
    }
}

void listaDe100NumerosImpares(void)
{
    // variables
    Nodo *inicio;
    Nodo *final;
    Nodo *iNodo;
    int contador;
    int i;

    // proceso
    inicio = (Nodo *) malloc(sizeof(Nodo));
    iNodo = inicio;
    contador = 0;
    i = 1;
    while (contador < 100) {
        if (i % 2 == 1) {
            iNodo->valor = i;
            iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
            final = iNodo;
            iNodo = iNodo->siguiente;
            ++contador;
        }
        ++i;
    }
    final->siguiente = NULL;

    // salida por pantalla
    iNodo = inicio;
    i = 1;
    while (iNodo != NULL) {
        printf("%d-> %d\n", i, iNodo->valor);
        iNodo = iNodo->siguiente;
        ++i;
    }
}

void listaDe100MultiplosDe2(void)
{
    // variables
    Nodo *inicio;
    Nodo *final;
    Nodo *iNodo;
    int i;

    // proceso
    inicio = (Nodo *) malloc(sizeof(Nodo));
    iNodo = inicio;
    for (i = 1; i <= 100; ++i) {
        iNodo->valor = i * 2;
        iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
        final = iNodo;
        iNodo = iNodo->siguiente;
    }
    final->siguiente = NULL;

    // salida por pantalla
    i = 1;
    iNodo = inicio;
    while (iNodo != NULL) {
        printf("%d-> %d\n", i, iNodo->valor);
        iNodo = iNodo->siguiente;
        ++i;
    }
}

void listaDe100NumerosPrimos(void)
{
    // variables
    Nodo *inicio;
    Nodo *final;
    Nodo *iNodo;
    int esPrimo;
    int contador;
    int i, k;

    // proceso
    inicio = (Nodo *) malloc(sizeof(Nodo));
    iNodo = inicio;
    contador = 0;
    i = 2;
    while (contador < 100) {
        // verifica si es primo el número "i"
        esPrimo = 1;
        k = 2;
        while (esPrimo && k < i) {
            if (i % k == 0) {
                esPrimo = 0;
            }
            ++k;
        }
        // agrega a la lista el número primo "i"
        if (esPrimo) {
            iNodo->valor = i;
            iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
            final = iNodo;
            iNodo = iNodo->siguiente;
            ++contador;
        }
        ++i;
    }
    final->siguiente = NULL;

    // salida por pantalla
    iNodo = inicio;
    i = 1;
    while (iNodo != NULL) {
        printf("%d-> %d\n", i, iNodo->valor);
        iNodo = iNodo->siguiente;
        ++i;
    }
}

void listaDe100NumerosNoPrimos(void)
{
    // variables
    Nodo *inicio;
    Nodo *final;
    Nodo *iNodo;
    int esPrimo;
    int contador;
    int i, k;
    int primeros[] = { 0, 1 };

    // proceso
    inicio = (Nodo *) malloc(sizeof(Nodo));
    iNodo = inicio;
    contador = 0;
    for (i = 0; i < 2; ++i) {
        iNodo->valor = primeros[i];
        iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
        final = iNodo;
        iNodo = iNodo->siguiente;
        ++contador;
    }
    i = 4;
    while (contador < 100) {
        esPrimo = 1;
        k = 2;
        while (esPrimo && k < i) {
            if (i % k == 0) {
                esPrimo = 0;
            }
            ++k;
        }
        if (!esPrimo) {
            iNodo->valor = i;
            iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
            final = iNodo;
            iNodo = iNodo->siguiente;
            ++contador;
        }
        ++i;
    }
    final->siguiente = NULL;

    // salida por pantalla
    iNodo = inicio;
    i = 1;
    while (iNodo != NULL) {
        printf("%d-> %d\n", i, iNodo->valor);
        iNodo = iNodo->siguiente;
        ++i;
    }
}

void listaDe100NumerosAlAzar(void)
{
    // variables
    Nodo *inicio;
    Nodo *final;
    Nodo *iNodo;
    int i;

    // proceso
    inicio = (Nodo *) malloc(sizeof(Nodo));
    iNodo = inicio;
    for (i = 0; i < 100; ++i) {
        iNodo->valor = rand() % 10 + 1;
        iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
        final = iNodo;
        iNodo = iNodo->siguiente;
    }
    final->siguiente = NULL;

    // salida por pantalla
    iNodo = inicio;
    i = 1;
    while (iNodo != NULL) {
        printf("%d-> %d\n", i, iNodo->valor);
        iNodo = iNodo->siguiente;
        ++i;
    }
}

void listaDeNumerosAlAzar(void)
{
    // variables
    Nodo *inicio;
    Nodo *final;
    Nodo *iNodo;
    int numero;
    int esta;
    int i;

    // agrega 100 valores aleatorios
    inicio = (Nodo *) malloc(sizeof(Nodo));
    iNodo = inicio;
    for (i = 0; i < 100; ++i) {
        iNodo->valor = rand() % 10 + 1;
        iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
        final = iNodo;
        iNodo = iNodo->siguiente;
    }
    final->siguiente = NULL;

    // proceso
    esta = 0;
    while (!esta) {
        printf("Numero? ");
        scanf("%d", &numero);
        iNodo = inicio;
        // comprueba si está o no está el número
        while (iNodo != NULL) {
            if (iNodo->valor == numero) {
                esta = 1;
                iNodo = NULL;
            } else {
                esta = 0;
                iNodo = iNodo->siguiente;
            }
        }
        // agrega el número que no estaba antes
        if (!esta) {
            iNodo = inicio;
            while (iNodo != NULL) {
                final = iNodo;
                iNodo = iNodo->siguiente;
            }
            iNodo = final;
            iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
            iNodo = iNodo->siguiente;
            iNodo->valor = numero;
            iNodo->siguiente = NULL;
        }
    }
    printf("El numero ya esta en la lista!\n");
}

void lista10NumerosPorTeclado(void)
{
    // variables
    Nodo *inicio;
    Nodo *final;
    Nodo *iNodo;
    int numero;
    int anterior;
    int i;

    // proceso
    printf("Numero? ");
    scanf("%d", &numero);
    anterior = numero;
    inicio = (Nodo *) malloc(sizeof(Nodo));
    inicio->valor = numero;
    inicio->siguiente = (Nodo *) malloc(sizeof(Nodo));
    iNodo = inicio->siguiente;
    for (i = 0; i < 9; ++i) {
        while (numero <= anterior) {
            printf("Numero mas grande? ");
            scanf("%d", &numero);
        }
        anterior = numero;
        iNodo->valor = numero;
        iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
        final = iNodo;
        iNodo = iNodo->siguiente;
    }
    final->siguiente = NULL;

    // salida por pantalla
    iNodo = inicio;
    i = 1;
    while (iNodo != NULL) {
        printf("%d-> %d\n", i, iNodo->valor);
        iNodo = iNodo->siguiente;
        ++i;
    }
}

void listaDe5NumerosInvertida(void)
{
    // variables de lista 1
    Nodo *inicio1;
    Nodo *final1;
    Nodo *iNodo1;

    // variables de lista 2
    Nodo *inicio2;
    Nodo *final2;
    Nodo *iNodo2;

    // variables
    int numero;
    int i;

    // llena lista 1 por teclado
    inicio1 = (Nodo *) malloc(sizeof(Nodo));
    iNodo1 = inicio1;
    iNodo1->anterior = NULL;
    for (i = 0; i < 5; ++i) {
        printf("Numero? ");
        scanf("%d", &numero);
        iNodo1->valor = numero;
        iNodo1->siguiente = (Nodo *) malloc(sizeof(Nodo));
        final1 = iNodo1;
        iNodo1 = iNodo1->siguiente;
        iNodo1->anterior = final1;
    }
    final1->siguiente = NULL;

    // copia lista 1 a lista 2 de forma invertida
    iNodo1 = final1;
    inicio2 = (Nodo *) malloc(sizeof(Nodo));
    iNodo2 = inicio2;
    while (iNodo1 != NULL) {
        iNodo2->valor = iNodo1->valor;
        iNodo2->siguiente = (Nodo *) malloc(sizeof(Nodo));
        final2 = iNodo2;
        iNodo2 = iNodo2->siguiente;
        iNodo1 = iNodo1->anterior;
    }
    final2->siguiente = NULL;

    // salida por pantalla de lista 2
    iNodo2 = inicio2;
    while (iNodo2 != NULL) {
        printf("%d\n", iNodo2->valor);
        iNodo2 = iNodo2->siguiente;
    }
}

void listaDe10NumerosAlAzarPor2(void)
{
    // variables de lista 1
    Nodo *inicio1;
    Nodo *final1;
    Nodo *iNodo1;

    // variables de lista 2
    Nodo *inicio2;
    Nodo *final2;
    Nodo *iNodo2;

    // variables
    int i;

    // llena lista 1 con valores al azar
    inicio1 = (Nodo *) malloc(sizeof(Nodo));
    iNodo1 = inicio1;
    for (i = 0; i < 10; ++i) {
        iNodo1->valor = rand() % 10 + 1;
        iNodo1->siguiente = (Nodo *) malloc(sizeof(Nodo));
        final1 = iNodo1;
        iNodo1 = iNodo1->siguiente;
    }
    final1->siguiente = NULL;

    // copia lista 1 a lista 2
    iNodo1 = inicio1;
    inicio2 = (Nodo *) malloc(sizeof(Nodo));
    iNodo2 = inicio2;
    while (iNodo1 != NULL) {
        iNodo2->valor = iNodo1->valor;
        iNodo2->siguiente = (Nodo *) malloc(sizeof(Nodo));
        final2 = iNodo2;
        iNodo2 = iNodo2->siguiente;
        iNodo1 = iNodo1->siguiente;
    }
    final2->siguiente = NULL;

    // multiplicamos por 2 los valores de la lista 2
    iNodo2 = inicio2;
    while (iNodo2 != NULL) {
        iNodo2->valor *= 2;
        iNodo2 = iNodo2->siguiente;
    }

    // copiamos valores de lista 2 a lista 1
    iNodo1 = inicio1;
    iNodo2 = inicio2;
    while (iNodo1 != NULL && iNodo2 != NULL) {
        iNodo1->valor = iNodo2->valor;
        iNodo1 = iNodo1->siguiente;
        iNodo2 = iNodo2->siguiente;
    }

    // salida por pantalla de lista 1
    iNodo1 = inicio1;
    while (iNodo1 != NULL) {
        printf("%d\n", iNodo1->valor);
        iNodo1 = iNodo1->siguiente;
    }
}

void listaDe10NumerosFibonacci(void)
{
    // variables
    Nodo *inicio;
    Nodo *final;
    Nodo *iNodo;
    int i;

    // proceso
    inicio = (Nodo *) malloc(sizeof(Nodo));
    iNodo = inicio;
    for (i = 1; i <= 10; ++i) {
        iNodo->valor = fibonacci(i);
        iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
        final = iNodo;
        iNodo = iNodo->siguiente;
    }
    final->siguiente = NULL;

    // salida por pantalla
    iNodo = inicio;
    while (iNodo != NULL) {
        printf("%d\n", iNodo->valor);
        iNodo = iNodo->siguiente;
    }
}

void listaDe100NumerosPerfectos(void)
{
    // variables
    Nodo *inicio;
    Nodo *final;
    Nodo *iNodo;
    int contador;
    int suma;
    int i, k;

    // proceso
    inicio = (Nodo *) malloc(sizeof(Nodo));
    iNodo = inicio;
    contador = 0;
    i = 6;
    while (contador < 100) {
        // comprueba si es perfecto
        suma = 1;
        for (k = 2; k < i; ++k) {
            if (i % k == 0) {
                suma += k;
            }
        }
        // es perfecto
        if (suma == i) {
            // agrega a la lista el número
            iNodo->valor = i;
            iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
            final = iNodo;
            iNodo = iNodo->siguiente;
            ++contador;
        }
        ++i;
    }
    final->siguiente = NULL;

    // salida por pantalla
    iNodo = inicio;
    while (iNodo != NULL) {
        printf("%d\n", iNodo->valor);
        iNodo = iNodo->siguiente;
    }
}

void listaDeNumerosCada10Milisegundos(void)
{
    // variables
    Nodo *inicio;
    Nodo *final;
    Nodo *iNodo;

    // proceso
    inicio = (Nodo *) malloc(sizeof(Nodo));
    iNodo = inicio;
    while (1) {
        Sleep(10);
        iNodo->valor = rand() % 10 + 1;
        printf("%d\n", iNodo->valor);
        iNodo->siguiente = iNodo;
        final = iNodo;
        iNodo = iNodo->siguiente;
    }
    final->siguiente = NULL;
}

void listaDeNumerosMedidasDeTendenciaCentral(void)
{
    // variables
    Nodo *inicio;
    Nodo *final;
    Nodo *iNodo;
    double promedio;
    int mayor;
    int menor;
    int suma;
    int i;

    // proceso
    inicio = (Nodo *) malloc(sizeof(Nodo));
    iNodo = inicio;
    for (i = 0; i < 10; ++i) {
        iNodo->valor = rand() % 10 + 1;
        iNodo->siguiente = (Nodo *) malloc(sizeof(Nodo));
        final = iNodo;
        iNodo = iNodo->siguiente;
    }
    final->siguiente = NULL;
    iNodo = inicio;
    suma = 0;
    mayor = iNodo->valor;
    menor = mayor;
    while (iNodo != NULL) {
        if (iNodo->valor > mayor) {
            mayor = iNodo->valor;
        }
        if (iNodo->valor < menor) {
            menor = iNodo->valor;
        }
        suma += iNodo->valor;
        iNodo = iNodo->siguiente;
    }
    promedio = suma / 10.0;

    // salida por pantalla
    printf("promedio: %lf\n", promedio);
    printf("mayor: %d\n", mayor);
    printf("menor: %d\n", menor);
}

int main(void)
{
    int opcion;
    srand(time(NULL));
    printf("Elija el problema para ejecutar (1-15)? ");
    scanf("%d", &opcion);
    switch (opcion) {
    case 1:
        listaDe100NumerosNaturales();
        break;
    case 2:
        listaDe100NumerosPares();
        break;
    case 3:
        listaDe100NumerosImpares();
        break;
    case 4:
        listaDe100MultiplosDe2();
        break;
    case 5:
        listaDe100NumerosPrimos();
        break;
    case 6:
        listaDe100NumerosNoPrimos();
        break;
    case 7:
        listaDe100NumerosAlAzar();
        break;
    case 8:
        listaDeNumerosAlAzar();
        break;
    case 9:
        lista10NumerosPorTeclado();
        break;
    case 10:
        listaDe5NumerosInvertida();
        break;
    case 11:
        listaDe10NumerosAlAzarPor2();
        break;
    case 12:
        listaDe10NumerosFibonacci();
        break;
    case 13:
        listaDe100NumerosPerfectos();
        break;
    case 14:
        listaDeNumerosCada10Milisegundos();
        break;
    case 15:
        listaDeNumerosMedidasDeTendenciaCentral();
        break;
    default:
        printf("Error!\n");
        break;
    }
    return 0;
}

