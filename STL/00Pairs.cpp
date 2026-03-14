#include<utility>// Pair is defined in the uitlity header file
#include<iostream> 
using namespace std;

int main(){
    pair<int,int> p={1,2};//Stores a pair of value 
    cout<<p.first<<p.second<<endl;

    pair<int,string> p1={1,"one"}; // it can be of different data types
    cout<<p1.first<<p1.second<<endl;

    pair<int,pair<int,int>> p2={1,{2,3}}; // It can be nested for increasing size etc
    cout<<p2.first<<p2.second.first<<p2.second.second<<endl;

    pair<int,int> p3={2,4};
    p3.first=8;                    // Updating values of pairs
    p3.second=9;
    cout<<p3.first<<p3.second<<endl;

    pair<int,int> arr[3]={{1,2},{3,4},{5,6}}; // We can create array of pairs
    cout<<arr[0].first<<arr[2].second<<endl; //Printing can be done like this
    // cout<<arr[0]; This gives error
    
    

}