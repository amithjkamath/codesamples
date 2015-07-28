# It is also usually a good idea to mention what a program does at the beginning, and also adding the author name and date. So, here goes:
# This program estimates number of people needed to be in a car in a carpool system.
# Author: Amith, Date: 1/2/15

cars = 100
# Note how variable names are quite descriptive: entire sentences separated by "_": underscores. One can also use camelcase (spaceInACar)
space_in_a_car = 4.0
drivers = 30
passengers = 90.0 # making anything involved in Mult or Div a float is a good idea.
cars_not_driven = cars - drivers
cars_driven = drivers
carpool_capacity = cars_driven * space_in_a_car
average_passengers_per_car = passengers/cars_driven

# Note that the variables are embedded in the text, and have spaces around them automatically! Really cool :)
print "There are", cars, "cars available."
print "There are only", drivers, "drivers available."
print "There will be", cars_not_driven, "empty cars today."
print "We can transport", carpool_capacity, "people today."
print "We have", passengers, "to carpool today."
print "We need to put about", average_passengers_per_car, "in each car."
