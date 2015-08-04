#include <iostream>

#include "point.h"
#include "creature.h"

int main()
{
//	creature me;
//	std::cout << me.getLocation().getX() << std::endl;
//	std::cout << me.getLocation().getY() << std::endl;

	point a(2,2);
	std::cout << "a: ";
	a.show();

	point b = a;
	std::cout << "b: ";
	b.show();

	point* c = new point;
	std::cout << "c: ";
	c->show();
	
	*c = b;
	std::cout << "c: ";
	c->show();
	
	creature me("Amith", *c);
	me.show();
	
	delete c;
	
	b.setX(5);
	b.setY(7);
	b.show();
	
	me.show();
	return 0;
}
