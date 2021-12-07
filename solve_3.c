/* solve_3.c */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INPUT_3 "3_input.txt"

// expected length of each input string
#define INPUT_STR_LEN 12

int main(int argc, char *argv[]) {
	int	count_zeroes[12];
	int	count_ones[12];
	int	count_lines = 0;

	FILE	*fp_in;
	char	*input_line = NULL;
	size_t	input_len = 0;

	if (fp_in = fopen(INPUT_3, "r")) {
		while (getline(&input_line, &input_len, fp_in) != -1) {

			printf("input_line %s\n", input_line);

			if (strlen(input_line) > INPUT_STR_LEN + 1) {
				printf("Error, input line was longer than expected %d at %d chars", INPUT_STR_LEN, strlen(input_line));
				exit(1);
			}

			count_lines++;
		}
		if (input_line) free(input_line);
		fclose(fp_in);
	}
	else {
		printf("Error, failed to open file %s for reading", INPUT_3);
		exit(1);
	}

	printf("Total lines %d\n", count_lines);
	return(0);
}
