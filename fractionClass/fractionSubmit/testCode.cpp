#include <cassert>    // for assert.
#include <iostream>   // for cout

#include "testCode.h"
#include "fraction.h" // for gcd, and fraction class.

void testGCD()
{
	// tests the euclidean gcd function. 
	// algorithm written after referring wikipedia.

	assert(gcd(3,6) == 3);
	assert(gcd(1,10) == 1);
	assert(gcd(5,5) == 5);
	assert(gcd(2,4) == 2);
	assert(gcd(1,17) == 1);
	std::cout << "All GCD tests passed." << std::endl;
}

void testFracBasic()
{
	// this function tests constructors, display, setters, 
	// getters (through display) and reduce.

	// test no input constructor.
	fraction fBlank;
	fBlank.display();
	
	assert(fBlank.getNum() == 1);
	assert(fBlank.getDen() == 1);

	// test setters.
	fBlank.setNum(4);
	fBlank.setDen(6);

	assert(fBlank.getNum() == 4);
	assert(fBlank.getDen() == 6);
	
	fBlank.display();

	// reduce and then display.
	fBlank.reduce();
	fBlank.display();
	assert(fBlank.getNum() == 2);
	assert(fBlank.getDen() == 3);

	// test two input constructor with default parameter.
	
	fraction fOne(3);
	fOne.display();

	assert(fOne.getNum() == 3);
	assert(fOne.getDen() == 1);	
	
	// test two input constructor.
	fraction fTwo(1,2);
	fTwo.display();

	assert(fTwo.getNum() == 1);
	assert(fTwo.getDen() == 2);

	// reduce already reduced form.
	fTwo.reduce();	
	fTwo.display();

	assert(fTwo.getNum() == 1);
	assert(fTwo.getDen() == 2);

	fraction fNeg(-1, 4);
	fNeg.display();

	assert(fNeg.getNum() == -1);
	assert(fNeg.getDen() == 4);

	std::cout << "All Basic Fraction tests passed." << std::endl;
}

void testFracArithmetic()
{
	// this function tests all the arithmetic operators.

	fraction fTwo(1,2);
	fTwo.display();
	
	fraction fBlank;
	fBlank.display();
	
	fBlank.setNum(4);
	fBlank.setDen(6);
	fBlank.display();

	// test add.
	fraction fAdd;
	fAdd = fTwo + fBlank;
	fAdd.display();

	assert(fAdd.getNum() == 7);
	assert(fAdd.getDen() == 6);

	// test subtract.
	fraction fSub;
	fSub = fTwo - fBlank;
	fSub.display();

	assert(fSub.getNum() == -1);
	assert(fSub.getDen() == 6);

	// test multiply.
	fraction fMult;
	fMult = fTwo*fBlank;
	fMult.display();

	assert(fMult.getNum() == 1);
	assert(fMult.getDen() == 3);

	// test divide.
	fraction fDiv;
	fDiv = fTwo / fBlank;
	fDiv.display();

	assert(fDiv.getNum() == 3);
	assert(fDiv.getDen() == 4);

	std::cout << "All Arithmetic Fraction tests passed." << std::endl;
}

void testFracComparison()
{
	// this function tests all the comparison operators.

	fraction fTwo(1,2);
	fTwo.display();
	
	fraction fBlank;
	fBlank.display();
	
	fBlank.setNum(4);
	fBlank.setDen(6);
	fBlank.display();

	// test not equal.
	assert(fTwo != fBlank);

	// test equal.
	assert(fTwo == fTwo);

	// test lesser than.
	assert(fTwo < fBlank);

	// test greater than.
	fBlank.setNum(0);
	assert(fTwo > fBlank);
	std::cout << "All comparison Fraction tests passed." << std::endl;
}