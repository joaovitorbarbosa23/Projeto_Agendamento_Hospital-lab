#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define qtde 200

typedef struct{
    char nome[qtde];
    int matricula[qtde];
    char cpf[qtde];
    char curso[qtde];
    int incluso;
} Aluno;

Aluno a[qtde];

void opcoesal();
void cadastraraluno();
void removeraluno();
void editaraluno();
void listaraluno();
void salvar2();
void apagar2();
void editar2();
int cont;

void menual(){
    opcoesal();
}

//Menu Aluno
void opcoesal(){
    int choice;

    do {
system("color C0");
system("cls");
printf(" ___________________________________________________\n");
printf("|                   MENU ALUNO:                     |\n");
printf("|___________________________________________________|\n");
printf(" ___________________________________________________\n");
printf("|              1.CADASTRAR ALUNO                    |\n");
printf("|              2.EDITAR ALUNO                       |\n");
printf("|              3.REMOVER ALUNO                      |\n");
printf("|              4.LISTAR ALUNO                       |\n");
printf("|              0.MENU PRINCIPAL                     |\n");
printf("|___________________________________________________|\n");
printf("             OPCAO ESCOLHIDA:");
scanf("%d",&choice);
        
        switch(choice){
            case 1:
                cadastraraluno();
                salvar2();
                break;
            case 2:
            	editaraluno();
            	editar2();
				break;
    		case 3:
    			removeraluno();
    			apagar2();
    			break;
    		case 4:
                listaraluno();
                break;
        }

    } while(choice!=0);
}

// Função para o Incluir um Aluno
void cadastraraluno(){
    system("cls");

    int matricula[qtde],op,i;
    char cpf[qtde];
    char cpf2[12];
    char nome[qtde];
    char curso[qtde];

    do {
        system("cls");
        printf("__________________________________________________\n");
		printf("Digite o Nome do Aluno: ");
        fflush(stdin);
        gets(nome);
	    printf("__________________________________________________\n");
        printf("Digite a Matricula do aluno: ");
        fflush(stdin);
        scanf("%d",&matricula[0]);
       	printf("__________________________________________________\n");
	    printf("Digite o CPF do Aluno(sem pontos ou tracos): ");
        fflush(stdin);
        gets(cpf2);
        printf("__________________________________________________\n");
        printf("Digite o curso do Aluno: ");
        fflush(stdin);
        gets(curso);

        for(i=0;i<qtde;++i){
			if(strcmp(a[i].cpf,cpf2)==0){
        		printf("ALUNO JA CADASTRADO!!");
        		break;
        	}
			else if(a[i].incluso==0){
                a[i].matricula[0]=matricula[0];
                strcpy(a[i].nome,nome);
                strcpy(a[i].cpf,cpf2);
                strcpy(a[i].curso,curso);
                a[i].incluso=1;
                break;
                system("pause");
            }
        }

        printf("\n\n1.Fazer um novo cadastro\n0.Sair\n");
        fflush(stdin);
        scanf("%d",&op);
   
    } while(op!=0);
}

// Função para listar e mostrar na tela os Alunos cadastrados
void listaraluno(){
    system("cls");
	int i;
	printf("LISTA DE TODOS OS ALUNOS JA CADASTRADOS:\n\n");
	for(i=0;i<qtde;++i){
        if(a[i].incluso==1){
            printf("MATRICULA ------------- : %d\n",a[i].matricula[0]);
            printf("NOME --------------- : %s\n",a[i].nome);
            printf("CPF ---------------- : %s\n",a[i].cpf);
            printf("CURSO ----------- : %s\n\n",a[i].curso);
        }
    }
	
	printf("#### Tecle <ENTER> para continuar!");
    getch();
}

