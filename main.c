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

int main() {
	
	return 0;
}

