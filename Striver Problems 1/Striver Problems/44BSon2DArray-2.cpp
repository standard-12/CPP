
#include <bits/stdc++.h>
using namespace std;

// I had tried for like 2 hrs this problem i was thinking that binary search on 4 boundarys will reduce the search spac(actually it does in avg case)
// but it doesnt work in some special cases and has worst case time complexity of O(nlogm) which is same as binary searching all rows 
// my solution is there in leetcode it was accepted but not optimal 


// This is stair case method and time complexity is O(m+n)
bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;

    //traverse the matrix from (0, m-1):
    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    searchElement(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}