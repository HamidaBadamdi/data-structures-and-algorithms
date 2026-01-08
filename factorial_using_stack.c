#include<stdio.h>
#define MAX 10
int top = -1;
int stack[MAX];
void push(int val);
int pop();
void main()
{
    int i , n , fact =1;
    
    printf("Enter The Number : ");
    scanf("%d"  , &n);

    for(i=1; i<=n; i++)
    {
        push(i);
    }
    
    while(top != -1)
    {
        fact = fact * pop();
    }
    printf("\n\nFactorial of No. %d is : %d " , n , fact);
}
void push(int val)
{

    if(top == MAX-1)
    {
        printf("\nStack is overflow !");
        return;
    }
    else
    {	
		top++;
        stack[top] = val;
    }
}

int pop()
{
    int val;
    if(top == -1)
    {
         printf("\n\nStack Underflow!");
         return -1;

    }
    val = stack[top];
    top--;
    return val;
}
