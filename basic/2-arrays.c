#include <stdio.h>
#include <stdlib.h>

int main() {
	/* Declaring ponter with a specific memory sice */
  int *array = malloc(sizeof(int) * 8);
  for (int i = 0; i < 8; i++) {
    array[i] = i + 1;
  }

  for (int i = 0; i < 8; i++) {
    printf("Value of array[%i] = %i\n", i, array[i]);
  }

	/* Free memory */
	free(array);
}
