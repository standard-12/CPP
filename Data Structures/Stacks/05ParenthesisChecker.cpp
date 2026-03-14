#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
bool check(char str[]){
    stack<char> S;
    
    for(int i=0;i<strlen(str);i++){
        if(str[i] == '(' || str[i]== '{' || str[i] =='[')
        S.push(str[i]);
   
        if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {   if(S.empty()){
            return false; //If the first entry is closing bracket ...this is necessary otherwise there will be undefined behaviour
        }
            char x=S.top();
            if(str[i]==')' && x=='(')
                S.pop();
            else if(str[i]=='}'&& x=='{')
                S.pop();
            else if(str[i]==']' && x=='[')
                S.pop();
            else
                return false;
        }
    }
    
    return S.empty();
}
int main(){
    char str[15];
    cout<<"Enter the parenthesis\n";
    gets(str);
    if(check(str)){
        cout<<"Balanced";
    }
    else
    cout<<"Not Balanced";
}