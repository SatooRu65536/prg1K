#include <stdio.h>

int main(void) {
  double arr[3] = {1.1, 2.1, 3.1};

  for (int i = 0; i < 3; i++) {
    printf("%p\n", &arr[i]);
  }

  return 0;
}