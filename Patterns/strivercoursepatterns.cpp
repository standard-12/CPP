#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>
using namespace std;
   void lefttriangle(int n)
    {
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    }
   void number1(int n){
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<i;j++){
            printf("%d",j+1);

        }
        printf("\n");
    }
   }
  void number2(int n){
    for (int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
        printf("%d",i);
        }
        printf("\n");
    }
  }
   void invertedtriangle(int n){
    for (int i=0;i<n;i++)
    {
    for(int j=n-i;j>0;j--){
        printf("* ");
    }
    printf("\n");
    }
   }
   void star2(int n){
    for (int i=n;i>=0;i--)
    {
        for(int j=1;j<=i;j++){
            printf("%d ",j);
        }
        printf("\n");
    }
   }
   void pyramid(int n){    
      for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
   }
   void invertedpyramid(int n){
    for(int i=n;i>0;i--){
        for(int k=0;k<n-i;k++)
        {
            printf(" ");
        }
        for(int j=0;j<2*i-1;j++){
            printf("*");
        }
        printf("\n");
        
    }
   }
   void diamond(int n){
    for(int i=0;i<2*n;i++){
        if(i<n){
        for(int j=n-1;j>i;j--){
            printf(" ");
        }
        for(int k=0;k<2*(i+1)-1;k++){
            printf("*");
        }
        printf("\n");
        }
        else
        {  for(int k=i;k>n;k--){
            printf(" ");
        }           
            for(int j=0;j<2*(2*n-i)-1;j++){
            printf("*");
        }    
        printf("\n");
        }
    }
   }
   void verticaltriangle(int n){
    for(int i=1;i<2*n;i++){
        if(i<=n){
        for(int j=0;j<i;j++){
            printf("*");
        }
        printf("\n");
    }
        else{
            for(int j=1;j<=2*n-i;j++){
                printf("*");
            }
            printf("\n");
        }
    }
   }
   void pattern_01_triangle(int n){
    for(int i=0;i<n;i++){        
            for(int j=0;j<=i;j++){
                if(abs(i-j)%2==0){
                    printf("1");
                }
                else{
                    printf("0");
                }
            }
            printf("\n");        
    }
   }
   void left_and_right_triangle(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
        cout<<j;
        for(int j=1;j<=2*(n-i);j++)
        cout<<" ";
        for(int j=i;j>=1;j--)
        cout<<j;

        cout<<endl;
    }
   }

   void increasing_number_triangle(int n){
    int k=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<k<<" ";
            k++;
        }
        cout<<endl;
    }
   }

   void printABCtriangle(int n){
    for(int i=0;i<n;i++){
        for(char ch='A';ch<='A'+i;ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
   }

   void printABCultatriangle(int n){
    for(int i=n;i>0;i--){
        for(char ch='A';ch<'A'+i;ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
   }

   void printABBCCC(int n){
    for(int i=0;i<n;i++){
        char ch='A'+i;
        for(int j=0;j<=i;j++){    
            cout<<ch<<" ";
        }
        cout<<endl;
    }
   }

   void ABCpyramid(int n){
    for(int i=0;i<n;i++){
    
    for(int j=0;j<n-i-1;j++){
        cout<<" ";
    }
    char ch='A';
    for(int l=0;l<2*i+1;l++){
        cout<<ch;
        if(l<(2*i+1)/2){
            ch++;
        }
        else {
            ch--;
        }
    }
    for(int k=0;k<n-i-1;k++){
        cout<<" ";
    }
    cout<<endl;
   }
}

void StartEpyramid(int n){
    
    for(int i=0;i<n;i++){
        char ch='A'+n-1;
        for(int j=0;j<=i;j++){
            cout<<ch--;
        }
        cout<<endl;
    }
}

void pattern19(int n){
    for(int c=0;c<2*n;c++){
    int k=c;
    if(c>=n){
        k=n-(c-n+1);
    }
    for(int i=0;i<n-k;i++){
        cout<<"*";
    }
    for(int i=0;i<2*k;i++){
        cout<<" ";
    }
    for(int i=0;i<n-k;i++){
        cout<<"*";
    }
    cout<<endl;
}
}

void pattern20(int n){
    for(int k=0;k<2*n-1;k++){
        int i=k;
        if(k>=n){
            i=n-(k-n+2);
        }
        
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        for(int j=0;j<2*(n-i-1);j++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern20_readable(int n){
    int spaces=2*n-2;
    for(int i=1;i<=2*n-1;i++){
        int stars=i;
        if(i>n) stars=2*n-i;
        //stars
        for(int i=1;i<=stars;i++){
            cout<<"*";
        }
        //spaces
        for(int i=1;i<=spaces;i++){
            cout<<" ";
        }
        //stars
        for(int i=1;i<=stars;i++){
            cout<<"*";
        }
        cout<<endl;
        if(i<n) spaces -= 2;
        else spaces += 2;
    }
}

void square(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1 || j==1 ||i==n ||j==n) cout<<"*"<<" ";
            else cout<<"  ";
        }
        cout<<endl;
    } 
}

void lastone(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top=i;
            int left=j;
            int bottom=2*n-2-i;
            int right=2*n-2-j;
            cout<<n-min(min(top,bottom),min(left,right));
        }
        cout<<endl;
    }
}

int  main(){
    int n=5;
    // lefttriangle(n);
    // number1(n);
    // number2(n);
    // invertedtriangle(n);
    // star2(n);
    // pyramid(n);
    // invertedpyramid(n);
    // diamond(n);
    // verticaltriangle(n);
    // pattern_01_triangle(n);
    // left_and_right_triangle(n);
    // increasing_number_triangle(n);
    // printABCtriangle(n);
    // printABCultatriangle(n);
    // printABBCCC(n);
    // ABCpyramid(n);
    // StartEpyramid(n);
    // pattern19(n);
    // pattern20(n);
    // pattern20_readable(n);   //Read this this has simple method taught by striver using more variables though
    // square(n);
    lastone(n);
    
    
    return 0;
    }


