class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        cache = {}

        def dfs(i, j):

            if (len(t)-j) > (len(s)-i): 
                return 0

            if j == len(t): # means we reached at the end of t
                return 1

            if i == len(s): # means we reached at the end of s
                return 0

            if (i,j) in cache:
                return cache[(i,j)]

            if s[i] == t[j]:
                cache[(i, j)] = dfs(i+1, j+1) + dfs(i+1, j)

            else:
                cache[(i, j)] = dfs(i+1, j)

            return cache[(i, j)] 

        return dfs(0, 0)