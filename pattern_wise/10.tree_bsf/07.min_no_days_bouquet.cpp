//date-7/1/26

//link-https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
/*Given an integer array bloomDay, an integer m and an integer k, return the minimum number of days to wait until we can make m bouquets from the flowers.
Each bouquet requires exactly k flowers.
If it is impossible to make m bouquets, return -1.

Example 1:
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: We need 3 bouquets each with 1 flower. The minimum number of days required is 3.

Example 2:
Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each with 2 flowers. It's impossible to make them in any day.

Example 3:
Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each with 3 flowers. The minimum number of days required is 12.
*/

//code-
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;
        for (int d : bloomDay) {
            if (d <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
         long long n = bloomDay.size();
        if ((long long)m * k > n) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};