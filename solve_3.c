/* solve_3.c */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INPUT_3 "3_input.txt"

// expected length of each input string
#define INPUT_STR_LEN 12

int main(int argc, char *argv[]) {
	int	count_zeroes[INPUT_STR_LEN];
	int	count_ones[INPUT_STR_LEN];
	int	count_lines = 0;
	unsigned long gamma_rate = 0L;
	unsigned long epsilon_rate = 0L;

	FILE	*fp_in;
	char	*input_line = NULL;
	size_t	input_len = 0;


	// don't assume array of counts is zero
	for (int pos=0; pos < INPUT_STR_LEN; pos++) {
		count_zeroes[pos] = 1;
		count_ones[pos] = 1;
	}

	if (fp_in = fopen(INPUT_3, "r")) {
		while (getline(&input_line, &input_len, fp_in) != -1) {

			//printf("input_line %s\n", input_line);

			if (strlen(input_line) > INPUT_STR_LEN + 1) {
				printf("Error, input line was longer than expected %d at %d chars", INPUT_STR_LEN, strlen(input_line));
				exit(1);
			}

			// scan the string for 0's and 1's
			for (int pos=0; pos < INPUT_STR_LEN; pos++) {
				if (input_line[pos] == '0') {
					count_zeroes[pos]++;
				} else if (input_line[pos] == '1') {
					count_ones[pos]++;
				} else
					printf("Error, line %d char position %d unexpected value %c\n", count_lines, pos, input_line[pos]);
			}

			count_lines++;
		}
		if (input_line) free(input_line);
		fclose(fp_in);

		// scan the counts
		for (int pos=0; pos < INPUT_STR_LEN; pos++) {
			printf("Pos %d zeroes count %d\n", pos, count_zeroes[pos]);
			printf("Pos %d ones count %d\n", pos, count_ones[pos]);

			if (count_zeroes[pos] < count_ones[pos]) {
				gamma_rate = (gamma_rate << 1) + 1;	// shift and set LSBit
				epsilon_rate = epsilon_rate << 1;	// shift
			} else {
				gamma_rate = gamma_rate << 1;		// shift
				epsilon_rate = (epsilon_rate << 1) + 1;	// shift and set LSBit
			}
		}
	}
	else {
		printf("Error, failed to open file %s for reading", INPUT_3);
		exit(1);
	}

	printf("Total lines %d\n", count_lines);
	printf("gamma rate %lu\n", gamma_rate);
	printf("epsilon rate %lu\n", epsilon_rate);
	printf("gamma x epsilon %lu\n", gamma_rate * epsilon_rate);
	return(0);
}
