#include <stdio_ext.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "validacion.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define LIM_NOMBRE 128
typedef struct
{
    int id;
    char nombre[LIM_NOMBRE];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();
void employee_print(Employee* this);

int employee_setId(Employee* this,int id);//escribe
int employee_getId(Employee* this,int* id);//trae

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_compararNombre(void* thisA,void* thisB);


#endif // employee_H_INCLUDED
