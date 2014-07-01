#ifndef PERSON_HEADER
#define PERSON_HEADER

#include "car.h"
#include <string>

class person
{
	public:
		person();
		person(const std::string& inName, car& inCar);

		const car& getCar() const;
		const std::string& getName() const;

		person(const person& other);
		person& operator=(const person& other);

		void show();

		void setName(const std::string& inName);
		void setCar(const car& inCar);

		~person();

	private:

		car* myCar;
		std::string myName;
};

#endif
