/*
Internally: Hash Table

Time complexity: Average case O(1) for insert/find/erase (but worst-case O(n) due to collisions)

No order — keys are stored based on hash values

Faster than map on average

Also acts like a dictionary, but one that doesn't care about order
*/

#include<iostream>
#include<iomanip>
#include<unordered_map>
#include<string> // Not necessary but good practice since iostram already pulls <string> from Standard Library
using namespace std; 

int main() {
    unordered_map<int,string> umap; 
    umap = {{1,"Hi"}, {2,"How"}, {3,"Are"}, {4,"You"}};

    for(auto i : umap){
        cout<<i.first<<" : "<<i.second<<setw(4);
    }
    cout<<endl;

    /* There are many more functions in map such as 
    find(),count() - Does same work of checking if key exist or not 
        find() - return iterator if key found otherwise returns map.end()
        count() - return 1 if key found otherwise 0
    insert({key,value}),emplace(key,value) - For inserting elements
    */
    
    auto it=umap.find(4);
    cout<<it->second;

    
}