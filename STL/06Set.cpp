// Sorted and Unique ....2 points to remember for set
#include<set>
#include<iostream>
using namespace std;

//This also uses tree and here we represent it as linear

int main(){
    set<int> s;
    s.insert(5); //{5}
    s.insert(3); //{3,5}
    s.insert(3); //{3,5} //Uniqueness property
    s.insert(2); // {2,3,5}

    auto it=s.find(3);// Return the iterator pointing to 3
    auto it2=s.find(6); // If element is not there then it will return st.end()

    s.erase(5); // {2,3} //We can directly give value or iterator both works
}
