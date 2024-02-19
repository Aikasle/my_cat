#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
	int i;
	int ret = 0;
	for (i = 1; i < argc; i++) {
		FILE *fp;
		fp = fopen(argv[i], "r");
		if (fp == NULL) {
			fprintf(stderr, "El fichero %s no existe o no se puede abrrir\n", argv[i]);
			ret = 1;
			continue;
		}
		char buffer[100];

		while(fgets(buffer, 100, fp) != NULL) {
		  printf("%s", buffer);
		}
		fclose(fp);	
	}

	char buffer[100];
	FILE *line = 0;
	int first = 1;
	if (argc == 1) {
		while(line != NULL || first) {
			//scanf("%s", buffer);
			first = 0;
			line = fgets(buffer, 100, stdin);
			printf("%s", buffer);
		}
	}
	return ret;


}
