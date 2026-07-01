class Solution:
    def findMissingRepeatingNumbers(self, nums):
        
        n = len(nums)

        SN = (n * (n + 1)) // 2

        S2N = (n * (n + 1) * (2 * n + 1)) // 6

        """ Calculate actual sum (S) and sum 
            of squares (S2) of array elements """
        S = 0
        S2 = 0
        for num in nums:
            S += num
            S2 += num * num

        val1 = S - SN          # (x-y)

        val2 = S2 - S2N        # (x^2 - y^2)

        val2 = val2 // val1    # (x+y)

        """ Calculate X and Y from X + Y and X - Y
            X = ((X + Y) + (X - Y)) / 2
            Y = X - (X - Y) """
        x = (val1 + val2) // 2
        y = x - val1

        return [int(x), int(y)]

nums = [3, 1, 2, 5, 4, 6, 7, 5]

sol = Solution()

result = sol.findMissingRepeatingNumbers(nums)

print(f"The repeating and missing numbers are: {{{result[0]}, {result[1]}}}")
