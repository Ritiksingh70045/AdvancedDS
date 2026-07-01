def maxLen(A: list[int], n: int) -> int:
    mpp: dict[int, int] = {}
    maxi = 0
    s = 0

    for i in range(n):
        s += A[i]

        if s == 0:
            maxi = i + 1
        else:
            if s in mpp:
                maxi = max(maxi, i - mpp[s])
            else:
                mpp[s] = i

    return maxi

def main():
    A = [9, -3, 3, -1, 6, -5]
    n = len(A)
    print(maxLen(A, n))

if __name__ == "__main__":
    main()
