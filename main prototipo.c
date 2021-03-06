#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include "pacientes.c"
#include "alunos.c"
#include "supervisor.c"
#include "agendamentos.c"
#include "atendimentos.c"

void mensagem_erro();

void mensagem_erro(){
	system("cls");
	int op;
	printf("\nERROR:opcao invalida");
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	scanf("%d",&op);
	printf("\n\nOPÇÃO: ");
	if(op==1){
		menuprinc();
	}
}
menuprinc(){
	int po;
	do{ 
	
	system("cls");
	printf("\n~~~~~~~~~~~~~~~ BEM VINDO(A)! ~~~~~~~~~~~~~~~\n");
	printf("\n~~~~~~~~~~~~ CLINICA ZEZIN PREA ~~~~~~~~~~~~~\n");
	printf("\n~~~~~~~~~~~~~~ MENU DE SELEÇAO ~~~~~~~~~~~~~~\n");
	printf("\n\n        ESCOLHA A OPÇÃO>>                   ");
	printf("\n\n            1- PACIENTTES:");
	printf("\n            2- ALUNOS:");
	printf("\n            3- SUPERVISOR:");
	printf("\n            4- AGENDAMENTO:");
	printf("\n            5- ATENDIMENTO:");
	printf("\n\n            0- SAIR:");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\n        OPÇÃO: ");
				scanf("%d", &po);
				fflush(stdin);
		switch(po){
			case 1:
				menupac();
				break;
			case 2:
				menual();
				break;
			case 3:
				menusuper();
				break;
			case 4:
				menu_agend();
				break;
			case 5:
				menuate();
				break;
			case 0:
				system("exit");	
			default:
				mensagem_erro();
				break;					
		}
	
	}while(po!=0);
}

main(){
	system("color 37");
	setlocale(LC_ALL, "Portuguese");
	menuprinc();
}
