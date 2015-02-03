#include <iostream>
#define SIZE 8
int main(void)
{
	int mid = SIZE/2;
	int width = 0;
	bool flip = false;
	char textArray[SIZE] = {' '}; // all spaces.
	
	for(int i = 0; i <= SIZE; i++)
	{
		for(int j = 0; j <= SIZE; j++)
		{
			textArray[j] = ' ';
			if(j > mid - width && j < mid + width)
				textArray[j] = '*';
		}
		if(width <= mid && flip == false)
			width++;
		if(width <= mid && flip == true)
			width--;
		if(width == mid)
			flip = true;
	
		std::cout << textArray << std::endl;
	}
	return 0;
}