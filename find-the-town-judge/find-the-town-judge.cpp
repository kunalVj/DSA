class Solution {
public:
// count the incoming and outgoing degree
// outgoing edge means the person trusts someone so he can never be town judge
// incoming edge means this person is trusted by someone
// a  person can be town judge only if it is trusted by everyone and he trusts no one
    int findJudge(int n, vector<vector<int>>& trust) {
       
       vector<int> count(n+1);

       for(int i = 0; i < trust.size(); i++){
           count[trust[i][0]]--;         // trust[A][B] = A trusts B , A can never be town judge so decrase it

         count[trust[i][1]]++;    // trust[A][B] B is trusted by A so it may be a town judge, so we increase it
           
       }

       for(int  i = 1; i <= n; i++){
           if(count[i] == n-1){    // if element is trusted by everyone i.e n-1 people and it trusts no one so it can be town judge
               return i; 
           }
       }
       return -1;
    }
};