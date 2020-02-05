#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void removeComment(char *c){
       int a, b;

       for(a=b=0; c[b] ;){
              if(c[b]=='/' && c[b+1] == '/') {for(b= b+2; c[b] && c[b++]!= '\n';) ; }
              else if (c[b] == '/' && c[b+1] == '*'){
                     for(b=b+2; c[b] && c[++b] && (c[b-1]!='*' || c[b]!='/' || !b++); );
              }
              else {c[a++] = c[b++];}
       }
       c[a]='\0';
}

int main(int argc, const char * argv[]) {

char c[]="Testing //test1 /*test2***/  123\n";

removeComment(c);

printf("%s", c);
return 0;
}
