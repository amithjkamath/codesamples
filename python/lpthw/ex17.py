# This exercise reads from one file and writes to another.
# Amith, 01/11

from sys import argv
# This allows us to check if a file exists.
from os.path import exists

script, from_file, to_file = argv

print "Copying from %s to %s" % (from_file, to_file)

# we could do these two on one line. How?
in_file = open(from_file)
inData = in_file.read() # inData = open(from_file).read()

# Note the use of len here. Length of the file.
print "The file %s is %d bytes long" % (from_file, len(inData))

print "Does the output file exist? %r" % exists(to_file)

# print "Ready? Hit RETURN to continue, CTRL-C to abort"
# raw_input("?")

open(to_file, 'w').write(inData) # See, in one line!
print "All done!"

in_file.close() # how to close out_file?
