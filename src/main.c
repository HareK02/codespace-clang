#include <stdio.h>

int main(void)
{
		FILE *fp;
		int No = 100;
		char Name[20] = "John";

		fp = fopen("test.txt", "w");
		if (fp == NULL) {
				printf("Error opening file\n");
				return 1;
		}
		fprintf(fp, "%d %s\n", No, Name);
		fclose(fp);
    return 0;
}