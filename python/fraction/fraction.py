# This file contains an implementation of the 'fraction' class, as elaborated in 
# https://runestone.academy/ns/books/published/pythonds3/Introduction/ObjectOrientedProgramminginPythonDefiningClasses.html 

class fraction:

    def __init__(self, num, den):
        self.numerator = int(num)
        self.denominator = int(den)

    def __str__(self):
        return str(self.numerator) + "/" + str(self.denominator)