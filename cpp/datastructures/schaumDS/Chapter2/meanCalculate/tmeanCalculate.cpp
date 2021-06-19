#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>

#include "meanCalculate.hpp"

using namespace CppUnit;
using namespace std;


//-----------------------------------------------------------------------------

class TestMeanCalculate : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestMeanCalculate);
    CPPUNIT_TEST(testArray1);
    CPPUNIT_TEST(testArray2);
    CPPUNIT_TEST_SUITE_END();

protected:
    void testArray1(void);
    void testArray2(void);

};

//-----------------------------------------------------------------------------

void TestMeanCalculate::testArray1(void)
{
	double arrayIn[5] = {1, 2, 3, 4, 5};
	int numElems = 5;
	double expected = 3; // (1+2+3+4+5)/5 = 3
	
	double actual = 0;
	meanCalculate(arrayIn, numElems, &actual);
	
	CPPUNIT_ASSERT(actual == expected);
}

void TestMeanCalculate::testArray2(void)
{
	double arrayIn[7] = {1, 2.5, 3, 4.5, 5, 6.5, 7.5};
	int numElems = 7;
	double expected = 30.0/7;
	
	double actual = 0;
	meanCalculate(arrayIn, numElems, &actual);
	
	CPPUNIT_ASSERT(actual == expected);
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestMeanCalculate );

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
