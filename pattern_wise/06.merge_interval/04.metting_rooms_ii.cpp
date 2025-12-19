//date-19/12/25
//link-https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1
/*Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting and end[i] is the ending time of ith meeting. Return the minimum number of rooms required to attend all meetings.

Note: A person can also attend a meeting if it's starting time is same as the previous meeting's ending time.

Examples:

Input: start[] = [1, 10, 7], end[] = [4, 15, 10]
Output: 1
Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings in a single room.*/

//code-
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
    // code here
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int i = 0, j = 0;
    int rooms = 0, maxRooms = 0;
    int n = start.size();
    while (i < n) {
        if (start[i] >= end[j]) {
            rooms--;   
            j++;
        }
        rooms++;       
        maxRooms = max(maxRooms, rooms);
        i++;
    }
    return maxRooms;
    }
};
