#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#define NUM 50

typedef struct m{
    char dia[2], mes[2], ano[4];
}DATAage;
typedef struct agendamentos{
	char cod[NUM], nome[NUM], codpac[NUM], area[NUM]; 
	DATAage d;
}cadastroage;
cadastroage a;
int op;
void criar_novo();
void cancelar();
void listarage();
void mensagem_errop();
void menu_agend();

void criar_novo(){
	int op;
	FILE *file;
	file=fopen("agendamentos.txt","w");
	
	do{
		system("cls");
		printf("\nINSIRA>> ");
		printf("\n\nCODIGO: ");
		fflush(stdin);
			gets(a.cod);
     	printf("\nCODIGO : %s", a.cod);
		fflush(stdin);
		printf("\nNOME: ");
			gets(a.nome);
		setbuf(stdin,NULL);
		printf("\nDIGITE DATA DE NASCIMENTO: ");
		printf("\nDIA: ");
	    	scanf("%s",&a.d.dia);
	    fflush(stdin);	
	    printf("\nMES: ");
	    	scanf("%s",&a.d.mes);
	    fflush(stdin);	
	    printf("\nANO: ");
	    	scanf("%s",&a.d.ano);
		fflush(stdin);
	    printf("\nCODIGO DO PACIENTE: ");
	    	gets(a.codpac);
	    fflush(stdin);	
		printf("\nAREA DO AGENDAMENTO: ");
	    	gets(a.area);
		fflush(stdin);
		fwrite(&a, sizeof(cadastroage), 1, file);
		  fclose(file);
		printf("\nRegistro gravado com sucesso!\n");
		fflush(stdin);
		printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
		printf("\n\nOPÇÃO: ");
			scanf("%d",&op);
	}while(op!=1);
		menu_agend();
}

void cancelar(){
	system("cls");
	char nome[NUM];
	int op,op2;
	cadastroage pac2;
	printf("\n\n~~~~~~~~~~~~~~EXCLUIR~~~~~~~~~~~~~~");
	FILE *file, *aux;
	file=fopen("agendamentos.txt","r+b");
	aux=fopen("auxiliar.txt","w+b");
	printf("\n\n\nDIGITE NOME DO PACIENTE DO AGENDAMENTO QUE DESEJA EXCLUIR: ");
	setbuf(stdin,NULL);	
		gets(nome);
	while(fread(&a,sizeof(cadastroage),1,file)==1){
           if(strcmp(nome, a.nome)==0){
           	printf("\nCODIGO: %s", a.cod);
			printf("\nNOME DO PACIENTE: %s", a.nome);
			printf("\nDATA DE NASCIMENTO: %d/%d/%d", a.d.dia,a.d.mes,a.d.ano);
			printf("\nCODIGO DO PACIENTE: %s", a.codpac);
			printf("\nAREA DO AGENDAMENTO: %s",a.area);
			printf("\n---------------------------------------------\n");
		   }
		   
		}
		printf("\n\nTEM CERTEZA QUE DESEJA EXCLUIR ESSE PACIENTE ?");
		printf("\n1 - SIM, 2- NAO ");
		printf("\n\nOPÇÃO: ");
		setbuf(stdin,NULL);
		scanf("%d", &op2);
		if(op2==1){
			rewind(file);
			while(fread(&a,sizeof(cadastroage),1,file)==1){
	            if(strcmp(nome, a.nome) != 0) {
	              fwrite(&a,sizeof(cadastroage), 1, aux);
	
				}
			}
			
			if(aux==NULL){
				printf("problemas na exclusão");
			}
		    fclose(file);
		    fclose(aux);
			system("del agendamentos.txt");
		    system("ren auxiliar.txt agendamentos.txt");
		    
		    system("cls");
			printf ("\n\n\n  ------------Agendamento removido com sucesso!-----------\n");
			printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
			printf("\n\nOPÇÃO: ");
			scanf("%d",&op);
			if(op==1){
				menu_agend();
			}	  
			
		}
		
		else{
			printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
			printf("\n\nopcao: ");
			scanf("%d",&op);
			printf("\n\nOPÇÃO: ");
			if(op==1){
				menu_agend();
		}	
			
	}
}

void listarage(){
	system("cls");
	FILE *file;
	file=fopen("agendamentos.txt","rb");
	printf("\n~~~~~~~~~~~~~~LISTA DE AGENDAMENTOS~~~~~~~~~~~~~~\n");
	if (file == NULL){
		printf ("\n\n-------------------------------");
		printf ("\n\nNenhum agendamento cadastrado!");
		printf ("\n\n-------------------------------");
	}
	else{
	while(fread(&a, sizeof(cadastroage), 1, file)==1){			
			printf("\nCODIGO: %s", a.cod);
			printf("\nNOME DO PACIENTE: %s", a.nome);
			printf("\nDATA DE NASCIMENTO: %d/%d/%d", a.d.dia,a.d.mes,a.d.ano);
			printf("\nCODIGO DO PACIENTE: %s", a.codpac);
			printf("\nAREA DO AGENDAMENTO: %s",a.area);
			printf("\n---------------------------------------------\n");
		}
	}
	fclose(file);
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	printf("\n\nOPÇÃO: ");
	scanf("%d",&op);
	if(op==1){
		 menu_agend();
	}
	
}
	
void mensagem_errop(){
	system("cls");
	int op;
	printf("\nERROR:opcao invalida");
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	scanf("%d",&op);
	printf("\n\nOPÇÃO: ");
	if(op==1){
		menu_agend();
	}
}

void menu_agend(){
	system("cls");
	printf("\n~~~~~~~~~~~~~~AGENDAMENTOS~~~~~~~~~~~~~~\n");
	int op;
	printf("\n\nESCOLHA A OPÇÃO>>");
	printf("\n\n           1- CRIAR NOVO: ");
	printf("\n             2- CANCELAR: ");
	printf("\n             3- LISTAR: ");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\n\n         OPÇÃO: ");
		scanf("%d", &op);
	fflush(stdin);
	
	switch(op){
		case 1:
			criar_novo();
			break;
		case 2:
			cancelar();
			break;	
		case 3:
			listarage();
			break;	
		default:
			mensagem_errop();
						
				}
}

					
					
					

