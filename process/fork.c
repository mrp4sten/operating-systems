#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int var = 1;
  for (int i = 0; i < 4; i++) {
    int result = fork();
    if (result != 0) {
      var++;
			break;
    } else {
      var += 2;
    }

    printf("Process: %i, Father: %i, Value: %i\n", getpid(), getppid(), var);
  }
}
