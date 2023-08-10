class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int length = 0;
        int l = 0;
        int r = 0;
        while(r < s.size()){
            if(hash.find(s[r]) != hash.end()){
                l = max(hash[s[r]] + 1, l);
            }
            hash[s[r]] = r;
            length = max(length, r - l + 1);
            r++;
        }
        return length;

        
    }
};