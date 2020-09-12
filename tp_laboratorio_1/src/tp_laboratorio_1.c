/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : Mariana
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	float operandoA;
	float operandoB;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	float resultadoFactorialA;
	float resultadoFactorialB;
	char opcion;
	char salir;
	int validacionFuncion;

	do
		{
		validacionFuncion=utn_getChar("\nIngrese una opcion\n a)1er operando:\n b)2do operando:\n c)Calcular todas las operaciones \n d)Resultados\n e)Salir",
				"\nOpcion no valida, ingrese un caracter en minuscula\n",
				&opcion, 2,'a','e');
		if(validacionFuncion==0)
		{
			switch(opcion)
			{
			case 'a':
				utn_getNumeroFloat("Ingrese 1er numero\n","Ingrese nuevamente,numero invalido\n", &operandoA, 2, -1000, 1000);
				printf("\nEl numero ingresado es: %2.f",operandoA);
				break;
			case 'b':
				utn_getNumeroFloat("Ingrese 2do numero\n","Ingrese nuevamente, numero invalido\n", &operandoB, 2, -1000, 1000);
				printf("\nEl numero ingresado es: %2.f", operandoB);
				break;
			case'c':
				operandoSuma(operandoA, operandoB, &resultadoSuma);
				operandoResta(operandoA, operandoB, &resultadoResta);
				operandoDividir(operandoA, operandoB, &resultadoDivision);
				operandoMultiplicar(operandoA, operandoB, &resultadoMultiplicacion);
				operandoFactoreo(operandoA,&resultadoFactorialA);
				operandoFactoreo(operandoB, &resultadoFactorialB);
				printf("\nSe realizo con exito los calculos!!\n");
				break;
			case'd':
				printf("\nEl resultado de la suma es:%2.f",resultadoSuma);
				printf("\nEl resultado de la resta es:%2.f",resultadoResta);
				if(resultadoDivision!=0){
					printf("\nEl resultado de la division es:%2.f",resultadoDivision);
				}
				else{
					printf("\nNo es posible dividir por cero");
				}
				printf("\nEl resultado de la multiplicacion es:%2.f",resultadoMultiplicacion);
				printf("\nEl resultado del factorial A es:%2.f",resultadoFactorialA);
				printf("\nEl resultado del factorial B es:%2.f",resultadoFactorialB);
				break;
			case'e':
				printf("\nUsted decidio salir");
				salir='s';
				break;
			}
		}
	}while(salir!='s');
 return EXIT_SUCCESS;
}
