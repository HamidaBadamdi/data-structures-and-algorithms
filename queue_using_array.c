#include<stdio.h>
#define MAX 5

int front = -1 , rear = -1;
int queue[MAX];

void insert();
void delete_element();
void display();

void main()
{
    int op;

    do
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter Your Choice : ");
        scanf("%d" , &op);


        switch(op)
        {
            case 1:
                insert();
                break;
            case 2:
                delete_element();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExit...");
                break;
            default:
                printf("\nInvalid Option !");
                break;



        }

    }while(op!=4);

}
void insert()
{
    int val;
    if(rear == MAX -1 )
    {
        printf("\nQueue Overflow !");
        return;
    }


    else
    {
        printf("\n\nEnter Value to be inserted : ");
        scanf("%d" , &val);

        if(front == -1 && rear == -1)
        {

            front = rear = 0;
        }
        else
        {

            rear++;
        }

        queue[rear] = val;
    }

}
void delete_element()
{
    int val;

    if(front == -1)
    {

        printf("\n Queue is empty!");
        return;
    }
    else
    {
        val = queue[front];
        printf("%d is deleted ..." , val);

        if(front == rear)
        {
            front = rear = -1;
        }
        else{
            front++;
        }
    }


}
void display()
{
        if(front != -1)
        {
            printf("\n Elements are...");

            for(int i=front; i<=rear; i++)
            {

                printf("\t%d"  ,queue[i]);
            }

       }
    else
    {

        printf("\n queue is empty!");
    }

}

