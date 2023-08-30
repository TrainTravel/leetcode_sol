# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
First, I tried the way "two pointer" is used to solve 392. Is Subsequence.
Then I found out basically for each character in target string, I need to scan through the source string to see if it at least exists in source. 

# Approach
<!-- Describe your approach to solving the problem. -->
First, I assumed that the target string would be longer than the source string, so I make iterating over the target string the outer loop.
The inner loop is a for loop iterating over source string.
So you can see in the inner loop, it's the same as problem 392, I advance the target string pointer **ti** when it exists in the source string, and advance the source string pointer **si** to see if the current subsequence is any longer.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(MN), where M is length of target string, and N is length of source string

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        ti, si = 0, 0
        char_found = False # to record if current character of target string exists in source string
        subseq_cnt = 0

        while ti < len(target):
            # check the source string to see if it contains the next character in target
            # for si in range(len(source)):

            char_found = False
            # go through the source string to see:
            #    1. if target[ti] exists in source
            #    2. or even better, what subsequence(length > 1) it gives
            for si in range(len(source)):

                # when target string is longer than source string
                if ti >= len(target):
                    return subseq_cnt + 1

                if target[ti] == source[si]:
                    char_found = True
                    ti += 1
                si += 1

            # source string doesn't contain the next character in target, return early
            if not char_found:
                return -1
            subseq_cnt += 1
        return subseq_cnt
                    
            
        
            
```
