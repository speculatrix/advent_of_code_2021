/* solve_3.c */

#include <stdlib.h>
#include <stdio.h>

#define INPUT_3 "3_input.txt"

int main(int argc, char *argv[]) {
	printf("hello world\n");

	FILE	*fp_in;
	char	*input_line = NULL;
	size_t	input_len = 0;

	if (fp_in = fopen(INPUT_3, "r")) {
		while (getline(&input_line, &input_len, fp_in) != -1) {

			printf("input_line %s\n", input_line);
		}

		// split input line
	}
	else {
		printf("Error, failed to open file %s for reading", INPUT_3);
		exit(1);
	}

	return(0);
}
