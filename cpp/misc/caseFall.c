#include <stdio.h>

int main(void)
{
	int x=0;
	switch(x)
	{
		case 1: printf( "One" );
		case 0: printf( "Zero" );
		case 2: printf( "Hello World" );
		case 3: printf( "This is printed as well" );
		default: printf( " This is really crappy behavior.\n" );
	}
	return 0;
}