#!/bin/bash
# Counting the number of lines in a list of files

# Author: Ridwan Kurmally
# Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

# Question 2 (Shell Function using COMMAND SUBSITUTION)

# Function that passes 1 argument being a filename and return the number of lines in that file as a
# command substitution. [ COMMAND SUBSTITUTION METHOD ]
############################################################################################################
count_lines () {
    # METHOD 1 [no array] USING sed
	#echo `wc -l $1 | sed 's/^\([0-9]*\).*$/\1/'`

    # METHOD 2 [array] USING read and IFS
    #IFS=' ' read -ra my_array <<< "$1"
    #echo ${my_array[0]}
    
    # METHOD 3 [array] using tr
    my_array=(`wc -l $1 | tr [:space:] "\n"`)
	echo ${my_array[0]}
    # This echo'ed value will be assigned to a variable outside the function using command substitution
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
    #function called with the current file reached
    l=$(count_lines $1)
    #prints filename and the number of lines read
    echo "$1: $l"
    #Update number of lines read so far
    s=$[ $s + $l ]
    #shifts the positional variables by 1 to the left
	shift
done

echo "$no_of_files files in total, with $s lines in total"