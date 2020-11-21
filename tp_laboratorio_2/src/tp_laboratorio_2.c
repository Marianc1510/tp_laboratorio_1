/*
 ============================================================================
 Name        : tp_laboratorio_2.c
 Author      : Mariana
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utN.h"
#include "employee.h"

int main(void) {
	Employee arrayEmpl[LIM_EMP];
	int opcion;
	int flagAlta=0;
	int i=0;
	int bufferId;

	if(emp_initEmployees(arrayEmpl, LIM_EMP)==0)
	{
		do{
			if(utn_getNumero("\n*****MENU DE EMPLEADOS*****"
					        "\n1-ALTA"
							"\n2-MODIFICACION"
							"\n3-BAJA"
							"\n4-INFORMES",
							"\nOPCION INVALIDA",&opcion, 2, 1, 4)==0)
			{
				switch(opcion)
				{
				case 1:
					if(emp_newEmployees(arrayEmpl, LIM_EMP)!=0)
					{
						printf("\nNo se pudo realizar la carga\n");
					}
					else
					{
						flagAlta=1;
						i++;
					}
					break;
				case 2:
					if(flagAlta !=1 )
					{
						printf("\n----------------------------------------\n"
								"NO HAY EMPLEADOS CARGADOS PARA MODIFICAR\n"
								"-----------------------------------------\n");
					}
					else if(emp_modificaEmployee(arrayEmpl,LIM_EMP)!=-1)
						{
							printf("\n--------------------\n"
									"MODIFICACION EXITOSA\n"
									"---------------------\n");
							emp_printEmployees(arrayEmpl, LIM_EMP);
						}
					break;
				case 3:
					if(flagAlta !=1)
					{
						printf("\n-------------------------------------------\n"
								"NO HAY EMPLEADOS CARGADOS PARA DAR UNA BAJA\n"
								"--------------------------------------------\n");
					}
					else if(emp_removeEmployee(arrayEmpl,LIM_EMP,bufferId)==0)
					{
						printf("\n--------------------\n"
								"    BAJA  EXITOSA    \n"
								"---------------------\n");
						emp_printEmployees(arrayEmpl, LIM_EMP);
					}
					break;
				case 4:
					if(flagAlta !=1)
					{
						printf("\n----------------------------------------\n"
								"      NO CARGA REALIZADA DE EMPLEADOS      \n"
								"-----------------------------------------\n");

					}
					else {
						 emp_informes(arrayEmpl, LIM_EMP);
					}
					break;
				}
			}
			}while(opcion <= 4);
	}



	return EXIT_SUCCESS;
}
