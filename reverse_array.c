void main()
{
   int a[5] ,i;
   
    printf("Enter Value For Array.....\n");
   for(i=0; i < sizeof(a) / sizeof(int); i++)
   {
       printf("\nEnter Value  %d : " , i+1);
       scanf("%d" , &a[i]);
   }
   
   printf("\n\nActual Array : \n");
   for(i=0; i < sizeof(a) / sizeof(int); i++)
   {
        printf("%d " , a[i]);

   }
   
   printf("\n\nReverse Array : \n");
   for(i=sizeof(a) / sizeof(int) - 1; i >=0; i--)
   {
   		printf("%d " , a[i]);
   }
}
