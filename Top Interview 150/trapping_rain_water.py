
"""
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 10
"""

class Solution:
    def trap(self, height: list[int]) -> int:
        maxLeft = [0] * len(height)
        maxHt = 0
        for i in range(len(height)):
            maxHt = max(maxHt, height[i])
            maxLeft[i] = maxHt
        maxHt = 0
        total = 0
        for i in range(len(height) - 1, -1, -1):
            maxHt = max(maxHt, height[i])
            res = min(maxHt, maxLeft[i]) - height[i]
            if res > 0:
                total += res
        return total

        