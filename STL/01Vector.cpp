#include<iostream>
#include <vector> // Vectors is a resizable array.

using namespace std;



int main(){
    vector<int> v1; // Creates an empty container

    v1.push_back(1); // Inserts 1
    v1.emplace_back(2); // Similar to push_back but faster reason is not required for now 

    cout<<v1[0]<<v1[1]<<endl;  // Printing can be done like this 
    cout<<v1.at(0)<<v1.at(1)<<endl; // or like this

    vector<pair<int,int>> v2;
    v2.push_back({2,3});
    v2.emplace_back(4,6); //It automatilcalle detects it as a pair
    cout<<v2.at(0).first<<v2[1].second<<endl;
    
    vector<int> v3(5,100); // Equal to {100,100,100,100,100}
    vector<int> v4(5); // {0,0,0,0,0} or itll be garbage values depending on the compiler 
    cout<<v4[0]<<endl; // In this it initialisez to zero
    v4.push_back(5); 
    cout<<v4[5]<<endl; // We can extend already initialised vectors

    vector<int> v5={1,2,3,4,5};
    cout<<v5.front()<<endl; // Prints first element 
    cout<<v5.back()<<endl; // Prints last element

    //Iterators

    vector<int>::iterator s=v5.begin(); // iterators store address ...here it stores address of the first element
    cout<<*(s)<<endl; // Dereferencing the address
    s++; //Moves to next adress ...since address of vectors are contiogus moves to next elements address 
    // Iterators are similar to pointer but there are differences which is not required for now
    s=v5.end(); // This doesn't point to last element but next address of last element 
    cout<<*(--s)<<endl; // Prints the last element 

    //Printing whole vectors

    for(auto i : v5)  // Auto autmoatically assings the required data tyoe and this is for each loop 
    cout<<i<<" ";
    cout<<endl;

    for(auto i=v5.begin(); i!=v5.end();i++){ // here i will be iterator automaically
        cout<<*(i)<<" ";
    }
    cout<<endl;

    // Deleting from vectors

    v5.erase(v5.begin() + 1 ); // We should pass an iterator to erase not indexes...Now v5={1,3,4,5}
    v5.erase(v5.begin()+1,v5.end()-1); // Now first will be pointing to ele at index 1 and 2nd parameter will be pointing to last element (since v.end() points to next element of last element) 
    // So elements starting from index 1 will be deleted except last ele(i.e the address pointed by 2nd parameter)
    cout<<v5[0]<<v5[1]<<endl; // {1,5}

    // Inserting 

    v5.insert(v5.begin()+1,2); //{1,2,5}
    v5.insert(v5.begin()+2,3); //{1,2,3,5}
    v5.insert(v5.end()-1,4); // {1,2,3,4,5}

    for(auto i : v5)   
    cout<<i<<" ";
    cout<<endl;

      
       


}