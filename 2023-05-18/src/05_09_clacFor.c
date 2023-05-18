#include <stdio.h>

int add(int n) {
  if (n > 0) n += add(n - 1);
  return n;
}

int main(void) {
  int sum = add(10);

  printf("sum = %d\n", sum);

  return 0;
}
