"""
76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
"""

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t):
            return ""

        min_window = [0, len(s) + 1]
        t_map = {}
        s_map = {}
        match_count = 0

        for char in t:
            if char not in t_map:
                t_map[char] = 1
            else:
                t_map[char] += 1
        
        l = 0
        for r in range(len(s)):
            char = s[r]
            if char in t_map:
                if char in s_map:
                    s_map[char] += 1
                else:
                    s_map[char] = 1
                
                if s_map[char] == t_map[char]:
                    match_count += 1
                
                while match_count == len(t_map):
                    if r - l < min_window[1] - min_window[0]:
                        min_window = [l, r]
                    if s[l] in s_map:
                        s_map[s[l]] -= 1
                        if s_map[s[l]] < t_map[s[l]]:
                            match_count -= 1
                    l += 1
        
        return "" if min_window[1] == len(s) + 1 else s[min_window[0] : min_window[1] + 1]

        