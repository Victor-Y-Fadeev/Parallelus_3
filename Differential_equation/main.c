#include <stdio.h>
#include <unistd.h>
#include "include/Logic.h"
#include "include/Files.h"


void start(char *input, char *output)
{
	Loader *loader = create_loader(input);
	Saver *saver = create_saver(output);

	Logic *logic = create_logic(loader, saver);
	auto_computation(logic);
	delete_logic(logic);

	delete_loader(loader);
	delete_saver(saver);
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
