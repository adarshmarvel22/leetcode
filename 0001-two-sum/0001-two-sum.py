class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen={}
        n=len(nums)
        for i in range(n):
            diff=target-nums[i]
            if diff in seen:
                return [i,seen[diff]]
            seen[nums[i]]=i
                
        return []
        