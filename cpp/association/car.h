#ifndef CAR_HEADER
#define CAR_HEADER

#include <string>

class car
{
	public:
		car();
		car(int y, bool ins, const std::string& name);

		int getYear();
		bool isInsured();
		const std::string& getName() const;
		void setName(const std::string& name);

		void show();

		~car();

	private:
		void setYear(int y);
		void setInsured(bool ins);

		int year;
		bool insured;
		std::string* name;
};

#endif
