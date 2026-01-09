#include<stdio.h>

// Function declaration for Tower of Hanoi
// n    : number of disks
// from : source rod
// to   : destination rod
// aux  : auxiliary rod

void toh(int n, char from, char to, char aux);

void main()
{
    int no;

    // Take number of disks from the user
    printf("Enter no. of disk : ");
    scanf("%d", &no);

    // Call Tower of Hanoi function
    toh(no, 'A', 'C', 'B');
}

// Recursive function to solve Tower of Hanoi problem
void toh(int n, char from, char to, char aux)
{
    // Base case: only one disk
    if(n == 1)
    {
        printf("\nMove disk 1 from %c Rod to %c Rod", from, to);
        return;
    }

    // Move n-1 disks from source rod to auxiliary rod
    toh(n - 1, from, aux, to);

    // Move the nth disk from source rod to destination rod
    printf("\nMove Disk %d from %c Rod to %c Rod", n, from, to);

    // Move the n-1 disks from auxiliary rod to destination rod
    toh(n - 1, aux, to, from);
}

