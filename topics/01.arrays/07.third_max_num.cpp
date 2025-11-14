//date-13/11/25
//link-https://leetcode.com/problems/third-maximum-number

/*Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.*/


//code
#include<vector>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end()); 
        vector<int> uniqueNums(s.begin(), s.end()); 
        if (uniqueNums.size() < 3) {
            return uniqueNums.back(); 
            } else {
                return *(uniqueNums.end() - 3); 
            } 
    }
};