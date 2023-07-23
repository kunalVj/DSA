class Solution {
public:
    string sortVowels(string s) {
        //first identify the vowels in the input string s and store them along with their positions in two separate vectors, vow and pos, respectively.

        vector<char> vowel;
        vector<int> pos;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || 
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                vowel.push_back(s[i]);
                pos.push_back(i);
            }
        }

        sort(vowel.begin(), vowel.end());      // sort the vowels

         string ans = s;  // ans string in which we have to make changes

        for(int i = 0; i < pos.size(); i++){
            ans[pos[i]] = vowel[i];         // replace the characters at the positions stored in the pos vector with the sorted vowels from the vow vector. 
        }

        return ans;
    }
};