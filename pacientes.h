#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


#define qtde 200

typedef struct{
    char nome[qtde];
    int cod[qtde];
    char end[qtde],cpf2[12],cpf[qtde];
    int incluso;
    char data[qtde];

}pac;

pac p[qtde];

void opcoespac();
void cadastrarpac();
void removerpac();
void editarpac();
void listarpac();
void salvar();
void apagar();
void editar();

void menupac(){
    opcoespac();
}

//Menu paciente
void opcoespac(){
    int choice;

    do {
system("color E0");
system("cls");
printf("             ___________________________________________________\n");
printf("            |                   MENU PACIENTE:                  |\n");
printf("            |___________________________________________________|\n");
printf("             ___________________________________________________\n");
printf("            |              1.CADASTRAR PACIENTE                 |\n");
printf("            |              2.EDITAR PACIENTE                    |\n");
printf("            |              3.REMOVER PACIENTE                   |\n");
printf("            |              4.LISTAR PACIENTE                    |\n");
printf("            |              0.MENU PRINCIPAL                     |\n");
printf("            |___________________________________________________|\n");
printf("                         OPCAO ESCOLHIDA:");
scanf("%d",&choice);
        switch(choice){
            case 1:
                cadastrarpac();
                salvar();
                break;
            case 2:
            	editarpac();
            	editar();
            	break;
    		case 3:
    			removerpac();
    			apagar();
    			break;
    		case 4:
                listarpac();
                break;
        }

    } while(choice!=0);
}


// Função para o Incluir um paciente
void cadastrarpac(){
    system("cls");

    char nome[qtde];
    int cod[qtde];
    char end[qtde],cpf2[12],cpf[qtde];
    char data[qtde],data2[15];
    int incluso,i,op;
    int cont=0;


    do {
        system("cls");
		printf("__________________________________________________\n");
		printf("Digite o Nome do Paciente:  ");
        fflush(stdin);
        gets(nome);
        printf("__________________________________________________\n");
		printf("Digite o Codigo do Paciente:  ");
        fflush(stdin);
        scanf("%d",&cod[0]);
        printf("__________________________________________________\n");
		printf("\nDigite a data de nascimento do paciente:  ");
        fflush(stdin);
		gets(data2);
		printf("__________________________________________________\n");
		printf("\nDigite o CPF do paciente(sem pontos ou tracos):  ");
        fflush(stdin);
        gets(cpf2);
        printf("__________________________________________________\n");
		printf("\nDigite o Endereco do paciente:  ");
        fflush(stdin);
        gets(end);
        printf("__________________________________________________\n");
		for(i=0;i<qtde;++i){
            if(strcmp(p[i].cpf,cpf2)==0){
        		printf("PACIENTE JA CADASTRADO!!");
        		break;
        	}
            else if(p[i].incluso==0){
				p[i].cod[0]=cod[0];
                strcpy(p[i].nome,nome);
                strcpy(p[i].end,end);
                strcpy(p[i].data,data2);
                strcpy(p[i].cpf,cpf2);
                p[i].incluso=1;
                break;
                system("pause");
            }
		
		}
         
        printf("\n\n1.Fazer um novo Cadastro\n0.Sair\n");
        fflush(stdin);
        scanf("%d",&op);
   
    } while(op!=0);
}

// Função para listar e mostrar na tela os pacientes cadastrados
void listarpac(){
    system("cls");
	int i;
    printf("LISTA DE TODOS OS PACIENTES JA CADASTRADOS:\n\n");
	for(i=0;i<qtde;++i){
        if(p[i].incluso==1){
            printf("CODIGO ------------- : %d\n",p[i].cod[0]);
            printf("NOME --------------- : %s\n",p[i].nome);
            printf("DATA DE NASCIMENTO - : %s\n",p[i].data);
            printf("CPF ---------------- : %s\n",p[i].cpf);
            printf("ENDERECO ----------- : %s\n\n",p[i].end);
        }
    }
    printf("#### Tecle <ENTER> para continuar!");
    getch();
}

