/*
 * validacion.h
 *
 *  Created on: 31 oct. 2020
 *      Author: mariana
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#ifndef VALIDACION_H_
#define VALIDACION_H_

int esNumerica(char* cadena);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
int esNumeroDecimal(char* cadena);
int getFloat(float* pResultado);
int esNombre(char* cadena, int limite);
int getString(char* cadena, int limite);
int esSoloCaracter(char* pResultado);
int esHoraNegativa(int esHoraValida);
int esSueldo(int sueldo);
int esNumericaRetornoInt(char* cadena, int* numeroValidado);
#endif /* VALIDACION_H_ */
