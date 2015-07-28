# This exercise introduces more escape sequences in strings.
# Amith, 01/03

tabby_cat = "\tI'm tabbed in."
persian_cat = "I'm split\non a line."
backslash_cat = "I'm \\ a \\ cat."

fat_cat = '''
I'll do a list:
\t* Cat food
\t* Fishies
\t* Catnip\n\t* Grass
'''

print tabby_cat
print persian_cat
print backslash_cat
print fat_cat

garbage_string =  "I'm 6'2\" tall. See, we escaped the \" using a \\\""

print garbage_string
print "%r is the string that includes all escape sequences." % garbage_string

# This is an infinite loop. Try at your own risk.
#while True:
#    for i in ["/", "-","|","\\","|"]:
#        print "%s\r" % i
