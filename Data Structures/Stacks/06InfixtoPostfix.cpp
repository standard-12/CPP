#include<iostream>
#include<ctype.h>
#include<stack>
using namespace std;

int priorityinput(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    else if(x=='^')
        return 4; //Because ^ has right to left precedence
    else 
        return 0;
}
int prioritystack(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    else if(x=='^')
        return 3;
    else 
        return 0;
}

int main(){
    int i=0;
    char str[15];
    stack<char> S;
    cout<<"Enter the expression\n";
    scanf("%s",str);
    while(str[i] != '\0'){
        if(str[i]=='('){
            S.push(str[i]);
        }
        else if(isalnum(str[i])){
            cout<<str[i];
        }
        else if(str[i]==')'){
            while(S.top() != '('){
                cout<<S.top();
                S.pop();
            }
            S.pop();    // To pop the ( from Stack
        }
        else{ if(S.empty()){          // To check if the stack is empty other wise it will directly go to S.top() which results in undefined behaviour
             S.push(str[i]);
        }
            else {
            while(prioritystack(S.top())>=priorityinput(str[i])){
                cout<<S.top();
                S.pop();                
            }
            S.push(str[i]);
        }
        }
        i++;        
    }
     
    while(!S.empty()){
        cout<<S.top();
        S.pop();
    }
}