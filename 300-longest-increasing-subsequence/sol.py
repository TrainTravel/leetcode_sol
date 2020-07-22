class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
    
    # if the first numnber in array is idx = 1 => 10
    # answer = 1 + lenghth(ans[nextBiggerthan 10 ~ 18]) if 
    #
    # BigO(n^2) time complexity
    # explanation:
    # ex. [10, 9, 2, 5, 3, 7, 101, 18]
    # Break the problem into subproblem:
    # For any subsequence of above array, the #LIS has the following property:
    # ex. [10, 9, 2, 5, 3, 7]
    # If the last element is 7,
    # the second last element might be: 10 or 9 or 2 or 5 or 3
    # For second last element = 10, #LIS = 1 because 7 < 10
    # For second last element = 9, #LIS = 1
    # For second last element = 2, #LIS = 2 because 7 > 2
    # For second last element = 5, #LIS = 2 because 7 > 5
    # For second last element = 3, #LIS = 3 because 7 > 3(dp[3] + 1), and 3 > 2(dp[2] + 1)
    # The #LIS for this sequence would be the maximum of the above.
    # #LIS of any sequence would be derived gradually from index 0 till last index like explained above.
    # #LIS of the whole sequence depends on #LIS of each of its subsequence.
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
