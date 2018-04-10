#include <stdio.h>
#include <string.h>

#define NPLAZAS 10

struct plaza {
	int estado;
	char tipo;
	char matricula[8];
};

void main() {
	char usuario[15] = "sandra", contraseña[15] = "2207";
	char usuarioaux[15], contraseñaaux[15];
	int matriculaaux[8];
	struct plaza plaza[NPLAZAS];
	int salida = 0, salida2 = 0, aparcado = 0;
	char opcion;
	int i = 1, j = 0;

	for (i = 0; i < NPLAZAS; i++) {
		plaza[i].estado = 0;
	}

	i = 1;

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

			while (salida2 == 0 ) {
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
					aparcado = 0;
					i = 0;
					while (aparcado == 0 && i < NPLAZAS) {
						if (plaza[i].estado == 0) {
							plaza[i].estado = 1;
							printf("Indique el tipo de vehiculo que desea aparcar C-coche, M-moto\n");
							getchar();
							scanf_s("%c", &plaza[i].tipo);
							while (plaza[i].tipo != 'c' && plaza[i].tipo != 'C' && plaza[i].tipo != 'm' && plaza[i].tipo != 'M') {
								printf("Ha introducido una opcion incorrecta, vuelva a indicar si es coche o moto\n");
								getchar();
								scanf_s("%c", &plaza[i].tipo);
							}
							printf("Indique la matricula de su vehiculo\n");
							scanf_s("%s", plaza[i].matricula, 8);
							aparcado = 1;
						}
						i++;
					}
					if (aparcado == 0) {
						printf("No quedan plazas libres\n");
					}
					break;

				case 'A':
				case'a':
					j = 0;
					for (i = 0; i < NPLAZAS; i++) {
						if (plaza[i].estado == 0) {
							j++;
						}
					}
					if (j == (NPLAZAS - 1)) {
						printf("No hay coches en el aparcamiento para retirar\n");
					}
					else {
						printf("Introduzca la matricula del coche a retirar:");
						scanf_s("%s", matriculaaux, 8);
						aparcado = 0;
						i = 0;
						while (aparcado == 0 && i < NPLAZAS) {
							if (plaza[i].estado == 1) {
								if (strcmp(matriculaaux, plaza[i].matricula) == 0) {
									plaza[i].estado = 0; /*Actualizo que se ha quedado vacia la plaza*/
									printf("\nCoche retirado\n");
									aparcado = 1;
								}
							}
							i++;
						}						
						if (aparcado == 0) {
							printf("La matricula introducida no coincide con ningun vehiculo\n");
						}
					}
					break;

				case 'E':
				case'e':
					for (i = 0; i < NPLAZAS; i++) {
						if (plaza[i].estado == 0) {
							printf("Plaza %d - Libre\n", i + 1);
						}
						else {
							printf("Plaza %d de %c - Ocupada - Matricula: %s\n", i + 1, plaza[i].tipo, plaza[i].matricula);
						}
					}
					break;

				case 'b':
				case 'B':
					j = 0;
					for (i = 0; i < NPLAZAS; i++) {
						if (plaza[i].estado == 0) {
							j++;
						}
					}
					if (j == (NPLAZAS - 1)) {
						printf("No hay coches en el aparcamiento\n");
					}
					else {
						printf("Introduzca la matricula del coche que desea buscar:");
						scanf_s("%s", matriculaaux, 8);
						aparcado = 0;
						i = 0;
						while (aparcado == 0 && i < NPLAZAS) {
							if (plaza[i].estado == 1) {
								if (strcmp(matriculaaux, plaza[i].matricula) == 0) {
									printf("El vehiculo de martricula %s se encuentra en la plaza 1\n", plaza[i].matricula);
									aparcado = 1;
								}
							}
							i++;
						}						
						if (aparcado == 0) {
							printf("La matricula introducida no coincide con ningun vehiculo\n");
						}
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