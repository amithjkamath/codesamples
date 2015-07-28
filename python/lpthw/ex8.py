# This is an example with more text manipulation than before.
# Amith, 01/02

formatter = "%r %r %r %r"

print formatter % (1,2,3,4) # This prints numbers using %r
print formatter % ('one', "two", 'three', "Four") # This prints numbers as text using %r
print formatter % (True, False, True, False) # This prints boolean values using %r
print formatter % (formatter, formatter, formatter, formatter)
print formatter % (
	"I had this thing.",
	"That you could type up right.",
	"But it didn't sing.",
	"So I'm saying goodnight."
)
