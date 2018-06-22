#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define qtde 200

typedef struct{
    char nome[qtde];
    int cod1[qtde],cod_2[qtde];
    char area[qtde],data2[12];
    char data[qtde];
    int incluso;

}Agendamento;

Agendamento ag[qtde];

void opcoesag();
void agendar();
void cancelarAgendamento();
void listarAgendamento();
void salvar4();
void salvar3();
void apagar4();
void apagar3();


int cont=0;
typedef struct{
    char nomeal[qtde],nomepac[qtde],nomesup[qtde];
    int cod[qtde],cod2[qtde],codpac[qtde],codal[qtde],codsup[qtde],codag[qtde],codat[qtde];
    char area[qtde],data2[12],data3[12];
    char datag[qtde],datat[qtde];
    int incluso;

} Atendimento;

Atendimento at[qtde];

void opcoesat();
void atendimento();
void cancelaratendimento();
void listaratendimento();
void listaraera();
void listaralunos();
void listarpaciente();

void menuag(){
	opcoesag();
}
void menuat(){
	opcoesat();
}
//Menu Agendamento
void opcoesag(){
    int choice,i;

    do {
system("cls");
system("color E0");
printf("           ___________________________________________________\n");
printf("          |                   MENU AGENDAMENTO:               |\n");
printf("          |___________________________________________________|\n");
printf("           ___________________________________________________\n");
printf("          |              1.CRIAR AGENDAMENTO                  |\n");
printf("          |              2.CANCELAR AGENDAMENTO               |\n");
printf("          |              3.LISTAR AGENDAMENTO                 |\n");
printf("          |              0.MENU PRINCIPAL                     |\n");
printf("          |___________________________________________________|\n");
printf("                         OPCAO ESCOLHIDA:");
scanf("%d",&choice);
        switch(choice){
            case 1:
                agendar();
                salvar3();
                break;
            case 2:
            	cancelarAgendamento();
            	apagar3();
            	break;
    		case 3:
    			listarAgendamento();
    
					break;

}
	}while(choice!=0);
}

//Função para Agendar o paciente
void agendar(){
    system("cls");

    char nome[qtde];
    int cod[qtde],cod2[qtde];
    char area[qtde],data2[12];
    char data[qtde];
    int incluso,i,op;
    int cont=0;

    do {
        system("cls");
        printf("__________________________________________________\n");
		printf("Digite o Nome do Paciente: ");
        fflush(stdin);
        gets(nome);

        printf("__________________________________________________\n");
		printf("Digite o Codigo do Paciente: ");
        fflush(stdin);
        scanf("%d",&cod2[0]);

        printf("__________________________________________________\n");
		printf("Digite a area do atendimento(Odontologia,Fisioterapia,Psicologia): ");
        fflush(stdin);
        gets(area);

        printf("__________________________________________________\n");
		printf("Digite a Data da consulta: ");
        fflush(stdin);
        gets(data2);

        for(i=0;i<qtde;++i){
            if(strcmp(ag[i].area,area)==0&&strcmp(ag[i].nome,nome)==0){
        		printf("PACIETE JA AGENDADO!!");
        		break;
        	}
            else if(ag[i].incluso==0){
                ag[i].cod1[0]=cont+100;
				ag[i].cod_2[0]=cod2[0];
                strcpy(ag[i].nome,nome);
                strcpy(ag[i].area,area);
                strcpy(ag[i].data,data2);
                ag[i].incluso=1;
                break;
                system("pause");
            }
		
		}
         cont ++;
        printf("\n\n1.Fazer um Agendamento\n0.Sair\n");
        fflush(stdin);
        scanf("%d",&op);
   
    } while(op!=0);
}

