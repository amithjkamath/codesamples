# This exercise includes some complex string manipulations.
# Amith, 01/02/2015
x = "There are %d types of people." % 10
binary = "binary"
do_not = "don't"
y = "Those who know %s and those who %s." % (binary, do_not) # one

print x
print y

print "I said: %r." % x # two
print "I also said: '%s'." % y # three

hilarious = False
joke_evaluation = "Isn't that joke so funny? %r"

print joke_evaluation % hilarious # four.

w = "This is the left side of..."
e = "a string with a right side."

print w + e # + on strings concatenates them. + is overloaded to mean concatenation.
print 5 + 6
