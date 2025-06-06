#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char* name; 
	int age;
} Person;

#define STRING_SIZE 20
#define ADD 0
#define SUBTRACTION 1
#define MULTIPLICATION 2
#define DIVISION 3

int add (int a, int b) {
	return a + b;
	}
	
int sub (int a, int b) {
	return a - b;
}

int mult (int a, int b) {
	return a * b;
}

int division (int a, int b) {
	return a / b;
}

	
void insert_names (char** names, int hmany) {
	for(int i = 0; i < hmany; i++) {
		names[i] = malloc(sizeof(char) * STRING_SIZE);	
	}
	//test
	strcpy(names[0], "MARIA");
	strcpy(names[1], "JOSEPH");
	strcpy(names[2], "JORGE");
	strcpy(names[3], "ARTHUR");
	strcpy(names[4], "LEVI");	
}


int main() {
	
	printf(" \n --- Party of Pointers --- \n\n");
	// Variavel -> Endereço e Valor (Ex: 20)
	// Ponteiro -> Endereço e Valor (Recebe o endereço de outra Variavel)
	
	
	// --- Ponteiro Simples ---
	int num = 20;
	printf (" num = %d\n", num);
	
	int *ptr = &num; // & Operador de referência (Exibe o endereço)
	*ptr = 40; // Alterando o valor da variavel 'num' pelo ponteiro que tem o endereço
	
	printf (" num = %d\n", num);
	
	// --- Ponteiro para String ---
	char *string = malloc(sizeof(char)*23); // Aponta para o primeiro caractere da array
	strcpy(string, "You're the best around");
	printf(" string = %s\n", string);
	free(string); // Liberar espaço
	
	// --- Ponteiro para Struct ---
	
	// Com o typedef, Person vira um 'apelido' para um tipo (definido nesse caso como struct)
	// Declaração de um ponteiro do tipo struct:
	// '->' sintaxe para ponteiros em struct, nesse caso '*char'
	Person *person = malloc(sizeof(Person));
	person->age = 40;
	person->name = malloc(sizeof(char) *5);
	strcpy(person->name, "JOHN");
	
	printf(" Name:%s, Age:%d\n", person->name, person->age);
	
	//Para liberar a memoria ocupada pela struct, primeiro libera a das variaveis
	//depois a da struct, caso contrário, o endereço das variaveis será perdido sem liberar a memoria
	
	free(person->name);
	free(person);
	
	//nota: free foi usado nas variaveis que pediram malloc
	
	// --- Ponteiro para função ---
	
	//Ponteiro para função add
	int (*func)(int, int) = add;
	
	printf(" Result: %d\n", add(5,10));
	printf(" Result: %d\n", func(10,12));
	
	// --- Ponteiro para ponteiros ---
	int hmany = 5;
	char **names = malloc(sizeof(char*) * hmany); 
	insert_names(names, hmany);
	for (int i = 0; i < hmany; i++) {
		printf(" name[%d] = %s\n", i, names[i]);
		free(names[i]);
	}
	free(names);
	
	//Ponteiro para ponteiros de função
	int (*funcs[])(int, int) = { add, sub, mult, division };
	
	for (int i = 0; i < 4; i++) {
			printf(" Result[%d] = %d\n", i, funcs[i](10,20));
	}
	
	int test = funcs[ADD](20,25);
	int test1 = funcs[DIVISION](6,2);
	int test2 = funcs[MULTIPLICATION](2,2);
	int test3 = funcs[SUBTRACTION](100,20);
	
	
	printf(" %d\n", test);
	printf(" %d\n", test1);
	printf(" %d\n", test2);
	printf(" %d\n", test3);
	
	printf("\n");
	
	printf(" End\n");
	
	return 0;
}

