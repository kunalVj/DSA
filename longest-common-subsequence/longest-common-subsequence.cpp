class Solution {
public:
int lcs(string &text1, string &text2, int n, int m, int dp[1001][1001]) {
        if(n==0 || m==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(text1[n-1]==text2[m-1]){
            return dp[n][m]= 1+lcs(text1,text2,n-1,m-1,dp);
        }else{
            return dp[n][m]= max(lcs(text1, text2, n, m-1, dp), lcs(text1, text2, n-1, m, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {

        int n=text1.size(), m=text2.size();
        int dp[1001][1001];
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j] = -1;
            }
        }
        return lcs(text1, text2, n, m, dp);


       /* int n = text1.size();
        int m = text2.size();

        int dp[1001][1001];

        for(int i = 0; i < 1001; i++){
            for(int j = 0; j < 1001; j++){
                dp[i][j] = -1;
            }
        }

        return lcs(text1, text2, n, m, dp); */
    }
};


/*
it will give tle

 if(n == 0 || m == 0){   // if any string gets finished. it means no char can match now so return 0
        return 0;
    }

 // if both char are matching then incraese the count of LCS and move both pointer towards left
    if(text1[n-1] == text2[m-1]){
        return 1 + lcs(text1, text2, n-1, m-1);
    }
    // if mot matching then try out both possiblities and take max
    // possibilities : check s1[i] with s[j-1] and check s[j] with s[i-1]
    else{
        
        return max(lcs(text1, text2, n-1, m), lcs(text1, text2, n, m-1));
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        return lcs(text1, text2, n, m);
    }

*/