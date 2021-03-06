#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#define NUM 50

typedef struct{
    char dia[2], mes[2], ano[4];
}DATAS;
typedef struct alunos{
	char mat[NUM];
	char nome[NUM],cpf[NUM],curso[NUM];
	DATAS d;
}cadastros;

cadastros al;
int op;
void menual();
void cadastraral();
void removeral();
void editaral();
void listaral();
void mensagem_errom();

void menual(){
	system("cls");
	printf("\n~~~~~~~~~~~~~~ALUNOS~~~~~~~~~~~~~~\n");
	int op;
	printf("\n\nESCOLHA A OPÇÃO>>");
	printf("\n\n          1- CADASTRAR:");
	printf("\n            2- EDITAR:");
	printf("\n            3- REMOVER:");
	printf("\n            4- LISTAR:");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\n\n        OPÇÃO: ");
		scanf("%d", &op);
	fflush(stdin);

	switch(op){
	case 1:
		cadastraral();
		break;
	case 2: 
		editaral();
		break;
	case 3:
		removeral();
		break;	
	case 4:
		listaral();
		break;	
	default:
		mensagem_errom();
						
	}
}

void cadastraral(){
	FILE *file;
	file=fopen("alunos.txt","ab");
	do{
		system("cls");
		printf("\nINSIRA>> ");
		printf("\nMATRICULA: ");
		fflush(stdin);
		gets(al.mat);
     	printf("\nMATRICULA : %s", al.mat);
		fflush(stdin);
		printf("\nNOME: ");
		gets(al.nome);
		setbuf(stdin,NULL);
		printf("\nDIGITE DATA DE NASCIMENTO: ");
		printf("\nDIGITE DIA: ");
	    scanf("%s",&al.d.dia);
	    setbuf(stdin,NULL);
	    printf("DIGITE MES: ");
	    scanf("%s",&al.d.mes);
	    setbuf(stdin,NULL);
	    printf("DIGITE ANO: ");
	    scanf("%s",&al.d.ano);
		fflush(stdin);
		printf("\nCPF: ");
		gets(al.cpf);
		fflush(stdin);	
		printf("\nCURSO: ");
			gets(al.curso);
	while(fread(&al, sizeof(cadastros), 1, file)==1){
		if(strcmp(al.cpf,al.cpf)==0){
			system("cls");
			printf("\n\nUSUARIO JA CADASTRADO!");
			printf("\n\nNÃO PODERÁ SE CADASTRAR NOVAMENTE!");
			printf("\n\nDESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
			printf("\n\nOPÇÃO: ");
				scanf("%d",&op);
			if(op==1){
			menual();
			}	
			
		}
	}
		fwrite(&al, sizeof(cadastros), 1, file);
		  fclose(file);
		printf("\nRegistro gravado com sucesso!\n");
		fflush(stdin);
		printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
		printf("\n\nOPÇÃO: ");
			scanf("%d",&op);
	}while(op!=1);
		menual();
}

void listaral(){
	
	system("cls");
	FILE *file;
	file=fopen("alunos.txt","rb");
	printf("\n~~~~~~~~~~~~~~LISTA DE ALUNOS~~~~~~~~~~~~~~\n");
	if (file == NULL){
		printf ("\n\n-------------------------------");
		printf ("\n\nNenhum aliente cadastrado!");
		printf ("\n\n-------------------------------");
	}
	else{
	while(fread(&al, sizeof(cadastros), 1, file)==1){			
			printf("\nMATRICULA: %s", al.mat);
			printf("\nNOME: %s", al.nome);
			printf("\nDATA DE NASCIMENTO: %s,%s,%s", al.d.dia,al.d.mes,al.d.ano);
			printf("\nCPF: %s", al.cpf);
			printf("\nCURSO: %s",al.curso);
			printf("\n---------------------------------------------\n");
		}
	}
	fclose(file);
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	printf("\n\nOPÇÃO: ");
	scanf("%d",&op);
	if(op==1){
		menual();
	}
	
}

void editaral(){

   	printf("\n~~~~~~~~~~~~~~EDITAR ALUNOS~~~~~~~~~~~~~~\n");
    char nome[NUM], mat[NUM];
    cadastros alunos, novo_dado;
    FILE *file, *aux;
	file=fopen("alunos.txt","r+");
	aux=fopen("auxiliar.txt","w+b");
    printf ("\t\tDIGITE O NOME: ");
    scanf (" %[^\n]s", nome);
    printf ("\t\tDIGITE O CPF: ");
    scanf (" %[^\n]s", mat);
    
while(fread(&al,sizeof(cadastros),1,file)==1){
            if (strcmp(nome,al.nome)==0){
            	if (strcmp(mat,al.mat)==0){
                    printf("\n\nCODIGO: ");
					fflush(stdin);
						scanf("%[^\n]s",novo_dado.mat);
			     	printf("\nCODIGO : %s", novo_dado.mat);
					fflush(stdin);
					printf("\nNOME: ");
						scanf("%[^\n]s",&novo_dado.nome);
					setbuf(stdin,NULL);
					printf("\nDIGITE DATA DE NASCIMENTO: ");
					printf("\nDIGITE DIA: ");
				    scanf("%[^\n]s",novo_dado.d.dia);
				    setbuf(stdin,NULL);
				    printf("DIGITE MES: ");
				    scanf("%[^\n]s",novo_dado.d.mes);
				    setbuf(stdin,NULL);
				    printf("DIGITE ANO: ");
				    scanf("%[^\n]s",novo_dado.d.ano);
					fflush(stdin);
					printf("\nCPF: ");
					    fflush(stdin);
						gets(novo_dado.cpf);
						fflush(stdin);	
                    fwrite(&novo_dado, sizeof(cadastros), 1, aux);
                    fclose(file);
				    fclose(aux);
					system("del alunos.txt.txt");
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
	system("del alunos.txt");
    system("ren auxiliar.txt alunos.txt");
}

void removeral(){
	system("cls");
	char cpf[NUM];
	int op,op2;
	printf("\n\n~~~~~~~~~~~~~~EXCLUIR~~~~~~~~~~~~~~");
	FILE *file, *aux;
	file=fopen("alunos.txt","r+b");
	aux=fopen("auxiliar.txt","w+b");
	printf("\n\n\nDIGITE CPF DO ALUNO QUE DESEJA EXCLUIR: ");
	setbuf(stdin,NULL);	
		gets(cpf);
	while(fread(&al,sizeof(cadastros),1,file)==1){
           if(strcmp(cpf,al.cpf)==0){
           	printf("\nMATRICULA: %s", al.mat);
			printf("\nNOME: %s", al.nome);
			printf("\nDATA DE NASCIMENTO: %s,%s,%s", al.d.dia,al.d.mes,al.d.ano);
			printf("\nCPF: %s", al.cpf);
			printf("\nCURSO: %s",al.curso);
			printf("\n---------------------------------------------\n");
			}
		}
		   
		printf("\n\nTEM CERTEZA QUE DESEJA EXCLUIR ESSE ALUNO ?");
		printf("\n1 - SIM, 2- NAO ");
		printf("\n\nOPÇÃO: ");
		setbuf(stdin,NULL);
		scanf("%d", &op2);
		if(op2==1){
			rewind(file);
			while(fread(&al,sizeof(cadastros),1,file)==1){
	            if(strcmp(cpf, al.cpf) != 0) {
	              fwrite(&al,sizeof(cadastro), 1, aux);
	
				}
			}
			if(aux==NULL){
				printf("problemas na exclusão");
			}
		    fclose(file);
		    fclose(aux);
			system("del alunos.txt");
		    system("ren auxiliar.txt alunos.txt");
		    
		    system("cls");
			printf ("\n------------Aluno removido com sucesso!-----------\n");
			printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
			printf("\n\nOPÇÃO: ");
			scanf("%d",&op);
			if(op==1){
				menual();
			}	  
			
		}
		
		else{
			printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
			printf("\n\nopcao: ");
			scanf("%d",&op);
			printf("\n\nOPÇÃO: ");
			if(op==1){
				menual();
		}	
			
	}
}

void mensagem_errom(){
	system("cls");
	int op;
	printf("\nERROR:opcao invalida");
	printf("\n\n DESEJA VOLTAR PRA O MENU? 1 - SIM, 2- NAO ");
	scanf("%d",&op);
	printf("\n\nOPÇÃO: ");
	if(op==1){
		menual();
	}
}


