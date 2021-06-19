#include <iostream>
#define SIZE 6

int main(void)
{
	int k = 0;
	char textArray[SIZE] = {' '};

	for(int i = 0; i <= SIZE; i++)
	{
		for(int j = 0; j <= SIZE; j++)
		{
			textArray[j] = ' ';
			textArray[k] = '*';
			textArray[SIZE - k] = '*';
		}
		k++;
		std::cout << textArray << std::endl;
	}
	return 0;
}