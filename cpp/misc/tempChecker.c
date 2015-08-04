#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINTEMP -40
#define MAXTEMP 120


int main(int argc, char* argv[])
{
	//check inputs for correct values.
	if(argc < 4)
	{
		printf("Usage: tempChecker.exe minTemp maxTemp steps\n");
		return 0;
	}
	//setup file for writing the data into.
	FILE *fp;
	fp = fopen("output.txt","w+");
	double minTemp = atof(argv[1]);
	double maxTemp = atof(argv[2]);
	double steps = atof(argv[3]);
	double i = 0;
	//printf("%f\n",minTemp);
	//printf("%f\n",maxTemp);
	//printf("%f\n",steps);
	
	if(minTemp < MINTEMP || maxTemp > MAXTEMP || steps <= 0)
	{
		printf("Invalid temperature range. Should be between -40 and 120 F. Try again.\n");
		return 0;
	}
	//setup the array for printing numbers.
	fprintf(fp,"This program outputs temperature conversions.\n");
	fprintf(fp,"Fahrenheit\tCelsius\n");
	printf("This program outputs temperature conversions.\n");
	printf("Fahrenheit\tCelsius\n");	
	for(i = minTemp; i < maxTemp; i+=steps)
	{
		fprintf(fp,"%3.2f     \t%3.2f\n",i,(5.0/9)*(i-32));
		printf("%3.2f     \t%3.2f\n",i,(5.0/9)*(i-32));
	}
	//do the math and write to file.
	fclose(fp);
	return 0;
}
	