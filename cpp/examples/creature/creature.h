#ifndef CREATURE_HEADER
#define CREATURE_HEADER

#include <string>

#include "point.h"

class creature
{
	public:
		creature();
		creature(std::string inName, point inLoc);
		creature(const creature& other);
		creature& operator=(const creature& other);
		
		void setName(const std::string& inName);
		void setLocation(const point loc);

		point getLocation() const;
		std::string getName() const;

		void show();
		
		~creature();
	private:
		point myLocation;
		std::string myName;
};

#endif
