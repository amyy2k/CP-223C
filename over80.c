#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000
#define LIMIT 80


int gline(char line[],int lim);

int main(int argc, const char * argv[]){

  int length;
  char line[MAXLINE];

  while((length = gline(line,MAXLINE)) > 0) {
    if( length > LIMIT ){
      printf("%s",line);
    }
  }
  return 0;
}

int gline(char s[],int lim) {
 int c, i;
 for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
 s[i] = c;
 if (c == '\n') {
 s[i] = c;
 ++i;
 }
 s[i] = '\0';
 return i;
 }
