void main()
{
    int a[5] ,b[5] , c[10] , i, j=0;



	printf("Enter Value For Array A : \n");
   for(i=0; i < sizeof(a) / sizeof(int); i++)
   {
       printf("\nEnter Value  %d : " , i+1);
       scanf("%d" , &a[i]);

   }

   printf("\n\nEnter Value For Array B : \n");
   for(i=0; i < sizeof(b) / sizeof(int); i++)
   {
       printf("\nEnter Value  %d : " , i+1);
       scanf("%d" , &b[i]);

   }
   for(i=0; i <sizeof(a) / sizeof(int); i++)
   {
       c[j] = a[i];
       j++;
    }
    
   for(i=0; i < sizeof(b) / sizeof(int); i++)
   {
       c[j] = b[i];
       j++;
   }
   
    printf("\nMerged Array:\n");
    for(i=0; i < sizeof(c) / sizeof(int); i++)
   {
       printf("%d\t"  , c[i]);
   }
}
