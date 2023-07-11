class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int right = 0;
        int end = s.size() - 1;
        int count = 0;

        int n = s.size();

        unordered_map<char, int> mp;

        while(right < n){

            mp[s[right]]++;

            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){

                count += 1 + (end - right);

                mp[s[left]]--;
                left++;
            }

            right++;
        }

        return count;
    }
};