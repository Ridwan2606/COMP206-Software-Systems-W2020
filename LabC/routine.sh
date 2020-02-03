#!/bin/bash

# Assume I have a set of commands that I do on Mimi every morning
# I am writer and I have an essay to write and finish. The essay
# is a textfile "essay.txt" in the directory "work" in my home directory
# Let's say I need to reach 1000 lines in my essay.txt. (Create one for this lab)

# On running this script, I want to:
# 1.) Display today's date nicely
# 2.) Display the folders/files in my home directory
# 3.) Display how many lines I have left to write in ~/work/essay.txt
#     reach my goal.

#Assigning a global variable
Goal=1000

#Go to home directory (Very important. Now script can be placed
# anywhere and it would still produce the intended output.)
cd ~

#Do the command "date" and redirect the stdout of that command
#to this global variable "datevar"
datevar=`date`

#Prints the date
echo "Today's date is $datevar"

#Displays the folders and files in the home directory
ls
#Go to work directory
cd work

#Do the command "wc -l essay.txt" and redirect the the stdout of that
#commadn to this global variable "reached"
#Effectively, if essay.txt has 10 lines, then the
#string "10 essay.txt" will be stored in reached.
reached=`wc -l essay.txt`

#We only care about the "10" part to perform our computation
#We use the "set" command to split a space-delimited string
#into words which are then placed in the appropriate positional variable
set $reached
# After this command, the following positional variable are assigned these
# values
# $1 <- "10"
# $2 <- "essay.txt"

#Computation to get the number of lines left to write. A new
#global variable is defined.
left=$[ $Goal - $1 ]

#print the number of lines left
echo "You have $left lines left to write! Keep going!"
exit