#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#define NUM 50


typedef struct supervisor{
	char cod[NUM];
	char nome[NUM],curso[NUM];

}cadastrosu;

cadastrosu super;
void menusuper();
void cadastrarsu();
void removersu();
void editarsu();
void listarsu();
void mensagem_errow();

void menusuper(){
	system("cls");
	printf("\n~~~~~~~~~~~~~~SUPERVISOR~~~~~~~~~~~~~~\n");
	int op;
	printf("\n\nESCOLHA A OPÇÃO>>");
	printf("\n\n          1- CADASTRAR:");
	printf("\n            2- EDITAR:");
	printf("\n            3- REMOVER:");
	printf("\n            4- LISTAR:");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\n\n        OPÇÃO: ");
		scanf("%d", &op);
	fflush(stdin);

	switch(op){
	case 1:
		cadastrarsu();
		break;
	case 2: 
		editarsu();
		break;	
	case 3:
		removersu();
		break;	
	case 4:
		listarsu();
		break;	
	default:
		mensagem_errow();
						
	}
}

void cadastrarsu(){
	FILE *file;
	file=fopen("supervisor.txt","ab");
	do{
		system("cls");
		printf("\nINSIRA>> ");
		printf("\nCODIGO : %s", super.cod);
		fflush(stdin);
			gets(super.cod);
        printf("\nCODIGO : %s", super.cod);
		fflush(stdin);
		printf("\nNOME: ");
			gets(super.nome);
			fflush(stdin);	
		printf("\nCURSO: ");
			gets(super.curso);
	while(fread(&super, sizeof(cadastrosu), 1, file)==1){
		if(strcmp(super.nome,super.nome)==0){
			system("cls");
			printf("\n\nUSUARIO JA CADASTRADO!");
			printf("\n\nNÃO PODERÁ SE CADASTRAR NOVAMENTE!");
			printf("\n\nDESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
			printf("\n\nOPÇÃO: ");
				scanf("%d",&op);
			if(op==1){
			menusuper();
			}	
			
		}
	}
		fwrite(&super, sizeof(cadastrosu), 1, file);
		  fclose(file);
		printf("\nRegistro gravado com sucesso!\n");
		fflush(stdin);
		printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
		printf("\n\nOPÇÃO: ");
			scanf("%d",&op);
	}while(op!=1);
		menusuper();
}

void listarsu(){
	system("cls");
	FILE *file;
	file=fopen("supervisor.txt","rb");
	printf("\n~~~~~~~~~~~~~~LISTA DE SUPERVISORES~~~~~~~~~~~~~~\n");
	if (file == NULL){
		printf ("\n\n-------------------------------");
		printf ("\n\nNenhum supervisor cadastrado!");
		printf ("\n\n-------------------------------");
	}
	else{
	while(fread(&super, sizeof(cadastrosu), 1, file)==1){			
			printf("\nCODIGO: %s", super.cod);
			printf("\nNOME: %s", super.nome);
			printf("\nCURSO: %s",super.curso);
			printf("\n---------------------------------------------\n");
		}
	}
	fclose(file);
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	printf("\n\nOPÇÃO: ");
	scanf("%d",&op);
	if(op==1){
		menusuper();
	}
	
}

void removersu(){
	system("cls");
	char nome[NUM];
	int op,op2;
	cadastrosu super2;
	printf("\n\n~~~~~~~~~~~~~~EXCLUIR~~~~~~~~~~~~~~");
	FILE *file, *aux;
	file=fopen("superunos.txt","r+");
	aux=fopen("auxiliar.txt","w+b");
	printf("\n\n\nDIGITE NOME DO SUPERVISOR QUE DESEJA EXCLUIR: ");
	setbuf(stdin,NULL);	
		gets(nome);
	while(fread(&super,sizeof(cadastrosu),1,file)==1){
           if(strcmp(nome,super.nome)==0){
           	printf("\nCODIGO: %s", super.cod);
			printf("\nNOME: %s", super.nome);
			printf("\nCURSO: %s",super.curso);
			printf("\n---------------------------------------------\n");
			}
		}
		   
		printf("\n\nTEM CERTEZA QUE DESEJA EXCLUIR ESSE SUPERVISOR ?");
		printf("\n1 - SIM, 2- NAO ");
		printf("\n\nOPÇÃO: ");
		setbuf(stdin,NULL);
		scanf("%d", &op2);
		if(op2==1){
			rewind(file);
			while(fread(&super,sizeof(cadastrosu),1,file)==1){
	            if(strcmp(nome, super.nome) != 0) {
	              fwrite(&super,sizeof(cadastrosu), 1, aux);
	
				}
			}
			if(aux==NULL){
				printf("problemas na exclusão");
			}
		    
			fclose(file);
		    fclose(aux);
			system("del supervisor.txt");
		    system("ren auxiliar.txt supervisor.txt");
		    
		    system("cls");
			printf ("\n\n\n------------Supervisor removido com sucesso!-----------\n");
			printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
			printf("\n\nOPÇÃO: ");
			scanf("%d",&op);
			if(op==1){
				menusuper();
			}	  
			
		}
		
		else{
			printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
			printf("\n\nopcao: ");
			scanf("%d",&op);
			printf("\n\nOPÇÃO: ");
			if(op==1){
				menusuper();
		}	
			
	}
}

void editarsu(){

   	printf("\n~~~~~~~~~~~~~~EDITAR SUPERVISOR~~~~~~~~~~~~~~\n");
    char nome[NUM], curso[NUM];
    cadastrosu paciente, novo_dado;
    FILE *file, *aux;
	file=fopen("supervisor.txt","r+");
	aux=fopen("auxiliar.txt","w+b");
    printf ("\t\tDIGITE O NOME: ");
    scanf (" %[^\n]s", nome);
    printf ("\t\tDIGITE CURSO: ");
    scanf (" %[^\n]s", curso);
    
while(fread(&super,sizeof(cadastrosu),1,file)==1){
            if (strcmp(nome,super.nome)==0){
            	if (strcmp(curso,super.curso)==0){
                    printf("\n\nCODIGO: ");
					fflush(stdin);
						scanf("%[^\n]s",novo_dado.cod);
			     	printf("\nCODIGO : %s", novo_dado.cod);
					fflush(stdin);
					printf("\nNOME: ");
						scanf("%[^\n]s",&novo_dado.nome);
					setbuf(stdin,NULL);
					printf("\nCURSO: ");
						scanf("%[^\n]s",&novo_dado.curso);
					setbuf(stdin,NULL);
					
                    fwrite(&novo_dado, sizeof(cadastrosu), 1, aux);
                    fclose(file);
				    fclose(aux);
					system("del supervisor.txt");
				    system("ren auxiliar.txt supervisor.txt");
                }

            } else {

                    printf("usuario não cadastro!");
                    close(file);
				    fclose(aux);
					system("del auxiliar.txt");
				

            }
    }

    fclose(file);
    fclose(aux);
	system("del supervisor.txt");
    system("ren auxiliar.txt supervisor.txt");
}

void mensagem_errow(){
	system("cls");
	int op;
	printf("\nERROR:opção invalida");
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	scanf("%d",&op);
	printf("\n\nOPÇÃO: ");
	if(op==1){
		menusuper();
	}
}


