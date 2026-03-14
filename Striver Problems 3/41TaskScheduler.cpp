#include<bits/stdc++.h>
using namespace std;

// I was not able to come up with the solution i was trying to simulate the working using priority queue but to only solve the question 
// we can directly do it by getting max frequent element without priority queue (there is no need to find out the order)

// This is the O(n) solution using maths
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Uses a nice concept 
        // No of slots= No of tasks+ idleSlots
        int size=tasks.size();
        vector<int> freq(26,0);
        int maxFreq=0;
        int maxFreqindex=0;
        for(int i=0;i<size;i++){
            int ind=tasks[i]-'A';
            freq[ind]++;
            if(freq[ind]>maxFreq) {
                maxFreq=freq[ind];
                maxFreqindex=ind;
            }
        }

        int idleSlots=(maxFreq-1)*n; // minimum idle slots
        // n is the minimum gap required

        for(int i=0;i<26;i++){
            if(i != maxFreqindex){
                idleSlots = idleSlots - min(maxFreq-1,freq[i]);
                // If another char has same frequency as maxFreq we should remomve only maxFreq-1 slots
            }
        }

        return tasks.size() + max(0,idleSlots); 
        
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        vector<int> freq(26, 0);
        for (char c : tasks) freq[c - 'A']++;
        // max-heap of remaining counts
        priority_queue<int> pq;
        for (int f : freq) if (f > 0) pq.push(f);

        int time = 0;
        // queue of pairs: (remaining_count, ready_time)
        queue<pair<int,int>> wait;

        while (!pq.empty() || !wait.empty()) {
            time++;
            if (!pq.empty()) {
                int cur = pq.top(); pq.pop();
                cur--; // execute one instance
                if (cur > 0) {
                    // will be ready again after n time units from now
                    wait.push({cur, time + n});
                }
            }
            // move tasks whose cooldown expired back into pq
            if (!wait.empty()) {
                auto front = wait.front();
                if (front.second == time) {
                    pq.push(front.first);
                    wait.pop();
                }
            }
        }
        return time;
    }
};
