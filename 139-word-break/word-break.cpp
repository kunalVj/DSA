class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<bool> seen(s.size(), 0);

        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int start = q.front();
            q.pop();

            if(start == s.size()){
                return true;
            }

            for(int end = start + 1; end <= s.size(); end++){
                if(seen[end]) continue;

                if(dict.find(s.substr(start, end - start)) != dict.end()){
                    q.push(end);
                    seen[end] = 1;
                }
            }
        }

        return false;
    }
};