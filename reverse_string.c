#include<stdio.h>
#define MAX 30   // Maximum size of the stack

// Function declarations
void push(char s);
char pop();

// Global variables for stack implementation
int top = -1;          // Stack top initialized to -1 (empty stack)
int stack[MAX];      

void main()
{
    char str[30];
    int i;

    
    printf("Enter a String : ");
    gets(str);  

    // Push each character of the string onto the stack
    for(i = 0; str[i] != '\0'; i++)
    {
        push(str[i]);
    }

    // Pop characters from stack to reverse the string
    printf("\nReverse string is as follow : \n");
    while(top != -1)
    {
        printf("%c", pop());
    }
}

// Function to push a character onto the stack
void push(char s)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow!");
        return;
    }

    // Insert element into stack
    top++;
    stack[top] = s;
}

// Function to pop a character from the stack
char pop()
{
    char val;
    if(top == -1)
    {
        printf("\nStack Underflow!");
        return -1;
    }

    // Remove and return the top element
    val = stack[top];
    top--;
    return val;
}


