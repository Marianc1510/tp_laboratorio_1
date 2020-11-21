/*
 * calculos.c
 *
 *  Created on: 29 sep. 2020
 *      Author: mariana
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "calculos.h"
#include "utN.h"

/* \brief operandoSuma : Esta funcion se le pasan dos valores float por parametros y el resultado de su suma se alojara en el puntero pResultado para
 * \informar dicho resultado, verificando a su vez que sea distinto de NULL.
 * \param float operando1: se registra el un valor emitido por el usuario.
 * \param float operando2: se registra el un valor emitido por el usuario.
 * \param float pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int operandoSuma(float operador1, float operador2, float* pResultado)
{
	int retorno=-1;
	if(pResultado !=NULL)
	{
		*pResultado= operador1 + operador2;
		retorno=0;
	}
	else
	{
		retorno=-1;
	}
	return retorno;
}
/* \brief operandoResta : Esta funcion se le pasan dos valores float por parametros y el resultado de su resta se alojara en el puntero pResultado para
 * \informar dicho resultado, verificando a su vez que sea distinto de NULL.
 * \param float operando1: se registra el un valor emitido por el usuario.
 * \param float operando2: se registra el un valor emitido por el usuario.
 * \param float pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int operandoResta(float operador1, float operador2, float* pResultado)
{
	int retorno=-1;
	if(pResultado !=NULL)
	{
		*pResultado= operador1 - operador2;
		retorno=0;
	}
	else
	{
		retorno=-1;
	}
	return retorno;
}
/* \brief operandoMultiplicar : Esta funcion se le pasan dos valores float por parametros y el resultado de su multiplicacion se alojara en el puntero pResultado para
 * \informar dicho resultado, verificando a su vez que sea distinto de NULL.
 * \param float operando1: se registra el un valor emitido por el usuario.
 * \param float operando2: se registra el un valor emitido por el usuario.
 * \param float pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int operandoMultiplicar(float operador1, float operador2, float* pResultado)
{
	int retorno=-1;
	if(pResultado !=NULL)
	{
		*pResultado= operador1 * operador2;
		retorno=0;
	}
	else
	{
		retorno=-1;
	}
	return retorno;
}
/* \brief operandoDividir : Esta funcion se le pasan dos valores float por parametros y el resultado de su division se alojara en el puntero pResultado para
 * \informar dicho resultado, verificando a su vez que sea distinto de NULL.
 * \param float operando1: se registra el un valor emitido por el usuario.
 * \param float operando2: se registra el un valor emitido por el usuario.
 * \param float pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int operandoDividir(float operador1, float operador2, float* pResultado)
{
	int retorno=-1;
	if(pResultado !=NULL && operador2 !=0)
	{
		*pResultado= operador1 / operador2;
		retorno=0;
	}
	else
	{
		retorno=-1;
	}
	return retorno;
}
/**
 * \brief 	Esta funcion se le pasa un valor float por parametro y el resultado de su factoreo se alojara en el puntero pResultado para
 * \informar dicho resultado, verificando a su vez que sea distinto de NULL.
 * \param operandoA se registra el un valor emitido por el usuario.
 * \param  pResultado es el puntero del espacio de memoria donde se almacenara el resultado final de la operacion.
 * \return Retorna 0 (EXITO) y -1 (ERROR) si no hubiese podido complertarse la accion
**/

int operandoFactoreo(float operando, float* pResultado)
{

	int retorno=-1;
	int i;
	int auxNumero=1;

	if(pResultado!=NULL)
	{
		for(i=operando;i>=1; i--)
		{
			auxNumero= auxNumero*i;
		}
		*pResultado=(float)auxNumero;
		retorno=0;
	}
	return retorno;
}
int contadorArrayChar(char array[], char* pvalorContado) //int numero otro parametro para que quede mas generico y poder reutilizarlo
{
	int retorno =-1;
	int i = 0;
	int contador=0;
	if(array !=NULL && pvalorContado != NULL)
	{
		//for(i=0; i< len; i ++)
			while(array[i] !='\0')
			{
				if(array[i]=='e')
				{
					contador++;
				}
				i++;
			}
		*pvalorContado = contador;
		retorno = 0;
	}
	return retorno;
}
int contadorArray(int array[], int len, int* pvalorContado) //int numero otro parametro para que quede mas generico y poder reutilizarlo
{
	int retorno =-1;
	int i;
	int contador = 0;
	if(array != NULL && len > 0 && pvalorContado != NULL)
	{
		for(i=0; i< len; i ++)
			{
				if(array[i] == pvalorContado)
				{
					contador++;
				}
			}
		*pvalorContado = contador;
		retorno = 0;
	}
	return retorno;
}
