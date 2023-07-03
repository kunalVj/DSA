class Solution {
public:
bool chk(int lo, int hi,string &str)
    {
        // int lo = 0, hi = str.size()-1;
        while(lo < hi)
        {
            if(str[lo] != str[hi])
                return false;
            lo++;
            hi--;
        }
        return true;
    }
    int solve(int ind, string &str, vector<int> &dp)
    {
        // If our curr string is already a palindrome, we dont need anymore cuts
        if(ind == str.size() || chk(ind,str.size()-1, str))
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int mincost =1e9;
        
        for(int part = ind; part<str.size();part++)
        {

            if(chk(ind, part, str))
            {
                //If both left and right halves are palind
                //We just need 1 cut
                if(chk(part+1,str.size()-1,str))
                {
                    mincost = 1;
                }
                else
                {
                    int take = 1 + solve(part+1,str,dp);
                    mincost = min(take,mincost);
                }
            }
        }
        return dp[ind] = mincost;
    }
public:
    int minCut(string s) {
        vector<int> dp(s.size(),-1);

        return solve(0,s,dp);
   
    }
};

/*
vector<vector<int>> dp2;
 bool isPal(string &s, int start, int end){
        if(dp2[start][end] != -1){
            return dp2[start][end] ;
        }
        while(start < end){
            if(s[start] != s[end]){
                return dp2[start][end] = 0 ;
            }
            start++ ;
            end-- ;
        }
        return dp2[start][end] = 1 ;
    }
    int util(string s, int start, int end, vector<vector<int>> &dp){
        if(dp[start][end] != -1){
            return dp[start][end] ;
        }
        if(start >= end){
            return dp[start][end] = 0 ;
        }
        //If the word is a palindrome, then zero cuts are required
        if(isPal(s, start, end)){
            return dp[start][end] = 0 ;
        }
        
        int ans = INT_MAX ;
        // Since the word is not a palindrome we will have to find the most optimal cut !!
        // So, we traverse all the possible n-1 cuts and then at each cut we check a few things
        for(int i = start ; i < end ; i++){
            // If the left part of the cut is not a palindrome then we need not do anything, we
            // continue
            if(!isPal(s,start,i)){
                continue ;
            }
            // If we are not hitting the above condition then, it is clear that the left half
            // of the cut is a palindrome, so its cost must be ZERO and no need to call the recursive function over the left half 
            // now with this cut, the cost is 0 + cost of right half + 1 (current cut)
            int tempans = 0 + util(s,i+1,end,dp) + 1 ;
            ans = min(ans, tempans) ; 
        }
        return dp[start][end] = ans ;

    }
    int minCut(string s) {
        vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,-1)) ;
        dp2.resize(s.length()+1,vector<int>(s.length()+1,-1)) ;
        return util(s, 0, s.length() - 1, dp) ;

}




*/


/*
bool palindrome(string &s, int i, int j){
    if(i >= j) return true;
    while(i < j){
        if(s[i++] != s[j--]){
            return false;
        }
    }

    return true;
}

int helper(string &s , int i , int j, vector<vector<int>> &dp){


     if(dp[i][j] != -1){
      return dp[i][j];
    }

    if(i >= j){
        return 0;
    }

    if(palindrome(s, i, j)){
        return 0;
    }

    int ans = INT_MAX;

    for(int k = i; k <= j-1; k++){

        if(palindrome(s, i, k)==false)
                continue;

        int temp = 1 + helper(s, i, k, dp) + helper(s, k+1, j, dp);

        if(temp < ans){
            ans = temp;
        }
    }

    return dp[i][j] = ans;
}
    int minCut(string s) {
       vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,-1));

        return helper(s, 0, s.size() - 1, dp);
        }
*/