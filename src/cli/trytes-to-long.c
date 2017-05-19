#include "../lib/util/converter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRYTE_LENGTH 2673

#define HINTS "### TRYTES TO LONG ###\nUsage:\n\t trytes-to-long <Tryte string all caps> \n"

int get_stdin(char *str, int len) {

	int i = 0;
	char chr;
	struct timeval timeout;
	fd_set readfds, savefds;
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);

	savefds = readfds;

	timeout.tv_sec = 0;
	timeout.tv_usec = 0;

	if (select(1, &readfds, NULL, NULL, &timeout)) {
		while ((chr = getchar()) != EOF) {
			if (i > len) return -1;
			str[i++] = chr;
		}
	}
	readfds = savefds;
	//str[i] = 0;
	return i;
}

int main(int argc, char *argv[]) {
	char *buf;

	if (argc > 1) {
		buf = argv[1];
		//memcpy(buf, argv[1], sizeof(char)*TRYTE_LENGTH);
	} else {
		buf = malloc(27 * sizeof(char));
		if(get_stdin(buf, 27) != 0) {
			fprintf(stderr, HINTS, TRYTE_LENGTH);
			return 1;
		}
	}
	init_converter();
	size_t length = strlen(buf);
	trit_t *input = trits_from_trytes(buf, length);
	trit_t value = long_value(input, 0, length * 3);
	fprintf(stdout,"%ld", value);
	return 0;
}

