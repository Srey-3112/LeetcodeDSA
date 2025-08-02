import random

class Solution:
    def findKthLargest(self, nums, k):
        return self.quickSelect(nums, k)

    def quickSelect(self, nums, k):
        pivot = random.choice(nums)

        left = []
        mid = []
        right = []

        for num in nums:
            if num > pivot:
                left.append(num)
            elif num < pivot:
                right.append(num)
            else:
                mid.append(num)

        if k <= len(left):
            return self.quickSelect(left, k)
        if k > len(left) + len(mid):
            return self.quickSelect(right, k - len(left) - len(mid))
        return pivot

        
        