#include <iostream>
#include <string>
#include <list>

#include <cmath>

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

#include "transmatrix.hpp"

using namespace CppUnit;
using namespace std;


//-----------------------------------------------------------------------------

class testtransmatrix : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(testtransmatrix);
    CPPUNIT_TEST(testMatrix1);
    //CPPUNIT_TEST(testMatrix2);
    CPPUNIT_TEST_SUITE_END();

protected:
    void testMatrix1(void);
  //  void testMatrix2(void);

};

//-----------------------------------------------------------------------------

void testtransmatrix::testMatrix1(void)
{
	double matrixIn[3][3] = {{1, 2, 3},
				 {4, 5, 6},
				 {7, 8, 9}};
	double actual[3][3];

	int numRows = 3;
	int numCols = 3;
	double expected[3][3] = {{1, 4, 7},
			 	 {2, 5, 8},
				 {3, 6, 9}};
	
	transmatrix(matrixIn[3][3], 3, 3, actual[3][3]);
	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			CPPUNIT_ASSERT(actual[i][j] == expected[i][j]);
}
/*
void testtransmatrix::testMatrix2(void)
{
	double arrayIn[6] = {1, 2, 1, 2, 1, 2};
	int numElems = 6;
	double expected = 0.5477;
	
	double actual = sdcalc(arrayIn, numElems);
	
	CPPUNIT_ASSERT(abs(actual - expected) < 0.001);
}
*/
//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( testtransmatrix );

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
