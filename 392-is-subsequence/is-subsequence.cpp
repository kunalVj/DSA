class Solution {
public:
    bool isSubsequence(string s, string t) {

        // dp approach, if the LCS size is equal to string s then it's true
        
        int n = s.size();
        int m = t.size();

        int dp[n+1][m+1];

        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < m+1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }

        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){

                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        if(n == dp[n][m]){
            return true;
        }

        return false;
    }
};

/*
int i = 0, j = 0;
        int a = s.size(), b = t.size();
        
        while(i < a && j < b){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i == a){
            return true;
        }
        return false;
*/