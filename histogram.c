#include <stdio.h>
#define IN 1 //inside a word
#define OUT 0 // outside a word
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LEN 25

int main(int argc, const char * argv[]){


  char wordbuf[50];
  int index = 0;
  int lim = 0;
  long nc, nl, nw;
  int c, state = OUT;
  nc= nl= nw = 0;
  int words[MAX_WORD_LEN];
  memset(words, 0, sizeof(words));

  while ((c = getchar()) != EOF){
    ++nc;
    if (isalpha(c)){ wordbuf[index++] = c;}//c (0) ca(1) cat (2)

    if (c== '\n') { ++nl;}
    if (c == ' ' || c == '\n' || c == '\t') { state = OUT;}
    else if (state == OUT) {
      state = IN;
      ++nw;
      words[index]++;
      wordbuf[0] = wordbuf[index];
      index = 0;
    }
  }
  for( int i = 1; i <= MAX_WORD_LEN; ++i){
    printf("%3d: ", i);
    for (int j = 0; j < words[i]; ++j){
      printf("*");
    }
    printf("\n");
    }

  for (int i = 1; i <=MAX_WORD_LEN; ++i){
    if(words[i] > lim){lim = words[i];}
}
for(int i = 1; i <= lim; ++i){
  for(int j = 1; j<= MAX_WORD_LEN; ++j){
    if(words[j] >= lim){
      printf("*");
    }
    else {printf(" ");}
  }
  for (i = 1; i <= MAX_WORD_LEN; ++i) {
    printf(" %3d ", i);
}
  printf("\n");
}

  return 0;
  }
