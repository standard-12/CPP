/* Pointers and Arrays*/

#include<stdio.h>
int main()
{
    int A[]={2,3,5,1};
    int i;
    int *p;
    p=A;  // Or we can also use p=&A[0]
    printf("%d \n",A);
    printf("%d \n",p);
    printf("%d \n",*A);
    printf("%d \n",*p);
    p++; // or p=p+1 is valid but A++ or A=A+1 is not valid
    //A=A+1;  This is not valid we cannot modify the value of A but in next line we have accessed 2nd element by A+1....Modification is not allowed
    printf("%d \n",A+1);
    for(i=0;i<4;i++)
        printf("%d \n",*(A+i));
            
}