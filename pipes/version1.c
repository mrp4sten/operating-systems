#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int pipe1[2];
  pipe(pipe1);
  char c = 'X';

  if (fork()) {
    /* Father */
    close(pipe1[1]);
    read(3, &c, sizeof(c));
    close(pipe1[0]);
    printf("Im Father I have write from descriptor %i character: %c\n",
           pipe1[0], c);
  } else {
    /* Children */
    c = 'A';
    close(pipe1[0]);
    write(4, &c, sizeof(c));
    close(pipe1[1]);
    printf("Im Children I have write into descriptor %i character: %c\n",
           pipe1[1], c);
  }
}
