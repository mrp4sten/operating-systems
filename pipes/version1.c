#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
  int pipe1[2];
  pipe(pipe1);
  char s[64];

  if (fork()) {
    /* Father */
    close(pipe1[1]);
    read(pipe1[0], s, 64);
    close(pipe1[0]);
    printf("Im Father I have write from descriptor %i string: %s\n",
           pipe1[0], s);
  } else {
    /* Children */
		strcpy(s, "Hello world, SO Course");
    close(pipe1[0]);
    write(pipe1[1], s, strlen(s));
    close(pipe1[1]);
    printf("Im Children I have write into descriptor %i string: %s\n",
           pipe1[1], s);
  }
}
