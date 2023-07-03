class Solution {
public:
    bool buddyStrings(string s, string goal) {
       if(s.size() != goal.size()){
           return false;
       }

       if(s == goal){
           // If we have 2 same characters in string 's',
        // we can swap them and still strings will remain equal.
           vector<int> freq(26, 0);

           for(auto it : s){
               freq[it - 'a'] += 1;
               if(freq[it - 'a'] == 2){
                   return true;
               }
           }
            // Otherwise, if we swap any two chanacters it will make strings unequal.
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
                   // We have atleast 3 indices with differnet characters,
                    // thus, we can never make strings equal with only one swap.
                   return false;
               }
           }
       }

       if(secondChar == -1){
           // We can't swap if character at only one index is different.
           return false;
       }

 // All characters of both the string are same except two indices.
       return s[firstChar] == goal[secondChar] && s[secondChar] == goal[firstChar];

    }
};