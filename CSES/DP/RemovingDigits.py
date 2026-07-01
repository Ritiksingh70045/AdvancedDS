def solve(amount, dp):
    if amount == 0:
        return 0

    if dp[amount] != -1:
        return dp[amount]

    dup = amount
    ans = 10**9

    while dup:
        dig = dup % 10

        if dig != 0:
            ans = min(ans, 1 + solve(amount - dig, dp))

        dup //= 10

    dp[amount] = ans
    return ans


n = int(input())

dp = [0] * (n + 1)

for amount in range(1 , n+1):
  dp[amount] = 10**9
  
  x = amount
  while x:
    d = x%10
    if d:
      dp[amount] = min(dp[amount] , 1 + dp[amount-d])
    
    x //= 10
    
print(dp[n])