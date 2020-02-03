#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 180

int main(int argc, const char * argv[]) {
  int c, n;
  int charNum[MAX];
  
  for (int i = 0; i < MAX; ++i)
      charNum[i] = 0;
  while ((c = getchar()) != EOF) {
      ++charNum[c - ' '];
      if (c == '\n') {
          for (int i = 0; i < MAX; i++)
              if (charNum[i] != 0) {
                  printf("%c: ", i + ' ');
                  for (n = 0; n < charNum[i]; n++) {
                      printf("*");
                  }
                  printf("\n");
              }
          for (int i = 0; i < MAX; ++i)
              charNum[i] = 0;
      }
  }
}
