#include <iostream>
#include <string>

#include "person.h"
#include "car.h"

int main()
{
	car myNewCar(2014, 1, "Mazda 3");

	myNewCar.show();

	person me("Amith", myNewCar);
	me.show();

	person you;

	you = me;
	
	you.setName("Sushama");
	
	you.show();

	me.show();

	return 0;
}
