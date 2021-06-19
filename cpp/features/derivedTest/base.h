#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>

class base
{
	public:
		base();
		base(std::string inName);

		virtual void print();
	protected:
		std::string _name;
};

#endif
