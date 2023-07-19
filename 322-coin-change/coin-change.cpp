class Solution {
public:

    int dp[10001];

    int cc(vector<int>& coins, int amount){
        if(!amount) return 0;
        if(dp[amount] != -1) return dp[amount];
        int n = 1e4 + 1;

        for(auto &coin : coins){
            if(amount >= coin) n = min(n, cc(coins, amount - coin) + 1);
        }

        return dp[amount] = n;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        if(cc(coins, amount) == 1e4 + 1) return -1;
        return cc(coins, amount);
    }
};