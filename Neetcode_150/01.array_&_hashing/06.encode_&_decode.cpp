//date-26/12/25
//link-https://neetcode.io/problems/string-encode-and-decode/question?list=neetcode150
/*Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.
Please implement encode and decode

Example 1:
Input: ["neet","code","love","you"]
Output:["neet","code","love","you"]*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            j++;
            result.push_back(s.substr(j, len));
            i = j + len;
        }
        return result;
    }
};
