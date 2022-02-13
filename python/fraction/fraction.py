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
    

    @staticmethod
    def _gcd(m, n):
        while m % n != 0:
            m, n = n, m % n
        return n


    def __str__(self):
        return str(self.numerator) + "/" + str(self.denominator)