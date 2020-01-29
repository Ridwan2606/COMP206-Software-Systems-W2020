#!/bin/bash
# Counting the number of lines in a list of files

# Author: Ridwan Kurmally
# Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

# Question 2 (Shell Function using EVAL METHOD)

# Function that passes 2 argument being a filename and variable that will store the number of lines
# and assigns the number of lines in that file to a global
# variable using a pointer from the 2nd argument [ EVAL METHOD ]
############################################################################################################
count_lines () {
    #This variable can be considered to be a pointer to the argument passed being the global variable l.
    #It will be dereferenced using eval to update the value of the l outside the function
    local __l=$2

    # METHOD 1 [no array] USING sed
	#l=`wc -l $1 | sed 's/^\([0-9]*\).*$/\1/'`

    # METHOD 2 [array] USING read and IFS
    #IFS=' ' read -ra my_array <<< "$1"
    #l=${my_array[0]}
    
    # METHOD 3 [array] using tr
    my_array=(`wc -l $1 | tr [:space:] "\n"`)
	eval $__l=${my_array[0]}
    # Pointer dereferenced to the actual value stored in the global variable l outside the function
}
############################################################################################################

if [ $# -lt 1 ]
then
  echo "Usage: $0 file ..."
  exit 1
fi

echo "$0 counts the lines of code" 
#l stores number of lines found in the current file
l=0
#s stores number of lines read so far
s=0
#stores number of files
no_of_files=$#

#while there is a positional variable
while [ "$*" != ""  ] 
do
    #function called with the current file reached and the variable l
    count_lines $1 l
    #prints filename and the number of lines read
    echo "$1: $l"
    #Update number of lines read so far
    s=$[ $s + $l ]
    #shifts the positional variables by 1 to the left
	shift
done

echo "$no_of_files files in total, with $s lines in total"
exit 100