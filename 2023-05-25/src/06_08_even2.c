#include <stdio.h>

int main(void) {
  for (int i = 0; i <= 10; i += 1) {
    if (i % 2) printf("%d\n", i);
  }

  return 0;
}