// Função para listar o Agendamento 
void listarAgendamento(){
    system("cls");
	char nome[qtde];
    int cod1[qtde],cod_2[qtde];
    char area[qtde],data2[12];
    char data[qtde];
    int incluso,i;
	printf("LISTA DE TODOS OS AGENDAMENTOS JA FEITOS:\n\n");
    for(i=0;i<qtde;++i){
        if(ag[i].incluso==1){
            printf("CODIGO DO AGENDAMENTO ------------- : %d\n",ag[i].cod1[0]);
            printf("NOME DO PACIENTE / CODIGO --------------- : %s / %d\n",ag[i].nome,ag[i].cod_2[0]);
            printf("AREA DO ATENDIMENTO ---------------- : %s\n",ag[i].area);
            printf("DATA DA CONSULTA ----------- : %s\n\n",ag[i].data);
        }
    }
    
    printf("#### Tecle <ENTER> para continuar!");
	getch();
}

//Função cancelar Agendamento
void cancelarAgendamento(){
	system("cls");

    char nome[qtde];
    int cod1[qtde],cod_2[qtde],cod3;
    char area[qtde],data2[12];
    char data[qtde];
    int incluso,i;

	
	int Agendamentoencontrado = 0;
	
    printf("Informe o codigo do Agendamento que deseja cancelar:\n");
    fflush(stdin);
	scanf("%d",&cod3);

	for(i=0;i<qtde;++i){
	   	if(ag[i].cod1[0]==cod3){
            ag[i].cod_2[0]=0;
			ag[i].cod1[0]=0;
            memset (ag[i].nome, 0, sizeof (nome) );
            memset (ag[i].area, 0, sizeof (area) );
            memset (ag[i].data, 0, sizeof (data) );
            ag[i].incluso=0; 
            
            Agendamentoencontrado = 1;
            
            break;
        }
    }
    
        if ( Agendamentoencontrado )
    	printf("\nAgendamento Cancelado com sucesso!\n\n");
    else
    	printf("\nCodigo nao encontrado!\n\n");
    
    printf("#### Tecle <ENTER> para continuar!");
    getch();
}



void salvar3(){
int i;
 FILE *fileagenda;
	system("cls");
	fileagenda=fopen("agendamento.txt","w");
	for(i=0;i<qtde;++i){
        if(ag[i].incluso==1){
            fprintf(fileagenda,"CODIGO DO AGENDAMENTO ------------- : %d\n",ag[i].cod1[0]);
            fprintf(fileagenda,"NOME DO PACIENTE / CODIGO --------------- : %s / %d\n",ag[i].nome,ag[i].cod_2[0]);
            fprintf(fileagenda,"AREA DO ATENDIMENTO ---------------- : %s\n",ag[i].area);
            fprintf(fileagenda,"DATA DA CONSULTA ----------- : %s\n\n",ag[i].data);
        }
    }
    
	fclose(fileagenda);
}
void apagar3(){
	int i;
	FILE *fileagenda;
	fileagenda=fopen("agendamento.txt","w");
	for(i=0;i<qtde;++i){
        if(ag[i].incluso==1){
            fprintf(fileagenda,"CODIGO DO AGENDAMENTO ------------- : %d\n",ag[i].cod1[0]);
            fprintf(fileagenda,"NOME DO PACIENTE / CODIGO --------------- : %s / %d\n",ag[i].nome,ag[i].cod_2[0]);
            fprintf(fileagenda,"AREA DO ATENDIMENTO ---------------- : %s\n",ag[i].area);
            fprintf(fileagenda,"DATA DA CONSULTA ----------- : %s\n\n",ag[i].data);
        }
    }
    
	fclose(fileagenda);
}

