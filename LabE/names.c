//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

#include<stdio.h>
#include<stdlib.h>

//QUESTION ONE
int main(int argc, char const *argv[])
{
    char name[30],multipleNames[1000];
    int numberOfTimes;

    /*
    PLEASE NOTE THAT THERE'S A MISTAKE IN THE LAB PDF.
    THE IF BRANCHES FROM THE LAB PDF ARE WRONG.
    THEY HAVE TO BE INTERCHANGED. 
    THE IF BRANCHES BELOW ARE CORRECT.

    Reasoning is that let's say you compiled names.c as names and run it with those parameters:-

    Case 1:
    ./names
    In that case, argc = 1 and therefore numberOfTimes should be set to 2 according to the lab

    Case 2:
    ./names 5
    In that case, argc = 2 and therefore numberOfTImes should be set to atoi(argv[1]) which is 5 here.
    */
   if (argc ==1) 
    {
        numberOfTimes=2;
    } else {
        numberOfTimes= atoi(argv[1]);
    }

    printf("Enter a name: ");
    scanf("%s",name);

    // We are not allowed to use strlen to find the length of the name
    // Instead, count the letters in name, which is an array of char, until we
    // we hit the null character indicating the end of the string.
    int count = 0;
    while (name[count]!='\0'){
        count++;
    }

    //Now we will be populating the multipleNames array.

    //Index of the current position being editted in the multipleNames
    int currIndex = 0;
    // For each copies of the name
    for (int i = 0; i < numberOfTimes; i++)
    {
        //Copy 1 copy of the name in the multiple array
        for (int j = 0; j< count; j++)
        {
            multipleNames[currIndex] = name[j];
            currIndex++;
        }
    }
    //multipleNames, being a string, should be null-terminated
    multipleNames[currIndex]='\0';

    //Prints the copies of the name
    printf("%s\n", multipleNames);
    return 0;
}
