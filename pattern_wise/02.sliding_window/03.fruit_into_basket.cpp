//17/11/25
//limk-https://leetcode-cn.com/problems/fruit-into-baskets/
/*You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.*/

//code-
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         unordered_map<int, int> count;
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.size(); right++) {
            count[fruits[right]]++;

            // If more than 2 fruit types, shrink window
            while (count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) {
                    count.erase(fruits[left]);
                }
                left++;
            }

            // Update max
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    
    }
};