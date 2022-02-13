# This file contains a simple test suite to check each function implemented in the fraction class

import unittest
import fraction

class TestFractionMethods(unittest.TestCase):

    def test_constructor(self):
        f = fraction.fraction(1, 2)
        self.assertEqual(f.numerator, 1)
        self.assertEqual(f.denominator, 2)


    def test_print(self):
        f = fraction.fraction(1, 2)
        self.assertEqual(str(f), "1/2")


    def test_add(self):
        f1 = fraction.fraction(1, 2)
        f2 = fraction.fraction(1, 2)
        f3 = f1 + f2
        self.assertEqual(f3.numerator, 1)
        self.assertEqual(f3.denominator, 1)
        self.assertEqual(str(f3), "1/1")


    def test_gcd(self):
        """
        Note that a static method can be called as a function. There are no 'hidden' methods.
        """
        self.assertEqual(fraction.fraction._gcd(1, 4), 1)


if __name__ == '__main__':
    unittest.main()