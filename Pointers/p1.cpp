/*This program demonstrates why pointers are declared with strong types
    1. For Accessing and modification
    2.  For pointer arithmetics */
#include<stdio.h>
int main()
{
    int a = 1025; //Which will be stored as 00000000 00000000 00000100 00000001
    int *p;
    p=&a;
    printf("Size of int is %d\n",sizeof(a));
    printf("Address = %d , Value = %d\n",p,*p);
    char *po; // Pointer which points to character type data
    po = (char*) p; //TypeCast 
    printf("Size of int is %d\n",sizeof(a));
    printf("Address = %d , Value = %d\n",p,*p);  // Dereferencing using integer pointer 
    printf("Address = %d , Value = %d\n",p,*po); // Dereferencing using Character pointer this prints "1" because character point reads only 1 byte which is (00000001) 
    printf("POINTER ARITHMETICS\n");
    printf("Address = %d , Value = %d\n",p,*p);
    printf("Address = %d , Value = %d\n",p+1,*(p+1)); // Incrementing a integer pointer. Value will be garbage value
    printf("Address = %d , Value = %d\n",po,*po);
    printf("Address = %d , Value = %d\n",po+1,*(po+1)); // Incrementing a character pointer. Here Value is 4 because now it points to next byte (00000100)

}