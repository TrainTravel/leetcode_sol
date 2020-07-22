class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
    
    # if the first numnber in array is idx = 1 => 10
    # answer = 1 + lenghth(ans[nextBiggerthan 10 ~ 18]) if 
    #
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        dp = [1] * n
        for i in range(1,n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
#         for i in range(n):
#             print(dp[i])
