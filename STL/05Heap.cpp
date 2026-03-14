#include<queue>//Also contains priority_queue or heap
#include<iostream>
using namespace std;

// Implementation of this is not linear it uses tree which we will learn later for now ill represent it as linear 

int main(){
    // Max Heap ...i,e the maximum number is given priority or in case of strings lexiographically max string is given priority 
    priority_queue<int> pq;
    pq.push(5); // {5}
    pq.push(3); // {5,3}
    pq.push(7); //{7,5,3} // Note Now 7 is pushed to top ...this is not linear like this just for represenation
    cout<<pq.top()<<endl;// Prints 7 since it is at the top

    pq.pop() ;// Pops 7

    //Min Heap
    priority_queue<int,vector<int>,greater<int>> pq1; // this should be written reason will be(should be ) explored later
    pq1.push(5); 
    pq1.push(3); 
    pq1.push(7);
    cout<<pq1.top()<<endl; // Prints 3

}
