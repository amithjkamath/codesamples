#include <stdio.h>

int findOne(int num);

int main(void)
{
	int x = 65;
	int y = 255;
	int z = 1;
	int k = 0;
	printf("Number of ones in %d is %d\n", x, findOne(x));
	printf("Number of ones in %d is %d\n", y, findOne(y));
	printf("Number of ones in %d is %d\n", z, findOne(z));
	printf("Number of ones in %d is %d\n", k, findOne(k));
	return 0;
}

int findOne(int num)
{
	int retVal = 0;
	int i = 0;
	for(; i < 32; i++)
	{
		if((1 << i) & num)
			retVal++;
	}
	return retVal;
}