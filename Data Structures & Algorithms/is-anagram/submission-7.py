class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        count1, count2 = {}, {}

        for n in range(len(s)):
            count1[s[n]] = 1 + count1.get(s[n], 0)
            count2[t[n]] = 1 + count2.get(t[n], 0)
        return count1 == count2
        