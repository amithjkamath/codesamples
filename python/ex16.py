# This exercise introduces reading and writing files.
# Amith, 01/11

from sys import argv

script, fileName = argv

print "We're going to erase %r." % fileName
print "If you don't want that, hit CTRL-C (^C)."
print "If you do want that, hit RETURN."

raw_input("?") # Note that it doesn't really matter if you pressed RETURN or any other key, excluding CTRL-C, in which case the program quits. 

print "Opening the file ... "
target = open(fileName,'w') # 'w' to write. Default is read only.

print "Truncating the file. Goodbye!"
target.truncate()

print "Now I'm going to ask you for three lines."

line1 = raw_input("line 1: ")
line2 = raw_input("line 2: ")
line3 = raw_input("line 3: ")

print "I'm going to write these lines to the file."

target.write(line1 + "\n") # This is an elegant way to write line1 and a \n character in one call to target.write()
target.write(line2)
target.write("\n")
target.write(line3)

print "And we finally close the file"
target.close()