//Menu Atendimento
void opcoesat(){
    int choice,op;

    do {
system("color E0");
system("cls");    
printf("            ___________________________________________________\n");
printf("           |                  MENU ATENDIMENTO:                |\n");
printf("           |___________________________________________________|\n");
printf("            ___________________________________________________\n");
printf("           |              1.CRIAR ATENDIMENTO                  |\n");
printf("           |              2.CANCELAR ATENDIMENTO               |\n");
printf("           |              3.LISTAR ATENDIMENTO                 |\n");
printf("           |              0.MENU PRINCIPAL                     |\n");
printf("           |___________________________________________________|\n");
printf("                        OPCAO ESCOLHIDA:");
scanf("%d",&choice);
        switch(choice){
            case 1:
			   atendimento();
			   salvar4();
                break;
            case 2:
            	cancelaratendimento();
            	apagar4();
            	break;
    		case 3:
printf(" ___________________________________________________\n");
printf("|              1.Listar todos Atendimentos          |\n");
printf("|              2.Listar Atendimento por area        |\n");
printf("|              3.Listar Atendimento por aluno       |\n");
printf("|              4.Listar Atendimento por paciente    |\n");
printf("|              0.MENU PRINCIPAL                     |\n");
printf("|___________________________________________________|\n");
printf("             OPCAO ESCOLHIDA:");
            scanf("%d",&op);
			switch(op){
				if(op>4){
				case 1:
					listaratendimento();
					break;
				case 2:
					listaraera();
					break;
				case 3:
    			listaralunos();
    			break;
    			case 4:
    				listarpaciente();
    				break;
    			case 0:
    				break;
    			}
    		}
    		break;
        }

    }while(choice!=0);
}

// Função para preencher o Atendimento
void atendimento(){
    system("cls");
    struct Agendamento;
	char nomeal[qtde],nomepac[qtde],nomesup[qtde];
    int cod[qtde],cod2[qtde],codpac[qtde],codal[qtde],codsup[qtde],codag[qtde],codat[qtde];
    char area[qtde],datag[12],datat[12];
    char data3[qtde],data2[qtde];
    int inclusoat,op,i;
    int cont=0;
    char nome[qtde];
    int cod1[qtde],cod_2[qtde],cod3;
    char area1[qtde],data_2[12];
    char data[qtde];
    int incluso;


    do {
        system("cls");
        printf("__________________________________________________\n");
		printf("Digite o Codigo do Agendamento: ");
        fflush(stdin);
        scanf("%d",&codag[0]);

        printf("__________________________________________________\n");
		printf("Digite a Data do Agendamento: ");
        fflush(stdin);
         gets(data2);

        printf("__________________________________________________\n");
		printf("Digite o nome do aluno e o codigo: ");
        fflush(stdin);
        gets(nomeal);
        fflush(stdin);
        scanf("%d",&codal[0]);
        printf("__________________________________________________\n");
        printf("Digite o nome do paciente e o codigo: ");
        fflush(stdin);
        gets(nomepac);
        fflush(stdin);
        scanf("%d",&codpac[0]);
        printf("__________________________________________________\n");
		printf("Digite a data do Atendimento: ");
		fflush(stdin);
		gets(data3);
		printf("__________________________________________________\n");
		printf("Digite a Area de atendimento(Odontologia,Fisioterapia,Psicologia): ");
		fflush(stdin);
		gets(area);
		printf("__________________________________________________\n");
		printf("Digite o nome do supervisor e o codigo:\n");
        fflush(stdin);
        gets(nomesup);
        fflush(stdin);
        scanf("%d",&codsup[0]);
        fflush(stdin);
        
		for(i=0;i<qtde;++i){
		     if(strcmp(ag[i].nome,nomepac)!=0&&ag[i].incluso==1){
		     	 printf("O Agendamento previo do paciente Nao foi feito!!\n");
		     	 break;
			 }
			 else if(strcmp(ag[i].nome,nomepac)==0&&at[i].incluso==0){
                at[i].codat[0]=cont+1;
				at[i].codag[0]=codag[0];
                at[i].codal[0]=codal[0];
                at[i].codpac[0]=codpac[0];
                at[i].codsup[0]=codsup[0];
				strcpy(at[i].nomeal,nomeal);
				strcpy(at[i].nomepac,nomepac);
				strcpy(at[i].nomesup,nomesup);
                strcpy(at[i].area,area);
                strcpy(at[i].datag,data2);
                strcpy(at[i].datat,data3);
                at[i].incluso=1;
                ag[i].cod1[0]=0;
            memset (ag[i].nome, 0, sizeof (nome) );
            memset (ag[i].area, 0, sizeof (area) );
            memset (ag[i].data, 0, sizeof (data) );
            ag[i].incluso=0;
			apagar3();
                break;
            }
           
		}
         cont ++;
        printf("\n\n1.Fazer um novo Atendimento\n0.Sair\n");
        fflush(stdin);
        scanf("%d",&op);
   
    } while(op!=0);
}

