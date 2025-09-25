/*
Problem: Count Subarrays Where Max Element Appears at Least K Times (LeetCode #2962)
Difficulty: Medium
Link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

Description:
Given an integer array nums and a positive integer k, return the number of subarrays 
where the maximum element of nums appears at least k times. 
A subarray is a contiguous sequence of elements within an array.

Example:
Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are:
[1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3], [3,3]

Constraints:
- 1 <= nums.length <= 10^5
- 1 <= nums[i] <= 10^6
- 1 <= k <= 10^5

Approach:
- Use a sliding window approach to track the maximum element occurrences.
- Count subarrays where the max appears >= k times efficiently.
- Time Complexity: O(n), Space Complexity: O(1) or O(n) depending on implementation.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int cnt = 0;  // count of mx in current window
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] == mx) cnt++;
            while (cnt >= k) {
                ans += n - r;
                if (nums[l] == mx) cnt--;
                l++;
            }
        }

        return ans;
    }
};
