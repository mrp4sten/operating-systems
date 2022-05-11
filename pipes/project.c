#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int pipe1[2], pipe2[2];
  pipe(pipe2);

  if (fork()) {
    /* Grandfather sort */
    close(pipe2[1]);
    close(0);
    dup(pipe2[0]);
    close(pipe2[0]);

    execlp("sort", "sort", "-u", NULL);
    printf("Error sort\n");
  } else {
    pipe(pipe1);
    if (fork()) {
      /* Father cut*/

      /* stdin */
      close(pipe1[1]);
      close(0);
      dup(pipe1[0]);
      close(pipe1[0]);

      /* stdout */
      close(pipe2[0]);
      close(1);
      dup(pipe2[1]);
      close(pipe2[1]);

      execlp("cut", "cut", "-c5-12", NULL);
      printf("Error cut\n");

    } else {
      /* Chidren ps */
      close(pipe2[0]);
      close(pipe2[1]);

      close(pipe1[0]);
      close(1);
      dup(pipe1[1]);
      close(pipe1[1]);

      execlp("ps", "ps", "-efl", NULL);
      printf("Error ps\n");
    }
  }
}
