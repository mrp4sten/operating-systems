#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int pipe1[2];
  pipe(pipe1);
  char s[64];

  if (fork()) {
    /* Father */
    close(pipe1[1]);
    close(0);
    dup(pipe1[0]);
    close(pipe1[0]);
		read(0, s, 64);
    printf("Im Father I have write from standard input string: %s\n", s);
  } else {
    strcpy(s, "Hello world, SO Course");
    close(pipe1[0]);
    close(1);
    dup(pipe1[1]);
    close(pipe1[1]);

    printf("%s\n", s);
  }
}
