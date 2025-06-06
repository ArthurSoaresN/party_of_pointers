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

	
	return 0;
}

