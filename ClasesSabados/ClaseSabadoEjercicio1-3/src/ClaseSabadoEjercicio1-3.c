/*
 ============================================================================
Ignacio Smirlian (1H)
ignaciosmirlian@gmail.com

Ejercicio 1-3:

Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de la UTN FRA,
los datos solicitados son:

Legajo
Tipo cursada(L: "libre" - P: "presencial" – R: "remota")
Cantidad de materias( mas de cero y menos de 8)
Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
Nota promedio (entre 0 y 10)
Edad (validar)

Se debe informar de existir, o informar que no existe , en el caso que corresponda.
a) El Legajo del mejor promedio femenino.
b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa más materias. (Sin importar su género)

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	char respuesta;

	//punto a
	int legajoMejorPromedioM;
	float mejorNotaM;
	//punto b
	char primerIngresoM;
	char primerIngresoH;
	int legajoHombreJovenLibre;
	int edadHombreMasJovenLibre;
	//punto c
	int contadorHombres;
	float acumuladorNotasHombres;
	float promedioNotasHombres;
	int contadorMujeres;
	float acumuladorNotasMujeres;
	float promedioNotasMujeres;
	int contadorNoBinarios;
	float acumuladorNotasNoBinarios;
	float promedioNotasNoBinarios;
	//punto d
	int mayorCantidadMaterias;
	int legajoMasMaterias;
	char primerIngreso;
	int edadMasMaterias;


	respuesta='s';
	primerIngresoM='s';
	primerIngresoH='s';
	primerIngreso='s';

	contadorHombres=0;
	acumuladorNotasHombres=0;

	contadorMujeres=0;
	acumuladorNotasMujeres=0;

	contadorNoBinarios=0;
	acumuladorNotasNoBinarios=0;


	while (respuesta=='s')
	{
		int legajoIngresado;
		char tipoDeCursada;
		int cantidadDeMaterias;
		char sexoIngresado;
		float notaPromedio;
		int edadIngresada;

		printf("Ingrese el numero de legajo: ");
		scanf("%d",&legajoIngresado);

		printf("Ingrese el tipo de cursada: L: libre - P: presencial – R: remota ");
		fflush(stdin);
		scanf("%c",&tipoDeCursada);

		while(tipoDeCursada!='L'&&tipoDeCursada!='P'&&tipoDeCursada!='R')
		{
			printf("Error, dato ingresado inválido. Vuelva a ingresarlo: ");
			fflush(stdin);
			scanf("%c",&tipoDeCursada);
		}

		printf("Ingrese la cantidad de materias: ");
		scanf("%d",&cantidadDeMaterias);

		while(cantidadDeMaterias>8||cantidadDeMaterias<1)
		{
			printf("Error. Dato fuera de rango. Vuelva a ingresarlo");
			scanf("%d",&cantidadDeMaterias);
		}

		printf("Ingrese el sexo del estudiante: F: femenino – M: masculino , O: no binario");
		fflush(stdin);
		scanf("%c",&sexoIngresado);

		while(sexoIngresado!='F'&&sexoIngresado!='M'&&sexoIngresado!='O')
		{
			printf("Error, dato ingresado inválido. Vuelva a ingresarlo: ");
			fflush(stdin);
			scanf("%c",&sexoIngresado);
		}

		printf("Ingrese la nota promedio: ");
		scanf("%f",&notaPromedio);

		while(notaPromedio>10||notaPromedio<1)
		{
			printf("Error. Dato fuera de rango. Vuelva a ingresarlo");
			scanf("%f",&notaPromedio);
		}

		printf("Ingrese la edad del estudiante: ");
		scanf("%d",&edadIngresada);

		while(edadIngresada>100||edadIngresada<16)
		{
			printf("Error. Dato fuera de rango. Vuelva a ingresarlo");
			scanf("%d",&edadIngresada);
		}

		printf("Desea ingresar otro dato? s (si) n (no): ");
		fflush(stdin);
		scanf("%c",&respuesta);

		switch(sexoIngresado)
		{
			case 'M':

				if(tipoDeCursada=='L')
				{
					if(primerIngresoH=='s'||edadIngresada<edadHombreMasJovenLibre)
					{
						legajoHombreJovenLibre=legajoIngresado; //Punto b
						edadHombreMasJovenLibre=edadIngresada;
						primerIngresoH='n';
					}
				}

				contadorHombres+=1;
				acumuladorNotasHombres+=notaPromedio;
				break;
			case 'F':
				if(primerIngresoM=='s'||notaPromedio>mejorNotaM)
				{
					legajoMejorPromedioM=legajoIngresado; //Punto a
					mejorNotaM=notaPromedio;
					primerIngresoM='n';
				}
				contadorMujeres+=1;
				acumuladorNotasMujeres+=notaPromedio;
				break;
			case 'O':
				contadorNoBinarios+=1;
				acumuladorNotasNoBinarios+=notaPromedio;
				break;
		}

		if(primerIngreso=='s')
		{
			 mayorCantidadMaterias=cantidadDeMaterias;
			 legajoMasMaterias=legajoIngresado;
			 edadMasMaterias=edadIngresada;
			 primerIngreso='n';
		} else
		{
			if(cantidadDeMaterias>mayorCantidadMaterias)
			{
				mayorCantidadMaterias=cantidadDeMaterias;
				legajoMasMaterias=legajoIngresado;
				edadMasMaterias=edadIngresada;
			}
		}




	}

	printf("El legado de la estudiante con mejor promedio es %d\n", legajoMejorPromedioM);
	printf("El legajo del hombre mas joven en cursada libre es %d\n", legajoHombreJovenLibre);

	if(contadorHombres>0)
	{
		promedioNotasHombres= acumuladorNotasHombres/contadorHombres;
	} else
	{
		promedioNotasHombres=0;
	}

	if(contadorMujeres>0)
	{
		promedioNotasMujeres=acumuladorNotasMujeres/contadorMujeres;
	} else
	{
		promedioNotasMujeres=0;
	}
	if(contadorNoBinarios>0)
	{
		promedioNotasNoBinarios=acumuladorNotasNoBinarios/contadorNoBinarios;
	} else
	{
		promedioNotasNoBinarios=0;
	}

	printf("El promedio de notas de los hombres es %.2f\nEl promedio de las mujeres es %.2f"
			"\nEl promedio de los no binarios es %.2f\n",promedioNotasHombres,promedioNotasMujeres,
			promedioNotasNoBinarios);

	printf("El legajo del estudiante con mas materias es %d y su edad es %d\n",legajoMasMaterias,edadMasMaterias);


	return EXIT_SUCCESS;
}
