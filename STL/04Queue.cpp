#include<queue>
#include<iostream>
using namespace std;
 
int main(){
    queue<int> q;
    q.push(4); //{4}
    q.push(5); //{4,5}
    q.pop(); //{5} // Deletion from front end
    q.push(6); // Insertion at rear/back end
    q.push(7); // {5,6,7}
    cout<<q.back()<<endl; //Prints 7
    cout<<q.front()<<endl; //Prints 5
    
}
