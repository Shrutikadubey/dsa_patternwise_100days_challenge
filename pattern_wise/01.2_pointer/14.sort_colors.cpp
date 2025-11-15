//date-15/11/25
//link-https://leetcode.com/problems/sort-colors/
/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]*/

//code-
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};



//concept-
/*Is problem ko normal sorting se nahi karna. Hum use karenge:

Dutch National Flag Algorithm

Isme hum 3 pointers use karte hain:

 low → 0s ko left me laane ke liye
 mid → current element check karne ke liye
 high → 2s ko right me bhejne ke liye
Rules:

Agar nums[mid] == 0
→ Swap(nums[low], nums[mid])
→ low++, mid++

Agar nums[mid] == 1
→ Mid++ (kyunki 1 already beech me hi hona chahiye)

Agar nums[mid] == 2
→ Swap(nums[mid], nums[high])
→ high-- (mid ko increase nahi, kyunki swapped element check karna hai)

Ye algorithm one-pass me array sort kar deta hai.*/