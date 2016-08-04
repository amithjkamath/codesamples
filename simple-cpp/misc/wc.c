#include <stdio.h>
#define MAXSTRINGSIZE 100
int main(int argc, char* argv[])
{
	FILE *fp;
	int numLines = 0;
	char stringStore[MAXSTRINGSIZE];
	if(argc != 2)
	{
		printf("Please enter a filename to run wc on.\n");
		printf("Usage: ./wc.exe <filename>\n");
		return 0;
	}	
	fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		printf("Filename specified by [%s] does not exist. Please use a valid filename.\n",argv[1]);
		printf("Usage: ./wc.exe <filename>\n");
		return 0;
	}
	//do the word count here.
	while(fgets(stringStore,MAXSTRINGSIZE,fp) != NULL)
	{
		numLines++;
	}
	printf("%s has %d lines\n",argv[1],numLines);
	fclose(fp);
	return 0;
}