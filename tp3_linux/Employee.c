#include "Employee.h"
#include "LinkedList.h"

Employee* employee_new()
{
	Employee* this;

		this=(Employee*)malloc(sizeof(Employee));

	return this;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* this=NULL;
	int auxiliarHorasTrabajadas;
	int auxiliarId;
	int auxiliarSueldo;
	if(idStr !=NULL && nombreStr !=NULL && horasTrabajadasStr !=NULL)
	{
		this=(Employee*)malloc(sizeof(Employee));
		if(this!=NULL)
		{
		  if(esNumericaRetornoInt(horasTrabajadasStr,&auxiliarHorasTrabajadas)==1 &&
		  	  esNumericaRetornoInt(idStr, &auxiliarId)==1 &&
			  esNumericaRetornoInt(sueldoStr, &auxiliarSueldo)==1 )
		  {
			  employee_setHorasTrabajadas(this, auxiliarHorasTrabajadas);
			  employee_setNombre(this,nombreStr);
			  employee_setId(this, auxiliarId);
			  employee_setSueldo(this, auxiliarSueldo);
		  }
		}
	}
	return this;
}
/*
 * brief employee_delete:
 */
void employee_delete(Employee* this)
{
	if(this !=NULL)
	free(this);
}
void employee_print(Employee* this)
{

	printf("\n %d \t %s\t %d\t %d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
}
/*
 * brief setId: Establece un nuevo id y conserva el mismo
 * \param Employee* this,
 * \param int id,
 * \return retorno
 */

int employee_setId(Employee* this,int id)
{
	int retorno=-1;
	static int maximoId = -1;
	if(this !=NULL)
	{
		retorno=0;
		if(id<0)
		{
			maximoId++;
			this->id = maximoId;
		}
		else
		{
			if(id > maximoId)
			{
				maximoId = id;
				this->id = id;
			}
		}
	}
	return retorno;
}
/*
 * brief getId: Obtiene el id asignado
 * \param Employee* this,
 * \param int id,
 * \return retorno
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this !=NULL && id !=NULL)
	{
			*id=this->id;
			retorno=0;
	}
	return retorno;
}
/*
 * brief setNombre:
 * \param
 * \param
 * \return
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this !=NULL && nombre !=NULL && esNombre(nombre,(int)sizeof(nombre))==1)
		{
			strncpy(this->nombre,nombre,sizeof(this->nombre));
			retorno=0;
		}
	return retorno;
}

/*
 * brief getNombre:
 * \param
 * \param
 * \return retorno
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno= -1;
	if(this !=NULL && nombre !=NULL)
	{
		strncpy(nombre,this->nombre,(int)sizeof(nombre));
		retorno = 0;
	}
	return retorno;
}
/*
 * brief setHorasTrabajadas:
 * \param
 * \param
 * \return
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this !=NULL && horasTrabajadas >=0 && esHoraNegativa(horasTrabajadas)==0)
	{
		 this->horasTrabajadas =horasTrabajadas;
		 retorno =0;
	}
	return retorno;
}

/*
 * brief getHorasTrabajadas:
 * \param
 * \param
 * \return
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this !=NULL && horasTrabajadas !=NULL)
	{
		*horasTrabajadas= this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
/*
 * brief setSueldo:
 * \param
 * \param
 * \return
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno =-1;
	if(this !=NULL && sueldo >=0 && esSueldo(sueldo)==0)
	{
		this->sueldo = sueldo;
		retorno=0;
	}
	return retorno;
}
/*
 * brief getSueldo:
 * \param
 * \param
 * \return
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this !=NULL && sueldo !=NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_compararNombre(void* thisA,void* thisB)
{
	int retorno ;
	//Employee* pEmpleadoA= (Employee*)thisA;
	//Employee* pEmpleadoB= (Employee*)thisB;

	char bufferNombre[256];
	char bufferNombreB[256];

	if(employee_getNombre((Employee*)thisA,bufferNombre)==0 && employee_getNombre((Employee*)thisB, bufferNombreB)==0)
	{
		if(strcmp(bufferNombre,bufferNombreB) > 0)
		{
			retorno = 1;
		}
		else if(strcmp(bufferNombre,bufferNombreB) < 0)
		{
			retorno=-1;
		}
		else
		{
			retorno=0;
		}
	}
	return retorno;
}
