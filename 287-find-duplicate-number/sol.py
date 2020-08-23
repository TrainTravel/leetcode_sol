#Time Complexity: O(nlogn)
#Space Complexity: O(1)
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        if len(nums) == 2:
            return nums[0]
        sorted_nums = sorted(nums)

        slow_ptr, fast_ptr = sorted_nums[0:2]
        for i in range(len(nums) - 2):
            if sorted_nums[slow_ptr] == sorted_nums[fast_ptr]:
                return sorted_nums[slow_ptr]
            slow_ptr += 1
            fast_ptr += 1
