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
	// test
	strcpy(names[0], "MARIA");
	strcpy(names[1], "JOSEPH");
	strcpy(names[2], "JORGE");
	strcpy(names[3], "ARTHUR");
	strcpy(names[4], "LEVI");	
}

int main() {
	
	printf(" \n --- Party of Pointers --- \n\n");
	// Variable -> Address and Value (e.g., 20)
	// Pointer -> Address and Value (Holds the address of another variable)
	
	// --- Simple Pointer ---
	int num = 20;
	printf (" num = %d\n", num);
	
	int *ptr = &num; // & Reference operator (Shows the address)
	*ptr = 40; // Modifying the value of the 'num' variable through the pointer
	
	printf (" num = %d\n", num);
	
	// --- Pointer to String ---
	char *string = malloc(sizeof(char)*23); // Points to the first character of the array
	strcpy(string, "You're the best around");
	printf(" string = %s\n", string);
	free(string); // Free memory
	
	// --- Pointer to Struct ---
	
	// With typedef, Person becomes an 'alias' for a type (in this case defined as struct)
	// Declaration of a pointer of struct type:
	// '->' syntax for struct pointers, in this case '*char'
	Person *person = malloc(sizeof(Person));
	person->age = 40;
	person->name = malloc(sizeof(char) *5);
	strcpy(person->name, "JOHN");
	
	printf(" Name:%s, Age:%d\n", person->name, person->age);
	
	// To free the memory used by the struct, first free the struct's variables
	// then the struct itself. Otherwise, the address of the variables will be lost without freeing memory
	
	free(person->name);
	free(person);
	
	// note: free was used on the variables that used malloc

	
	return 0;
}

