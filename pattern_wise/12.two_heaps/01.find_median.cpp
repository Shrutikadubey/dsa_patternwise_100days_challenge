//date-17/1/26
//link-https://leetcode.com/problems/sliding-window-median/
/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation: 
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6*/
//code-
class Solution {
     multiset<int> low, high;

    void balance() {
        // low can have at most 1 extra element
        if (low.size() > high.size() + 1) {
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));
        }
        else if (low.size() < high.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }

    void add(int num) {
        if (low.empty() || num <= *low.rbegin())
            low.insert(num);
        else
            high.insert(num);
        balance();
    }

    void remove(int num) {
        if (low.find(num) != low.end())
            low.erase(low.find(num));
        else
            high.erase(high.find(num));
        balance();
    }

    double getMedian(int k) {
        if (k % 2 == 1)
            return *low.rbegin();
        return ((double)*low.rbegin() + *high.begin()) / 2.0;
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);

            if (i >= k - 1) {
                ans.push_back(getMedian(k));
                remove(nums[i - k + 1]);
            }
        }
        return ans;  
    }
};
