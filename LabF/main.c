//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

#include <stdio.h>
#include <string.h>

/*
QUESTION 1 (a)(b)
*/
int main1() {
    char *str="Hello World!";
    char *p;
    p=str;
    printf("First character is:%c\n",*p);
    p =p+1;
    printf("Next character is:%c\n",*p);
    printf("Printing all the characters in a string\n");
    p=str; //reset the pointer

    for(int i=0;i<strlen(str);i++) {
        printf("%c\n",*p);
        p++;
    }
    return 0;
}

/*
QUESTION 1 (c)
*/
void main2(){

    char *str="Hello World!";
    char *p;
    p=str;
    printf("First character is:%c\n",*p);
    p =p+1;
    printf("Next character is:%c\n",*p);
    printf("Printing all the characters in a string\n");
    p=str; //reset the pointer

   while (*p != '\0')
   {
        printf("%c\n",*p);
        p++;
   }
   
    return;
    
}

/*
QUESTION 1 (d)
*/
void main3(){

    char *str_with_null="Hello World!"; //This string contain the null character at the end
    char array [50]; //We want to copy the above string into this array without the null character
    char *p = str_with_null;
    
    for(int i=0;i<strlen(str_with_null);i++) {
        array[i] = *p;
        p++;
    }
    //at this point array contains "Hello World!" without null termination


    printf ("String without null termination: %s\n", array);
    //You  may or may not see some random characters after the the "Hello World!" depending 
    // on where is the next null character in the memory after this sentence. The program will print anything it see between
    // the first character "H" in the string "Hello World!" and the first null char it hits
    return;

}

//Recursive Factorial Algorithm
int factorial(int n){
    if (n==0){
        return 1;
    } else {
        return (n)*factorial(n-1);
    }
}

/*
QUESTION 2 
This method tests the factorial method
*/
int main4(){
    int x;
    printf("Please enter an integer: ");
    scanf("%d",&x);
    printf("%d! = %d\n", x ,factorial(x));
    return 0;
}


/*
TEACHING INSTRUCTIONS
*/

// As this function accepts argument by value, the parameter passed in from the main will not have their values swapped
void swap_byval (int x, int y){
    int temp = x;
    x = y;
    y = temp;
}

// As this function accepts argument by reference, the parameter passed in from the main will actually have their values swapped
void swap_byref (int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//The argument passed as the n parameter will not have its value changed inside the main and
// and the function will return the incremented value
int increment_byval (int n){
    n = n + 1;
    return n;
}

//The argument passed as the n parameter will have its value changed inside the main 
// and the function will return the incremented value
int increment_byref (int * n){
    *n = *n + 1;
    return *n;
}

// This method is to test the swap_by_val example
// Swapping will not occur in this case
int main5() {
    int a = 1;
    int b = 2;
    printf("Values before calling swap_byval\na: %d, b: %d\n",a,b);
    swap_byval(a,b);
    printf("Values after calling swap_byval\na: %d, b: %d\n",a,b);
}


// This method is to test the swap_by_ref example
// Swapping will occur in this case
int main6() {
    int a = 1;
    int b = 2;
    printf("Values before calling swap_byref\na: %d, b: %d\n",a,b);
    swap_byref(&a,&b);
    printf("Values before calling swap_byref\na: %d, b: %d\n",a,b);
}

// This is the main method that is always executed when the compiled program is run.
// Uncomment only the sub main method that you want to test
int main(){
    //main1();
    //main2();
    //main3();
    //main4();
    //main5();
    //main6();
}



