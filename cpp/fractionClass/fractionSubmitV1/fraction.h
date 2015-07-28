#ifndef FRACTION_HEADER
#define FRACTION_HEADER

class fraction {
	public:
		//constructors.
		// let the blank constructor be initialized to 1/1.		
		fraction();
		// this will setup the numerator and denominator.
		fraction(int numVal, int denval);
		
		//getters and setters
		void setNum(int val);
		int getNum() const;
		
		void setDen(int val);
		int getDen() const;
		
		// this function displays the fraction: Fraction is : num / den
		void display();

		// this function reduces the fraction to the simplest form.
		// this does not handle improper fractions yet.
		void reduce();

		// friend functions
		// these are friend functions because they do not change the state 
		// of the current fraction object.
		friend fraction operator+(const fraction& fracOne, const fraction& fracTwo);
		friend fraction operator-(const fraction& fracOne, const fraction& fracTwo);
		friend fraction operator*(const fraction& fracOne, const fraction& fracTwo);
		friend fraction operator/(const fraction& fracOne, const fraction& fracTwo);

		friend bool operator==(const fraction& fracOne, const fraction& fracTwo);
		friend bool operator!=(const fraction& fracOne, const fraction& fracTwo);
		friend bool operator>(const fraction& fracOne, const fraction& fracTwo);
		friend bool operator<(const fraction& fracOne, const fraction& fracTwo);

		~fraction();
	private:

		int myNum;
		int myDen;
};

// This is an independent GCD function, needed for reducing the fraction to the simplest form.
int gcd(int x, int y);

#endif
