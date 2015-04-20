#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define ADMINISTRADOR "carlos"

typedef struct Tarea Tarea;
typedef struct Nodo Nodo;

struct Nodo
{
    int id;
    Nodo *siguiente;
};

struct Tarea
{
    char propietario[50];
    int edad;
    Nodo *dependencias;
    char concepto[255];
    Tarea *siguiente;
};

int main(int argc, char **argv)
{
    // comprobación
    if (argc == 1) {
        printf("Indentifiquese\n");
        return 1;
    }
    if (strcmp(argv[1], ADMINISTRADOR) != 0) {
        printf("No eres el administrador\n");
        return 2;
    }

    // variables
    char res = 's';
    int dependencia;
    Tarea *tareas;
    Tarea *iNodo;
    Tarea *finalTareas;
    Nodo *iNodoDep;
    Nodo *finalDep;
    FILE *F;

    // proceso
    tareas = (Tarea *) malloc(sizeof(Tarea));
    iNodo = tareas; // inicio de la lista
    do {
        printf("Ingrese los datos de una tarea\n");
        printf("Propietario: ");
        setbuf(stdin, NULL);
        gets(iNodo->propietario);
        printf("Edad: ");
        scanf("%d", &iNodo->edad);
        printf("Introduza dependencias por espacios"
               " (cuando termine ponga -1)\n");
        printf("Dependencias: ");
        iNodo->dependencias = (Nodo *) malloc(sizeof(Nodo));
        iNodoDep = iNodo->dependencias; // inicio de la lista de deps.
        do {
            scanf("%d", &dependencia);
            if (dependencia != -1) {
                iNodoDep->id = dependencia;
                iNodoDep->siguiente = (Nodo *) malloc(sizeof(Nodo));
                finalDep = iNodoDep;
                iNodoDep = iNodoDep->siguiente;
            }
        } while (dependencia != -1);
        finalDep->siguiente = NULL; // marca el final con NULL
        printf("Concepto: ");
        setbuf(stdin, NULL);
        gets(iNodo->concepto);

        printf("Desea ingresar otra tarea? [s/n]: ");
        setbuf(stdin, NULL);
        scanf("%c", &res);

        iNodo->siguiente = (Tarea *) malloc(sizeof(Tarea));
        finalTareas = iNodo;
        iNodo = iNodo->siguiente;
    } while (res == 'S' || res == 's');
    finalTareas->siguiente = NULL;

    F = fopen("agenda.txt", "w");
    if (F == NULL) {
        printf("Error de fichero\n");
        return 3;
    }

    iNodo = tareas; // inicio de la lista de tareas
    while (iNodo != NULL) {
        fprintf(F, "Propietario: %s\n", iNodo->propietario);
        fprintf(F, "Edad: %d\n", iNodo->edad);
        fprintf(F, "Dependencias: ");
        iNodoDep = iNodo->dependencias; // inicio de la lista de deps.
        while (iNodoDep != NULL) {
            fprintf(F, "%d ", iNodoDep->id);
            iNodoDep = iNodoDep->siguiente;
        }
        fprintf(F, "\nConcepto: %s\n", iNodo->concepto);
        fprintf(F, "*\n");
        iNodo = iNodo->siguiente;
    }

    fflush(F);
    fclose(F);
    return 0;
}

