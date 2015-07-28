# This exercise introduces passing arguments from command line, and the 'from x import y' syntax
# Amith, 01/07

# This structure of 'importing' modules and not having everything available by default helps to keep programs small, and also acts as documentation for others.
from sys import argv

script, first, second, third = argv

print "The script is called:", script
print "Your first variable is:", first
print "Your second variable is:", second
print "Your third variable is:", third

runTimeInput = raw_input("Enter a number:")
print "Number entered is %r" % runTimeInput

anotherInput = int(raw_input("Now a real number:"))
print "I can now use percent d to print this: %d" % anotherInput
