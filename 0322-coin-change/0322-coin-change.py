class Solution:
    def coinChange(self, coins, amount):

        # dp={}

        # def dfs(amount):
        #     if amount == 0:
        #         return 0
        #     if amount in dp:
        #         return dp[amount]
        #     res = 1e9
        #     for coin in coins:
        #         if amount - coin >= 0:
        #             res = min(res, 1 + dfs(amount - coin))


        #     dp[amount]=res
        #     return res


        # minCoins = dfs(amount)

        # return -1 if minCoins >= 1e9 else minCoins


        arr=[]
        for i in range(amount+1):
            arr.append(float('inf'))

        arr[0]=0

        for coin in coins:
            for j in range(coin,len(arr)):
                arr[j]=min(arr[j],arr[j-coin]+1)

        return -1 if arr[-1]==float('inf') else arr[-1]



       