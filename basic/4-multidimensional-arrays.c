#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char c[][8] = {"Hello", "Message"};
	printf("%s\n", c[0]);
	printf("%s\n", c[1]);
}
