#include <stdio.h>

int main() {
	int a = 5;
	int *pointer_a = &a;
	int *another_pointer = pointer_a;
	printf("Value of pointer: %p\n", pointer_a);
	printf("Value where point pointer: %i\n", *pointer_a);
	printf("Value of another pointer: %p\n", another_pointer);
}
