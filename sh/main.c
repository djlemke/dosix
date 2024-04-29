#include <stdio.h>
#include <unistd.h>

void zerobuf(char *buffer, int len);

int main(int argc, char* argv[]) {
	char buffer[80];
	char c;
	char prompt[] = {"$ "};
	int i;

	if (argc > 1) {
		// process command line opts
		return 0;
	}

	printf("%s", prompt);

	i = 0;
	zerobuf(&buffer, 80);
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			printf("%s\n", buffer);
			zerobuf(&buffer, 80);
			i = 0;
			printf("%s", prompt);
			continue;
		}
		buffer[i++] = c;
	}

	return 0;
}

void zerobuf(char *buffer, int len) {
	int i;

	for (i = 0; i < len; i++) {
		buffer[i] = '\0';
	}
}

