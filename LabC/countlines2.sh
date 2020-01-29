#!/bin/bash
# Counting the number of lines in a list of files

# Author: Ridwan Kurmally
# Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

# Question 1 (Shell Function using GLOBAL)

# Function that passes 1 argument being a filename and assigns the global variable l with the number
# of lines in that file. [ GLOBAL METHOD ]
############################################################################################################
count_lines () {
    #A new variable called f is created. This is a local value. Its scope is only within this function.
    local f=$1

    # METHOD 1 [no array] USING sed
	#l=`wc -l $f | sed 's/^\([0-9]*\).*$/\1/'`

    # METHOD 2 [array] USING read and IFS
    #IFS=' ' read -ra my_array <<< "$l"
    #l=${my_array[0]}
    
    # METHOD 3 [array] using tr
    my_array=(`wc -l $f | tr [:space:] "\n"`)
	l=${my_array[0]}
    # The global variable l is assigned a new value and can of course be accessed outside the function
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
    count_lines $1
    #prints filename and the number of lines read
    echo "$1: $l"
    #Update number of lines read so far
    s=$[ $s + $l ]
    #shifts the positional variables by 1 to the left
	shift
done

echo "$no_of_files files in total, with $s lines in total"