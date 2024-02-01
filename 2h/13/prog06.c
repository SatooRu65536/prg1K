#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct melem {
  char name[64];
  int height;
  int weight;
  struct melem *next;
} Melem;

void printMelem(Melem *root) {
  printf("%s %d %d\n", root->name, root->height, root->weight);
  if (root->next != NULL) printMelem(root->next);
}

Melem *addMelem(Melem *root, char *name, int height, int weight) {
  Melem *next = root;
  Melem *prev = NULL;

  // ここでprevとnextを決める。
  while (next != NULL) {
    if (strcmp(next->name, name) > 0) break;
    prev = next;
    next = next->next;
  }

  Melem *new = (Melem *)malloc(sizeof(Melem));

  strcpy(new->name, name);
  new->height = height;
  new->weight = weight;

  new->next = next;
  if (prev == NULL) return new;

  new->next = next;
  prev->next = new;
  return root;
}

void freeMelem(Melem *root) {
  if (root->next != NULL) freeMelem(root->next);
  free(root);
}

int main(void) {
  Melem *root = NULL;

  root = addMelem(root, "bbb", 180, 70);
  root = addMelem(root, "aaa", 170, 60);
  root = addMelem(root, "ccc", 190, 80);

  printMelem(root);

  freeMelem(root);

  return 0;
}