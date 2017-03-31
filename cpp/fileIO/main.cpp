#include <iostream>
#include <fstream>

long getFileSize(FILE* fPointer);

void readFile(FILE* fPointer);

int main(int argc, char* argv[])
{
	FILE* thisFile;
	std::string fileName;
	if(argc == 1)
	{
		std::cout << "Enter filename:" << std::endl;
		std::cin >> fileName;
	}
	else
	{
		fileName = std::string(argv[1]);
	}
	thisFile = fopen(fileName.c_str(),"rb"); //the b specifes reading as binary. Otherwise read as text.
	if(thisFile != NULL)
	{
		std::cout << "This file is " << getFileSize(thisFile) << " bytes in size." << std::endl;
		fseek(thisFile, 0, SEEK_SET);
		readFile(thisFile);
		fclose(thisFile);
	}
	else
	{
		std::cout << "File does not exist. Try again!" << std::endl;
	}
	return 0;
}

long getFileSize(FILE* fPointer)
{
	if(fPointer != NULL)
	{
		fseek(fPointer, 0, SEEK_END);
		return ftell(fPointer);
	}
	else
		return 0;
}

void readFile(FILE* fPointer)
{
	if(fPointer != NULL)
	{
		char str[5];
		int i = 0;
		while(fgets(str, 5, fPointer) != NULL)
		{
			//std::cout << "reading file" << std::endl;	
			std::cout << str;
			fseek(fPointer, i+4, SEEK_SET);
			i = i + 4;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Error: This file does not exist!" << std::endl;
	}
}
