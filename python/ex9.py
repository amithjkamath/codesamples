# This exercise introduces escape characters in strings. 
# Amith, 01/03

days = "Mon Tue Wed Thu Fri Sat Sun"
# Note the use of \n: escape character, much like C here:
months = "Jan\nFeb\nMar\nApr\nMay\nJun\nJul\nAug\nSep\nOct\nNov\nDec\n"

print "Here are the days of the week: %s" % days
print "Here are the months of the year: ", months # see how it is not using formatters here.

print """
There's something going on here.
With the three double-quotes, 
we'll be able to type as much as we like.
Even 4 lines if we want, or 5,
really!
"""
