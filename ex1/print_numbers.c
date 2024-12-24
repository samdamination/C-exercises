/*
**    EX-1) Write a function with the following declaration: (20')
**
**          int print_numbers(const char * input);
**
**      The function print_numbers must print on the standard output all the numbers in the input
**      string, each on an individual line. A number is a contiguous sequence of digits (characters ’0’,
**      . . . , ’9’) possibly preceded by a sign (characters ’-’ or ’+’). The function returns the total count
**      of numbers printed. Write your implementation in a file called print_numbers.c.
**
*/

#include <stdio.h>
#include <ctype.h>


int print_numbers(const char * input){
    const char *ptr = input;  // Pointer to traverse the input string
    int in_number = 0;        // Flag to indicate we are inside a number

    while (*ptr != '\0') {    // Loop until the end of the string
        if (*ptr == '-' || *ptr == '+' || isdigit(*ptr)) {
            if (!in_number) {
                in_number = 1; // Mark that we are inside a number
            }
            printf("%c", *ptr);
        } else {
            if (in_number) {
                // End the current number
                printf("\n");
            }
            in_number = 0;      // Reset the flag
        }
        ptr++;                  // Move to the next character
    }

    // Print a newline if the string ends while inside a number
    if (in_number) {
        printf("\n");
    }

    return 1; // Return the count of numbers found
}

int main(){
    const char * test_input = "abc -123 +456 789 def gh-012 prova non si 1 sa mai";
    print_numbers(test_input);
}


/*
ABOVE SOLUTION BY CHAT-GPT
*/