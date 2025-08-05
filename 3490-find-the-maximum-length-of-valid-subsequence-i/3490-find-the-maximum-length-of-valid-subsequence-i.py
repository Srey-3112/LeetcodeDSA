class Solution(object):
    def maximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        even_count = 0
        odd_count = 0
        for x in nums:
            if x % 2 == 0:
                even_count += 1
            else:
                odd_count += 1
        
        # Candidate A: take all evens or all odds (sum of adjacent = even)
        best_same_parity = max(even_count, odd_count)
        
        # Step 2: Build the longest alternating-parity subsequence (sum = odd)
        longest_alt = 0
        prev_parity = None
        
        for x in nums:
            curr_parity = x % 2
            # I take x if it's the first pick, or if it flips parity
            if prev_parity is None or curr_parity != prev_parity:
                longest_alt += 1
                prev_parity = curr_parity
        
        # Candidate B: that alternating run
        best_alternating = longest_alt
        
        # Step 3: The answer is the larger of the two strategies
        return max(best_same_parity, best_alternating)
        