// Função para editar os dados cadastrados de um Aluno
void editaraluno(){
	system("cls");
	int matricula[qtde],i;
	char cpf[qtde],cpf2[12];
    char nome[qtde];
    char curso[qtde];

	int alunoencontrado = 0;

   	printf("Digite o numero do CPF do aluno que deseja editar:\n");
   	fflush(stdin);
   	gets(cpf2);

	for(i=0;i<qtde;++i){
		if( strcmp(a[i].cpf, cpf2) == 0 ){
            printf("__________________________________________________\n");
			printf("Digite o Nome do aluno:\n");
            fflush(stdin);
            gets(nome);
            printf("__________________________________________________\n");
            printf("Digite a Matricula do aluno:\n");
            fflush(stdin);
           scanf("%d",&matricula[0]);
			printf("__________________________________________________\n");
			printf("Digite o CPF do aluno(sem pontos ou tracos):\n");
            fflush(stdin);
            gets(cpf);
           printf("__________________________________________________\n");
            printf("Digite o Curso do aluno:\n");
            fflush(stdin);
            gets(curso);

            a[i].matricula[0]=matricula[0];
            strcpy(a[i].nome,nome);
            strcpy(a[i].cpf,cpf);
            strcpy(a[i].curso,curso);
            a[i].incluso=1;           
           
            alunoencontrado = 1;
            
			break;
        }
    }
    
    if ( alunoencontrado )
    	printf("\nAluno alterado com sucesso!\n");
    else
    	printf("\nCPF nao encontrado!\n");
    
    printf("#### Tecle <ENTER> para continuar!");
    getch();
}

// Função para remover um Aluno do cadastro
void removeraluno(){
	system("cls");

    int matricula[qtde];
    char cpf[qtde],cpf2[12];
	char nome[qtde];
    char curso[qtde];
	int i;
	
	int alunoencontrado = 0;
	
    printf("Informe o CPF do Aluno que deseja remover:\n");
    fflush(stdin);
	gets(cpf2);

	for(i=0;i<qtde;++i){
	   	if( strcmp(a[i].cpf,cpf2) == 0){
            a[i].matricula[0]=0;
            memset (a[i].nome, 0, sizeof (nome) );
            memset (a[i].cpf, 0, sizeof (cpf) );
            memset (a[i].curso, 0, sizeof (curso) );
            a[i].incluso=0; 
            
            alunoencontrado = 1;
            
            break;
        }
    }
    
        if ( alunoencontrado )
    	printf("\nAluno removido com sucesso!\n\n");
    else
    	printf("\nCPF nao encontrado!\n\n");
    
    printf("#### Tecle <ENTER> para continuar!");
    getch();
}
void salvar2(){
int i;
FILE *filealuno;
	system("cls");
    filealuno=fopen("alunoscadastro.txt","w");
    for(i=0;i<qtde;++i){
        if(a[i].incluso==1){
            fprintf(filealuno,"MATRICULA ------------- : %d\n",a[i].matricula[0]);
            fprintf(filealuno,"NOME --------------- : %s\n",a[i].nome);
            fprintf(filealuno,"CPF ---------------- : %s\n",a[i].cpf);
            fprintf(filealuno,"CURSO ----------- : %s\n\n",a[i].curso);
        }
    }
    fclose(filealuno);
}
void apagar2(){
	int i;
	FILE *filealuno;
    filealuno=fopen("alunoscadastro.txt","w");
    for(i=0;i<qtde;++i){
        if(a[i].incluso==1){
            fprintf(filealuno,"MATRICULA ------------- : %d\n",a[i].matricula[0]);
            fprintf(filealuno,"NOME --------------- : %s\n",a[i].nome);
            fprintf(filealuno,"CPF ---------------- : %s\n",a[i].cpf);
            fprintf(filealuno,"CURSO ----------- : %s\n\n",a[i].curso);
        }
    }
    fclose(filealuno);
}
void editar2(){
	int i;
	FILE *filealuno;
    filealuno=fopen("alunoscadastro.txt","w");
    for(i=0;i<qtde;++i){
        if(a[i].incluso==1){
            fprintf(filealuno,"MATRICULA ------------- : %d\n",a[i].matricula[0]);
            fprintf(filealuno,"NOME --------------- : %s\n",a[i].nome);
            fprintf(filealuno,"CPF ---------------- : %s\n",a[i].cpf);
            fprintf(filealuno,"CURSO ----------- : %s\n\n",a[i].curso);
        }
    }
    fclose(filealuno);
}
