# This exercise introduces 'return' from functions, and hence daisy-chaining them.
# Amith, 01/11

def add(a, b):
    print "Adding %d + %d" % (a,b)
    return a + b

def subtract(a, b):
    print "Subtracting %d - %d" % (a,b)
    return a - b

def multiply(a,b):
    print "Multiplying %d * %d" % (a,b)
    return a*b

def divide(a,b):
    print "Dividing %d / %d" % (a,b)
    return a/b

print "Let's do some math with just functions!"

age = add(30,5)
height = subtract(78,4)
weight = multiply(90,2)
iq = divide(100,2)

# Example of how "string %x" % variable is combined with "string", variable, "string again" ...
print "Age: %d, Height: %d, Weight:" % (age, height), weight, ", IQ: %d" % iq

print "Here's a puzzle"

what = add(age, subtract(height, multiply(weight, divide(iq, 2))))

print "That becomes: ", what, " Can you do it by hand?"
