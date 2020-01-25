#Runtime: 32 ms, faster than 66.39% of Python3 online submissions for Longest Common Prefix.
#Memory Usage: 12.7 MB, less than 100.00% of Python3 online submissions for Longest Common Prefix.
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        shortest = min(strs, key=len)
        for i, ch in enumerate(shortest):
            for other in strs:
                if ch != other[i]:
                    return shortest[:i]
        return shortest
