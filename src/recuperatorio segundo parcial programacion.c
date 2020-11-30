/*
 ============================================================================
 Name        : recuperatorio.c
 Author      : Pazos Ezequiel
 Description : Recuperatorio 2do parcial programacion
 ============================================================================

 .Dada la estructura eVehiculo crear una función constructora
  base y una parametrizada

 2. Dada la estructura del punto anterior declarar una variable
 con valores y guardarla en un archivo de texto.

 3. Dada la estructura del punto anterior declarar una variable
  con valores y guardarla en un archivo binario
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int id;
	char marca[20];
	int tipo;
	float peso;
}eVehiculo;

eVehiculo* vehiculo_new(void);
eVehiculo* vehiculo_newParametros(int id, char* marca, int tipo, float peso);

int main(void) {

	setbuf(stdout, NULL);

	eVehiculo* pVehiculo;
	char variablePrueba[ ]= "Esta es una cadena de prueba";
	int longitud, cantidad;
	char variablePruebaDos[] = "3.1416";

	if((pVehiculo=fopen("prueba.dat","r"))==NULL) //read archivo de texto
	{
		if((pVehiculo=fopen("prueba.dat","w"))==NULL) //write archivo de texto
		{
			printf("\nEl archivo no puede ser abierto");
			exit (1);
		}

		longitud=strlen(variablePrueba);

		cantidad = fwrite(variablePrueba, sizeof(char), longitud, pVehiculo);

		if (cantidad<longitud)
		{
			printf("\nError al escribir el archivo");
		}else{
			printf("\nSe escribieron %d caracteres", cantidad);
		}

		fclose(pVehiculo);
	}

	if((pVehiculo=fopen("prueba.dat","rb"))==NULL) //read binario
	{
		if((pVehiculo=fopen("prueba.dat","wb"))==NULL) //write binario
		{
			printf("\nEl archivo no puede ser abierto");
			exit (1);
		}

		longitud=strlen(variablePrueba);

		cantidad = fwrite(variablePrueba, sizeof(char), longitud, pVehiculo);

		if (cantidad<longitud)
		{
			printf("\nError al escribir el archivo");
		}else{
			printf("\nSe escribieron %d caracteres", cantidad);
		}

		fclose(pVehiculo);
	}

	return EXIT_SUCCESS;
}


eVehiculo* vehiculo_new(void)
{
	return (eVehiculo*) malloc(sizeof(eVehiculo));
}

eVehiculo* vehiculo_newParametros(int id, char* marca, int tipo, float peso)
{
	eVehiculo* this = vehiculo_new();

	if(!vehiculo_setId(this, id) && //faltaria setear id marca tipo peso
	   !vehiculo_setMarca(this, marca) &&
	   !vehiculo_setTipo(this, tipo) &&
	   !vehiculo_setPeso(this, peso))
	{
		return this;
	}
	vehiculo_delete(this); //falta hacer un delete que es un free(this)
	return NULL;
}
