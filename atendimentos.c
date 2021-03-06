#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#define NUM 50

typedef struct {
	char codatend[NUM], codagend[NUM],nomeal[NUM], codal[NUM], nomepac[NUM], codpac[NUM],dataagend[NUM], dataatend[NUM], area[NUM], nomesuper[NUM], codsuper[NUM];

}atendimento;

atendimento ate;
void menuate();
void criar_atendimento();
void cancelar_atendimento();
void listar_todos_atendimentos();
void listar_atendimento_area(); 
void listar_por_aluno(); 
void listar_por_paciente();
void mensagem_errof(); 
int op;

void menuate(){
	system("cls");
	int op;
	printf("\n~~~~~~~~~~~~~~ATENDIMENTO~~~~~~~~~~~~~\n");
	printf("\n\n        ESCOLHA A OPÇÃO>>");
	printf("\n\n            1- PACIENTTES:");
	printf("\n            2- ALUNOS:");
	printf("\n            3- SUPERVISOR:");
	printf("\n            4- AGENDAMENTO:");
	printf("\n            5- ATENDIMENTO:");
	printf("\n\n            0- SAIR:");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\n        OPÇÃO: ");
				scanf("%d", &op);
				fflush(stdin);
		switch(op){
			case 1:
				criar_atendimento();
				break;
			case 2:
				cancelar_atendimento();
				break;
			case 3:
				listar_todos_atendimentos();
				break;
			case 4:
				listar_por_aluno(); 
				break;
			case 5:
				listar_por_paciente(); 
				break;
			default:
				mensagem_errof();
				break;					
		}
}

void listar_todos_atendimentos(){
	FILE* file;
	file = fopen ("atendimentos.txt", "rb");

		while (fread(&ate, sizeof(atendimento), 1, file) == 1){
			printf ("\nCODIGO DE ATENDIMENTO: %s\n", ate.codatend);
			printf ("\nCODIGO DO AGENDAMENTO: %s\n", ate.codagend);
			printf ("\nDATA DO AGENDAMENTO: %s\n", ate.dataagend);
			printf ("\nNOME DO ALUNO: %s\n", ate.nomeal);
			printf ("\nCODIGO DO ALUNO: %s\n", ate.codal);
			printf ("\nNOME DO PACIENTE: %s\n", ate.nomepac);
			printf ("\nCODIGO DE PACIENTE: %s\n", ate.codpac);
			printf ("\nDATA DO ATENDIMENTO: %s\n", ate.dataatend);
			printf ("\nAREA DO ATENDIMENTO: %s\n", ate.area);
			printf ("\nNOME DO SUPERVISOR: %s\n", ate.nomesuper);
			printf ("\nCODIGO DO SUPERVISOR: %s\n\n", ate.codsuper);
			printf ("-----------------------------------\n\n");
		}
	
	fclose (file);
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	scanf("%d",&op);
	printf("\n\nOPÇÃO: ");
	if(op==1){
		menuate();
	}
	
	
}
void criar_atendimento(){
	FILE* file;
	file= fopen ("atendimentos.txt", "ab");
	
		do{
			
			printf ("\nCODIGO DE ATENDIMENTO: ");
			gets (ate.codatend);
			setbuf(stdin,NULL);
			printf ("\nCODIGO DO AGENDAMENTO: ");
			gets (ate.codagend);
			setbuf(stdin,NULL);
			printf ("\nDATA DO AGENDAMENTO: ");
			gets (ate.dataagend);
			setbuf(stdin,NULL);
			printf ("\nNOME DO ALUNO: ");
			gets (ate.nomeal);
			setbuf(stdin,NULL);
			printf ("\nCODIGO DO ALUNO: ");
			gets (ate.codal);
			setbuf(stdin,NULL);
			printf ("\nNOME DO PACIENTE: ");
			gets (ate.nomepac);
			setbuf(stdin,NULL);
			printf ("\nCODIGO DE PACIENTE: ");
			gets (ate.codpac);
			setbuf(stdin,NULL);
			printf ("\nDATA DO ATENDIMENTO: ");
			gets (ate.dataatend);
			setbuf(stdin,NULL);
			printf ("\nAREA DO ATENDIMENTO: ");
			gets (ate.area);
			setbuf(stdin,NULL);
			printf ("\nNOME DO SUPERVISOR: ");
			gets (ate.nomesuper);
			setbuf(stdin,NULL);
			printf ("\nCODIGO DO SUPERVISOR: ");
			gets (ate.codsuper);
			setbuf(stdin,NULL);
			fwrite (&ate, sizeof(atendimento), 1, file);
			printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
			printf("\n\nOPÇÃO: ");
			scanf("%d",&op);
		}while (op!=1);
		fclose (file);
		menuate();
	}
void cancelar_atendimento(){
	FILE* file;
	FILE* aux;
	char auxi[NUM];
	file = fopen ("atendimentos.txt", "rb");
	aux = fopen ("auxiliar.txt", "ab");

		printf ("\nDigite o código do atendimento a ser cancelado: ");
		fflush (stdin);
		gets (auxi);
		while (fread(&ate, sizeof(atendimento), 1, file) == 1){
			if (strcmp (ate.codatend, auxi) == 1){
				fwrite (&ate, sizeof(atendimento), 1, aux);
			}
		}
		fclose (file);
		fclose (aux);
		system ("cls");
		printf ("\n\n\n  ------------Atendimento removido com sucesso!-----------\n");
		system ("del atendimentos.txt");
		system ("ren auxiliar.txt atendimentos.txt");
		printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	scanf("%d",&op);
	printf("\n\nOPÇÃO: ");
	if(op==1){
		menuate();
	}
}



