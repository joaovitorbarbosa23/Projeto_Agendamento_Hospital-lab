#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define qtde 200

typedef struct{
    char nome[qtde];
    int cod[qtde];
    char curso[qtde];
    int incluso;
} Supervisor;

Supervisor s[qtde];

void opcoessup();
void cadastrarsupervisor();
void removersupervisor();
void editarsupervisor();
void listarsupervisor();
void apagar1();
void salvar1();
void editar1();

int cont;

void menusup(){
    opcoessup();
}

//Menum Supervisor
void opcoessup(){
    int choice;

    do {
system("cls");
system("color 17");
printf(" ___________________________________________________\n");
printf("|                   MENU SUPERVISOR:                |\n");
printf("|___________________________________________________|\n");
printf(" ___________________________________________________\n");
printf("|              1.CADASTRAR SUPERVISOR               |\n");
printf("|              2.EDITAR SUPERVISOR                  |\n");
printf("|              3.REMOVER SUPERVISOR                 |\n");
printf("|              4.LISTAR SUPERVISOR                  |\n");
printf("|              0.MENU PRINCIPAL                     |\n");
printf("|___________________________________________________|\n");
printf("             OPCAO ESCOLHIDA:");
scanf("%d",&choice);
        
        switch(choice){
            case 1:
                cadastrarsupervisor();
                salvar1();
                break;
            case 2:
            	editarsupervisor();
            	editar1();
            	break;
    		case 3:
    			removersupervisor();
    			 apagar1();
    			break;
    		case 4:
                listarsupervisor();
        }

    } while(choice!=0);
}

// Função para o Incluir um Supervisor
void cadastrarsupervisor(){
    system("cls");

    int cod[qtde],op,i;
    char nome[qtde];
    char curso[qtde];

    do {
        system("cls");
        printf("__________________________________________________\n");
		printf("Digite o Nome do Supervisor: ");
        fflush(stdin);
        gets(nome);
        printf("__________________________________________________\n");
		printf("Digite o Codigo do Supervisor:  ");
        fflush(stdin);
        scanf("%d",&cod[0]);
        printf("__________________________________________________\n");
		printf("Digite o curso do Supervisor: ");
        fflush(stdin);
        gets(curso);

        for(i=0;i<qtde;++i){
           if (strcmp(s[i].nome,nome)==0){
            	 printf("\nSupervisor ja cadastrado!!");
            	 break;
		}
		   
		    else if(s[i].incluso==0){
                s[i].cod[0]=cod[0];
                strcpy(s[i].nome,nome);
                strcpy(s[i].curso,curso);
                s[i].incluso=1;
                break;
                system("pause");
            }
		
		}
        cont++;

        printf("\n\n1.Fazer um novo cadastro\n0.Sair\n");
        fflush(stdin);
        scanf("%d",&op);
   
    } while(op!=0);
}

// Função para listar e mostrar na tela os Supervisores cadastrados
void listarsupervisor(){
    system("cls");
	int i;
	for(i=0;i<qtde;++i){
        if(s[i].incluso==1){
            printf("CODIGO ------------- : %d\n",s[i].cod[0]);
            printf("NOME --------------- : %s\n",s[i].nome);
            printf("CURSO ----------- : %s\n\n",s[i].curso);
        }
    }
    printf("#### Tecle <ENTER> para continuar!");
    getch();
}

// Função para editar os dados cadastrados de um Supervisor
void editarsupervisor(){
	system("cls");
	int cod[qtde],i,cod2;
    char nome[qtde];
    char curso[qtde];

	int supervisorencontrado = 0;

   	printf("Digite o numero do codigo do Supervisor que deseja editar:\n");
   	fflush(stdin);
   scanf("%d",&cod2);

	for(i=0;i<qtde;++i){
		if( s[i].cod[0]==cod2){
            printf("__________________________________________________\n");
			printf("Digite o Nome do Supervisor:\n");
            fflush(stdin);
            gets(nome);
            printf("__________________________________________________\n");
            printf("Digite o Codigo do Supervisor:\n");
            fflush(stdin);
            scanf("%d",&cod[0]);
			printf("__________________________________________________\n");
            printf("Digite o Curso do Supervisor:\n");
            fflush(stdin);
            gets(curso);

            s[i].cod[0]=cod[0];
            strcpy(s[i].nome,nome);
            strcpy(s[i].curso,curso);
           s[i].incluso=1;           
           
            supervisorencontrado = 1;
            
			break;
        }
    }
    
    if ( supervisorencontrado )
    	printf("\nSupervisor alterado com sucesso!\n");
    else
    	printf("\ncodigo nao encontrado!\n");
    
    printf("#### Tecle <ENTER> para continuar!");
    getch();
}

// Função para remover um Supervisor do cadastro
void removersupervisor(){
	system("cls");

    int cod[qtde],cod2;
	char nome[qtde];
    char curso[qtde];
	int i;
	
	int supervisorencontrado = 0;
	
    printf("Informe o codigo do Supervisor que deseja remover:\n");
    fflush(stdin);
	scanf("%d",&cod2);

	for(i=0;i<qtde;++i){
	   	if( s[i].cod[0]==cod2){
            s[i].cod[0]=0;
            memset (s[i].nome, 0, sizeof (nome) );
            memset (s[i].curso, 0, sizeof (curso) );
            s[i].incluso=0; 
            
            supervisorencontrado = 1;
            
            break;
        }
    }
    
        if ( supervisorencontrado )
    	printf("\nSupervisor removido com sucesso!\n\n");
    else
    	printf("\ncodigo nao encontrado!\n\n");
    
    printf("#### Tecle <ENTER> para continuar!");
    getch();
}
void salvar1(){
int i;
 FILE *filesup;
    filesup=fopen("supervisores.txt","a");
	system("cls");
    printf("LISTA DE TODOS OS SUPERVISORES JA CADASTRADOS:\n\n");
    for(i=0;i<qtde;++i){
        if(s[i].incluso==1){
            fprintf(filesup,"CODIGO ------------- : %d\n",s[i].cod[0]);
            fprintf(filesup,"NOME --------------- : %s\n",s[i].nome);
            fprintf(filesup,"CURSO ----------- : %s\n\n",s[i].curso);
        }
    }
    fclose(filesup);
}
void apagar1(){
	int i;
	FILE *filesup;
   filesup=fopen("supervisores.txt","w");
	 if(filesup==NULL){
    	printf("arquivo nao pode ser aberto");
    	system("pause");
	}
    for(i=0;i<qtde;++i){
        if(s[i].incluso==1){
            fprintf(filesup,"CODIGO ------------- : %d\n",s[i].cod[0]);
            fprintf(filesup,"NOME --------------- : %s\n",s[i].nome);
            fprintf(filesup,"CURSO ----------- : %s\n\n",s[i].curso);
        }
    }
    fclose(filesup);
}
void editar1(){
	int i;
	FILE *filesup;
   filesup=fopen("supervisores.txt","w");
	 if(filesup==NULL){
    	printf("arquivo nao pode ser aberto");
    	system("pause");
	}
    for(i=0;i<qtde;++i){
        if(s[i].incluso==1){
            fprintf(filesup,"CODIGO ------------- : %d\n",s[i].cod[0]);
            fprintf(filesup,"NOME --------------- : %s\n",s[i].nome);
            fprintf(filesup,"CURSO ----------- : %s\n\n",s[i].curso);
        }
    }
    fclose(filesup);
}

