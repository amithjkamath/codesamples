# This exercise introduces functions.
# Amith, 01/11

# Functions name pieces of code like variables name strings, numbers and so on.
# Functions take arguments like the scripts take argv.
# Using the above two, functions create "mini-scripts" or "tiny re-usable commands"

# This one is like your scripts with argv
def print_two(*args):
    arg1, arg2 = args # unpack the arguments.
    print "arg1: %r, arg2: %r" % (arg1, arg2)

def print_three(*args): # *args does not need to tell how many args it actually carries. Wild-card of sorts. Makes args a list.
    arg1, arg2, arg3 = args # This line uniquely decides how many arguments this function needs.
    print "arg1: %r, arg2: %r, arg3: %r" % (arg1, arg2, arg3)


# ok, that *args is actually pointless, we can just do this:
def print_two_again(arg1, arg2):
    print "Again: arg1: %r, arg2: %r" % (arg1, arg2)

# This just takes one argument
def print_one(arg1):
    print "arg1: %r" % arg1

# this one takes no arguments.
def print_none(): # Note: () still required.
    print "I got nothin'."

# Call these functions. Note that there is no 'main' function required to run. This is still a 'script' with functions in it.
print_two("Amith", "Kamath")
print_two_again("Amith", "Kamath")
print_three("Amith", "Kamath", "Wow!")
print_one("First!")
print_none()
