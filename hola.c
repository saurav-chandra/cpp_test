#include<stdio.h>
int main()
{
    int i,j,s;
    printf("enter size of an array : ");
    scanf("%d",&s);
    int arr[s];
    int b[s];
    printf("\nenter %d elements : ",s);
    for(i=0;i<s;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<s;i++)
    b[i]=arr[i];
    printf("\nnow i will check if any item is repeated\n");
    for(i=0;i<s;i++)
        if(arr[i]==b[i]);
            printf("%d ",b[i+1]);
    //printf("are repeated");
return 0;
}