void listar_atendimento_area(){
		FILE* file;
	char palavra[NUM];
	file = fopen ("atendimentos.txt", "rb");
	
		fflush (stdin);
		printf ("-------------------------------------------------------");
		printf ("\n\nDigite o nome da área a ser pesquisado: ");
		gets(palavra);
		printf ("\n\n---------------------------------------------------");
		while (fread(&ate, sizeof(atendimento), 1, file) == 1){
			if (strcmp(palavra, ate.area) == 0){
				printf ("\nCODIGO DE ATENDIMENTO: %s\n", ate.codatend);
				printf ("\nCODIGO DO AGENDAMENTO: %s\n", ate.codagend);
				printf ("\nDATA DO AGENDAMENTO: %s\n", ate.dataagend);
				printf ("\nNOME DO ALUNO: %s\n", ate.nomeal);
				printf ("\nCODIGO DO ALUNO: %s\n", ate.codal);
				printf ("\nNOME DO PACIENTE: %s\n", ate.nomepac);
				printf ("\nCODIGO DE PACIENTE: %s\n", ate.codpac);
				printf ("\nDATA DO ATENDIMENTO: %s\n", ate.dataatend);
				printf ("\nAREA DO ATENDIMENTO: %s\n", ate.area);
				printf ("\nNOME DO SUPERVISOR: %s\n", ate.nomesuper);
				printf ("\nCODIGO DO SUPERVISOR: %s\n\n", ate.codsuper);
				printf ("-----------------------------------\n\n");
			}
		}
	
	fclose (file);
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	scanf("%d",&op);
	printf("\n\nOPÇÃO: ");
	if(op==1){
		menuate();
	}
	
	
}
void listar_por_aluno(){
	FILE* file;
	char palavra[NUM];
	file = fopen ("atendimentos.txt", "rb");
	
		fflush (stdin);
		printf ("-------------------------------------------------------");
		printf ("\n\nDigite o nome do aluno a ser pesquisado: ");
		gets(palavra);
		printf ("\n\n---------------------------------------------------");
		while (fread(&ate, sizeof(atendimento), 1, file) == 1){
			if (strcmp(palavra, ate.nomeal) == 0){
				printf ("\nCODIGO DE ATENDIMENTO: %s\n", ate.codatend);
				printf ("\nCODIGO DO AGENDAMENTO: %s\n", ate.codagend);
				printf ("\nDATA DO AGENDAMENTO: %s\n", ate.dataagend);
				printf ("\nNOME DO ALUNO: %s\n", ate.nomeal);
				printf ("\nCODIGO DO ALUNO: %s\n", ate.codal);
				printf ("\nNOME DO PACIENTE: %s\n", ate.nomepac);
				printf ("\nCODIGO DE PACIENTE: %s\n", ate.codpac);
				printf ("\nDATA DO ATENDIMENTO: %s\n", ate.dataatend);
				printf ("\nAREA DO ATENDIMENTO: %s\n", ate.area);
				printf ("\nNOME DO SUPERVISOR: %s\n", ate.nomesuper);
				printf ("\nCODIGO DO SUPERVISOR: %s\n\n", ate.codsuper);
				printf ("-----------------------------------\n\n");
			}
		}
	
	fclose (file);
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	scanf("%d",&op);
	printf("\n\nOPÇÃO: ");
	if(op==1){
		menuate();
	}
	
}

void listar_por_paciente(){
	FILE* file;
	char palavra[NUM];
	file = fopen ("atendimentos.txt", "rb");
		fflush (stdin);
		printf ("-------------------------------------------------------");
		printf ("\n\nDigite o nome do paciente a ser pesquisado: ");
		gets(palavra);
		printf ("\n\n---------------------------------------------------");
		while (fread(&ate, sizeof(atendimento), 1, file) == 1){
			if (strcmp(palavra, ate.nomepac) == 0){
				printf ("\nCODIGO DE ATENDIMENTO: %s\n", ate.codatend);
				printf ("\nCODIGO DO AGENDAMENTO: %s\n", ate.codagend);
				printf ("\nDATA DO AGENDAMENTO: %s\n", ate.dataagend);
				printf ("\nNOME DO ALUNO: %s\n", ate.nomeal);
				printf ("\nCODIGO DO ALUNO: %s\n", ate.codal);
				printf ("\nNOME DO PACIENTE: %s\n", ate.nomepac);
				printf ("\nCODIGO DE PACIENTE: %s\n", ate.codpac);
				printf ("\nDATA DO ATENDIMENTO: %s\n", ate.dataatend);
				printf ("\nAREA DO ATENDIMENTO: %s\n", ate.area);
				printf ("\nNOME DO SUPERVISOR: %s\n", ate.nomesuper);
				printf ("\nCODIGO DO SUPERVISOR: %s\n\n", ate.codsuper);
				printf ("-----------------------------------\n\n");
			}
		}
		fclose (file);
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	scanf("%d",&op);
	printf("\n\nOPÇÃO: ");
	if(op==1){
		menuate();
	}
	}
	void mensagem_errof(){
	system("cls");
	int op;
	printf("\nERROR:opção invalida");
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	scanf("%d",&op);
	printf("\n\nOPÇÃO: ");
	if(op==1){
		menuate();
	}
}
	

	


