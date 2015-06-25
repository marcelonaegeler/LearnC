/* main.c */
#include <stdio.h>

struct person {
	int id, age;
	char name[25];
} client[50];
int personIndex = 0;

int menu() {
	int option = 0;
	printf("Escolha uma opção: \n");
	printf("1. Cadastrar\n");
	printf("2. Listar\n");
	printf("0. Sair\n");

	scanf("%d", &option);
	printf("\n");
	return option;
};

int cadastrar() {
	if(personIndex >= 49)
		return 1;

	printf("Insira a ID: ");
    scanf("%d", &client[personIndex].id);

	printf("Insira o nome: ");
    scanf("%s", &client[personIndex].name);

    printf("Insira a idade: ");
    scanf("%d", &client[personIndex].age);

    personIndex++;
	return 0;
};

int listar() {
	if(personIndex == 0)
		return 1;

	printf("ID\t| Nome\t| Idade\n");
	for(int i = 0; i < personIndex; i++) {
		printf("%d\t| %s\t| %d\n", client[i].id, client[i].name, client[i].age);
	}
	printf("Fim da lista\n\n");

	return 0;
}

int main() {
	int work = 1;
	printf("\n--- Cadastro de clientes ---\n\n");

	while(work == 1) {
		int option = menu();

		if(option == 0) {
			work = 0;
			break;
		} else if(option == 1) {
			int cadastro = cadastrar();
			if(cadastro == 0)
				printf("Cadastro efetuado!\n\n");
			else
				printf("Erro ao cadastrar: lista cheia.\n\n");
		} else if(option == 2) {
			int list = listar();
			if(list != 0)
				printf("Lista vazia!\n\n");
		}

	}

	return 0;
}
