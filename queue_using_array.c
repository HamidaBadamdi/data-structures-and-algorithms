#include <stdio.h>
#define MAX 5   // Maximum size of the queue

int front = -1, rear = -1;   // Queue pointers
int queue[MAX];              // Queue array

// Function declarations
void insert();
void delete_element();
void display();

int main()
{
    int op;

    // Menu-driven program
    do
    {
        printf("\n\n---- Queue Operations ----");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter Your Choice : ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                insert();          // Enqueue operation
                break;
            case 2:
                delete_element();  // Dequeue operation
                break;
            case 3:
                display();         // Display queue elements
                break;
            case 4:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid Option!");
        }

    } while (op != 4);

    return 0;
}

// Function to insert an element into the queue
void insert()
{
    int val;

    // Check for queue overflow
    if (rear == MAX - 1)
    {
        printf("\nQueue Overflow!");
        return;
    }

    printf("\nEnter value to be inserted : ");
    scanf("%d", &val);

    // If queue is empty, initialize front and rear
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;   // Move rear forward
    }

    queue[rear] = val;  // Insert element
}

// Function to delete an element from the queue
void delete_element()
{
    int val;

    // Check for queue underflow
    if (front == -1)
    {
        printf("\nQueue is empty!");
        return;
    }

    val = queue[front];
    printf("\n%d is deleted...", val);

    // If only one element was present
    if (front == rear)
    {
        front = rear = -1;  // Reset queue
    }
    else
    {
        front++;  // Move front forward
    }
}

// Function to display queue elements
void display()
{
    int i;

    // Check if queue is empty
    if (front == -1)
    {
        printf("\nQueue is empty!");
        return;
    }

    printf("\nQueue elements are:");
    for (i = front; i <= rear; i++)
    {
        printf("\t%d", queue[i]);
    }
}
