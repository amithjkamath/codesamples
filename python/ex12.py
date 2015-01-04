# This cleans up the exercise 11 code and shows how clear python is.
# Amith, 01/03

age = raw_input("What is your age? ") # Note the space after 'age'.
height = raw_input("What is your height? ")
weight = raw_input("What is your weight? ")

print "So, you are %r old, %r tall and %r heavy." % (
age, height, weight)
