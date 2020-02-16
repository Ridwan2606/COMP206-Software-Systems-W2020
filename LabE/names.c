#include<stdio.h>
#include<stdlib.h>

//QUESTION ONE
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
    scanf("%s",name);

    // We are not allowed to use strlen to find the length of the name
    // Instead, count the letters in name, which is an array of char, until we
    // we hit the null character indicating the end of the string.
    int length = 0;
    int index = 0;
    while (name[index]!='\0'){
        length++;
        index++;
    }

    //Now we will be populating the multipleNames array.

    //Index of the current position being editted in the multipleNames
    int currIndex = 0;
    // For each copies of the name
    for (int i = 0; i < numberOfTimes; i++)
    {
        //Copy 1 copy of the name in the multiple array
        for (int j = 0; j< length; j++)
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
