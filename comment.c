#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "files.h"

#define MAX 80


bool open_io_files(int argc, const char* argv[], FILE** fin, FILE** fout,
                   int min_expected_argc, int max_expected_argc,
                   const char* usage) {
  /* open an input file, and optionally an output file */
  if (argc < min_expected_argc || argc > max_expected_argc) {
    fprintf(stderr, "%s\n", usage);
    return false;
  }

  *fin = fopen(argv[1], "r");
  if (*fin == NULL) {
    fprintf(stderr, "failed to open input file: '%s'\n", argv[1]);
    return false;
  }
            // In this case, we don't want to open output file
  if (fout == NULL) {  return true; }  // everything cool

  *fout = fopen(argv[2], "w");
  if (*fout == NULL) {  // output file failed to open
    fprintf(stderr, "failed to open output file: '%s'\n", argv[2]);
    fprintf(stderr, "closing already open input file: '%s'\n", argv[1]);
    fclose(*fin);
    return false;
  }

  return true;
}


void closefiles(int n, ...) {   // uses varargs (variable # of args)
  va_list pargs;
  va_start (pargs, n);    // initialize the list ptr

  for (int i = 0; i < n; i++)
    fclose(va_arg (pargs, FILE*));  // get next argument

  va_end (pargs);   // clean up
}


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
FILE* fin;
FILE* fout;
int i = 0;
int c = 0;
char file[MAX];

while((c = fgetc(fin))!=EOF && i < MAX){
file[i] = fgetc(fin);
++i;
}
removeComment(file);
fputs(file, fout);
closefiles(2, fin, fout);
return 0;
}
