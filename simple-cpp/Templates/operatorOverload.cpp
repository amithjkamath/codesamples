#include <iostream>

class USCurrency
{
private:
	int dollars;
	int cents;
public:
	USCurrency();
	USCurrency(int initDollars, int initCents){dollars = initDollars; cents = initCents;}
	
	int getDollars(){return dollars;}
	int getCents(){return cents;}
	
	USCurrency operator+(const USCurrency o)
	{
		USCurrency tmp(0,0);
		tmp.cents = cents + o.cents;
		tmp.dollars = dollars + o.dollars;
	
		if(tmp.cents >= 100)
		{
			tmp.dollars += 1;
			tmp.cents -= 100;
		}
		return tmp;
	}
};

int main(void)
{
	USCurrency a(1,20);
	std::cout << "a : " << a.getDollars() << "." << a.getCents() << std::endl;
	USCurrency b(2,30);	
	std::cout << "b : " << b.getDollars() << "." << b.getCents() << std::endl;
	
	USCurrency c = a + b;
	std::cout << "c : " << c.getDollars() << "." << c.getCents() << std::endl;
	return 0;
}