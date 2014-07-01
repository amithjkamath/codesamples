// get.cpp

#include <iostream>
#include <cstdlib>
#include <string>
#include "get.h"

bool get_bool(const std::string & prompt)
{
	return get_bool(std::cin, prompt);
}

char get_char(const std::string & prompt)
{
	return get_char(std::cin, prompt);
}

short get_short(const std::string & prompt)
{
	return get_short(std::cin, prompt);
}

int get_int(const std::string & prompt)
{
	return get_int(std::cin, prompt);
}

long get_long(const std::string & prompt)
{
	return get_long(std::cin, prompt);
}

float get_float(const std::string & prompt)
{
	return get_float(std::cin, prompt);
}

double get_double(const std::string & prompt)
{
	return get_double(std::cin, prompt);
}

std::string get_string(const std::string & prompt)
{
	return get_string(std::cin, prompt);
}

bool get_bool(std::istream & is, const std::string & prompt)
{
	std::string s = get_string(is, prompt);

	if (s == "true")
	{
		return true;
	}
	else if (s == "false")
	{
		return false;
	}
	else
	{
		std::cerr << "Invalid input. Enter 'true' or 'false'." << std::endl;
		return false;
	}
}

char get_char(std::istream & is, const std::string & prompt)
{
	std::string s = get_string(is, prompt);

	if (s.length() == 0)
	{
		std::cerr << "Invalid input. Enter at least one character." << std::endl;

		return '?';
	}
	else
	{
		return s[0];
	}
}

short get_short(std::istream & is, const std::string & prompt)
{
	int i = get_int(is, prompt);

	short s = (short) i;

	return s;
}

int get_int(std::istream & is, const std::string & prompt)
{
	std::string s = get_string(is, prompt);

	if (s.length() == 0)
	{
		std::cerr << "Invalid input. Enter at least one character." << std::endl;

		return 0;
	}
	else
	{
		int i = atoi(s.c_str());

		return i;
	}
}

long get_long(std::istream & is, const std::string & prompt)
{
	std::string s = get_string(is, prompt);

	long l = atol(s.c_str());

	return l;
}

float get_float(std::istream & is, const std::string & prompt)
{
	std::string s = get_string(is, prompt);

	float f = (float) atof(s.c_str());

	return f;
}

double get_double(std::istream & is, const std::string & prompt)
{
	std::string s = get_string(is, prompt);

	double d = atof(s.c_str());

	return d;
}

std::string get_string(std::istream & is, const std::string & prompt)
{
	if (is == std::cin)
	{
		std::cout << prompt << std::flush;
	}

	char buffer[256];

	is.getline(buffer, sizeof(buffer));

	std::string s(buffer);

	return s;
}
