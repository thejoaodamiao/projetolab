#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#define NUM 50

typedef struct tempo{
    char dia[2], mes[2], ano[4];
}DATA;
typedef struct pacientes{
	char cod[NUM];
	char nome[NUM],cpf[NUM],ende[NUM];
	DATA d;
}cadastro;

cadastro pac;
int op,i=0;
void verificadorcpf();
void menupac();
void cadastrar();
void remover();
void editar();
void listar();
void mensagem_errol();

void menupac(){
	system("cls");
	printf("\n~~~~~~~~~~~~~~PACIENTES~~~~~~~~~~~~~~\n");
	int op;
	printf("\n\n        ESCOLHA A OPÇÃO>>");
	printf("\n\n            1- CADASTRAR:");
	printf("\n            2- EDITAR:");
	printf("\n            3- REMOVER:");
	printf("\n            4- LISTAR:");
	
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\n        OPÇÃO: ");
				scanf("%d", &op);
				fflush(stdin);
				
				switch(op){
					case 1:
						cadastrar();
						break;
					case 2:
						editar();
						break;
					case 3:
						remover();
						break;	
					case 4:
						listar();
						break;	
					default:
						mensagem_erro();
						
				}
}
void cadastrar(){
	FILE *file;
	file=fopen("pacientes.txt","ab");
	printf("\n~~~~~~~~~~~~~~CADASTRAR PACIENTES~~~~~~~~~~~~~~\n");
	do{
		system("cls");
		printf("\nINSIRA>> ");
		printf("\n\nCODIGO: ");
		fflush(stdin);
			gets(pac.cod);
     	printf("\nCODIGO : %s", pac.cod);
		fflush(stdin);
		printf("\nNOME: ");
			gets(pac.nome);
		setbuf(stdin,NULL);
		printf("\nDIGITE DATA DE NASCIMENTO: ");
		printf("\nDIGITE DIA: ");
	    scanf("%s",&pac.d.dia);
	    setbuf(stdin,NULL);
	    printf("DIGITE MES: ");
	    setbuf(stdin,NULL);
	    scanf("%s",&pac.d.mes);
	    setbuf(stdin,NULL);
	    printf("DIGITE ANO: ");
	    scanf("%s",&pac.d.ano);
		fflush(stdin);
		printf("\nCPF: ");
		    fflush(stdin);
			gets(pac.cpf);
			fflush(stdin);	
		printf("\nEndereco: ");
			gets(pac.ende);
	while(fread(&pac, sizeof(cadastro), 1, file)==1){
		if(strcmp(pac.cpf,pac.cpf)==0){
			system("cls");
			printf("\n\nUSUARIO JA CADASTRADO!");
			printf("\n\nNÃO PODERÁ SE CADASTRAR NOVAMENTE!");
			printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
			printf("\n\nOPÇÃO: ");
				scanf("%d",&op);
			if(op==1){
			menupac();
			}	
			
		}
	}
		fwrite(&pac, sizeof(cadastro), 1, file);
		  fclose(file);
		printf("\nRegistro gravado com sucesso!\n");
		fflush(stdin);
		printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
		printf("\n\nOPÇÃO: ");
			scanf("%d",&op);
	}while(op!=1);
		menupac();
}
void editar(){

   	printf("\n~~~~~~~~~~~~~~EDITAR PACIENTES~~~~~~~~~~~~~~\n");
    char nome[NUM], cpf[NUM];
    cadastro paciente, novo_dado;
    FILE *file, *aux;
	file=fopen("pacientes.txt","r+");
	aux=fopen("auxiliar.txt","w+b");
    printf ("\t\tDIGITE O NOME: ");
    scanf (" %[^\n]s", nome);
    printf ("\t\tDIGITE O CPF: ");
    scanf (" %[^\n]s", cpf);
    
while(fread(&pac,sizeof(cadastro),1,file)==1){
            if (strcmp(nome,pac.nome)==0){
            	if (strcmp(cpf,pac.cpf)==0){
                    printf("\n\nCODIGO: ");
					fflush(stdin);
						scanf("%[^\n]s",novo_dado.cod);
			     	printf("\nCODIGO : %s", novo_dado.cod);
					fflush(stdin);
					printf("\nNOME: ");
						scanf("%[^\n]s",&novo_dado.nome);
					setbuf(stdin,NULL);
					printf("\nDIGITE DATA DE NASCIMENTO: ");
					printf("\nDIGITE DIA: ");
				    scanf("%[^\n]s",novo_dado.d.dia);
				    printf("DIGITE MES: ");
				    scanf("%[^\n]s",novo_dado.d.mes);
				    printf("DIGITE ANO: ");
				    scanf("%[^\n]s",novo_dado.d.ano);
					fflush(stdin);
					printf("\nCPF: ");
					    fflush(stdin);
						gets(novo_dado.cpf);
						fflush(stdin);	
					printf("\nEndereco: ");
						gets(novo_dado.ende);
                    fwrite(&novo_dado, sizeof(cadastro), 1, aux);
                    fclose(file);
				    fclose(aux);
					system("del pacientes.txt");
				    system("ren auxiliar.txt pacientes.txt");
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
	system("del pacientes.txt");
    system("ren auxiliar.txt pacientes.txt");
}
void listar(){
	system("cls");
	FILE *file;
	file=fopen("pacientes.txt","rb");
	printf("\n~~~~~~~~~~~~~~LISTA DE PACIENTES~~~~~~~~~~~~~~\n");
	if (file == NULL){
		printf ("\n\n-------------------------------");
		printf ("\n\nNenhum paciente cadastrado!");
		printf ("\n\n-------------------------------");
	}
	else{
	while(fread(&pac, sizeof(cadastro), 1, file)==1){			
			printf("\nCODIGO: %s", pac.cod);
			printf("\nNOME: %s", pac.nome);
			printf("\nDATA DE NASCIMENTO: %s/%s/%s", pac.d.dia,pac.d.mes,pac.d.ano);
			printf("\nCPF: %s", pac.cpf);
			printf("\nENDERECO: %s",pac.ende);
			printf("\n---------------------------------------------\n");
		}
	}
	fclose(file);
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	printf("\n\nOPÇÃO: ");
	scanf("%d",&op);
	if(op==1){
		menupac();
	}
	
}

void remover(){
	system("cls");
	char cpf[NUM];
	int op,op2;
	cadastro pac2;
	printf("\n\n~~~~~~~~~~~~~~EXCLUIR~~~~~~~~~~~~~~");
	FILE *file, *aux;
	file=fopen("pacientes.txt","r+");
	aux=fopen("auxiliar.txt","w+b");
	printf("\n\n\nDIGITE CPF DO PACIENTE QUE DESEJA EXCLUIR: ");
	setbuf(stdin,NULL);	
		gets(cpf);
	while(fread(&pac,sizeof(cadastro),1,file)==1){
           if(strcmp(cpf,pac.cpf)==0){
           	printf("\n\n\nCODIGO: %s", pac.cod);
			printf("\nNOME: %s", pac.nome);
			printf("\nDATA DE NASCIMENTO: %s/%s/%s", pac.d.dia,pac.d.mes,pac.d.ano);
			printf("\nCPF: %s", pac.cpf);
			printf("\nENDERECO: %s",pac.ende);
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
			while(fread(&pac,sizeof(cadastro),1,file)==1){
	            if(strcmp(cpf, pac.cpf) != 0) {
	              fwrite(&pac,sizeof(cadastro), 1, aux);
	
				}
		
			}
			if(aux==NULL){
				printf("problemas na exclusão");
			}
		    fclose(file);
		    fclose(aux);
			system("del pacientes.txt");
		    system("ren auxiliar.txt pacientes.txt");
		    system("cls");
			printf ("\n------------Paciente removido com sucesso!-----------\n");
			printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
			printf("\n\nOPÇÃO: ");
			scanf("%d",&op);
			if(op==1){
				menupac();
			}	  
			
		}
		
		else{
			printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
			printf("\n\nopcao: ");
			scanf("%d",&op);
			printf("\n\nOPÇÃO: ");
			if(op==1){
				menupac();
		}	
			
	}
}

void mensagem_errol(){
	system("cls");
	int op;
	printf("\nERROR:opcao invalida");
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	scanf("%d",&op);
	printf("\n\nOPÇÃO: ");
	if(op==1){
		menupac();
	}
}


