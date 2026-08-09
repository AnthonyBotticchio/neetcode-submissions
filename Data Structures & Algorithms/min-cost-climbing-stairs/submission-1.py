class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cache = {} # We use dict for key (num) and value (minimum cost at that step)

        def dfs(i):
            if i >= len(cost): # We know that at the last step or above the cost to add is 0
                return 0

            if i in cache: # We want to search cache for value since we do min(dfs, dfs)
                return cache[i]
            
            # Here we add the cost to the min cost of doing two steps or one step afterwards
            cache[i] = cost[i] + min(dfs(i + 1), dfs(i + 2))
            return cache[i] # We ofc cache the value then return it
        
        return min(dfs(0), dfs(1))

