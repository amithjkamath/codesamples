# This exercise combines functions with file I/O.
from sys import argv

script, fileName = argv

def print_all(f): # f is the file handle.
    print f.read() #Wrapper for the read function.

def rewind(f):
    f.seek(0) # Seek to the beginning of the file. A la a tape.
    # Seek deals with bytes: resets reading to the 0th byte.

def print_a_line(line_count, f):
    # The following line describes the function, like a comment.
    """This function prints line 'line_count' and lines from file f based on where it is currently reading from"""
    print line_count, f.readline()

current_file = open(fileName)

print "First, let's print the whole file:\n"

print_all(current_file)

print "Now, let's rewind, kind of like a tape"

rewind(current_file)

print "Let's print three lines:"

current_line = 4
print_a_line(current_line, current_file)

print_a_line(current_line+1, current_file)

current_line += 2 # note that the previous time we incremented current_line, it didn't save in current_line! That's why we are incrementing by 2.
print_a_line(current_line, current_file)
