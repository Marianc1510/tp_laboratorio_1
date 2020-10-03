/*
 * nac.c
 *
 *  Created on: 29 sep. 2020
 *      Author: mariana
 */
#include "employee.h"

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "utN.h"
#define TRUE 1
#define FALSE 0
static int emp_generarIdNuevo(void);

/*
 *\brief addEmployee: Agrega a una lista de empleados los valores recibidos por parametros en la primera posicion vacia
 *\param Employee pArray, es el puntero al array de employee direccion de memoria aguardar dichos valores
 *\param int limite, es el limite del array
 *\param int id, int que identifica a cada empleado
 *\param char name, direccion de memoria que va aguardar los nombres
 *\param char lastname, direccion de memoria que va aguardar los apellidos
 *\param float salary
 *\param int sector
 *\ Retorno: 0 (EXITO) si esta todo OK. -1(ERROR) Si hubo un error
 */
int emp_addEmployee(Employee* pArray, int limite,int indice, int id, char* name, char* lastname,float salary,int sector)
{
	int retorno = -1;
	Employee buffer;
	if(pArray!= NULL && limite >= 0 &&
	   name != NULL && lastname !=NULL &&
	   salary > 0 && id >=0 && indice >=0 && indice<limite)
	{
	  if(emp_buscarLibreRef(pArray, limite, &indice)==0)
		{

		if(utn_getTexto("\nINGRESE NOMBRE DEL EMPLEADO:", "\nNOMBRE INCORRECTO", buffer.name, LONG_NAME, 2)==0 &&
			utn_getTexto("\nINGRESE APELLIDO DEL EMPLEADO:", "\nAPELLIDO INCORRECTO", buffer.lastname, LONG_LASTNAME, 2)==0 &&
			utn_getNumeroConDecimal("\nINGRESE SALARIO:", "\nDATO INCORRECTO", &buffer.salary, 2, MIN_SAL, MAX_SAL)==0 &&
			utn_getNumero("\nINGRESE SECTOR", "\nSECTOR INCORRECTO", &buffer.sector, 2, MIN_SEC, MAX_SEC)==0)
				{
					buffer.id= emp_generarIdNuevo();
					pArray[indice]= buffer;
					pArray[indice].isEmpty= FALSE;
					retorno=0;
				}
		}
	}
	return retorno;
}
static int emp_generarIdNuevo(void)
{
	static int id=0;
	id= id+1;
	return id;
}
/*
 * \brief initEnployees: inicializa el array indicando que todas las posiciones esten vacias
 * \param pArray, array de Employee a ser actualizado
 * \param int limite, la longitud del limite del array de employee
 * \return retorno 0 (EXITO) si esta todo bien, -1 (ERROR) si no
 */
int emp_initEmployees(Employee* pArray, int limite)
{
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		for(int i=0; i< limite; i ++)
		{
			pArray[i].isEmpty = TRUE;
		}
		retorno =0;
	}

	return retorno;
}
/*
 * brief printEmployees: Imprime el array de empleados de manera columnada
 * \param Employee* pArray,  direccion de memoria donde se guardan todos los datos
 * \param int limite, longitud del array
 * \return retorno 0(EXITO) se pudo imprimir, -1(ERROR) si no
 */