//Função de editar paciente
	void editarpac(){
	system("cls");
	char nome[qtde];
    int cod[qtde];
    char end[qtde],cpf2[12],cpf[qtde];
    char data[qtde],data2[12];
    int incluso,i;
    int cont=0;

	int pacienteencontrado = 0;

   	printf("Digite o numero do CPF do paciente que deseja editar:\n");
   	fflush(stdin);
   	gets(cpf2);

	for(i=0;i<qtde;++i){
		if( strcmp(p[i].cpf,cpf2)== 0){
            system("cls");
        printf("__________________________________________________\n");
		printf("Digite o Nome do Paciente:  ");
        fflush(stdin);
        gets(nome);
        printf("__________________________________________________\n");
		printf("Digite o Codigo do Paciente:  ");
        fflush(stdin);
        scanf("%d",&cod[0]);
        printf("__________________________________________________\n");
		printf("\nDigite a data de nascimento do paciente:  ");
        fflush(stdin);
		gets(data2);
		printf("__________________________________________________\n");
		printf("\nDigite o CPF do paciente(sem pontos ou tracos):  ");
        fflush(stdin);
        gets(cpf2);
        printf("__________________________________________________\n");
		printf("\nDigite o Endereco do paciente:  ");
        fflush(stdin);
        gets(end);
        printf("__________________________________________________\n");

                p[i].cod[0]=cont+120;
                strcpy(p[i].nome,nome);
                strcpy(p[i].end,end);
                strcpy(p[i].data,data2);
                strcpy(p[i].cpf,cpf2);
                p[i].incluso=1;
                       
           
            pacienteencontrado = 1;
            
			break;
        }
    }
    cont++;
    
    if ( pacienteencontrado )
    	printf("\nPaciente alterado com sucesso!\n");
    else
    	printf("\nCPF nao encontrado!\n");
    
    printf("#### Tecle <ENTER> para continuar!");
    getch();
}

//função remover paciente
void removerpac(){
	system("cls");
    char nome[qtde];
    int cod[qtde];
    char end[qtde],cpf2[12],cpf[qtde];
    char data[qtde],data2[15];
    int incluso,i,op;
    int cont=0;
	int pacienteencontrado = 0;
	
    printf("Informe o CPF do paciente que deseja remover:\n");
    fflush(stdin);
	gets(cpf2);

	for(i=0;i<qtde;++i){
	   	if( strcmp(p[i].cpf,cpf2) == 0){
            p[i].cod[0]=0;
            memset (p[i].data, 0, sizeof (data) );
			memset (p[i].nome, 0, sizeof (nome) );
            memset (p[i].cpf, 0, sizeof (cpf) );
            memset (p[i].end, 0, sizeof (end) );
            p[i].incluso=0; 
            
            pacienteencontrado = 1;
            
            break;
        }
    }
    
		if ( pacienteencontrado )
    	printf("\nPaciente removido com sucesso!\n\n");
    else
    	printf("\nCPF nao encontrado!\n\n");
   
  printf("#### Tecle <ENTER> para continuar!");
    getch();
}
void salvar(){
int i;
FILE *filepacientes;
FILE *filepac;
filepac=filepacientes;
filepacientes=fopen("pacientes.txt","w");
    if(filepacientes==NULL){
    	printf("arquivo não pode ser aberto");
    	system("pause");
	}
    for(i=0;i<qtde;++i){
        if(p[i].incluso==1){
            fprintf(filepacientes,"CODIGO ------------- : %d\n",p[i].cod[0]);
            fprintf(filepacientes,"NOME --------------- : %s\n",p[i].nome);
            fprintf(filepacientes,"DATA DE NASCIMENTO - : %s\n",p[i].data);
            fprintf(filepacientes,"CPF ---------------- : %s\n",p[i].cpf);
            fprintf(filepacientes,"ENDERECO ----------- : %s\n\n",p[i].end);
        }
    }
fclose(filepacientes);
 
}

void apagar(){
	int i;
	FILE *filepacientes;
	FILE *filepac;
	filepac=filepacientes;
	filepacientes=fopen("pacientes.txt","w");
	 if(filepacientes==NULL){
    	printf("arquivo não pode ser aberto");
    	system("pause");
	}
    for(i=0;i<qtde;++i){
        if(p[i].incluso==1){
            fprintf(filepacientes,"CODIGO ------------- : %d\n",p[i].cod[0]);
            fprintf(filepacientes,"NOME --------------- : %s\n",p[i].nome);
            fprintf(filepacientes,"DATA DE NASCIMENTO - : %s\n",p[i].data);
            fprintf(filepacientes,"CPF ---------------- : %s\n",p[i].cpf);
            fprintf(filepacientes,"ENDERECO ----------- : %s\n\n",p[i].end);
        }
    }
     fclose(filepacientes);
}
void editar(){
	int i;
	FILE *filepacientes;
	FILE *filepac;
	filepac=filepacientes;
	filepacientes=fopen("pacientes.txt","w");
	 if(filepacientes==NULL){
    	printf("arquivo não pode ser aberto");
    	system("pause");
	}
    for(i=0;i<qtde;++i){
        if(p[i].incluso==1){
            fprintf(filepacientes,"CODIGO ------------- : %d\n",p[i].cod[0]);
            fprintf(filepacientes,"NOME --------------- : %s\n",p[i].nome);
            fprintf(filepacientes,"DATA DE NASCIMENTO - : %s\n",p[i].data);
            fprintf(filepacientes,"CPF ---------------- : %s\n",p[i].cpf);
            fprintf(filepacientes,"ENDERECO ----------- : %s\n\n",p[i].end);
        }
    }
     fclose(filepacientes);
}

