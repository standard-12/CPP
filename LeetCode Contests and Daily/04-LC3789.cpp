#include<bits/stdc++.h>
using namespace std;

// This was my solution but there is a cleaner solution with less no of lines
// But i took way too much time than i should have for this
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mini=LLONG_MAX;
        long long ans1=1LL*max(need1,need2)*costBoth;
        long long ans2=1LL*cost1*need1+1LL*cost2*need2;
        mini=min(mini,min(ans1,ans2));
        if(need1 !=need2){
            if(need2>need1){
                long long ans3=1LL*costBoth*need1+1LL*cost2*abs(need2-need1);
                mini=min(mini,ans3);
            }
            else {
                long long ans4=1LL*cost1*abs(need1-need2)+1LL*costBoth*need2;
                mini=min(mini,ans4);
            }
        }
        return mini;
    }
};

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long min, max, ans;
        min = fmin(need1, need2);
        max = fmax(need1, need2);
        ans = (long long) need1 * cost1 + (long long) need2 * cost2;
        ans  = fmin(ans, (long long)min * costBoth + (long long) (need1 - min) * cost1 + (long long) (need2 - min) * cost2); 
        // Using the above line i need not do 2 separate conditions for need1 > need2 and need2 > need1 (niceee)
        ans = fmin(ans, (long long) max * costBoth);
        return ans;
    }
};