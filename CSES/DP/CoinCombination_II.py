MOD = 1000000007

n, x = map(int, input().split())
coins = list(map(int, input().split()))

dp = [0] * (x + 1)
dp[0] = 1

for coin in coins:
    for s in range(coin, x + 1):
        dp[s] = (dp[s] + dp[s - coin]) % MOD

print(dp[x])