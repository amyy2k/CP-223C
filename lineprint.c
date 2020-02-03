#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000 // Maximum input line size

int gline(char line[], int maxline);
void copy(char to[], char from[]);

int gline(char s[], int lim)
{
    int c, i, j;

  for(i = 0, j = 0; (c = getchar())!=EOF && c != '\n'; ++i) {
  if(i < lim - 1) {s[j++] = c;}
  }
    if(c == '\n') {
      if(i <= lim - 1) {
     s[j++] = c;
    ++i;
    }
  s[j] = '\0';
  return i;
}
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
// Print longest input line
int main(int argc, const char * argv[]){
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = gline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
    else
    return 0;
}
	if (max > 0) {
		printf("The max is %d:\n%s", max, longest);
	return 0;
}}}
