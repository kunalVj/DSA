class Solution {
public:
    bool buddyStrings(string s, string goal) {
       if(s.size() != goal.size()){
           return false;
       }

       if(s == goal){
           vector<int> freq(26, 0);

           for(auto it : s){
               freq[it - 'a'] += 1;
               if(freq[it - 'a'] == 2){
                   return true;
               }
           }
           return false;
       }

       int firstChar = -1;
       int secondChar = -1;

       for(int i = 0; i < s.size(); i++){
           if(s[i] != goal[i]){
               if(firstChar == -1){
                   firstChar = i;
               }
               else if(secondChar == -1){
                   secondChar = i;
               }
               else{
                   return false;
               }
           }
       }

       if(secondChar == -1){
           return false;
       }

       return s[firstChar] == goal[secondChar] && s[secondChar] == goal[firstChar];

    }
};