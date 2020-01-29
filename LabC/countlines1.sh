#!/bin/bash

# Author: Ridwan Kurmally
# Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

# Question 1 (Explicit For Loop)
# Counting the number of lines in a list of files
# for loop over arguments

if [ $# -lt 1 ] #if the number of arguments is less than 2, we have to files to count
then
  echo "Usage: $0 file ..."
  exit 1
fi

#Prints to the screen "q1.sh counts the lines of code"
echo "$0 counts the lines of code" 

#n stores number of files read so far
n=0
#s stores number of lines read so far
s=0
#l stores number of lines found in the current file
l=0

#for f in [$1,$2,$3...]
for f in $*
do
    # METHOD 1 [no array] USING sed
	#l=`wc -l $f | sed 's/^\([0-9]*\).*$/\1/'`

    # METHOD 2 [array] USING read and IFS
    #IFS=' ' read -ra my_array <<< "$l"
    #l=${my_array[0]}
    
    # METHOD 3 [array] using tr
    my_array=(`wc -l $f | tr [:space:] "\n"`)
	l=${my_array[0]}

    # Method 4 but not applicable for this case.
    #Note that we could have easily split 
    #the output of `wc -l $f` as positional variables using "set" as shown below:
    # set `wc -l $f`
    # $1 would hold the number of lines
    # $2 would hold the file name
    # This is not convenient as this will overwrite the filenames in $1 and $2.

    #Increment number of files
    n=$[ $n + 1 ]
    #Update number of lines read so far
    s=$[ $s + $l ]
done

#Prints result. Note the number of files is also given $#.
echo "$n files in total, with $s lines in total"