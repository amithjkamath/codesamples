#include <stdio.h>
#define MAXWIDTH 100

int main(void)
{
	char buffer[MAXWIDTH];
	char c;
	int i = 0;
	printf("Enter a string to be reversed:\n");
	for(i = 0; i < MAXWIDTH; i++)
	{
		c = getchar();
		if(c != '\n')
			buffer[i] = c;
		else
		{
			buffer[i] = '\0';
			break;
		}
	}
	printf("This is the entered String: %s\n",buffer);
	i--;
	while(i >= 0)
	{
		putchar(buffer[i]);
		i--;
	}
	
	return 0;
}