#ifndef FRACTION_HEADER
#define FRACTION_HEADER

class fraction {
	public:
		//constructors.
		fraction();
		fraction(int numVal, int denval);
		
		// kill copy constructor.
		fraction& operator=(fraction& other);
		
		//functions
		bool isZero();
		bool isNegative();
		
		
		//getters and setters
		void setNum(int val);
		int getNum();
		
		void setDen(int val);
		int getDen();
		
		void display();
		
		//Overloaded operators
		fraction& operator+(fraction& other);
		bool operator==(fraction& other);
	private:
		int myNum;
		int myDen;
};

#endif