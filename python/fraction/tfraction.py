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

    def test_split(self):
        s = 'hello world'
        self.assertEqual(s.split(), ['hello', 'world'])
        # check that s.split fails when the separator is not a string
        with self.assertRaises(TypeError):
            s.split(2)

if __name__ == '__main__':
    unittest.main()