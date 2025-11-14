//date-13/11/25
//link-https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

/*Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]*/


//code
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       int n = nums.size();
    vector<bool> present(n + 1, false);  
     for (int num : nums) {
        present[num] = true; 
    }

    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (!present[i]) {    
            result.push_back(i);
        }
    }
    return result; 
    }
};