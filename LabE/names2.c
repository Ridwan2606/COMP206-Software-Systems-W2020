//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//QUESTION TWO
int main(int argc, char const *argv[])
{
    char name[30],multipleNames[1000];
    int numberOfTimes;
    
    if (argc ==1) 
    {
        numberOfTimes=2;
    } else {
        numberOfTimes= atoi(argv[1]);
    }

    printf("Enter a name: ");

   int index = -1;
   do { 
       index++; 
       name[index] = getc(stdin); 
    } while(name[index] != '\n');

    name[index]='\0';

    // At this point onwards, we can repeat the same algorithm in 
    // Question 1. I am showing an alternative that using the 
    // strcat function from the string.h library.

    //We want to use strcat to concatenate numberOfTimes copies of the name.
    //Because of the way strcat works, we need to make sure that the first character in
    //the multipleNames is the null character. 
    // Each call to strcat will add 1 new copy of name starting from the 
    // null character in the array.
    multipleNames[0]='\0';

    //Add numberOfTimes copies of name in the array multipleNames.
    for (int i = 0; i < numberOfTimes; i++)
    {
        strcat(multipleNames,name);
    }

    //Prints the copies of the name
    printf("%s\n", multipleNames);

    return 0;
}
