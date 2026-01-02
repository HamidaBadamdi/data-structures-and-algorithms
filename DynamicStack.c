#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push() {
    int value;
    
	//Dynamic Memory allocation....
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to push: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed into stack.\n", value);
}

void pop() {
    if (top == NULL)
        printf("Stack Underflow! Stack is empty.\n");
    else {
        struct Node *temp = top;
        printf("%d popped from stack.\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    struct Node *temp = top;
    if (temp == NULL)
        printf("Stack is empty.\n");
    else
    {
        printf("Stack elements are:\n");
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}
int peek()
{
	return top->data;
}
void update()
{
	int idx,val,i;
	struct Node *temp = top;
	
	if(top == NULL)
	{
		printf("\nStack is empty!");
		return;
	}
	
	printf("\nEnter the Index :");
	scanf("%d" , &idx);
	
	printf("\nEnter new value foe index %d to be updated : " , idx);
	scanf("%d" , &val);
	
	while(temp != NULL && i < idx)
	{
		temp = temp->next;
		i++;
	}

	
	if(temp == NULL)
	{
		printf("\nInvalid index!\n");
		return;
	}
	else
	{	temp->data = val;
		printf("\nValue updated...\n");
	}
	
	
}
void main()
{
    int choice,x;
    while (1)
    {
        printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. PEEK\n5. UPDATE\n6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: x=peek(); printf("Topmost element is : %d " , x);break;
            case 5: update(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