int emp_printEmployees(Employee* pArray, int limite)
{
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		printf("\n----------------------------------------------------------"
			   "\n ID   | NOMBRE    | APELLIDO    | SALARIO    | SECTOR     "
			   "\n----------------------------------------------------------");
		for(int i=0; i< limite; i ++)
		{
			if(pArray[i].isEmpty == FALSE)
			{
				printf("\n %d    -%s     -%s      -%2.f     -%d  \n", pArray[i].id,pArray[i].name,pArray[i].lastname,pArray[i].salary,pArray[i].sector);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief removeEmployee: Recorre el array para eliminar un empleado utilizando su id
 * \param Employee* pArray, direccion de memoria donde se guardan todos los datos
 * \param int limite, longitud del array
 * \param int id, valor cual debemos buscar en el array
 * \return retorno 0(EXITO)si se pudo eliminar, -1(ERROR) si no se pudo encontrar el empleado, puntero nulo
 */
int emp_removeEmployee(Employee* pArray, int limite, int id)
{
	int retorno = -1;
	int i;
	int modificar;
	if(pArray !=NULL && limite >=0)
	{
		if(utn_getNumero("\nINGRESE ID A ELIMINAR", "\nERROR", &modificar, 1,1,LIM_EMP)==0)
		{

			for(i=0; i < limite; i++)
			{
				id= modificar;
				if(emp_findEmployeeById(pArray, limite,id)==0)
				 {
							pArray[i].isEmpty = TRUE;
							retorno=0;
				 }
			}
		}
	}
	return retorno;
}
int emp_modificaEmployee(Employee* pArray, int limite)
{
	int retorno = -1;
	int i;
	int idBuscado;
	int modificar;
	Employee buffer;
	if(pArray !=NULL && limite >= 0)
	{

		if(utn_getNumero("\nINGRESE ID A MODIFICAR", "\nERROR", &modificar, 1,1,limite)==0)
		{
			for(i=0; i < limite; i++)
			{
				idBuscado= modificar;
				if(emp_findEmployeeById(pArray, limite,idBuscado)==0)
				 {

					if(utn_getTexto("\nINGRESE NOMBRE DEL EMPLEADO:", "\nNOMBRE INCORRECTO", buffer.name, LONG_NAME, 2)==0 &&
									   utn_getTexto("\nINGRESE APELLIDO DEL EMPLEADO:", "\nAPELLIDO INCORRECTO", buffer.lastname, LONG_LASTNAME, 2)==0 &&
									   utn_getNumeroConDecimal("\nINGRESE SALARIO:", "\nDATO INCORRECTO", &buffer.salary, 2, MIN_SAL, MAX_SAL)==0 &&
									   utn_getNumero("\nINGRESE SECTOR", "\nSECTOR INCORRECTO", &buffer.sector, 2, MIN_SEC, MAX_SEC)==0)
										{
											buffer.id= pArray[i].id;
											buffer.isEmpty=pArray[i].isEmpty;
											pArray[i]=buffer;
											retorno=0;
											break;
										}
				 }

			}
		}
	}
	return retorno;
}
/*
 * brief sortEmployees: recorre el array ordenando a los empleados por los apellidos y sector de manera ascendente
 * \param Employee* pArray,  direccion de memoria donde se guardan todos los datos
 * \param int limite, longitud del array
 * \param int orden, valor que indica de que manera a ordenar 1 (UP,ascendente), 0(DOWN, descendente)
 * \return retorno 0(exito) si se pudo ordenar, -1 (ERROR) si no
 */
int emp_sortEmployees(Employee* pArray, int limite, int orden)
{
	int retorno = -1;
	int i;
	int flagSwap;
	Employee buffer;
	if(pArray != NULL && limite >= 0 && (orden ==0 || orden ==1))
	{
		do
		{
			flagSwap=0;
			for(i=0;i<limite-1;i++)
			{
				if(pArray[i].isEmpty == FALSE && pArray[i+1].isEmpty == FALSE)
				{
					if((orden == 1 && strncmp(pArray[i].lastname,pArray[i+1].lastname,LONG_LASTNAME) > 0) ||
					   (orden == 0 && strncmp(pArray[i].lastname,pArray[i+1].lastname,LONG_LASTNAME) < 0)==0 ||
					   ((orden ==1 && pArray[i].sector == pArray[i+1].sector) > 0) ||
					   ((orden ==0 && pArray[i].sector == pArray[i+1].sector) < 1 ))
					{
						buffer=pArray[i];
						pArray[i]=pArray[i+1];
						pArray[i+1]=buffer;
						flagSwap =1;
					}
				}
			}
		}while(flagSwap);
	}
	return retorno;
}

/*
 * brief buscarLibreRef: recorre el array buscando una posicion vacia
 * \param Employee* pArray, direccion de memoria donde se guardan todos los datos
 * \param int limite, longitud del array
 * \param int* pIndice, direccion de memoria donde se va a guardar el espacio vacio
 * \return retorno 0(EXITO)si encuentra espacio vacio, -1(ERROR)si no
 */

int emp_buscarLibreRef(Employee* pArray, int limite,int* pIndice)
{	int retorno =-1;
	int i;

	if(pArray != NULL && limite > 0 && pIndice!=NULL)
	{
		for(i=0; i<limite; i++)
		{
			if(pArray[i].isEmpty == TRUE)
			{
				*pIndice=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
/*
 * \brief findEmployeeById: recorre el array buscando por su ID
 * \param Employee* pArray, direccion de memoria donde se guardan todos los datos
 * \param int limite, es la longitud del array
 * \param int idBuscar, valor cual debemos buscar en el array
 * \return retorno la posicion en cual se encuentra el array, devolviendo el valor buscado.
 */
int emp_findEmployeeById(Employee* pArray, int limite, int idBuscar)
{
	int retorno =-1;
	int i;

	if(pArray != NULL && limite > 0  && idBuscar >=0)
	{
		for(i=0; i<limite; i++)
		{
			if(pArray[i].id == idBuscar)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int emp_newEmployees(Employee* pArray, int limite,int indice)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite >=0)
	{
		for(i=0; i <limite; i++)
		{
			if(emp_addEmployee(pArray,limite, indice,pArray[i].id,pArray[i].name,pArray[i].lastname,pArray[i].salary,pArray[i].sector)==0)
				{

					printf("\nCarga exitosa");
					retorno=0;
					break;
				}
			else
			{
				printf("\nNO SE PUDO CARGAR");
			}
		}
	}
	return retorno;
}
