class Solution {
public:
void backtrack(string &digits, vector<string> &ans, vector<string> &letter, int idx, string &comb){
    if(idx == digits.size()){
        ans.push_back(comb);
        return;
    }

    for(auto it : letter[digits[idx] - '0']){
        comb.push_back(it);
        backtrack(digits, ans, letter, idx + 1, comb);
        comb.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }
        vector<string> letter({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string comb = "";

        backtrack(digits, ans, letter, 0, comb);

        return ans;
    }
};