#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utN.h"
#include "parser.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    //LinkedList* listaAuxiliar = ll_newLinkedList();
    do{
    	if(utn_getNumero("\n-----MENU PUBLICACIONES----\n"
						" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
						" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
						" 3. Alta de empleado\n"
						" 4. Modificar datos de empleado\n"
						" 5. Baja de empleado\n"
						" 6. Listar empleados\n"
						" 7. Ordenar empleados\n"
						" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
						" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
						" 10. Salir\n","OPCION INVALIDA\n", &option, 10, 1,10)==0)
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==0)
                {
                	controller_printList(listaEmpleados);
                }
                break;
            case 2:
            	if(controller_loadFromBinary("dataB.csv", listaEmpleados)==0)
            	{
            		controller_printList(listaEmpleados);
            	}
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	if(controller_editEmployee(listaEmpleados)==0)
            	{
            		printf("su modificacion fue exitosa");
            		controller_printList(listaEmpleados);
            	}
            	break;
            case 5:
            	if(controller_removeEmployee(listaEmpleados)==0)
            	{
            		printf("Eliminacion Exitosa");
            		controller_printList(listaEmpleados);
            	}
            	break;
            case 6:
            	if(ll_len(listaEmpleados)==0)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Debe realizar la carga de empleados\n");
            	}
            	break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
            	if(controller_saveAsText("dataT.csv", listaEmpleados)==0)
            	{
            		printf("Se pudo generar correctamente el archivo de texto\n");
            	}
            	break;
            case 9:
            	if(controller_saveAsBinary("dataB.csv", listaEmpleados)==0)
            	{
            		printf("se pudo generar correctamente el archivo\n");
            	}
            	break;
        }
    }while(option != 10);
    return 0;
}

