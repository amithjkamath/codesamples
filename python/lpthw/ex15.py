# This exercise introduces file reading.
# Amith, 01/11

from sys import argv

# Use argv to get the filename as an input.
script, fileName = argv

# This is equivalent to fopen in C.
txt = open(fileName)

print "Here's your file %r:" % fileName
print txt.read() # This prints whatever is read from the file.
# Hey txt, do your read function with no arguments!

# This demonstrates how a file name can be entered at run-time.
print "Type filename again:"
file_again = raw_input("$ ")

txt_again = open(file_again)

print txt_again.read()

# Strictly speaking, the files have to be closed before termination.
txt.close()
txt_again.close()
