class Solution {
public:
int longestCommonSubsequence(string &text1, string &text2,int m,int n,int memo[1001][1001]) {
        if(m==0 || n==0){
            return 0;
        }
        if(memo[m][n]!=-1){
            return memo[m][n];
        }
        if(text1[m-1]==text2[n-1]){
            return memo[m][n]= 1+longestCommonSubsequence(text1,text2,m-1,n-1,memo);
        }else{
            return memo[m][n]= max(longestCommonSubsequence(text1,text2,m-1,n,memo),longestCommonSubsequence(text1,text2,m,n-1,memo));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {

        int m=text1.size(),n=text2.size();
        int memo[1001][1001];
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                memo[i][j]=-1;
            }
        }
        return longestCommonSubsequence(text1,text2,m,n,memo);


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