/*
 * nac.h
 *
 *  Created on: 29 sep. 2020
 *      Author: mariana
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#define LONG_LASTNAME 51
#define LONG_NAME 51
#define LIM_EMP 20
#define MIN_SAL 4000
#define MAX_SAL 150000
#define MIN_SEC	1
#define MAX_SEC	20
#define TRUE 1
#define FALSE 0

typedef struct
{
	char name[LONG_NAME];
	char lastname[LONG_LASTNAME];
	float salary;
	int sector;
	int isEmpty;
	int id;
}Employee;

int emp_addEmployee(Employee* pArray, int limite,int id, char* name, char* lastname,float salary,int sector);
int emp_initEmployees(Employee* pArray, int limite);
int emp_printEmployees(Employee* pArray, int limite);
int emp_removeEmployee(Employee* pArray, int limite, int id);
int emp_sortEmployees(Employee* pArray, int limite, int orden);
int emp_buscarLibreRef(Employee* pArray, int limite, int* pIndice);
int emp_findEmployeeById(Employee* pArray, int limite, int idBuscar);
int emp_newEmployees(Employee* pArray, int limite);
int emp_modificaEmployee(Employee* pArray, int limite);
int emp_printUnSoloEmployee(Employee* pArray, int limite, int id);
int emp_informes(Employee* pArray, int limite);
//int emp_addEmployeeForzada(Employee* pArray, int limite,int id, char* name, char* apellido,float salary, int sector, int posicion);
#endif /* EMPLOYEE_H_ */
