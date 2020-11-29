#include<stdio.h>

int main( int argc, char *argv[] )
{
	printf("You have supplied %d arguments!\n", argc);
	
	int i;
	for (i=0; i<argc; i++)
	{
		printf("Argument %d: %s\n", i, argv[i]);
	}
	
	printf("\n\nargv[1] = %s", argv[1]);
}