# This exercise introduces command line inputs.
# Amith, 01/03

print "How old are you?"
age = raw_input()
print "How tall are you (in centimeters)?"
height = raw_input()
print "How much do you weigh (in lbs)?"
weight = raw_input()

print "So, you're %r years old, %r centimeters tall, and %r lbs heavy!" % (
age, height, weight)

BMI = float(weight) * 703.0 * (2.54*2.54)/(float(height)*float(height))

print "and your BMI is %f." % BMI
