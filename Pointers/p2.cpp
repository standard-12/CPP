/* Pointer to pointers */
#include<stdio.h>
int main()
{
    int a = 10;
    int *p;
    int **q;  // Will point to pointer `
    int ***r; // Will point to pointer which is pointing a pointer 
    p = &a;
    q = &p;   
    r = &q; 
    printf("%d \n",a);
    printf("%d \n",p);
    printf("%d \n",*p);
    printf("%d \n",q);
    printf("%d \n",*(*q));
    printf("%d \n",r);
    printf("%d \n",*(*(*r)));
    ***r=12;    // Changes the value of a
    printf("%d \n",a); 

}
