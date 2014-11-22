#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<limits.h>

//-----DECLARACIon DE FUNCIONES EXTERNAS

//El menu de ayuda se ejecutara si ejecutamos el programa en un terminal y no pasamos ningun parametro
void help() 
{
	printf("+----------------------------------------------------------------+\n");
	printf("|                           MENU DE AYUDA                        |\n");
	printf("+----------------------------------------------------------------+\n");
	printf("| -t => Muestra una tabla de multiplicar a tu eleccion           |\n");
	printf("| -T => Muestra todas las tablas hasta la que eligas             |\n");
	printf("| -m => Obtiene la media de una asignatura                       |\n");
	printf("| -M => Obtiene la media de todas las asignaturas                |\n");
	printf("| -e => Abre un editor de texto en la terminal (para salir[fin]) |\n");
	printf("| -a => Abrir el archivo creado con el editor en la terminal     |\n");
	printf("+----------------------------------------------------------------+\n");
	printf("\n");
}

/*El ErrorString funcionara en aquellas entradas que esperen un numero ya sea entero o flotante para prevenir 
que los string sean convertidos en numeros y se convierta en un bucle*/
void ErrorString()
{
	printf("\n");
	printf("[+]\n");
	printf("+----------------------------------------------------------+\n");
	printf("| Ha insertado una cadena de texto no un numero o el 0     |\n");
	printf("| PORFAVOR INSERTE UN NUMERO COMPUTABLE                    |\n ");
	printf("+---------------------------------------------------------+\n");
	printf("\n");
	system("pause");
	submenu();
}
// Cuando la opcion insertada sea inexistente o imposible
void OpcionErronea()
{
	printf("\n");
	printf("OPCION ERRONEA\n \a");
	printf("\n");
	Sleep(3000);
}
//Menu que preguntara si se desea continuar
void submenu()
{
	char sn[3];
	printf("\n");
	printf("[+]Quieres continuar?:(S/N)\n");
	fflush(stdin);
	scanf("%s", &sn);
	printf("\n");
	if(strcmp("SI", sn) == 0 || strcmp("Si", sn) == 0 || strcmp("si", sn) == 0 || strcmp("s", sn) == 0 || strcmp("S", sn) == 0)
	{
	}
	else if (strcmp("NO", sn) == 0 || strcmp("No", sn) == 0 || strcmp("no", sn) == 0 || strcmp("n", sn) == 0 || strcmp("N", sn) == 0)
	{
		exit(1);
	}
	else
	{
		OpcionErronea();
		submenu();
	}
}
//Funcion que mostrara una tabla a elegir por el usuario
void tabla()
{
	int i, tabla, j;
	printf("Que tabla deseas ver: \n");
	fflush(stdin);
	scanf("%d", &tabla);
	printf("\n");
	if(tabla <= 0 )
	{
		printf("Numero muy bajo o muy alto\n \a");
	}
	else
	{
		printf("=================================\n");
		for(i = 1;i <=10 ;i++)
		{
			j = tabla * i;
			printf("%d * %d = %d\n", tabla, i,j);
		}
		printf("=================================\n");
	}
}
// Funcuion que mostrara todas las tablas hasta la que se le haya indicado (empezando desde la del 1)
void tablas()
{
	int i,j, tablas,contador;
	tablas = 0;
	contador = 0;
	printf("Hasta que tabla dese ver: \n");
	fflush(stdin);
	scanf("%d", &tablas);
	if(tablas == 0)
	{
		ErrorString();
	}
	else
	{
		for(i = 1;i <= tablas;i++)
		{
		printf("\n");
		printf("La tabla del %d\n", i);
		printf("=================================\n");
			for(j = 1; j <= 10 ;j++)
			{
				contador = i *j;
				printf("%d * %d = %d\n",i,j,contador); // Muestra la tabla con un formato 4 * 4 = 16
			}
		printf("=================================\n");
		}
	}
}
//Funcion que calcula la media de los examenes ingresados por el usuario
void media1()
{
	int i, examenes;
	examenes = 0;
	float media;
	media = 0;
	printf("Cuantos examenes tienes: \n");
	fflush(stdin);
	scanf("%d", &examenes);
	if(examenes == 0)
	{
		ErrorString();
	}
	else
	{
		printf("Tienes %d examenes\n", examenes);
		float nota[examenes];
		nota[examenes] = examenes;
		
		for(i = 0; i < examenes; i++)
		{
			printf("Cual es la nota: \n");
			scanf("%f", &nota[i]);
			fflush(stdin);
			media += nota[i];
		}
		media /= examenes; 
		if (media > 10 || media < 0)
		{
			printf("La media es imposible de calcular\n");
		}
		else if (media <= 10)
		{
			printf("\n");
			printf("La media es: %f \n", media);
			printf("\n");
		}
		else
		{
			printf("La media es imposible de calcular\n");
		}
	}
}
// Funcion que calcula la media de todas las asignaturas insertadas
void media2()
{
	int i,j,k, asig;
	float media, contador, contador1;
	contador = 0;
	media = 0;
	printf("Cuantas asignaturas tienes(max: 20): \n");
	fflush(stdin);
	scanf("%d", &asig);
	fflush(stdin);
	if (asig < 0 || asig > 20)
	{
		ErrorString();
	}
	else 
	{
		float asi[asig];
		asi[asig] = asig;
		for(i = 0;i < asig;i++)
		{
			printf("Cuantos examenes tiene la asignatura #%d: \n", i+1);
			scanf("%f", &asi[i]);
			for(j = 0; j < asi[i];j++)
			{
				printf("Cual es la nota del examen #%d de la asignatura #%d: \n", j+1, i+1 );
				//fflush(stdin);
				scanf("%f", &contador);
				media += contador;
			}
			media /= asi[i];
			printf("\n\n");
			printf("La media es: %f\n", media);
			printf("\n\n");
			system("pause");
			media = 0; // resetear media IMPORTANTE
		}	
	}	
}
//Editor de texto de 1000000 - 1 palabra porque el \0 ocupa un lugar
void file()
{
	char texto[1000000];
	
	FILE *archivo;
	int contador; // para que no realice espacios en la primera linea
	contador = 0;
	archivo = fopen("editordetexto.txt", "at");
	if (archivo == NULL)
	{
		printf("\n No se ha podido abrir el archivo \n");
		exit(1);		
	}
	printf("Para salir escribe fin\n");
	printf("======================\n");
	do
	{
		gets(texto); //Guarda lo que quieras en la variable texto
		fputs(texto, archivo); //Inserta lo que hay en la variable texto y lo escribe en archivo
		if (contador >= 1)
		{
			if (strcmp(texto, "fin") != 0)//Para insertar un espacio cuando escribamos un intro
			{
				fputs("\n", archivo);
			}	
		}
		contador++;
	}while(strcmp(texto, "fin") != 0);
	fclose(archivo);
}
// Esta funcion abrira el archi previamente creado en caso de existir
void leer()
{
	char tex[1000000];
	FILE *textR;
	textR = fopen("editordetexto.txt","rt");
	while(!feof(textR))
	{
			fgets(tex, 1000000, textR);
			fflush(stdin);
			printf("%s", tex);	
	}
	printf("\n\n");
	printf("FINAL DEL ARCHIVO\n");
	fclose(textR);
}
int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		int opc,i,j,k;
		do
		{
			system("cls");
			printf("+--------------------------------------------------+\n");
			printf("|                  MENU DE OPCIONES                |\n");
			printf("+--------------------------------------------------+\n");
			printf("| 1 - Mostrar una tabla de multiplicar             |\n");
			printf("| 2 - Mostrar una tabla de multiplicar             |\n");
			printf("| 3 - Sacar media de una sola nota                 |\n");
			printf("| 4 - Sacar la media de varias asignaturas         |\n");
			printf("| 5 - Editor de texto en la terminal               |\n");
			printf("| 6 - Abrir texto del editor en la terminal        |\n");
			printf("| 7 - Salir                                        |\n");
			printf("+--------------------------------------------------+\n");
			printf("Selecione una opcion:(1/2/3/4/5/6/7)\n");
			fflush(stdin);
			scanf("%d", &opc);
			switch(opc)
			{
				case 1:
					tabla();
					submenu();
				break;
				case 2:
					tablas();
					submenu();
				break;
				case 3:
					media1();
					submenu();
				break;
				case 4:
					media2();
					submenu();
				break;
				case 5:
					file();
					submenu();
				break;
				case 6:
					leer();
					submenu();
				break;
				case 7:
					printf("\n");
					printf("ADIOS");
					printf("\n");
				break;
				default: 
					OpcionErronea();
				break;
			}
		}while(opc != 6);
	}
	else if (strcmp("-t", argv[1]) == 0)
	{
		tabla();
	}
	else if(strcmp("-T", argv[1]) == 0)
	{
		tablas();
	}
	else if (strcmp("-m", argv[1]) == 0)
	{
		media1();
	}
	else if (strcmp("-M", argv[1]) == 0)
	{
		media2();
	}
	else if (strcmp("-e", argv[1]) == 0)
	{
		file();
	}
	else if (strcmp("-a", argv[1]) == 0)
	{
		
	}
	else
	{
		help();
	}

}
