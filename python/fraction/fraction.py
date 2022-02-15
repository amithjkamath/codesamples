# This file contains an implementation of the 'fraction' class, as elaborated in 
# https://runestone.academy/ns/books/published/pythonds3/Introduction/ObjectOrientedProgramminginPythonDefiningClasses.html 

class fraction:

    def __init__(self, num, den):
        self.numerator = int(num)
        self.denominator = int(den)


    def __add__(self, another):
        new_num = self.numerator * another.denominator + \
                 self.denominator * another.numerator
        new_den = self.denominator * another.denominator
        
        common = self._gcd(new_num, new_den)
        
        return fraction(new_num // common, new_den // common)
    

    def __sub__(self, another):
        # Re-use the add implementation to also do subtract.
        return self.__add__(fraction(-another.numerator, another.denominator))


    def __eq__(self, other_fraction) -> bool:
        # This is necessary because there's no unique representation of the same fraction.
        first_num = self.numerator * other_fraction.denominator
        second_num = other_fraction.numerator * self.denominator

        return first_num == second_num


    def __mul__(self, another):
        if isinstance(another, int) or isinstance(another, float):
            new_num = self.numerator * another
            new_den = self.denominator
        elif isinstance(another, fraction):
            new_num = self.numerator * another.numerator
            new_den = self.denominator * another.denominator
        
        common = self._gcd(new_num, new_den)
        return fraction(new_num//common, new_den//common)


    @staticmethod
    def _gcd(m, n):
        while m % n != 0:
            m, n = n, m % n
        return n


    def __str__(self):
        return str(self.numerator) + "/" + str(self.denominator)