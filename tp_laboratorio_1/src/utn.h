/*
 * utn.h
 *
 *  Created on: 3 sep. 2020
 *      Author: mariana
 */

#ifndef UTN_H_
#define UTN_H_

int operandoSuma(float operador1, float operador2, float* pResultado);
int operandoResta(float operador1, float operador2, float* pResultado);
int operandoMultiplicar(float operador1, float operador2, float* pResultado);
int operandoDividir(float operador1, float operador2, float* pResultado);
int operandoFactoreo(float operando, float* pResultado);

int utn_getNumero(char* msg,char* msgError,int* pResultado,int reintentos,int min,int max);
int utn_getNumeroFloat(char* mensaje, char* mensajeError,float* pResultado,int reintentos,int min, int max);
int utn_getChar(char* mensaje, char* mensajeError,char* pResultado,int reintentos,char min, char max);
#endif /* UTN_H_ */
