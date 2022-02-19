"""
This is the module doc string for fraction. This contains only one class, Fraction, for now.
"""
class Fraction:
    """
    This is an implementation of the fraction class, inspired by
    https://runestone.academy/ns/books/published/pythonds3/Introduction/ObjectOrientedProgramminginPythonDefiningClasses.html
    """
    def __init__(self, num, den):
        self.numerator = int(num)
        self.denominator = int(den)


    def __add__(self, another):
        new_num = self.numerator * another.denominator + \
                 self.denominator * another.numerator
        new_den = self.denominator * another.denominator

        common = self._gcd(new_num, new_den)

        return Fraction(new_num // common, new_den // common)


    def __sub__(self, another):
        # Re-use the add implementation to also do subtract.
        return self.__add__(Fraction(-another.numerator, another.denominator))


    def __eq__(self, other_fraction) -> bool:
        # This is necessary because there's no unique representation of the same fraction.
        first_num = self.numerator * other_fraction.denominator
        second_num = other_fraction.numerator * self.denominator

        return first_num == second_num


    def __mul__(self, another):
        if isinstance(another, int) or isinstance(another, float):
            new_num = self.numerator * another
            new_den = self.denominator
        elif isinstance(another, Fraction):
            new_num = self.numerator * another.numerator
            new_den = self.denominator * another.denominator

        common = self._gcd(new_num, new_den)
        return Fraction(new_num//common, new_den//common)


    @staticmethod
    def _gcd(integer_m, integer_n):
        while integer_m % integer_n != 0:
            integer_m, integer_n = integer_n, integer_m % integer_n
        return integer_n


    def __str__(self):
        return str(self.numerator) + "/" + str(self.denominator)
