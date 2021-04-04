# Used to initialize assignments


# Initialize variables
assignment = 8 # Assignment number
questions = 'abcdefghij'
path = 'a' + str(assignment) + '/solutions/' 

for q in questions:
    open(path + q + '.c', 'a').close()

