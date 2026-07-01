# For all types of array having negative , positive and zero elements


def longest_subarray(nums, target):
    prefix = 0
    first = {0: -1}
    ans = 0

    for i, x in enumerate(nums):
        prefix += x

        if prefix - target in first:
            ans = max(ans, i - first[prefix - target])

        if prefix not in first:
            first[prefix] = i

    return ans