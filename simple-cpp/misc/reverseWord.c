#include <stdio.h>
#define MAXSIZE 100

int main(void)
{
	char buffer[MAXSIZE];
	int i = 0;
	int strSize = 0;
	char c;
	int loc = MAXSIZE;
	
	printf("Enter the string to be reversed word by word:\n");
	for(i = 0; i < MAXSIZE; i++)
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
	strSize =  --i;
	loc = strSize;
	//iterate from the end
	for(i = strSize; i >= 0; i--)
	{
		//find first space, keep location of this.
		if(buffer[i] == ' ' || i == 0)
		{
			//print everything after it.
			int j = i+1;
			if(i == 0)
			{
				j = 0;
			}
			for(; j <= loc; j++)
			{
				putchar(buffer[j]);
			}
			loc = i-1;
			putchar(' ');
		}
		else
		{
			//continue until reaching the beginning of the string.
		}
	}
	
	return 0;
}