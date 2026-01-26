/*
-------------------------------------------------------
Program Name : Doubly Linked List in C

Description  :
This program implements a menu-driven Doubly Linked List
using dynamic memory allocation. It allows the user to
perform various operations such as insertion, deletion,
searching, updating, counting, sorting, and displaying
nodes in the list.

Concepts Used:
- Structures
- Pointers
- Dynamic memory allocation (malloc/free)
- Menu-driven programming
- Doubly linked list traversal

Author       : Hamida Badamdi
-------------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure definition for a doubly linked list node
struct node
{
    struct node *prev; 		// Pointer to previous node
    int data;				// Data part
    struct node *next;		// Pointer to next node
};

struct node *start = NULL;

void create_ll();
void display();
void insert_beg();
void insert_end();
void insert_before();
void insert_after();
void delete_beg();
void delete_end();
void delete_specific();
void search();
void count();
void sort();
void update();

void main()
{
    int option;

    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a specific node");
        printf("\n 10: Search Node");
		printf("\n 11: Update");
		printf("\n 12: Count");
		printf("\n 13: Sort");
		printf("\n 14: EXIT");
       
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                create_ll();
                printf("\n DOUBLY LINKED LIST CREATED");
                break;
            case 2:
                display();
                break;
            case 3:
                insert_beg();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_before();
                break;
            case 6:
                insert_after();
                break;
            case 7:
                delete_beg();
                break;
            case 8:
                delete_end();
                break;
            case 9:
                delete_specific();
                break;
            case 10:
				 search();
				 break;
			case 11:
				 update();
				 break;
			case 12:
				 count();
				 break;
			case 13:
				 sort();
				 break;				
			case 14:
                printf("\n Exit..");
                break;
            default:
                printf("\n Invalid..");
                break;
		}
	}while(option !=14);
}

// Function to create a doubly linked list
void create_ll()
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while(num != -1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->prev = NULL;
        new_node->next = NULL;

        if(start == NULL)
        {
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->prev = ptr;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
}

void display()
{
    struct node *ptr = start;
    if(ptr == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    printf("\n Doubly linked list elements:");
    while(ptr != NULL)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
}

// Function to insert a node at the beginning of the list
void insert_beg()
{
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->prev = NULL;
    new_node->next = start;

    if(start != NULL)
        start->prev = new_node;

    start = new_node;
}

void insert_end()
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;

    if(start == NULL)
    {
        new_node->prev = NULL;
        start = new_node;
        return;
    }

    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = new_node;
    new_node->prev = ptr;
}

void insert_before()
{
    struct node *new_node, *ptr;
    int num, val;

    if(start == NULL)
    {
        printf("\n List is empty.");
        return;
    }

    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);

    ptr = start;
    while(ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if(ptr == NULL)
    {
        printf("\n Value not found.");
        return;
    }

    if(ptr == start)
    {
        printf("\n Value is in the first node. Use 'Add a node at the beginning' option instead.\n");
        return;
    }

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;

    new_node->next = ptr;
    new_node->prev = ptr->prev;

    ptr->prev->next = new_node;
    ptr->prev = new_node;
}

void insert_after()
{
    struct node *new_node, *ptr;
    int num, val;

    if(start == NULL)
    {
        printf("\n List is empty.");
        return;
    }

    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted : ");
    scanf("%d", &val);

    ptr = start;
    while(ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if(ptr == NULL)
    {
          printf("\n Value not found.");
        return;
    }

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;

    new_node->prev = ptr;
    new_node->next = ptr->next;

    if(ptr->next != NULL)
        ptr->next->prev = new_node;

    ptr->next = new_node;
}

void delete_beg()
{
    struct node *ptr;

    if(start == NULL)
    {
        printf("\n List is empty.");
        return;
    }

    ptr = start;
    start = start->next;

    if(start != NULL)
        start->prev = NULL;

    free(ptr);
}

void delete_end()
{
    struct node *ptr;

    if(start == NULL)
    {
        printf("\n List is empty.");
        return;
    }

    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;

    if(ptr->prev != NULL)
        ptr->prev->next = NULL;
    else
        start = NULL;

    free(ptr);
}
// Function to delete a specific node by value

void delete_specific()
{
    struct node *ptr;

    int val;

    if(start == NULL)
    {
        printf("\n List is empty.");
        return;
    }

    printf("\n Enter the value of the node which has to be deleted : ");
    scanf("%d", &val);

    ptr = start;

    while(ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if(ptr == NULL)
    {
        printf("\n Value not found.");
        return;
    }

    if(ptr == start)
    {
        delete_beg();
        return;
    }

    if(ptr->next != NULL)
        ptr->next->prev = ptr->prev;

    if(ptr->prev != NULL)
        ptr->prev->next = ptr->next;

    free(ptr);
}
void search()
{
	struct node *ptr; 
	int val;
	bool found = false;
	if(start == NULL)
	{
		printf("\nLinked List is empty !");
		return;
	}
	
	printf("\nEneter Value to be search : ");
	scanf("%d" , &val);
	
	ptr = start;
	
	while(ptr != NULL)
	{
		if(ptr->data == val)
		{
			found = true;
			printf("%d Found ." , ptr->data);
			break;
		}
		ptr = ptr->next;
	}
	
	if(!found)
	{
		printf("\n%d Not Found !" , val);
	}
}
void update()
{
	struct node *ptr;
	int idx = 0, count = 1 , num;
	bool valid = false;	
	
	if(start == NULL)
	{
		printf("\nLinked List is empty !");
		return 0;
	}
	
	printf("\nEnter index : ");
	scanf("%d" , &idx);
	
	printf("Enter new value for index %d : " , idx);
	scanf("%d" , &num);
	
	ptr = start;
	
	while(ptr != NULL)
	{
		if(idx == count)
		{
				ptr->data = num;
				printf("%d value is update at index %d ."  , num , idx);
				valid = true;
				break;
		}	
		
		ptr = ptr->next;
		count++;
	}
	
	if(!valid)
	{
		printf("Invalid Index %d !"  , idx);
	}
}
void count()
{
	struct node *ptr;
	int count;
	if(start == NULL)
	{
		printf("\nLinked List is empty !");
		return 0;
	}
	ptr = start;
	
	while(ptr != NULL)
	{
		ptr = ptr->next;
		count++;
	}
	printf("Total No. of Nodes : %d" , count);
}
void sort()
{
	struct node *ptr1 , *ptr2;
	int temp;
	if(start == NULL)
	{
		printf("\nLinked List is empty !");
		return;
	}
	
	ptr1 = start;
	while(ptr1->next != NULL)
	{
		ptr2 = ptr1->next;
		while(ptr2 != NULL)
		{
			if(ptr1->data > ptr2->data)
			{
				temp = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = temp;
				
			}
			
			ptr2 = ptr2->next;
		}
		
		ptr1 = ptr1->next;
	}
	
	printf("\nSorted Linked List : ");
	ptr1 = start;
	
	while(ptr1 != NULL)
	{
		printf("\t%d" , ptr1->data);
		ptr1 = ptr1->next;	
	} 

}


