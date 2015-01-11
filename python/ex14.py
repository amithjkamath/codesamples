# This exercise uses argv and raw_input together.
# Amith, 01/11

from sys import argv

try: 
    script, userName = argv
except:
    print "Enter your name after the program name"

# This variable prompt is used in all raw_input calls.
prompt = '$ '

print "Hi %s, I'm the %s script." % (userName, script)
print "I'd like to ask you a few questions."
print "Do you like me, %s?" % userName
likes = raw_input(prompt)

print "Where do you live, %s?" % userName
lives = raw_input(prompt)

print "What kind of computer do you have?"
computer = raw_input(prompt)

# This """ allows multi line strings.
print """ 
Alright! So you said %r about liking me.
You live in %r, not really sure where that is.
You have a %r computer. Really cool!
""" % (likes, lives, computer)
