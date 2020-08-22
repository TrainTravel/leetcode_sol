class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        currentMaxSum = runSum = nums[0]

        for i in range(1, len(nums)):
            #if runSum(current Sum) is positive, try add next element
            #if runSum is negative, just discard the past elements, look forward
            #because the currentMax keeps track of the max sum for us.
            runSum = runSum + nums[i] if runSum > 0 else nums[i]
            # print(runSum)
            currentMaxSum = max(runSum, currentMaxSum)
        return currentMaxSum
