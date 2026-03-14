// String Reversal Using Stack
#include<iostream>
#include<string.h>
#include<stack> // Stack form Standara Template Library STL
using namespace std;

void reverse(char str[],int n){
    stack<char> S;
    for(int i=0;i<n;i++){
        S.push(str[i]);
    }
    for(int i=0;i<n;i++){
        str[i]=S.top();
        S.pop();
    }

}

int main(){
    char s[20];
    cout<<"Enter the stirng\n";
    gets(s);
    reverse(s,strlen(s));
    cout<<s;
    return 0;

}