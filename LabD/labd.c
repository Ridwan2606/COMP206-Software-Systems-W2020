//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

#include <stdio.h>
//We need to include stdio.h library to use the "puts" function

//main function that is executed.
int main() {
    //int variable
    int count = 5;

    // for i=0,1,2,3,4
    for (int i = 0; i < count; i++)
    {
        //Prints Hello World followed by 2 newlines.
        puts("Hello World\n\n");
    }

    // Return 0 for successful execution of main method (That's a convention)
    return 0;
}