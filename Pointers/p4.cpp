#include<stdio.h>
int main()
{
    int a[]={1,2,3,4,5};
    int size=sizeof(a)/sizeof(a[0]); // This will calculate no of elements in array
    printf("Main function - Size of a - %d Size of a[0] - %d\n",sizeof(a),sizeof(a[0]));
    int SumOfElements(int a[],int size); // We can also declare 'int a[]' as 'int *a' 
    int sum = SumOfElements(a,size); // Array name itself is the pointer
    printf("Sum = %d \n",sum);
    return 0;
}
int SumOfElements(int a[],int size)
{
    int sum=0;
    printf("SOE - Size of a - %d Size of a[0] - %d\n",sizeof(a),sizeof(a[0]));
    for (int i=0;i<size;i++)
         sum += a[i];  // Although a is not array but a pointer the expression a[i] is same as *(a+i) (Because arrays and pointer are designed similarly for convenience)
    return sum;
}