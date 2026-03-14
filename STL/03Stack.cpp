#include<stack>
#include<iostream>
using namespace std;

int main(){
    stack<int> st;
    st.push(4); // {4}
    st.push(5); // {5,4}
    st.push(6); // {6,5,4}
    cout<<st.top()<<endl;// Prints 6
    st.emplace(7); // emplace also works {7,6,5,4}
    st.pop(); // {6,5,4}
    
    // stack<int> st={1,2}; Cannont initialize like vectors but in CHATGPT it says we can do something by using underlaying container etc like stack<int,vector<int>> ...FOr now this is not neccessary so lets go forward 
    stack<int> st2;
    st2.emplace(1);

    st2.swap(st); // Element of both stacks are exchanged

    cout<<st.top(); //Prints 1


}