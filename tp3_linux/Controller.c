#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utN.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorno int 0(exito) si todo salio bien, si no -1
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	FILE* pFile= fopen(path, "r");
	if(pFile !=NULL)
	{
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		retorno=0;
	}
	fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pFile= fopen(path, "rb");

	if(pFile !=NULL && path !=NULL && pArrayListEmployee !=NULL)
	{
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		retorno=0;
	}
	fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int tamBuscado;
	int ultimoId;
	Employee* ultimoEmpleado;
	Employee* nuevoEmpleado;
	char nombre[LIM_NOMBRE];
	char horasTrabajadas[5];
	char sueldo[20];
	char id[3];

	if(pArrayListEmployee !=NULL)
	{
		tamBuscado = ll_len(pArrayListEmployee);
		ultimoEmpleado = ll_get(pArrayListEmployee,tamBuscado);
		employee_getId(ultimoEmpleado, &ultimoId);


		if(utn_getTexto("INGRESE EL NOMBRE DEL EMPLEADO: ","\nDATO INVALIDO",nombre, LIM_NOMBRE, 2)==0 &&
			utn_getTextoNumero("INGRESE HORAS TRABAJADAS: ", "\nDATO INCORRECTO",horasTrabajadas,5, 2)==0 &&
			utn_getTextoNumero("INGRESE SUELDO: ", "\nDATO INCORRECTO", sueldo,20, 2)==0)
		{
			ultimoId++;
			sprintf(id,"%d",ultimoId);
			nuevoEmpleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
			ll_add(pArrayListEmployee,nuevoEmpleado);
			printf("Carga Exitosa");
			retorno=0;
		}
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int indice;
	int opcion;
	Employee* pEmployee;
	Employee buffer;
	if(pArrayListEmployee != NULL)
	{
		if(utn_getNumero("Ingrese id a modificar\n", "Error\n",&buffer.id, 2, 0, 10000)==0)
		{

			indice = controller_findById(pArrayListEmployee,buffer.id);
			if(indice !=-1)
			{
					pEmployee = ll_get(pArrayListEmployee, indice);
				if(pEmployee != NULL)
				{
					do{
						if(utn_getNumero("¿Que desea modificar? \n1-Nombre\n2-Horas Trabajadas\n3-Sueldo\n",
								"\nDato invalido", &opcion, 2, 1, 3)==0)
						{
							switch(opcion)
							{
							case 1:
								if(utn_getTexto("Ingrese su nuevo nombre:\n", "\nError", buffer.nombre, LIM_NOMBRE, 2)==0)
								{
									employee_setNombre(pEmployee, buffer.nombre);
									retorno=0;
								}
								else
								{
									retorno=-2;
								}
								break;
							case 2:
								if(utn_getNumero("Ingrese nueva hora trabajada:\n", "\nError", &buffer.horasTrabajadas, 2, 0,2000)==0)
								{
									employee_setHorasTrabajadas(pEmployee, buffer.horasTrabajadas);
									retorno=0;
								}
								else
								{
									retorno= -3;
								}
								break;
							case 3:
								if(utn_getNumero("Ingrese su nuevo sueldo:\n", "\nError", &buffer.sueldo, 2, 0, 300000)==0)
								{
									employee_setSueldo(pEmployee, buffer.sueldo);
									retorno=0;
								}
								else
								{
									retorno=-4;
								}
								break;
							}
							if(retorno < 0)
							{
								break;
							}
						}
					}while(opcion !=3);
				}
			}
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int indice;
	Employee* pEmployee;
	Employee buffer;
	int respuesta;
	if(pArrayListEmployee != NULL)
	{
		if(utn_getNumero("Ingrese id del empleado a eliminar:\n", "\nDato incorrecto", &buffer.id, 2, 0, 10000)==0)
		{
			indice= controller_findById(pArrayListEmployee, buffer.id);
			if(indice !=-1)
			{
				pEmployee= ll_get(pArrayListEmployee, indice);
				if(pEmployee != NULL && utn_getNumero("¿Desea confirmar eliminacion? SI[1] para confirmar- NO[2]\n", "\nError",&respuesta, 2, 1, 2)==0 &&
						respuesta==1)
				{
					employee_delete(pEmployee);
					retorno= ll_remove(pArrayListEmployee,indice);
				}
			}
		}
	}

	return retorno;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int tamBuscado;
	int i;
	Employee* auxEmpleado;
	if(pArrayListEmployee !=NULL)
	{

		tamBuscado = ll_len(pArrayListEmployee);
		for(i=0;i<tamBuscado;i++)
		{
		    auxEmpleado = ll_get(pArrayListEmployee,i);
			if(auxEmpleado !=NULL)
			{

				retorno= controller_unSoloPrint(auxEmpleado, i);
			}
		}
	}
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	if(pArrayListEmployee != NULL)
	{
		retorno= ll_sort(pArrayListEmployee,employee_compararNombre,1);
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	Employee* auxEmpleado;
	int auxValidacion;
	int auxiliarId;
	char auxiliarNombre[64];
	int auxiliarHoras;
	int auxiliarSueldo;
	FILE* pFile= fopen(path, "w");
	if(pFile !=NULL && pArrayListEmployee !=NULL && ll_len(pArrayListEmployee) >0 )
		{
			auxValidacion= ll_len(pArrayListEmployee);
			for(i=0; i< auxValidacion; i++)
			{
				auxEmpleado = ll_get(pArrayListEmployee, i);
				if(auxEmpleado!=NULL )
				{
					employee_getId(auxEmpleado, &auxiliarId);
					employee_getNombre(auxEmpleado, auxiliarNombre);
					employee_getHorasTrabajadas(auxEmpleado, &auxiliarHoras);
					employee_getSueldo(auxEmpleado, &auxiliarSueldo);
					fprintf(pFile,"%d,%s,%d,%d\n",auxiliarId,auxiliarNombre, auxiliarHoras,auxiliarSueldo);
				}
			}
			retorno=0;
		}
		fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 *///destruye el archivo original y genera uno nuevo, lo pisa
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	int i;
	Employee* auxEmpleado;
	int auxLim;
	FILE* pFile=fopen(path,"wb");

	if(pArrayListEmployee !=NULL && ll_len(pArrayListEmployee) >0)
	{
		auxLim= ll_len(pArrayListEmployee);
		for(i=0; i< auxLim; i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);
			employee_print(auxEmpleado);
			if(auxEmpleado!=NULL && fwrite(auxEmpleado,sizeof(Employee),1,pFile) >0)
			{
				printf("salio bien la carga!\n");
			}
		}
		retorno=0;
	}
	fclose(pFile);
    return retorno;
}

int controller_printList(LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	int auxValidacion;
	Employee* auxEmpleado;
	int i;
	if(pArrayListEmployee !=NULL)
	{
		auxValidacion= ll_len(pArrayListEmployee);
		if(auxValidacion >0)
		{
			printf("\nID \t NOMBRE \t HORAS TRABAJADAS \t SUELDO\n"
					"***************************************************\n");
			for(i=0;i<auxValidacion;i++)
			{
				auxEmpleado = ll_get(pArrayListEmployee, i);
				employee_print(auxEmpleado);
			}
		}
	}
	return retorno;
}

int controller_findById(LinkedList* pArrayListEmployee, int idBuscar)
{
	int retorno=-1;
	int len;
	Employee* auxEmployee;
	int bufferId;
	int i;
	if(pArrayListEmployee !=NULL && idBuscar >0)
	{
		len= ll_len(pArrayListEmployee);
		for(i=0; i<len;i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);
			if(auxEmployee !=NULL && employee_getId(auxEmployee, &bufferId)==0 && bufferId == idBuscar)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int controller_unSoloPrint(LinkedList* pArrayListLinkedlist, int indice)
{
	int retorno=-1;
	Employee* pEmployee;
	Employee buffer;
	if(pArrayListLinkedlist !=NULL && indice > 0)
	{
		pEmployee = (Employee*) ll_get(pArrayListLinkedlist, indice);
		if(pEmployee !=NULL && employee_getId(pEmployee, &buffer.id)==0 &&
				employee_getNombre(pEmployee, buffer.nombre)==0 &&
				employee_getHorasTrabajadas(pEmployee,&buffer.horasTrabajadas)==0 &&
				employee_getSueldo(pEmployee, &buffer.sueldo)==0)
		{
			printf("\nID \t NOMBRE \t HORAS TRABAJADAS \t SUELDO\n"
				   "***************************************************\n");
			printf("\n %d \t %s\t %d\t %d\n",buffer.id,buffer.nombre,buffer.horasTrabajadas,buffer.sueldo);
			retorno=0;
		}
	}
	return retorno;
}
