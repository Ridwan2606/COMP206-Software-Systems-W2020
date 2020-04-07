#Author: Ridwan Kurmally
#Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

#Note here that the default branch "bank" will cover all branches in this specific case.

#The prerequisite for the branch main are main.o and bank.o. 
#After these prerequisite are met, we can complete the branch "bank" by executing the commands in it.

#A prerequisite is either a file or another branch.

# The first prereq "main.o" is actually a branch. So to meet this requirement, 
# we recursively go in the "main.o" branch and complete this branch.
# The prerequisite for main.o is main.c which is not a branch 
# ( we know that as there's not branch "main.c" below it) 
# So the make command will understand that main.c must be a file in the current directory. 
# If this file is not present, the "make" command won't work. It will throw an error
# Assuming main.c is in the directory, "gcc -c main.c" will be executed and the branch "main.o" will be completed.

# Now the 2nd prereq for bank which is a branch labelled bank.o has to be fulfilled. 
# For this we require two files, bank.c and bank.h. If they are present, "gcc -c bank.c" is executed.
# bank.o is completed then.

# We return to branch "bank". Its prereq are satisfied so we execute "gcc -o bank main.o bank.o"
# The make command is then completed.
bank: main.o bank.o
	gcc -o bank main.o bank.o
bank.o: bank.c bank.h
	gcc -c bank.c
main.o: main.c
	gcc -c main.c


