#include <stdio.h>
#include <string.h>

struct plaza {
	int estado;
	char tipo;
	char matricula[8];
};

void main() {
	char usuario[15] = "sandra", contraseña[15] = "2207";
	char usuarioaux[15], contraseñaaux[15];
	int matriculaaux[8];
	struct plaza plaza1 = { 0, 'C' }, plaza2 = { 0, 'M' };
	int salida = 0, salida2 = 0;
	char opcion, tipo;
	int i = 1;

	system("color 79");

	while (salida == 0) {

		printf("Introduzca su usuario:\n");
		gets(usuarioaux);
		printf("Introduzca su contraseña:\n");
		gets(contraseñaaux);
		if (strcmp(usuarioaux, usuario) == 0 && strcmp(contraseñaaux, contraseña) == 0) {
			printf("Bienvenido al aparcamiento\n");
			system("pause");
			system("cls");

			while (salida2 == 0) {
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
					if (plaza1.estado == 1 && plaza2.estado == 1) { /*Compruebo si estan los dos ocupados*/
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
							if (plaza1.estado == 0) {
								printf("Introduzca su matricula:");
								scanf_s("%s", plaza1.matricula, 8);
								plaza1.estado = 1;
								printf("Coche aparcado\n");
							}
							else {
								printf("No quedan plazas de coche libres\n");
							}
							break;

						case 'm':
						case 'M':
							if (plaza2.estado == 0) {
								printf("Introduzca su matricula:");
								scanf_s("%s", plaza2.matricula, 8);
								plaza2.estado = 1;
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
					if (plaza1.estado == 0 && plaza2.estado == 0) { /*Si estan ambos libres*/
						printf("No hay coches en el aparcamiento para retirar\n");
					}
					else {
						printf("Introduzca la matricula del coche a retirar:");
						scanf_s("%s", matriculaaux, 8);
						if (strcmp(matriculaaux, plaza1.matricula) == 0) {
							plaza1.estado = 0; /*Actualizo que se ha quedado vacia la plaza*/
							printf("\nCoche retirado\n");
						}
						else if (strcmp(matriculaaux, plaza2.matricula) == 0) { /*Entra si las matriculas son iguales*/
							plaza2.estado = 0;
							printf("\nCoche retirado\n");
						}
						else {
							printf("La matricula introducida no coincide con ningun coche\n");
						}
					}
					break;

				case 'E':
				case'e':
					if (plaza1.estado == 0) { /*plaza 1 libre*/
						printf("Plaza 1 de coche - Libre\n");
					}
					else /*plaza 1 ocupada*/
						printf("Plaza 1 de coche - Ocupada - Matricula: %s\n", plaza1.matricula);

					if (plaza2.estado == 0) { /*plaza 2 libre*/
						printf("Plaza 2 de moto - Libre\n");
					}
					else /*plaza 2 ocupada*/
						printf("Plaza 2 de moto - Ocupada - Matricula: %s\n", plaza2.matricula);
					break;

				case 'b':
				case 'B':
					if (plaza1.estado == 1 || plaza2.estado == 1) {
						printf("Intoduzca la matricula del vehiculo que desea buscar\n");
						scanf_s("%s", matriculaaux, 8);
						if (strcmp(matriculaaux, plaza1.matricula) == 0) {
							printf("El vehiculo de martricula %s se encuentra en la plaza 1\n", plaza1.matricula);
						}
						else if (strcmp(matriculaaux, plaza2.matricula) == 0) {
							printf("El vehiculo de martricula %s se encuentra en la plaza 2\n", plaza2.matricula);
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
					salida2 = 1;
					break;

				default:
					printf("No ha introducido una opcion correcta\n");
				}
				system("pause");
				system("cls");
				getchar();

			}
			
		}
		else {
			if (i == 3) {
				printf("Has agotado el numero de intentos\n");
				salida = 1;
			}
			else {
				printf("El usuario o la contraseña son incorrectos\n");
				printf("Te quedan %d intentos\n", 3 - i);
				printf("Vuelve a introducirlos\n");
				i++;
			}
			system("pause");
		}
	}	
}