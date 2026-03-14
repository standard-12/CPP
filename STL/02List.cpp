#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> L;
    
    L.push_back(5); //{5}
    L.emplace_back(4); //{5,4}

    L.push_front(3); //{3,5,4} this is the extra function in list w.r.t vectors this is faster compared to insert of vectors 
    // We wont do deeper for the reasons for now itll be explored later it seems ( but he said list uses DLL and vector uses SLL)

    //Other functions begin ,end,size ,clear ,epmty are same as vector

}