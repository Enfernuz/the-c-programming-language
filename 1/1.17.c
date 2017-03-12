#include <stdio.h>

#define MAX_LENGTH 80

int getLine(char buf[], int maxLength);

int main() {
	
	char line[MAX_LENGTH + 1]; // fits a whole MAX_LENGTH characters line plus a terminator character
	int len;
	char c;
	
	while ((len = getLine(line, MAX_LENGTH)) > 0) { // while there's a line to read
		
		// if the line reaches the max length and doesn't end with a newline, 
		// that means the line meets the length requirement and is to be printed
		if (len == MAX_LENGTH && line[MAX_LENGTH - 1] != '\n') { 
			
			printf("[%s", line); // print the buffered part of the line
			
			// then print all the rest characters until a newline or EOF is reached
			while ((c = getchar()) != EOF && c != '\n') { 
				putchar(c);
				len++;
			}
				
			// if the line ends with a newline, increment its length by one (because we count a newline as a line's character), 
			// otherwise do not
			printf("] :: %d\n", c == '\n' ? ++len : len);
		}
	}

	return 0;
}

// gets the next line from the input stream, saves up to %maxLength% characters of the line in the %buf% array
// returns the length of the read line or 0 if there is no line to read
int getLine(char buf[], int maxLength) {
	
	char c;
	int i;
	for (i = 0; i < maxLength && (c = getchar()) != EOF && c != '\n'; i++) {
		buf[i] = c;
	}
	
	if (c == '\n')
		buf[i++] = '\n';
	
	buf[i] = '\0';
	
	return i;
}