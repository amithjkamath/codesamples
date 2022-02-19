# This file contains a simple test suite to check each function implemented in the fraction class

import unittest
import fraction

class TestFractionMethods(unittest.TestCase):
    """
    TestFractionMethods is a unittest dependent class to test Fraction.
    """
    def test_constructor(self):
        """
        This method tests the fraction constructor.
        """
        test_fraction = fraction.Fraction(1, 2)
        self.assertEqual(test_fraction.numerator, 1)
        self.assertEqual(test_fraction.denominator, 2)


    def test_print(self):
        """
        This method tests the fraction print or string conversion.
        """
        test_fraction = fraction.Fraction(1, 2)
        self.assertEqual(str(test_fraction), "1/2")


    def test_add(self):
        """
        This method tests the fraction add operator overload.
        """
        test_fraction1 = fraction.Fraction(1, 2)
        test_fraction2 = fraction.Fraction(1, 2)
        test_fraction3 = test_fraction1 + test_fraction2
        self.assertEqual(test_fraction3.numerator, 1)
        self.assertEqual(test_fraction3.denominator, 1)
        self.assertEqual(str(test_fraction3), "1/1")


    def test_subtract(self):
        """
        This method tests the fraction subtract operator overload.
        """
        test_fraction1 = fraction.Fraction(1, 2)
        test_fraction2 = fraction.Fraction(1, 2)
        test_fraction3 = test_fraction1 - test_fraction2
        self.assertEqual(test_fraction3.numerator, 0)
        self.assertEqual(test_fraction3.denominator, 1)
        self.assertEqual(str(test_fraction3), "0/1")


    def test_equality(self):
        """
        This method tests the fraction equality operator.
        """
        test_fraction1 = fraction.Fraction(4, 29)
        test_fraction2 = fraction.Fraction(4*5, 29*5)
        self.assertTrue(test_fraction1 == test_fraction2)
        test_fraction3 = fraction.Fraction(-4*5, -29*5)
        self.assertTrue(test_fraction1 == test_fraction3)


    def test_multiply(self):
        """
        This method tests the fraction multiply operator overload, 
        for both scalar and fraction multiplication.
        """
        test_fraction1 = fraction.Fraction(4, 29)
        test_fraction2 = fraction.Fraction(1, 2)
        test_fraction3 = test_fraction1 * test_fraction2
        self.assertEqual(test_fraction3.numerator, 2)
        self.assertEqual(test_fraction3.denominator, 29)
        test_integer3 = 5
        test_fraction4 = test_fraction3 * test_integer3
        self.assertEqual(test_fraction4.numerator, 10)
        self.assertEqual(test_fraction4.denominator, 29)


    def test_gcd(self):
        """
        Note that a static method can be called as a function. There are no 'hidden' methods.
        """
        self.assertEqual(fraction.Fraction._gcd(1, 4), 1)
        self.assertEqual(fraction.Fraction._gcd(29, 87), 29)


if __name__ == '__main__':
    unittest.main()
