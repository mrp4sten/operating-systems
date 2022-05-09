#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *next;
};

int main() {
  struct Node *head = malloc(sizeof(struct Node));
  head->value = 1;
  head->next = malloc(sizeof(struct Node));
  head->next->value = 2;

  printf("First node direction: %p\n", head);
  printf("First node value: %i\n", head->value);
  printf("Second node direction: %p\n", head->next);
  printf("Second node value: %i\n", head->next->value);
}
