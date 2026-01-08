//date-7/1/26

//link-https://leetcode.com/problems/excel-sheet-column-number/description/
/*Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 
Example 1:
Input: columnTitle = "A"
Output: 1*/

//code-
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;

        for (char ch : columnTitle) {
            int value = ch - 'A' + 1;
            result = result * 26 + value;
        }
        return result;
    }
};