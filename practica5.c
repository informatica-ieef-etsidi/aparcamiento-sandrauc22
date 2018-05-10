#include <stdio.h>
#include <string.h>

#define NPLAZAS 10

struct plaza {
	int estado;
	char tipo;
	char matricula[8];
};
struct usuario {
	char usuario[15];
	char contraseña[15];
};

char menu();
int esDigitoValido(char caracter);
int esLetraValida(char caracter);
int esMatriculaValida(char matricula[]);
int existeUsuario(struct usuario usuarioValido, char username[], char password[]);

void main() {
	struct usuario usu = {"admin", "1234"};
	char usuarioaux[15], contraseñaaux[15];
	int matriculaaux[8];
	struct plaza plaza[NPLAZAS];
	int salida = 0, salida2 = 0, aparcado = 0;
	char opcion;
	int i = 1, j = 0;
	int comprobacion;
	int usuValido;

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
		usuValido = existeUsuario(usu, usuarioaux, contraseñaaux);
		if (usuValido == 0) {
			while (salida2 == 0) {
				opcion = menu();

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
							comprobacion = esMatriculaValida(plaza[i].matricula);							
							while (comprobacion == 0) {
								printf("La matricula no es valida\nVuelva a introducirla\n");
								scanf_s("%s", plaza[i].matricula, 8);
								comprobacion = esMatriculaValida(plaza[i].matricula);
							}
							if (comprobacion == 1) {
								aparcado = 1;
								printf("Vehiculo aparcado correctamente\n");
							}							
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
char menu() {
	char opcion;
	printf("Seleccione una de estas opciones:\n");
	printf("R - Reservar una plaza\n");
	printf("A - Abandonar una plaza\n");
	printf("E - Estado del aparcamiento\n");
	printf("B - Buscar vehículo por matrícula\n");
	printf("S - Salir del programa\n");
	scanf_s("%c", &opcion);
	system("cls");
	return opcion;
}
int esDigitoValido(char caracter) {
	if (caracter >= '0' && caracter <= '9') {
		return 1;
	}
	else {
		return 0;
	}
}
int esLetraValida(char caracter) {
	if (caracter >= 'a' && caracter <= 'z') {
		caracter = caracter - 32;
	}
	if (caracter > 'A' && caracter <= 'Z' && caracter != 'E' && caracter != 'I' && caracter != 'O' && caracter != 'U') {
		return 1;
	}
	else {
		return 0;
	}
}
int esMatriculaValida(char matricula[]) {
	int comprobacion = 1, i, numero;
	for (i = 0; i < 7; i++) {
		if (i < 4) {
			numero = esDigitoValido(matricula[i]);
			if (numero == 0) {
				comprobacion = 0;
			}
		}
		else {
			numero = esLetraValida(matricula[i]);
			if (numero == 0) {
				comprobacion = 0;
			}
		}
	}
	return comprobacion;
}
int existeUsuario(struct usuario usuarioValido, char username[], char password[]) {
	int salida = 0;
	
	if (strcmp(username, usuarioValido.usuario) == 0 && strcmp(password, usuarioValido.contraseña) == 0) {
		printf("Bienvenido al aparcamiento\n");
		system("pause");
		system("cls");
	}
	else {
		salida = 1;
	}
	return salida;
}