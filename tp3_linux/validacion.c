/*
 * validacion.c
 *
 *  Created on: 31 oct. 2020
 *      Author: mariana
 */

#include "validacion.h"

/*
 *\brief myGets: lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un
 *\				maximo de 'longitud -1'cadacteres
 *\param char cadena,cadena de caracteres a ser analizada
 *\param int longitud, define el tamaño de la cadena
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int myGets(char* cadena, int longitud)
{
	int retorno = -1;
    if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin) == cadena)
    {
		__fpurge(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno =0;
    }
    return retorno;
}
/*
 *\brief getInt: verifica si la cadena ingresa es numerica de enteros
 *\param int pResultado, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[4096];
    if(pResultado != NULL)
    {
    	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
    	{
			retorno  = 0;
			*pResultado = atoi(buffer);
    	}
    }
    return retorno;
}
/*
 *\brief getFloat: verifica si la cadena ingresa es numerica con decimales
 *\param float pResultado, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */

int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[4096];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && esNumeroDecimal(buffer))
		{
			retorno = 0;
			*pResultado = atof(buffer);
		}
	}
	return retorno;
}
/*
 *\brief esNumerica: verifica si la cadena ingresa es numerica
 *\param char cadena,cadena de caracteres a ser analizada
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */


int esNumerica(char* cadena)
{
  int i=0;
  int retorno =-1;

  if(cadena != NULL && strnlen(cadena,sizeof(cadena)) > 0)
  {
	while(cadena[i] != '\0')
	{
		if(cadena[0] == '-' || cadena[0] == '+')
		{
			continue;
		}
		if(cadena[i] < '0' || cadena[i] > '9')
		{
			retorno =0;
			break;
		}
		i++;
	}
   }
   return retorno;
}


int esNumericaRetornoInt(char* cadena, int* numeroValidado)
{
  int i=0;
  int retorno =-1;

  if(cadena != NULL && strnlen(cadena,sizeof(cadena)) > 0)
  {
	retorno=1;
	while(cadena[i] != '\0')
	{

		if(cadena[0] == '-' || cadena[0] == '+')
		{
			continue;
		}
		if(cadena[i] < '0' || cadena[i] > '9')
		{
			retorno =0;
			break;
		}
		i++;
	}
	if(retorno==1)
		*numeroValidado=atoi(cadena);
   }
   return retorno;
}

int esHoraNegativa(int esHoraValida)
{
	int retorno = -1;
	if(esHoraValida >=0)
	{
		retorno=0;
	}
	return retorno;
}
int esSueldo(int sueldo)
{
	int retorno =-1;
	if(sueldo >=0)
	{
		retorno=0;
	}
	return retorno;
}
/*
 *\brief esNumeroDecimales: verifica si la cadena ingresa es numerica con decimales
 *\param char* cadena, cadena de caracteres a ser analizada
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int esNumeroDecimal(char* cadena)
{
	int i =0;
	int retorno = -1;

	if(cadena != NULL && strnlen(cadena,sizeof(cadena)) > 0)
	{
		while(cadena[i] !='\0')
		{
			if(cadena[0] == '-' || cadena[0] == '+' || cadena[i] == '.')
					{
						continue;
					}
					if(cadena[i] < '0' || cadena[i] > '9')
					{
						retorno =0;
						break;
					}
					i++;
		}
	}
	return retorno;
}
/*
 *\brief getString: verifica si la cadena ingresa son solo letras
 *\param char* cadena,puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\param int limite, define el tamaño de la cadena
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int getString(char* cadena, int limite)
{
	char buffer[4096];
	int retorno =-1;
	if(cadena !=NULL && limite > 0)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNombre(buffer,sizeof(buffer)))
		{
			retorno  = 0;
			strncpy(cadena,buffer,limite);
		}
	}
	return retorno;
}
/*
 *\brief getCaracter: verifica si la cadena ingresada son solo caracteres
 *\param char* cadena, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int getCaracter(char* cadena)
{
	char buffer[4096];
	int retorno =-1;
	if(cadena !=NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esSoloCaracter(buffer))
		{
			retorno  = 0;
			strcpy(cadena,buffer);
		}
	}
	return retorno;
}
/*
 *\brief esSoloLetras: verifica si la cadena ingresa son solo letras
 *\param char* cadena,cadena de caracteres a ser analizada
 *\param int limite, define el tamaño de la cadena
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int esNombre(char* cadena, int limite)
{
	int respuesta = 1; //TODO OK
	for(int i;i<=limite && cadena[i]!='\0' ;i++)
	{
		if( (cadena[i]<'A'|| cadena[i]>'Z') &&
			(cadena[i]<'a'|| cadena[i]>'z') &&
			 cadena[i] != '.')
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}
/*
 *\brief esSoloCaracter: verifica si el caracter ingresado es una letra
 *\param char* pResultado,Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int esSoloCaracter(char* pResultado)
{
	int i;
	int retorno =-1;
	if(pResultado != NULL && strnlen(pResultado,sizeof(pResultado)) > 0)
	  {
		while(pResultado[i] != '\0')
		{
			if((pResultado[i] < 'a' || pResultado[i] > 'z') &&
				(pResultado[i]<'A' || pResultado[i]>'Z'))
			{
				retorno =0;
				break;
			}
			i++;
		}
	   }
	return retorno;
}
