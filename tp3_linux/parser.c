#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	char auxId[5];
	char auxNombre[20];
	char auxHorasTrabajadas[30];
	char auxSueldo[200];
	Employee* auxEmpleado;

	if(pFile !=NULL)
	{
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo)!=0)
			{
				auxEmpleado = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
				ll_add(pArrayListEmployee, auxEmpleado);
			}
		}while(feof(pFile)==0);
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* auxCargado;
	do
	{
		auxCargado= employee_new();
		if(auxCargado !=NULL)
		{
			fread(auxCargado,sizeof(Employee),1,pFile);
			employee_print(auxCargado);
			ll_add(pArrayListEmployee, auxCargado);
			retorno=0;
		}
		else
		{
			employee_delete(auxCargado);
		}
	}while(feof(pFile)==0);

    return retorno;
}
