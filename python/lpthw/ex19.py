# This exercise demonstrates variables with respect to functions
# Amith 01/11

# Functions cannot be called before defined.
# cheese_and_crackers(10,4)

# Note that cheese_count is a local variable, and is 'passed by value'
def cheese_and_crackers(cheese_count, boxes_of_crackers):
    print "You have %d cheeses!" % cheese_count
    print "You have %d boxes of crackers!" % boxes_of_crackers
    print "Man, that's enough for a party!"
    print "Get a blanket.\n"

print "We can just give the function numbers directly"
cheese_and_crackers(20, 30)

print "Or, we can use variables from our script"
amount_of_cheese = 10
amount_of_crackers = 50
cheese_and_crackers(amount_of_cheese, amount_of_crackers)

print "Or, we can even do math inside:"
cheese_and_crackers(10 + 20, 5 + 6)

print "And finally, we can combine variables and math!"
cheese_and_crackers(amount_of_cheese + 5, amount_of_crackers*1.4)

def addTwoNumbers(a,b):
    print "Sum of %d and %d is %d" % (a, b, a+b)

a = 4; b = 5;
addTwoNumbers(1,2)
addTwoNumbers(a,2)
addTwoNumbers(4,b)
addTwoNumbers(a,b)
addTwoNumbers(a+b, a-b)
addTwoNumbers(a+2, b)
addTwoNumbers(a,int(raw_input("Enter a number: ")))
addTwoNumbers(int(raw_input("Enter a number: ")),5)
addTwoNumbers(int(raw_input("Enter a number: ")),int(raw_input("Enter another number: ")))
addTwoNumbers(a+b+2, a-b-2)
