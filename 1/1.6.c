#include <stdio.h>

int main() {
	
	int result = (getchar() != EOF);
	if (result == 0 || result == 1) {
		printf("Myth confirmed.\n");
	} else {
		printf("Myth busted.\n");
	}
	
	return 0;
}