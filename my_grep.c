#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {

    if (argc == 1) {
	    printf("Two little arguments");
	    return 1;
    } 

    int l = strlen(argv[1]);
    if (argc == 2) {
	char buffer[100];
	FILE *line = 0;
	while(line != NULL || line == 0) {
		line = fgets(buffer, 100, stdin);
		int i, j;
		for (i = 0; i < 100; i++) {
			int same = 1;
			for (j = 0; j <  l && i+j < 100; j++) {
				same &= buffer[i+j] == argv[1][j];
				if (!same)
					break;
			}

			if (same && j >= 1) {
				printf("%s", line);
				break;

			}
		}
	}
    }

    if (argc == 3) {
	    FILE *fp;
	    char *line = NULL;
	    size_t len = 0;
	    ssize_t read;
	    fp = fopen(argv[2], "r");

	    if (fp == NULL)
		exit(EXIT_FAILURE);

	   while ((read = getline(&line, &len, fp)) != -1) {
		int i, j;
		for (i = 0; i < (int)read; i++) {
			int same = 1;
			for (j = 0; j <  l && i+j < (int)read; j++) {
				same &= line[i+j] == argv[1][j];
				//printf("%d", same);
				if (!same)
					break;
			}

			if (same && j >= 1) {
				printf("%s", line);
				break;

			}
		}

	    }

	   free(line);
	    exit(EXIT_SUCCESS);
    }
}


