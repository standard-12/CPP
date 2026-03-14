#include<bits/stdc++.h>
using namespace std;

// This was also there in our DAA syllabus so i was able to solve it on my own
// Key point : Sort According to (Value per Weight)
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double,int>> ref;
        int n=val.size();
        for(int i=0;i<n;i++){
            double d=(double)val[i]/wt[i];
            ref.push_back({d,wt[i]});
        }
        
        sort(ref.begin(),ref.end(),greater<pair<double,int>>());
        
        double ans=0;
        for(int i=0;i<n;i++){
            double d=ref[i].first;
            int w=ref[i].second;
            double val=d*w;
            
            if(capacity-w>0){
                capacity-=w;
                ans+=val;
            }
            else {
                double ratio= (double)capacity/(double)w;
                ans+=ratio*val;
                return ans;
            }
        }
        return ans;
    }
};

// Same thing but we can create a custom compartor to sort the original array by VALUE PER WEIGHT instead of 
// creating a separate array to store it and then sort it

class Solution {
public:
    struct Item {
        int value;
        int weight;
    };
    // Comparator function to sort items by value/weight ratio
    bool static comp(Item a, Item b) {
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;  // Return true if the ratio of item a is greater than item b
    }

    // Function to calculate the maximum value we can get with fractional knapsack
    double fractionalKnapsack(int W, Item arr[], int n) {
        
        // Sort items based on the value/weight ratio
        sort(arr, arr + n, comp);

        int curWeight = 0;  // Current weight of knapsack
        double finalvalue = 0.0;  // Final value we can achieve

        // Iterate through the sorted items
        for (int i = 0; i < n; i++) {

            // If the current item can be fully added to the knapsack
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;  // Add the full value of the item
            } else {
                // If the current item can't be fully added, take the fractional part
                int remain = W - curWeight;
                finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
                break;  // Break as we have filled the knapsack
            }
        }

        return finalvalue;  // Return the maximum value that can be carried
    }
};

