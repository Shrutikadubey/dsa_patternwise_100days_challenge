//date-08/11/25
//link-

/*Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].*/

// code-
#include <vector>
#include <algorithm>  
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
         int siz = nums.size();
        vector<int> neg, pos;
        
        // Separate negative and positive numbers
        for (int i = 0; i < siz; i++) {
            if (nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }

        // If only positive numbers
        if (neg.empty()) {
            for (int i = 0; i < pos.size(); i++)
                pos[i] = pos[i] * pos[i];
            return pos;
        }

        // If only negative numbers
        if (pos.empty()) {
            for (int i = 0; i < neg.size(); i++)
                neg[i] = neg[i] * neg[i];
            reverse(neg.begin(), neg.end());
            return neg;
        }

        // Both negative and positive numbers
        int n = neg.size();
        int m = pos.size();

        // Square and reverse negative numbers
        for (int i = 0; i < n; i++)
            neg[i] = neg[i] * neg[i];
        reverse(neg.begin(), neg.end());

        // Square positive numbers
        for (int j = 0; j < m; j++)
            pos[j] = pos[j] * pos[j];

        vector<int> res(n + m);
        int i = 0, j = 0, id = 0;

        // Merge both sorted arrays
        while (i < n && j < m) {
            if (neg[i] <= pos[j])
                res[id++] = neg[i++];
            else
                res[id++] = pos[j++];
        }

        while (i < n)
            res[id++] = neg[i++];
        while (j < m)
            res[id++] = pos[j++];

        return res;
    }
};