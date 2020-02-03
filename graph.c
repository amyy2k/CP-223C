#include <stdio.h>
#define IN 1 //inside a word
#define OUT 0 // outside a word
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LEN 25

int main(int argc, const char * argv[]){
char wordbuf[1000];
int index = 0;
long nc, nl, nw;
int c, state = OUT;
nc= nl= nw = 0;
int words[MAX_WORD_LEN];
memset(words, 0, sizeof(words));

int i = 0;
while ((c = getchar()) != EOF){
  if (c == ' ' || c == '\n' || c == '\t') { printf("\n");}
  else { printf("*");}
  }
return 0;
}
