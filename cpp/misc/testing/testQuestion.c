#include <stdio.h>

int main(void)
{
int i;
double x[10];

for (i=0;i<=10;i++)
{
   x[i]=(double)i;
   printf("%f\n",x[i]);
}
	return 0;
}