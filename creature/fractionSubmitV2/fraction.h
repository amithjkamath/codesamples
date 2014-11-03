#ifndef FRACTION_HEADER
#define FRACTION_HEADER

class fraction 
{
	public:
		//constructors.
		// let the blank constructor be initialized to 1/1.
		// give a default value to both numerator and denominator if not specified,
		// e.g: fraction fr(4); // will be 4/1.
		// fraction fr; // will be 1/1.
		fraction(int numVal = 1, int denVal = 1);
		
		//getters and setters
		void setNum(int val);
		int getNum() const;
		
		void setDen(int val);
		int getDen() const;
		
		// this function displays the fraction: Fraction is : num / den
		void display() const;

		// this function reduces the fraction to the simplest form.
		// this does not handle improper fractions yet.
		void reduce();
		
		// destructor.
		~fraction();

	private:

		int myNum;
		int myDen;
};

// This is an independent GCD function, needed for reducing the fraction to the simplest form.
int gcd(int x, int y);

// friend functions
// these are friend functions because they do not change the state 
// of the current fraction object.
fraction operator+(const fraction& fracOne, const fraction& fracTwo);
fraction operator-(const fraction& fracOne, const fraction& fracTwo);
fraction operator*(const fraction& fracOne, const fraction& fracTwo);
fraction operator/(const fraction& fracOne, const fraction& fracTwo);

bool operator==(const fraction& fracOne, const fraction& fracTwo);
bool operator!=(const fraction& fracOne, const fraction& fracTwo);
bool operator>(const fraction& fracOne, const fraction& fracTwo);
bool operator<(const fraction& fracOne, const fraction& fracTwo);

#endif