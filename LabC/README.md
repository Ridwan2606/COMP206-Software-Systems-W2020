routine.sh: Simple script showcasing basics of bash script with a given scenario
countlines1.sh : Explicit For Loop example
countlines2.sh : Shell Function using global method
countlines3.sh : Shell Function using command substitution method
countlines4.sh : Shell Function using eval method

The countlines files were slightly modified from the bash scripts at this website:
https://www.macs.hw.ac.uk/~hwloidl/Courses/LinuxIntro/x945.html

RETURNING VALUES VS RETURNING ERROR CODE:

Do note that in all the countlines script, we are returning actual values from the function.
Returning values from function will either use 1 of the 3 above methods and the returned value
can somewhat be of whatever length or type we wish.

Returning error code from function can only happen using the "exit" or "return" command.
The error code will then necessarily be in $? after the exit/return command.
This error code will be an int ranging from 0 - 255. 

Also, if you have a function that return a value which you're sure will be between 0 to 255,
instead of going with global/command substitution/eval method, you can return an "error" code 
(more like a status code) that correspond to that value using "return". The value will then 
be stored in $? .

Use "exit" if a major goof happened as it will set $? to the error code and terminate the script.
Using "return" will set $? to the error code and will take you back to the line which invoked that function in the script.

That's the main difference between returning values and error code.