//Função para listar atendimento
void listaratendimento(){
    FILE *fileatend;
	system("cls");
    char area2;
	int i;
	fileatend=fopen("atendimentos.txt","w");
	printf("LISTA DE TODOS OS ATENDIMENTOS JA FEITOS:\n\n");
    for(i=0;i<qtde;++i){
        if(at[i].incluso==1){
            fprintf(fileatend,"CODIGO DO ATENDIMENTO ------------- : %d\n",at[i].codat[0]);
            fprintf(fileatend,"CODIGO DO AGENDAMENTO ------------- : %d\n",at[i].codag[0]);
            fprintf(fileatend,"DATA DO AGENDAMENTO ----------- : %s\n\n",at[i].datag);
			fprintf(fileatend,"NOME DO ALUNO/ CODIGO --------------- : %s / %d\n",at[i].nomeal,at[i].codal[0]);
			fprintf(fileatend,"NOME DO PACIENTE / CODIGO --------------- : %s / %d\n",at[i].nomepac,at[i].codpac[0]);
			fprintf(fileatend,"NOME DO SUPERVISOR / CODIGO --------------- : %s / %d\n",at[i].nomesup,at[i].codsup[0]);
            fprintf(fileatend,"DATA DO ATENDIMENTO ----------- : %s\n\n",at[i].datat);
			fprintf(fileatend,"AREA DO ATENDIMENTO ---------------- : %s\n",at[i].area);
        }
    }
    
	for(i=0;i<qtde;++i){
        if(at[i].incluso==1){
            printf("CODIGO DO ATENDIMENTO ------------- : %d\n",at[i].codat[0]);
            printf("CODIGO DO AGENDAMENTO ------------- : %d\n",at[i].codag[0]);
            printf("DATA DO AGENDAMENTO ----------- : %s\n\n",at[i].datag);
			printf("NOME DO ALUNO/ CODIGO --------------- : %s / %d\n",at[i].nomeal,at[i].codal[0]);
		    printf("NOME DO PACIENTE / CODIGO --------------- : %s / %d\n",at[i].nomepac,at[i].codpac[0]);
			printf("NOME DO SUPERVISOR / CODIGO --------------- : %s / %d\n",at[i].nomesup,at[i].codsup[0]);
            printf("DATA DO ATENDIMENTO ----------- : %s\n\n",at[i].datat);
		    printf("AREA DO ATENDIMENTO ---------------- : %s\n",at[i].area);
        }
    }
	
	
	
	
	
	printf(" Tecle <ENTER> para continuar!");
    getch();
}
//Função listar por area
void listaraera(){
system("cls");
int i;
char area2[qtde];
printf("Digite a area:\n");
fflush(stdin);
gets(area2);
printf("LISTA DE TODOS OS ATENDIMENTOS FEITOS POR AREA:\n\n");
for(i=0;i<qtde;++i){
        if( strcmp(at[i].area,area2)== 0){
            printf("CODIGO DO ATENDIMENTO ------------- : %d\n",at[i].codat[0]);
            printf("CODIGO DO AGENDAMENTO ------------- : %d\n",at[i].codag[0]);
            printf("DATA DO AGENDAMENTO ----------- : %s\n\n",at[i].datag);
			printf("NOME DO ALUNO/ CODIGO --------------- : %s / %d\n",at[i].nomeal,at[i].codal[0]);
			printf("NOME DO PACIENTE / CODIGO --------------- : %s / %d\n",at[i].nomepac,at[i].codpac[0]);
			printf("NOME DO SUPERVISOR / CODIGO --------------- : %s / %d\n",at[i].nomesup,at[i].codsup[0]);
            printf("DATA DO ATENDIMENTO ----------- : %s\n\n",at[i].datat);
			printf("AREA DO ATENDIMENTO ---------------- : %s\n",at[i].area);
        }
    }
    printf(" Tecle <ENTER> para continuar!");
    getch();

}
//Função listar por aluno
void listaralunos(){
system("cls");
int i;
char aluno2[qtde];
printf("Digite o nome do aluno:\n");
fflush(stdin);
gets(aluno2);
printf("LISTA DE TODOS OS ATENDIMENTOS FEITOS POR ALUNO:\n\n");
for(i=0;i<qtde;++i){
        if( strcmp(at[i].nomeal,aluno2) == 0){
            printf("CODIGO DO ATENDIMENTO ------------- : %d\n",at[i].codat[0]);
            printf("CODIGO DO AGENDAMENTO ------------- : %d\n",at[i].codag[0]);
            printf("DATA DO AGENDAMENTO ----------- : %s\n\n",at[i].datag);
			printf("NOME DO ALUNO/ CODIGO --------------- : %s / %d\n",at[i].nomeal,at[i].codal[0]);
			printf("NOME DO PACIENTE / CODIGO --------------- : %s / %d\n",at[i].nomepac,at[i].codpac[0]);
			printf("NOME DO SUPERVISOR / CODIGO --------------- : %s / %d\n",at[i].nomesup,at[i].codsup[0]);
            printf("DATA DO ATENDIMENTO ----------- : %s\n\n",at[i].datat);
			printf("AREA DO ATENDIMENTO ---------------- : %s\n",at[i].area);
        }
    }
    printf(" Tecle <ENTER> para continuar!");
    getch();

}
//Função listar por paciente
void listarpaciente(){
system("cls");
int i;
char paciente2[qtde];
printf("Digite o nome do paciente:\n");
fflush(stdin);
gets(paciente2);
printf("LISTA DE TODOS OS ATENDIMENTOS FEITOS POR PACIENTE:\n\n");
for(i=0;i<qtde;++i){
        if( strcmp(at[i].nomepac,paciente2) == 0){
            printf("CODIGO DO ATENDIMENTO ------------- : %d\n",at[i].codat[0]);
            printf("CODIGO DO AGENDAMENTO ------------- : %d\n",at[i].codag[0]);
            printf("DATA DO AGENDAMENTO ----------- : %s\n\n",at[i].datag);
			printf("NOME DO ALUNO/ CODIGO --------------- : %s / %d\n",at[i].nomeal,at[i].codal[0]);
			printf("NOME DO PACIENTE / CODIGO --------------- : %s / %d\n",at[i].nomepac,at[i].codpac[0]);
			printf("NOME DO SUPERVISOR / CODIGO --------------- : %s / %d\n",at[i].nomesup,at[i].codsup[0]);
            printf("DATA DO ATENDIMENTO ----------- : %s\n\n",at[i].datat);
			printf("AREA DO ATENDIMENTO ---------------- : %s\n",at[i].area);
        }
    }
    printf(" Tecle <ENTER> para continuar!");
    getch();

}

