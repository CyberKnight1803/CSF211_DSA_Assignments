# Used to initialize assignments
import os

# Initialize variables
assignment = 10 # Assignment number
dir = 'a' + str(assignment)
os.makedirs(dir)
solutions = dir + '/solutions/'
os.makedirs(solutions)

questions = 'abcdefghij'

for q in questions:
    open(solutions + q + '.c', 'a').close()

