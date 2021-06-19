#include "testRef.h"

#include <string>


testRef::testRef()
{
	setName("");
}

testRef::testRef(const std::string& myName)
{
	setName(myName);
}

testRef::testRef(const testRef& other)
{
	setName(other.getName());
}

testRef& testRef::operator=(const testRef& other)
{
	setName(other.getName());
	return *this;
}

void testRef::setName(const std::string& inName)
{
	name = new std::string(inName);
}

const std::string& testRef::getName() const
{
	return *name;
}

testRef::~testRef()
{
	delete name;
}
