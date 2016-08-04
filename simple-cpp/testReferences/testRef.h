#ifndef TESTREF_HEADER
#define TESTREF_HEADER

#include <string>

class testRef
{
	public:
		testRef();
		testRef(const std::string& myName);

		testRef(const testRef& other);
		testRef& operator=(const testRef& other);

		void setName(const std::string& inName);
		const std::string& getName() const;

		~testRef();
	private:
		std::string* name;
};

#endif
