class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list) # mapping char count to list of Anagrams
        for s in strs:
            countChar = [0] * 26 # from a - z
            for i in s: # map a to index 0 and z to index 25
                countChar[ord(i) - ord("a")] += 1 
                # Assigns the index of countChar to be the associated value from 'a'
                # Every string s that is an anagram of another will share the same countChar
                # list. Thus, the key in the dict is match that of an anagram and will append it
                # to the tuple that exists for that anagram.
            res[tuple(countChar)].append(s)
        print(res)
        return res.values()
            
            
            
            
                

        