/*
------------------------------------------------------------
Program Name   : Circular Doubly Linked List

Description :
    This program demonstrates a menu-driven implementation
    of a Circular Doubly Linked List in C. It supports various
    operations such as insertion, deletion, searching,
    updating, counting, and sorting of nodes.

Author      : Hammida Badamdi
------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    struct node *next;
    int data;
    struct node *prev;
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
void delete_node();
void search();
void count();
void sort();
void update();



void main()
{
    int option;
    do
    {
        printf("\n\n***** MAIN MENU *****");
        printf("\n1: Create a list");
        printf("\n2: Display the list");
        printf("\n3: Add a node at the beginning");
        printf("\n4: Add a node at the end");
        printf("\n5: Insert before a specific node");
        printf("\n6: Insert after a specific node");
        printf("\n7: Delete a node from the beginning");
        printf("\n8: Delete a node from the end");
        printf("\n9: Delete a specific node");
       	printf("\n10: Search Node");
		printf("\n11: Update");
		printf("\n12: Count");
		printf("\n13: Sort");
		printf("\n14: EXIT");
      
        printf("\n\nEnter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            create_ll();
            printf("\nCIRCULAR DOUBLY LINKED LIST CREATED\n");
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
            delete_node();
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
            	printf("\nInvalid Option! Try Again.\n");	
            	break;
	 }
  }while(option !=14);
    
}

// Creates a circular doubly linked list
void create_ll()
{
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter data: ");
    scanf("%d", &num);

    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;

        if (start == NULL)
        {
            start = new_node;
            new_node->next = start;
            new_node->prev = start;
        }
        else
        {
            ptr = start->prev;
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = start;
            start->prev = new_node;
        }

        printf("Enter data: ");
        scanf("%d", &num);
    }
}

// Displays all elements of the circular doubly linked list
void display()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    ptr = start;
    printf("\nList elements: ");
    while (1)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
        if (ptr == start)
            break;
    }
    printf("\n");
}

// Inserts a node at the beginning of the list
void insert_beg()
{
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if (start == NULL)
    {
        start = new_node;
        new_node->next = start;
        new_node->prev = start;
    }
    else
    {
        ptr = start->prev;
        new_node->next = start;
        new_node->prev = ptr;
        ptr->next = new_node;
        start->prev = new_node;
        start = new_node;
    }
}

// Inserts a node at the end of the list
void insert_end()
{
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if (start == NULL)
    {
        start = new_node;
        new_node->next = start;
        new_node->prev = start;
    }
    else
    {
        ptr = start->prev;
        ptr->next = new_node;
        new_node->prev = ptr;
        new_node->next = start;
        start->prev = new_node;
    }
}

// Inserts a node before a specific value
void insert_before()
{
    struct node *new_node, *ptr;
    int val, num, found = 0;
    if (start == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nEnter value before which to insert: ");
    scanf("%d", &val);
    printf("Enter new data: ");
    scanf("%d", &num);

    ptr = start;
    while (1)
    {
        if (ptr->data == val)
        {
            found = 1;
            break;
        }
        ptr = ptr->next;
        if (ptr == start)
            break;
    }

    if (!found)
    {
        printf("\nNode not found!\n");
        return;
    }

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if (ptr == start)
    {
        insert_beg();
        free(new_node);
    }
    else
    {
        new_node->next = ptr;
        new_node->prev = ptr->prev;
        ptr->prev->next = new_node;
        ptr->prev = new_node;
    }
}
// Inserts a node after a specific value
void insert_after()
{
    struct node *new_node, *ptr;
    int val, num, found = 0;
    if (start == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nEnter value after which to insert: ");
    scanf("%d", &val);
    printf("Enter new data: ");
    scanf("%d", &num);

    ptr = start;
    while (1)
    {
        if (ptr->data == val)
        {
            found = 1;
            break;
        }
        ptr = ptr->next;
        if (ptr == start)
            break;
    }

    if (!found)
    {
        printf("\nNode not found!\n");
        return;
    }

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    new_node->next = ptr->next;
    new_node->prev = ptr;
    ptr->next->prev = new_node;
    ptr->next = new_node;
}

// Deletes the first node of the list
void delete_beg()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    if (start->next == start)
    {
        free(start);
        start = NULL;
        return;
    }

    ptr = start->prev;
    struct node *temp = start;
    start = start->next;
    ptr->next = start;
    start->prev = ptr;
    free(temp);
}
// Deletes the last node of the list
void delete_end()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    if (start->next == start)
    {
        free(start);
        start = NULL;
        return;
    }

    ptr = start->prev;
    ptr->prev->next = start;
    start->prev = ptr->prev;
    free(ptr);
}
// Deletes a node containing a specific value
void delete_node()
{
    struct node *ptr;
    int val, found = 0;
    if (start == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nEnter value of node to delete: ");
    scanf("%d", &val);

    ptr = start;
    while (1)
    {
        if (ptr->data == val)
        {
            found = 1;
            break;
        }
        ptr = ptr->next;
        if (ptr == start)
            break;
    }

    if (!found)
    {
        printf("\nNode not found!\n");
        return;
    }

    if (ptr->next == start && ptr->prev == start)
    {
        free(ptr);
        start = NULL;
    }
    else if (ptr == start)
    {
        delete_beg();
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }
}
// Searches for a value in the list
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
	
	do
	{
		if(ptr->data == val)
		{
			found = true;
			printf("%d Found ." , ptr->data);
			break;
		}
		ptr = ptr->next;
	}while(ptr != start);

	
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
	
	do
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
		
	}while(ptr != start);
	
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
		return;
	}
	ptr = start;
	
	do
	{
		ptr = ptr->next;
		count++;
	}while(ptr != start);
	
	printf("Total No. of Nodes : %d" , count);
}
// Sorts the circular doubly linked list
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
	do
	{
		ptr2 = ptr1->next;
		while(ptr2 != start)
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
	}while(ptr1!= start);
	
	printf("\nSorted Linked List : ");
	ptr1 = start;
	
	do
	{
		printf("\t%d" , ptr1->data);
		ptr1 = ptr1->next;	
	}while(ptr1 != start);
}



