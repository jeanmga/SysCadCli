// Sistema de Cadastro de Clientes
// Desenvolvido por Jean Carlo Angeli
// (44) 99865-1993


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TAM 99

char nome[50];
char cpf[15];
char endereco[50];
char cidade[20];
char uf[3];  
char fone[16]; 
int opcao = 0;
int setor;
	
void logo(){
	printf("#################################################\n");	
	printf("      >>>>>  SysCadCli - Versao 3.0  <<<<<\n");
	printf("#################################################\n");
	printf("\nCarregando...\n");
}


void barraProgresso(){
	int i = 0;		
	while (i < 11){
		if (i == 0){
			logo();
			printf("|                       0%%                       |");
		}
		if (i ==1){
			logo();
			printf("||||||                  10%%                      |");
		}
		if (i ==2){
			logo();
			printf("|||||||||||             20%%                      |");
		}
		if (i ==3){
			logo();
			printf("||||||||||||||||        30%%                      |");
		}
		if (i ==4){
			logo();
			printf("|||||||||||||||||||||   40%%                      |");
		}
		if (i ==5){
			logo();
			printf("||||||||||||||||||||||||50%%                      |");
		}
		if (i ==6){
			logo();
			printf("||||||||||||||||||||||||60%%|||||                 |");
		}
		if (i ==7){
			logo();
			printf("||||||||||||||||||||||||70%%||||||||||            |");
		}
		if (i ==8){
			logo();
			printf("||||||||||||||||||||||||80%%|||||||||||||||       |");
		}
		if (i ==9){
			logo();
			printf("||||||||||||||||||||||||90%%|||||||||||||||||||   |");
		}
		if (i ==10){
			logo();
			printf("|||||||||||||||||||||||100%%|||||||||||||||||||||||");
		}		
		Sleep(300);	
		i++;		
		system("cls");
	}
}


/*
void salvarRegistro(){
    FILE *arquivo;
    char linha[256]; 
    int id;
    arquivo = fopen("registro.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%d", &id); // Extrair o Id da linha
    }
	id++;
    fclose(arquivo);
    arquivo = fopen("registro.csv", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura");
		}
	fprintf(arquivo, "\n");	
	fprintf(arquivo, "%i" ";", id);
	fprintf(arquivo, "%s" ";", nome);
	fprintf(arquivo, "%s" ";", cpf);
	fprintf(arquivo, "%s" ";", endereco);
	fprintf(arquivo, "%s" ";", cidade);	
	fprintf(arquivo, "%s" ";", uf);
	fprintf(arquivo, "%s", fone);
    fclose(arquivo);   
	}

*/


void incluir(){			
	printf("+----------------------------------------+\n");
	printf("|         Incluir novo cliente:          |\n");
	printf("+----------------------------------------+\n");
	fflush(stdin);
	printf("Nome: ");
	scanf("%50[^\n]s", &nome);
	fflush(stdin);
	printf("CPF: ");
	scanf("%s", &cpf);
	fflush(stdin);
	printf("Endereço: ");
	scanf("%50[^\n]s", &endereco);
	fflush(stdin);
	printf("Cidade: ");
	scanf("%19[^\n]s", &cidade);
	fflush(stdin);
	printf("UF: ");
	scanf("%s", &uf);
	fflush(stdin);
	printf("Fone: ");
	scanf("%s", &fone);
	fflush(stdin);
	printf("Nome: " "%s\n", nome);
	printf("CPF: " "%s\n", cpf);
	printf("Endereco: " "%s\n", endereco);
	printf("Cidade: " "%s\n", cidade);
	printf("UF: " "%s\n", uf);
	printf("Fone: " "%s\n", fone);
	fflush(stdin);
	
// = SALVAR DADOS EM ARQUIVO
//	salvarRegistro();	
	FILE *arquivo;
    char linha[256]; 
    int id;
    arquivo = fopen("registro.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%d", &id); // Extrair o Id da linha
    }
	id++;
    fclose(arquivo);
    arquivo = fopen("registro.csv", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura");
		}
	fprintf(arquivo, "\n");	
	fprintf(arquivo, "%i" ";", id);
	fprintf(arquivo, "%s" ";", nome);
	fprintf(arquivo, "%s" ";", cpf);
	fprintf(arquivo, "%s" ";", endereco);
	fprintf(arquivo, "%s" ";", cidade);	
	fprintf(arquivo, "%s" ";", uf);
	fprintf(arquivo, "%s", fone);
    fclose(arquivo); 		
	printf("Registro cadastrado com sucesso!\n");
	system("pause");
	system("cls");
}

