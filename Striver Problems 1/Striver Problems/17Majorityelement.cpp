#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// This gives a candidate. If the problem states there is a solution for sure then this works otherwise we should verify it it occurs more than n/2 times
int majority(vector<int> &nums)
{
    int size = nums.size();
    int count = 0;
    int major = nums[0];
    for (int i = 0; i < size; i++)
    {
        if (count == 0)
        {
            major = nums[i];
            count++;
        }
        else if (nums[i] == major)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return major;
}
/* This is for n/3 elements here it is necessary to verify if it exists more than n/3 times
 and its neccessary to check if val1 and val2 are not same*/
vector<int> majortiy3(vector<int> &nums)
{
    int size = nums.size();
    int cnt1 = 0;
    int val1 = INT_MIN;
    int val2 = INT_MIN;
    int cnt2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (cnt1 == 0 && val2 != nums[i])  // val2!=nums[i] is important or we can switch these 2 statements with the next statement like 
        {
            cnt1++;
            val1 = nums[i];
        }
        else if (cnt2 == 0 && val1 != nums[i])
        {
            cnt2++;
            val2 = nums[i];
        }
        else if (nums[i] == val1 || nums[i] == val2) // With this in that case if any of them is equal then it will be incremented rather than being considered as val1 or val2
        {
            if (nums[i] == val1)
                cnt1++;
            else
                cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ans;
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == val1)
            cnt1++;
        if (nums[i] == val2)
            cnt2++;
    }
    if (cnt1 > nums.size() / 3)
        ans.push_back(val1);
    if (cnt2 > nums.size() / 3)
        ans.push_back(val2);
    return ans;
}



int main()
{
    vector<int> nums = {4, 2, 4, 2, 4, 4, 2, 4, 2, 2, 2, 4, 4};
    cout << majority(nums)<<endl;
    vector<int> ans= majortiy3(nums);
    for(int ans:ans) cout<<ans<<" ";
    return 0;
}