/*
Problem: Push Dominoes (LeetCode #838)
Difficulty: Medium
Link: https://leetcode.com/problems/push-dominoes/

Description:
There are n dominoes in a line, each upright. Some dominoes are pushed
to the left ('L') or right ('R'), while others are upright ('.').
After each second, falling dominoes push adjacent upright dominoes.
Return the final state of dominoes.

Example:
Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."

Constraints:
- 1 <= dominoes.length <= 10^5
- dominoes[i] ∈ {'L','R','.'}

Approach:
- Use two passes: left→right and right→left to track forces.
- Calculate net force on each domino and determine final state.
- Time Complexity: O(n), Space Complexity: O(n)
*/

#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n, INT_MAX), right(n, INT_MAX);

        // Pass 1: left → right (track force from 'R')
        int time = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') time = 0;
            else if (dominoes[i] == 'L') time = INT_MAX;
            else if (time != INT_MAX) time++;
            right[i] = time;
        }

        // Pass 2: right → left (track force from 'L')
        time = INT_MAX;
        for (int i = n-1; i >= 0; i--) {
            if (dominoes[i] == 'L') time = 0;
            else if (dominoes[i] == 'R') time = INT_MAX;
            else if (time != INT_MAX) time++;
            left[i] = time;
        }

        // Determine final state
        for (int i = 0; i < n; i++) {
            if (left[i] < right[i]) dominoes[i] = 'L';
            else if (right[i] < left[i]) dominoes[i] = 'R';
            else dominoes[i] = '.';
        }

        return dominoes;
    }
};