//Função cancelar atendimento
void cancelaratendimento(){
	system("cls");

    char nomeal[qtde],nomepac[qtde],nomesup[qtde];
    int cod[qtde],cod2[qtde],codpac[qtde],codal[qtde],codsup[qtde],codag[qtde],codat[qtde],codaux;
    char area[qtde],data2[12],data3[12];
    char datag[qtde],datat[qtde];
    int inclusoat,op,i;
    int cont=0;

	
	int Atendimentoencontrado = 0;
	
    printf("Informe o codigo do Atendimento que deseja cancelar:\n");
    fflush(stdin);
	scanf("%d",&codaux);

	for(i=0;i<qtde;++i){
	   	if(at[i].codat[0]==codaux){
            at[i].codat[0]=0;
			at[i].codag[0]=0;
            at[i].codal[0]=0;
            at[i].codpac[0]=0;
            at[i].codsup[0]=0;
            memset (at[i].nomeal, 0, sizeof (nomeal) );
            memset (at[i].nomepac, 0, sizeof (nomepac) );
            memset (at[i].nomesup, 0, sizeof (nomesup) );
            memset (at[i].area, 0, sizeof (area) );
            memset (at[i].datag, 0, sizeof (datag) );
            memset (at[i].datat, 0, sizeof (datat) );
            at[i].incluso=0; 
            
            Atendimentoencontrado = 1;
            
            break;
        }
    }
    
        if ( Atendimentoencontrado )
    	printf("\nAtendimento Cancelado com sucesso!\n\n");
    else
    	printf("\nCodigo nao encontrado!\n\n");
    
    printf("#### Tecle <ENTER> para continuar!");
    getch();
}
void salvar4(){
int i;
 FILE *fileatend;
	system("cls");
    char area2;
	fileatend=fopen("atendimentos.txt","w");
	printf("LISTA DE TODOS OS ATENDIMENTOS JA FEITOS:\n\n");
    for(i=0;i<qtde;++i){
        if(at[i].incluso==1){
            fprintf(fileatend,"CODIGO DO ATENDIMENTO ------------- : %d\n",at[i].codat[0]);
            fprintf(fileatend,"CODIGO DO AGENDAMENTO ------------- : %d\n",at[i].codag[0]);
            fprintf(fileatend,"DATA DO AGENDAMENTO ----------- : %s\n\n",at[i].datag);
			fprintf(fileatend,"NOME DO ALUNO/ CODIGO --------------- : %s / %d\n",at[i].nomeal,at[i].codal[0]);
			fprintf(fileatend,"NOME DO PACIENTE / CODIGO --------------- : %s / %d\n",at[i].nomepac,at[i].codpac[0]);
			fprintf(fileatend,"NOME DO SUPERVISOR / CODIGO --------------- : %s / %d\n",at[i].nomesup,at[i].codsup[0]);
            fprintf(fileatend,"DATA DO ATENDIMENTO ----------- : %s\n\n",at[i].datat);
			fprintf(fileatend,"AREA DO ATENDIMENTO ---------------- : %s\n",at[i].area);
        }
    }
    fclose(fileatend);
}
void apagar4(){
	int i;
 FILE *fileatend;
	system("cls");
    char area2;
	fileatend=fopen("atendimentos.txt","w");
	printf("LISTA DE TODOS OS ATENDIMENTOS JA FEITOS:\n\n");
    for(i=0;i<qtde;++i){
        if(at[i].incluso==1){
            fprintf(fileatend,"CODIGO DO ATENDIMENTO ------------- : %d\n",at[i].codat[0]);
            fprintf(fileatend,"CODIGO DO AGENDAMENTO ------------- : %d\n",at[i].codag[0]);
            fprintf(fileatend,"DATA DO AGENDAMENTO ----------- : %s\n\n",at[i].datag);
			fprintf(fileatend,"NOME DO ALUNO/ CODIGO --------------- : %s / %d\n",at[i].nomeal,at[i].codal[0]);
			fprintf(fileatend,"NOME DO PACIENTE / CODIGO --------------- : %s / %d\n",at[i].nomepac,at[i].codpac[0]);
			fprintf(fileatend,"NOME DO SUPERVISOR / CODIGO --------------- : %s / %d\n",at[i].nomesup,at[i].codsup[0]);
            fprintf(fileatend,"DATA DO ATENDIMENTO ----------- : %s\n\n",at[i].datat);
			fprintf(fileatend,"AREA DO ATENDIMENTO ---------------- : %s\n",at[i].area);
        }
    }
    fclose(fileatend);
}
