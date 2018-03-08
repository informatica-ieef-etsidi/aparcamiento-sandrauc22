/*El programa resuelto con cadena de caracteres esta comentado detras de los for que lo sustituyen ya que por algun problema del
visual no me deja guardarlos en memoria. He probado el mismo programa escribiendolo en notepad y compilandolo mediante el compilador
gcc y si que funciona, debe ser algun asunto de seguridad del visual.*/
#include <stdio.h>
#include <string.h> 
/*hay que incluir la libreria string.h para poder usar strcmp, linea 72*/

void main() {
	int estado_p1 = 0, estado_p2 = 0; /*si estan a 0 es que estan libres*/
	int i;
	char matric_p1[8], matric_p2[8];
	char matricula[8];
	char opcion;

	while (1) {

		printf("Seleccione una de estas opciones:\n");
		printf("R - Reservar una plaza\n");
		printf("A - Abandonar una plaza\n");
		printf("E - Estado del aparcamiento\n");
		scanf_s("%c", &opcion);
		system("cls");

		switch (opcion) {

		case 'R':
		case'r':
			if (estado_p1 == 1 && estado_p2 == 1) { /*Compruebo si estan los dos ocupados*/
				printf("No quedan plazas libres\n");
			}
			else if (estado_p1 == 0) { /* esta libre la plaza 1*/
				for (i = 0; i < 7; i++) {
					printf("Introduce el caracter %d de la matricula\n", i + 1);
					getchar();
					scanf_s("%c", &matric_p1[i]);
				}
			estado_p1 = 1;/*Actualizo que la plaza esta ocupada*/
			printf("\nCoche aparcado\n");
				/*printf("Introduzca su matricula:");
				scanf_s("%s", matric_p1);
				estado_p1 = 1; 
				printf("\nCoche aparcado\n");*/
			}
			else { /*estaba ocupada la plaza 1, sigue libre la 2*/
				for (i = 0; i < 7; i++) {
					printf("Introduce el caracter %d de la matricula\n", i + 1);
					getchar();
					scanf_s("%c", &matric_p2[i]);
				}
			estado_p2 = 1;
			printf("\nCoche aparcado\n");
				/*printf("Introduzca su matricula:");
				scanf_s("%s", matric_p2);
				estado_p2 = 1;
				printf("\nCoche aparcado\n");*/
			}
			break;

		case 'A':
		case'a':
			if (estado_p1 == 0 && estado_p2 == 0) { /*Si estan ambos libres*/
				printf("No hay coches en el aparcamiento para retirar\n");
			}
			else {
				for (i = 0; i < 7; i++) {
					printf("Introduce el caracter %d de la matricula del coche a retirar\n", i + 1);
					getchar();
					scanf_s("%c", &matricula[i]);
				}
				/*printf("Introduzca la matricula del coche a retirar:");
				scanf_s("%s", matricula);*/
				if (strcmp(matricula, matric_p1) == 1) {
					estado_p1 = 0; /*Actualizo que se ha quedado vacia la plaza*/
					printf("\nCoche retirado\n");
				}
				else if (strcmp(matricula, matric_p2) == 1) { /*Entra si las matriculas son iguales*/
					estado_p2 = 0;
					printf("\nCoche retirado\n");
				}
				else {
					printf("La matricula introducida no coincide con ningun coche\n");
				}
			}
			break;

		case 'E':
		case'e':
			if (estado_p1 == 0) { /*plaza 1 libre*/
				printf("Plaza 1 - Libre\n");
			}
			else /*plaza 1 ocupada*/
				printf("Plaza 1 - Ocupada - Matricula: %s\n", matric_p1);

			if (estado_p2 == 0) { /*plaza 2 libre*/
				printf("Plaza 2 - Libre\n");
			}
			else /*plaza 2 ocupada*/
				printf("Plaza 2 - Ocupada - Matricula: %s\n", matric_p2);
			break;

		default:
			printf("No ha introducido una opcion correcta\n");
		}
		system("pause");
		system("cls");
	}
}
