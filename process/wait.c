#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int result = fork();
  if (result < 0) {
    printf("Fork call failed\n");
    exit(-1);
  }

  if (result != 0) {
    printf("Im father, Im going to execute ps, but before I wait children\n");
    wait(NULL);
    printf("Executing ps\n");
  } else {
    printf("Im children, Im going to execute ls\n");
  }
}
