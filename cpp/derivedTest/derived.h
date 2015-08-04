#ifndef DERIVED_H
#define DERIVED_H

#include "base.h"

class derived : public base
{
	public:
		derived();
		derived(int value);

		virtual void print();
	private:
		int myValue;
};

#endif
