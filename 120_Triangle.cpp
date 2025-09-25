/*
Problem: Triangle (LeetCode #120)
Difficulty: Medium
Link: https://leetcode.com/problems/triangle/

Description:
Given a triangle array, return the minimum path sum from top to bottom.
At each step, you may move to adjacent numbers on the row below.

Example:
Input: [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: Minimum path = 2 + 3 + 5 + 1 = 11

Constraints:
- 1 <= triangle.length <= 200
- triangle[0].length == 1
- triangle[i].length == triangle[i - 1].length + 1
- -10^4 <= triangle[i][j] <= 10^4

Approach (Bottom-Up DP):
- Start from the second last row and move upward.
- For each cell, add the minimum of its two children from the row below.
- At the end, the top cell holds the minimum path sum.
- Time Complexity: O(n^2), Space Complexity: O(1) (in-place).

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Start from the second last row, move upward
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                // Update current cell with best path sum
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
