# The following line prints a message.
print "I will now count my chickens."

# The following line prints "Hens" and then computes the value.
# Precedence is PEMDAS: Parenthesis, Exponentiation, Multiplication, Division, Addition and then Subtraction. Here, D is done first. Most operators are left to right associative.
print "Hens", 25 + 30 / 6
# Here, 25*3 is evaluated first, then divided by 4, and then subtracted.
print "Roosters", 100 - 25 * 3.0 / 4

print "Now I will count the eggs:"

# Here, % and / are computed first, and then the other operations.
print 3 + 2 + 1 - 5 + 4 % 2 - 1.0 / 4 + 6

print "Is it true that 3 + 2 < 5 - 7?"

# This computes a logical, equivalent to (3 + 2) < (5 - 7).
# logical operations have lesser precedence than math!
print 3 + 2 < 5 - 7

print "What is 3 + 2?", 3 + 2
print "What is 5 - 7?", 5 - 7

print "Oh, that's why it's False"

print "How about some more."

# These are examples of using other logical operations on numbers.
print "Is it greater?", 5 > -2
print "Is it greater or equal?", 5 >= -2
print "Is it less or equal?", 5 <= -2
