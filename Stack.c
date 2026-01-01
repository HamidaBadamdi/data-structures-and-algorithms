#include<stdio.h>
#define MAX 3

int stack[MAX];
int top = -1;

void push(int val);
void pop();
int peek();
void update(int idx, int val);
void display();


void main()
{
    int op , val ,x , idx ;
    do
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Update");
        printf("\n5.Display");
        printf("\n6.Exit");

        printf("\n\nEnter Your Choice...");
        scanf("%d" , &op);
         switch(op)
        {
        case 1:
            if(top == MAX-1)
            {

                printf("\nStack is overflow!\n");
                continue;


            }
                printf("Enter Value To Be Pushed : ");
                scanf("%d" , &val);
                push(val);
                break;

            case 2:

                pop();
                break;

            case 3:
                x=peek();
                printf("\nTopmost elements is : %d" , x);
                break;

            case 4:
                printf("Enter Index For The Update : ");
                scanf("%d" , &idx);

                printf("Enter New Value  : ");
                scanf("%d" , &val);
                update(idx , val);
                break;

            case 5:
                if(top == -1)
                {
                    printf("\nStack is empty!\n\n");
                    continue;
                }
                display();
                break;

            case 6:
                printf("You are exiting!");
                return;


            default:
                printf("\nInvalid Choice!");



         }

    }while(op!=6);


}

void push(int val)
{
    top++;
    stack[top] = val;



}
void pop()
{
    int val;
    if(top == -1)
    {
         printf("\n\nStack Underflow!\n");
         return -1;

    }
    else
    {
        printf("\n\n%d is poped...\n", stack[top]);
        top--;

    }
}

int peek()
{
    if(top == -1)
    {
        printf("\n Stack is empty!\n");
        return;
    }

    return stack[top];


}
void update(int idx , int val)
{
    if(top - idx +1 <= -1)
    {
        printf("\nInvalid Index !");
        return;
    }


      stack[top - idx +1] = val;
      printf("\nValue Updated...\n");


}
void display()
{
	int i;
    printf("\n Stack elements are...\n");
    for(i=top; i>=0; i--)
    {
        printf("%d\n" , stack[i]);
    }

}


