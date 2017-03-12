#include <stdio.h>

#define MAXLINE 25	/* maximum input line size */

int getline(char line[], int maxline);

void copy(char to[], char from[]);

/* print longest input line */
int main() {
	
	int len; 		/* current line length */
	int max; 		/* maximum length seen so far */
	int exceedingLineLength; /* current known length of the line exceeding the length limit */
	char line[MAXLINE]; 	/* current input line */
	char longest[MAXLINE]; 	/* longest line saved here */
	char temp[MAXLINE]; 	/* current length-exceeding line saved here */
	
	exceedingLineLength = 0;
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) {

		if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n') { // if the line is not ending with a newline
			
			if ((exceedingLineLength += len) == len)
				copy(temp, line);
		} else {
			
			if (exceedingLineLength > 0) {
				
				if ((exceedingLineLength += len) > max) {
					max = exceedingLineLength;
					copy(longest, temp);
				}
				exceedingLineLength = 0;
			} else {
				
				if (len > max) {
					max = len;
					copy(longest, line);
				}
			}
		}
	}
	
	if (max > 0) { 	/* there was a line */
		printf("Longest line length: %d\n", max);
		printf("Longest line begins with: %s\n", longest);
	}
		
	
	return 0;
}

/* getline:		read a line into s, return length */
int getline(char s[], int lim) {
	
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) 
		s[i] = c;
	
	if (c == '\n') {
		s[i++] = c;
	}
	
	s[i] = '\0';
	
	return i;
}

/* copy:	copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[]) {
	
	for (int i = 0; (to[i] = from[i]) != '\0'; i++);
}