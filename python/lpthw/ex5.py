#This exercise shows how strings are manipulated.
# Amith, 01/02/15

name = "Amith"
age = 26
height = 175 #centimeters
weight = 195 #lbs
eyes = 'Black'
hair = eyes
teeth = 'White'

print "Let's talk about %s." % name
print "He's %d centimeters, and hence %f inches tall." % (height, height/2.54)
print "He's %d pounds heavy. That's quite a bit!" % weight
print "Actually, that's quite heavy."
print "He's got %r eyes and %s hair." % (eyes, hair) # need the parenthesis.
print "His teeth are usually %s in color, depending on coffee." % teeth

# This line is tricky. Many embedded variables in the string.
print "If I add %d, %d, and %d I get %d." % (age, height, weight, age + height + weight)
