#include <iostream>
#include "matrix.h"

int main()
{
	matrix m(5,5);

	m.setVal(2.5,0,0);
	m.setVal(3.5,1,2);
	m.setVal(2.6,2,2);	
	m.setVal(2.7,3,3);
	m.setVal(2.8,4,4);
	m.setVal(2.9,3,4);
	m.display();

	matrix k(5,5);

	k.setVal(2.5,0,0);
	k.setVal(3.5,4,3);
	k.setVal(2.6,2,2);	
	k.setVal(2.7,2,4);
	k.setVal(2.8,4,4);
	k.setVal(2.9,2,4);
	k.display();

	matrix l(5,5);
	l = m + k;
	l.display();
	l = l - k;
	l.display();
	l = 0.1*l;
	l.display();
	l = l*100;
	l.display();	

	matrix n(1,1);
	n.display();

	return 0;
}
