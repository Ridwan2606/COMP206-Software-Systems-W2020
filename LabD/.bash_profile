# Lab D - Question 1 Editting your login script
# Author: Ridwan Kurmally
# Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

# Do note that different accounts can have different login script.
# In my case, it was .bash_profile. But other accounts can have
# .bashrc or .profile etc can login script
# It's really for you to find out which one is the right login script.
# Login scripts are hidden files because of the naming convention that places
# a "." before the file name. 
# Display hidden files using "ls -a" and look at the potential candidate 
# for your login scripts.

# PS1 is an environment variable that stores the prompt.
# PS1 is one of those variables whose content are erased upon logging out.
# By including the assignment of PS1 in the login script, 
# we ensure that we will always the phrase below as our prompt.
export PS1="Ridwan Kurmally $"

# Welcomes the user to his/her login shell.
echo "Welcome to your login Shell"


