#include <stdio.h>
#include <string.h> 
#include <time.h>
/*La plaza 1 sera para coche y la 2 para moto*/

void main() {
	int estado_p1 = 0, estado_p2 = 0; /*si estan a 0 es que estan libres*/
	int i, salida = 0;
	char matric_p1[8], matric_p2[8];
	char matricula[8];
	char opcion, tipo;

	system("color 79");

	while (salida == 0) {

		printf("Seleccione una de estas opciones:\n");
		printf("R - Reservar una plaza\n");
		printf("A - Abandonar una plaza\n");
		printf("E - Estado del aparcamiento\n");
		printf("B - Buscar vehículo por matrícula\n");
		printf("S - Salir del programa\n");
		scanf_s("%c", &opcion);
		system("cls");

		switch (opcion) {

		case 'R':
		case'r':
			if (estado_p1 == 1 && estado_p2 == 1) { /*Compruebo si estan los dos ocupados*/
				printf("No quedan plazas libres\n");
			}
			else {
				printf("Indique el tipo de vehiculo que desea aparcar\n");
				printf("C-coche\n");
				printf("M-moto\n");
				getchar();
				scanf_s("%c", &tipo);
				system("cls");
				switch (tipo) {

				case 'c':
				case 'C':
					if (estado_p1 == 0) {
						printf("Introduzca su matricula:");
						scanf_s("%s", matric_p1, 8);
						estado_p1 = 1;
						printf("Coche aparcado\n");
					}
					else {
						printf("No quedan plazas de coche libres\n");
					}
					break;

				case 'm':
				case 'M':
					if (estado_p2 == 0) {
						printf("Introduzca su matricula:");
						scanf_s("%s", matric_p2, 8);
						estado_p2 = 1;
						printf("Moto aparcada\n");
					}
					else {
						printf("No quedan plazas de moto libres\n");
					}
					break;

				default:
					printf("No ha introducido una opcion correcta\n");
				}
			}
			break;

		case 'A':
		case'a':
			if (estado_p1 == 0 && estado_p2 == 0) { /*Si estan ambos libres*/
				printf("No hay coches en el aparcamiento para retirar\n");
			}
			else {
				printf("Introduzca la matricula del coche a retirar:");
				scanf_s("%s", matricula, 8);
				if (strcmp(matricula, matric_p1) == 0) {
					estado_p1 = 0; /*Actualizo que se ha quedado vacia la plaza*/
					printf("\nCoche retirado\n");
				}
				else if (strcmp(matricula, matric_p2) == 0) { /*Entra si las matriculas son iguales*/
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
				printf("Plaza 1 de coche - Libre\n");
			}
			else /*plaza 1 ocupada*/
				printf("Plaza 1 de coche - Ocupada - Matricula: %s\n", matric_p1);

			if (estado_p2 == 0) { /*plaza 2 libre*/
				printf("Plaza 2 de moto - Libre\n");
			}
			else /*plaza 2 ocupada*/
				printf("Plaza 2 de moto - Ocupada - Matricula: %s\n", matric_p2);
			break;

		case 'b':
		case 'B':
			if (estado_p1 == 1 || estado_p2 == 1) {
				printf("Intoduzca la matricula del vehiculo que desea buscar\n");
				scanf_s("%s", matricula, 8);
				if (strcmp(matricula, matric_p1) == 0) {
					printf("El vehiculo de martricula %s se encuentra en la plaza 1\n", matric_p1);
				}
				else if (strcmp(matricula, matric_p2) == 0) {
					printf("El vehiculo de martricula %s se encuentra en la plaza 2\n", matric_p2);
				}
				else {
					printf("La matricula introducida no coincide con ningun vahiculo aparcado\n");
				}
			}
			else {
				printf("No hay vehiculos aparcados\n");
			}
			break;

		case 's':
		case 'S':
			salida = 1;
			break;

		default:
			printf("No ha introducido una opcion correcta\n");
		}
		system("pause");
		system("cls");
		getchar();

	}
}