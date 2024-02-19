#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv) {
	int i;
	int ret = 0;

	if (argc != 3)
		fprintf(stderr, "Los arguntos no son los correctos. Recuerda: my_cp [file_to_copy] [new_path/path_to_folder]\n");

	FILE *fp;
	fp = fopen(argv[1], "r");

	if (fp == NULL) {
		fprintf(stderr, "El fichero '%s' no existe o no se puede abrrir\n", argv[i]);
		return 1;
	}
	char buffer[100];


	FILE *new_fp;
	new_fp = fopen(argv[2], "w+");

	if (new_fp == NULL) {
		char new_path[256];
		strcpy(new_path, argv[2]);
		new_path[strlen(argv[2])] = '/';
		strcpy(new_path+strlen(argv[2])+1, argv[1]);
		new_fp = fopen(new_path, "w+");
	}


	if (new_fp == NULL) {
		fprintf(stderr, "'%s' no es un destino aceptable\n", argv[i]);
		return 1;
	}

	while(fgets(buffer, 100, fp) != NULL) {
	  fprintf(new_fp, "%s", buffer);
	}

	fclose(fp);	
	fclose(new_fp);	
	return ret;
}

