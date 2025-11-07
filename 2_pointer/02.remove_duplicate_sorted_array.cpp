// date-4/11/25
//link-https://leetcode.com/problems/remove-duplicates-from-sorted-array/

/* Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.
Custom Judge:
The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).*/

//code- 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //123334-> 1234
            if (nums.empty()) return 0;  // Edge case: empty array

    int i = 0; // slow pointer for unique position

    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {  // Found a new unique element
            i++;                   // Move slow pointer forward
            nums[i] = nums[j];     // Update the position with new unique value
        }
    }

    return i + 1; // length of unique elements
    }
};


// code-
//     int removeDuplicates(vector<int>& nums) {
//         //123334-> 1234
//         int k=1;
//         for(int i=1; i< nums.size() ;i++){
//             if(nums[i]!=nums[i-1]){
//                 nums[k]=nums[i];
//                 k=k+1;
//             }
//         }
//         return k;
//     }