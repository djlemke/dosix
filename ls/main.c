#include <direct.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
        DIR *dir;
        struct dirent *entry;

        if (argc < 2)
                dir = opendir(".");
        else
                dir = opendir(argv[1]);

	if (dir == NULL) {
		if (errno != EZERO)
			printf("Error: %s\n", strerror(errno));

		return errno;
	}

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] == '.')
			continue;

		if (entry->d_attr & _A_SUBDIR)
			printf("%s/\n", entry->d_name);
		else
			printf("%s\n", entry->d_name);
	}

	closedir(dir);

        return 0;
}

