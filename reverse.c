#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000

int gline(char line[],int lim);
void reverse(char s[]);

int gline(char s[],int lim) {
  int i,c;
  for(i=0;i<lim-1 &&(c=getchar())!=EOF && c != '\n';++i)
    s[i] = c;
  if( c == '\n') {
    s[i] = c;
    ++i;
  }
  else { s[i] = '\0'; }
  return i;
}

void reverse(char s[]) {
  int i,j;
  char temp;

  for(i=0 ; s[i]!='\0' ; ++i)
  ;
  --i;
  if(s[i]=='\n')
  --i;
  j = 0;

  while(j < i) {
    temp = s[j];
    s[j] = s[i];
    s[i] = temp;
    ++j;
    --i;
  }
}


int main(int argc, const char * argv[]){
  int size;
  char line[MAXLINE];

  while((size=gline(line,MAXLINE))>0) {
    reverse(line);
    printf("%s",line);
  }
  return 0;
}
