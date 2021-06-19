#ifndef POINT_HEADER
#define POINT_HEADER

class point
{
	public:
		point();
		point(int inX, int inY);

		point(const point& other); // copy constructor.
		point& operator=(const point& other); // assignment operator.
		
		void setX(double x); // command
		void setY(double y); // command
		
		double getX() const; //query
		double getY() const; // query

		void show(); // command and query

		~point();
	private:
		double _x;
		double _y;
};

#endif
