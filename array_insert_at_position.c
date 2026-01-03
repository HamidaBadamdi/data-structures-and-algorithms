void main()
{
   int arr[5], i , pos , newVal;



    printf("Enter 5 Value For Array : \n");
   for(i=0; i < sizeof(arr) / sizeof(int); i++)
   {
       printf("\nEnter Value  %d : " , i+1);
       scanf("%d" , &arr[i]);

   }

   printf("\n\nEnter Position  :");
    scanf("%d" , &pos);

    printf("\nEnter New Value For Position  %d :" , pos);
    pos--;

    scanf("%d" , &newVal);

    if(pos > sizeof(arr) / sizeof(int))
    {

        printf("Invalid Index !");
    }

    for(i=sizeof(arr) / sizeof(int)+1; i>=pos; i--)
    {
        arr[i] = arr[i-1];


    }
    arr[pos] = newVal;
    
    printf("\n\nArray elements are : \n");
    for(i=0; i < sizeof(arr) / sizeof(int) + 1; i++)
   {
       printf("\t%d" , arr[i]);


   }

}


