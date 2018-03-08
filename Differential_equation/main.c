#include <stdio.h>
#include <unistd.h>
#include "include/Files.h"
#include "include/Logic.h"


void start(char *input, char *output)
{
	FILE *file;
	file = fopen(input, "r");
	char str[256] = {'\0'};

	while (!feof(file))
	{
		fgets(str, 256, file);
		printf("%s", str);
	}

	fclose(file);
}

int main(int argc, const char **argv)
{
	char *input = NULL;
	char *output = NULL;

	if (argc < 3)
	{
		input = "input.txt";
		output = "output.txt";
	} else {
		input = argv[1];
		output = argv[2];
	}

	if(access(input, F_OK) == -1)
	{
		printf("File doesn't exist!\n");
		return -1;
	}

	start(input, output);

	return 0;
}
