#include <stdio.h>

int main() {
	
	int c = getchar();
	while (c != EOF) {
		
		putchar(c);
		if (c == ' ') {
			while ((c = getchar()) == ' '); // skip all the following whitespaces
		} else
			c = getchar();
		
	}
	
	return 0;
}