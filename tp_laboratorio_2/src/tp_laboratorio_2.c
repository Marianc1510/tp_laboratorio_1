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
	int opcion;
	int indice;
	int orden;
	//int contador=0;
	//int acumuladorSalario=0;
	//float promedioSalario;
	Employee pArrayEmployees[LIM_EMP];
	indice=emp_initEmployees(pArrayEmployees, LIM_EMP);
	if(indice==0)
	{
		do{
			if(utn_getNumero("\nMenu carga de Empleados \n1)ALTAS \n2)MODIFICAR \n3)BAJA \n4)INFORMAR\n",
							 "Dato Incorrecto\n", &opcion, 2, 1, 4)==0)
			{
				switch(opcion)
				{
				 case 1:
					 if(emp_buscarLibreRef(pArrayEmployees, LIM_EMP, &indice)==0)
					 {
						 emp_newEmployees(pArrayEmployees, LIM_EMP,indice);
					 }
					 break;
				 case 2:
					 if(emp_printEmployees(pArrayEmployees, LIM_EMP)!=-1)
					 {
						 if(emp_modificaEmployee(pArrayEmployees, LIM_EMP)==0)
						 {
							 printf("\nModificacion EXITOSA");
						 }
						 else
						 {
							 printf("\nID incorrecto");
						 }
					 }
					 else
					 {
						 printf("\nNO SE PUEDE MODIFICAR SIN DATOS CARGADOS");
					 }
					 break;
				 case 3:
					 if(emp_printEmployees(pArrayEmployees, LIM_EMP)!=-1)
					 {
						 if(emp_removeEmployee(pArrayEmployees, LIM_EMP, indice)==0)
						 {
							 printf("\nEL EMPLEADO HA SIDO ELIMINADO");
						 }
						 else{
							 printf("\nNO SE PUDO ELIMINAR");
						 }
					 }
					 else
					 {
						 printf("\nNO HAY EMPLEADOS REGISTRADOS");
					 }
					 break;
				 case 4:
					 if(indice!=1)
					 {
						 if(emp_sortEmployees(pArrayEmployees, LIM_EMP, orden)==0)
						 {
							 printf("\nSe ordeno correctamente");
							 emp_printEmployees(pArrayEmployees, LIM_EMP);
						 }
						 else
						 {
							 printf("\nNO SE PUDO ORDENAR");
						 }


					 }
					 else
					 {
						 printf("\nNO HAY EMPLEADOS CARGADOS");
					 }

				}
			}
		}while(opcion<4);
	}

	return EXIT_SUCCESS;
}
