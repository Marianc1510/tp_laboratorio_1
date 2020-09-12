/*
 * utn.c
 *
 *  Created on: 3 sep. 2020
 *      Author: mariana
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 *\brief utn_getNumero : Pide al usuario un numero entero
 *\param char* msg: El mensaje que imprime para pedir un valor
 *\param char* msgError: mensaje que imprime si el rango no es valido
 *\param int* pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 *\param int reintentos, cantidad de oportunidades para ingresar el dato
 *\param int min: valor minimo admitido(inclusive)
 *\param int max: valor maximo admitido (no inclusive)
 *\ Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getNumero(char* msg,char* msgError,int* pResultado,int reintentos,int min,int max)
{
	int retorno=-1;
	int bufferInt;
	int resultadoScanf;

	if(msg!=NULL &&
			msgError !=NULL &&
			pResultado !=NULL &&
			reintentos >=0 &&
			max >= min)
	{
		do
		{
			printf("%s\n",msg);
			__fpurge(stdin);
			resultadoScanf= scanf("%d",&bufferInt);
			if (resultadoScanf== 1 && bufferInt>=min && bufferInt <=max)
				{
					*pResultado= bufferInt;
					retorno=0;
					break;
				}
			else
			{
				printf("%s",msgError);
				reintentos--;
			}
		}while(reintentos > 0);
	}
	return retorno;
}
/* \brief utn_getNumeroFloat : Pide al usuario un numeros decimales
 * \param char mensaje: El mensaje que imprime para pedir un valor
 * \param char mensajeError: mensaje que imprime si el rango no es valido
 * \param float pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int min: valor minimo admitido (inclusive)
 * \param int max: valor maximo admitido  (no inclusive)
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getNumeroFloat(char* mensaje, char* mensajeError,float* pResultado,int reintentos,int min, int max)
{
	int retorno=-1;
	float bufferFloat;
	int resultadoScanf;

	if(pResultado != NULL && mensaje !=NULL && mensajeError !=NULL)
	{
		while(reintentos > 0)
			{
				printf("%s\n",mensaje);
				__fpurge(stdin);
				resultadoScanf= scanf("%f",&bufferFloat);
				if (resultadoScanf== 1 && bufferFloat>=min && bufferFloat <=max)
					{
						*pResultado= bufferFloat;
						retorno=0;
						break;
					}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}
			}
	}
	return retorno;
}
/* \brief utn_getChar : Pide al usuario caracteres
 * \param char mensaje: El mensaje que imprime para pedir un valor
 * \param char mensajeError: mensaje que imprime si el rango no es valido
 * \param int pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param char min: valor minimo admitido (inclusive)
 * \param char max: valor maximo admitido  (no inclusive)
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */

int utn_getChar(char* mensaje, char* mensajeError,char* pResultado,int reintentos,char min, char max)
{
	int retorno=-1;
	char bufferChar;

	if(pResultado != NULL && mensaje !=NULL && mensajeError !=NULL)
		{
			while(reintentos>=0)
				{
					printf("%s\n",mensaje);
					__fpurge(stdin);
					scanf("%c",&bufferChar);
					if (bufferChar>=min && bufferChar <=max && reintentos !=0)
						{
							*pResultado= bufferChar;
							retorno=0;
							break;
						}
					else
					{
						printf("%s",mensajeError);
						reintentos--;
					}
				}
		}


	return retorno;
}
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
/* \brief operandoSuma : Esta funcion se le pasan dos valores float por parametros y el resultado de su multiplicacion se alojara en el puntero pResultado para
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
/* \brief operandoSuma : Esta funcion se le pasan dos valores float por parametros y el resultado de su division se alojara en el puntero pResultado para
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

