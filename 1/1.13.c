#include <stdio.h>

#define IN 1
#define OUT 0
#define THRESHOLD 10

int main() {
	
	int wordsByLength[THRESHOLD + 1];
	for (int i = 0; i < THRESHOLD + 1; i++) {
		wordsByLength[i] = 0;
	}
	
	int c, state = OUT, currentWordLength = 0, maxCount = 0, count = 0;
	while ((c = getchar()) != EOF) {
		
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				state = OUT;
				count = (currentWordLength > THRESHOLD) ? ++wordsByLength[THRESHOLD] : ++wordsByLength[currentWordLength - 1];
				if (count > maxCount)
					maxCount = count;
				currentWordLength = 0;
			}
		} else {
			if (state == OUT)
				state = IN;
			currentWordLength++;
		}
	}
	
	if (currentWordLength > 0) {
		count = (currentWordLength > THRESHOLD) ? ++wordsByLength[THRESHOLD] : ++wordsByLength[currentWordLength - 1];
		if (count > maxCount)
			maxCount = count;
	}
	
	for (int i = maxCount; i > 0; i--) {
		printf("%3d ", i);
		for (int j = 0; j < THRESHOLD + 1; j++) {
			if (wordsByLength[j] >= i)
				printf("  *");
			else
				printf("  -");
		}
		putchar('\n');
	}
	
	printf("     ");
	for (int i = 0; i < THRESHOLD; i++) {
		printf("%2d ", i);
	}
	
	printf("%2d+", THRESHOLD);
	
	putchar('\n');
	
	return 0;
}