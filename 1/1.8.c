#include <stdio.h>

int main() {
	
	long blanks = 0L, tabs = 0L, newlines = 0L;
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			blanks++;
		else if (c == '\t')
			tabs++;
		else if (c == '\n')
			newlines++;
	}
	
	printf("Blanks: %d, tabs: %d, newlines: %d.\n", blanks, tabs, newlines);
	
	return 0;
}