void listar(){
    FILE *arquivo;
    char linha[256]; 
    int id;
    char nome[50];
    char cpf[15];
	char endereco[50];
	char cidade[20];
	char uf[3];  
    char fone[16];   

    arquivo = fopen("registro.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    printf("+-------------------------------------------------------------------------------------------------------------------------+\n");    
    printf("| %-3s | %-25s | %-15s | %-25s | %-15s | %-3s | %-15s |\n", "Id", "Nome", "Cpf", "Endereço", "Cidade", "UF", "Fone");
    printf("+-------------------------------------------------------------------------------------------------------------------------+\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%d;%49[^;];%14[^;];%49[^;];%19[^;];%2[^;];%15s\n", &id, nome, cpf, endereco, cidade, uf, fone);
        printf("| %-3d | %-25s | %-15s | %-25s | %-15s | %-3s | %-15s |\n", id, nome, cpf, endereco, cidade, uf, fone);
    }

    fclose(arquivo);   
	printf("+-------------------------------------------------------------------------------------------------------------------------+\n");
    fclose(arquivo);
    system("pause");
    system("cls");	
}


int excluirRegistro() {
    FILE *arquivoEntrada, *arquivoTemporario;
    char linha[1024]; 
    int idParaExcluir; 
	printf("Digite o ID que deseja EXCLUIR: ");
	scanf("%d", &idParaExcluir);

    arquivoEntrada = fopen("registro.csv", "r");
    if (arquivoEntrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada para leitura");
        return 1;
    }

    arquivoTemporario = fopen("temporario.csv", "w");
    if (arquivoTemporario == NULL) {
        perror("Erro ao abrir o arquivo temporário para escrita");
        fclose(arquivoEntrada);
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL) {
        int idNaLinha;
        sscanf(linha, "%d,", &idNaLinha);
        if (idNaLinha != idParaExcluir) {
            fprintf(arquivoTemporario, "%s", linha);
        }
    }

    fclose(arquivoEntrada);
    fclose(arquivoTemporario);

    remove("registro.csv");

    rename("temporario.csv", "registro.csv");

    printf("Registro Id %d excluído com sucesso.\n", idParaExcluir);
    
    printf("\n");
	system("pause");
	system("cls");

    return 0;
}

int main(){
	setlocale(LC_ALL, "");	
	barraProgresso();
	while(opcao < 4){
		printf("+----------------------------------------+\n");
		printf("|    Sistema de Cadastro de Clientes     |\n");
		printf("+----------------------------------------+\n");
		printf("| [1] - Cadastrar Cliente                |\n");
		printf("| [2] - Listar Clientes                  |\n");
		printf("| [3] - Excluir Cliente                  |\n");
		printf("| [4] - Sair                             |\n");
		printf("+----------------------------------------+\n");
		scanf("%d", &opcao);
	
		switch(opcao){
			case 1: printf("Cadastrar Cliente:\n");
				incluir();
				break;
			case 2: printf("Listagem de Clientes:\n");	
				listar();			
				break;
			case 3: printf("Excluir Cliente\n");	
				excluirRegistro();		
				break;
			case 4: printf("Sair\n");
				break;
			default: printf("Opção inválida!\n");
				opcao = 0;
				break;
		}
	}	
}
