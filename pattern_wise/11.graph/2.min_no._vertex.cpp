//date-16/1/26
//link-https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
/*Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.
Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.
Notice that you can return the vertices in any order.

Example 1:
Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output: [0,3]
Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].*/
//code-
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
      vector<int> indegree(n, 0);
        // Calculate indegree
        for (auto &e : edges) {
            indegree[e[1]]++;
        }
        // Collect nodes with indegree 0
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                result.push_back(i);
        }
        return result; 
    }
};