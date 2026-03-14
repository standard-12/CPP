/* Pointers and 2D Arrays*/
#include<stdio.h>
int main()
{
    int a[2][2][3]={{1,2,3},{4,5,6}};
    int *p;
    p=a[0][0];
    int (*ptr)[2][3];
    ptr=a;
    printf("%d\n",***ptr);
    printf("%d\n",*p);
    printf("%d\n",**a);

    

    return 0;
}