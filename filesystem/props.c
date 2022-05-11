#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("File needed\n");
    exit(-1);
  }

  struct stat data;
  char file_type[32];

  if (stat(argv[1], &data) != 0) {
    printf("Call to stat failed\n");
    exit(-1);
  }
  printf("File: %s\n", argv[1]);

  switch (data.st_mode & S_IFMT) {
  case S_IFREG:
    strcpy(file_type, "Regular file");
    break;
  case S_IFDIR:
    strcpy(file_type, "Directory");
    break;
  default:
    printf("Error, is not a file or directory");
    break;
  }

	printf("Type: %s\n", file_type);
	printf("Permissions: %o\n", data.st_mode & 0777);
	printf("Link: %lu\n", data.st_nlink);
	printf("Size: %lu\n", data.st_size);
	printf("Node: %lu\n", data.st_ino);
	printf("Last Access: %s\n", ctime(&data.st_mtime));
}
