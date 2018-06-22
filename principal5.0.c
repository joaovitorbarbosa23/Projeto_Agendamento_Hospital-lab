#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"
#include "Supervisores.h"
#include "agat.h"
#include "pacientes.h"

//Compilador usado dev c++ (versão 5.11)
int main()
{
int op,ag;
 do {
system("cls");
system("color 3F");
printf("             ___________________________________________________\n");
printf("            |                    BEM VINDOS!!!!                 |\n");
printf("            |___________________________________________________|\n");
printf("             ___________________________________________________\n");
printf("            |Clinica Escola da Universidade Estadual da Paraiba |\n");
printf("            |___________________________________________________|\n");
printf("             ___________________________________________________\n");
printf("            |              1.Menu Paciente                      |\n");
printf("            |              2.Menu Aluno                         |\n");
printf("            |              3.Menu Supervisor                    |\n");
printf("            |              4.Menu Agendamento                   |\n");
printf("            |              5.Menu Atendimento                   |\n");
printf("            |              6.Sair                               |\n");
printf("            |___________________________________________________|\n");
printf("                           OPCAO ESCOLHIDA:");
scanf("%d",&op);
switch(op){
	case 1:
		opcoespac();
		break;
	case 2:
		menual();
		break;
	case 3:
	  menusup();
		break;
	case 4:
	   menuag();
		break;
	case 5:
		 menuat();
		 break;
	case 6:
		break;

}

}while(op!=0&&op!=6);

return 0;	
}
